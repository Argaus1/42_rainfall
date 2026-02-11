# BONUS 0

Though one.

## The exploit

Goal : overflow return addr of pp with shellcode for "system("/bin/sh")".

### program unfolding

The normal unfolding of this program:
- stdin is read two times and the inputs are buffered
- the buffers are concatenated with a space in between them
- the are displayed on stdout : "input1 input2"

In the main function, a first buffer is allocated on the stack, of 0x2a/44 bytes. --> **We'll call it v0**.

A function pp is called, in which two 0x14/20 bytes buffers are allocated on the stack. --> **v1 and v2**

Lastly, pp calls a p function two times. This function uses a buffer of 0x1000 bytes. --> **read_buf**

Calling p 2 times is the first thing pp does. P allocates a static read\_buf[0x1000], and calls read() with it + stdin. It then seeks for a \n and replaces it with \0. 20 bytes of this buf are strncpied in the buf[20] given as an argument.

This way, the two vx[20] statically allocated in pp are filled with p.

**Read_buf is way greater than 20, which means we can use it to write shell code further in memory.**

In pp, we see that the two buffers of 20 are allocated next to each other. **When read_buf was strncpyied in v2, it overwrote v1's \0 (if v1 was 20 bytes long)**.

After p is called two times, v1 is strcpyied in v0. **And v2 is copyied too, since the null byte was overwritten, the copying goes on until v2's null byte**.

For now we have v1 + v2 in v0. Pp keeps on with strcat, to conctenate v2 in v0. Since v1 and v2 have already been copyied, **adding v2 will go beyond the 0x2a limit of v0**. 20 + 20 + space + 20 = **61 bytes**.

**61 bytes are enough to overwrite main's return address, and give the address of the shellcode we wrote deep in read_buf**.

The plan:
- writing 20 bytes in v1 and shellcode deep enough in read\_buf for it not to be overwritten by the second calling of read
- writing padding + shellcode address (read\_buf) in v2

### Stack overview

These 4 buffers are laid out like this on the stack:

```
	address read_buf 0xbffff680
p -> base pointer 0xbffff688
	address v1 0xbffff6b8
	address v2 0xbffff6cb
pp -> base pointer 0xbffff6e8
	address v0 0xbffff706
main -> base pointer 0xbffff738
	eip at 0xbffff73c
```


## Writing the exploit

This is our exploit :

```
(python -c 'print "\x90" * 100 + "\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x89\xc1\x89\xc2\xb0\x0b\xcd\x80\x31\xc0\x40\xcd\x80" ; python -c 'print "A" * 9 + "\xd0\xe6\xff\xbf" + "B" * 7'; cat) | ./bonus0
```

The shellcode is the one we used in level0.

It is a bit annoying to find the right padding, but the noops allow us to be free enough to determinate the address to write.
