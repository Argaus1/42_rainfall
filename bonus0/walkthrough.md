# BONUS 0

Goal : overflow return addr of pp with shellcode for "system("/bin/sh")".

Using this big read buff and strcat.

## Unaligned buffer

Something is worth noticingm sthg that makes the padding more difficult thant before : **the buffer we use for oiverwriting the return address is unaligned**. Its address isn't a multiple of 0x10(16).

We can see this in this snippet of asm :

``
	80485a4:	55                   	push   ebp
	80485a5:	89 e5                	mov    ebp,esp
	80485a7:	83 e4 f0             	and    esp,0xfffffff0
	80485aa:	83 ec 40             	sub    esp,0x40
	80485ad:	8d 44 24 16          	lea    eax,[esp+0x16]
	80485b1:	89 04 24             	mov    DWORD PTR [esp],eax
	80485b4:	e8 65 ff ff ff       	call   804851e <pp>
``

``lea eax,[esp+0x16]`` will give an unaligned buffer.
