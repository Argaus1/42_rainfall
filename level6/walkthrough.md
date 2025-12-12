# LEVEL 6

No particular protection for our bin, we can exploit !!!!

This program takes user arguments. To see argv in gdb :

break \_start (before prologue)
run AAAA

Here esp = argc
esp + 4 = argv[0]
esp + 8 = argv[1]

x/wx $esp+8 -> gives the addr of argv[1]
x/s \*(char\*\*)($esp+8) --> displays argv[1] as a string

Once we reconstruct the main.c, we can see that this is a very obvious exploit.

strcpy, a known dangerous function wich buffer is always likely to be overflowed, is used just before a function is called with a pointer.

Since the pointer is on the stack, we just need to use the buffer and overflow it, changing the address in the pointer with the address of n(), a function that calls system("cat .pass") and we have our flag.
