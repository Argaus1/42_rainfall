This program takes two arguments, looking at the decompiled code, we can notice : 

A vulnerable memcpy whose source reads directly from argv[2].

A line with execl("/bin/sh", "sh", 0). The goal of this exercice is to execute this line. 

But there are two test that must pass in order to get to this line. 

The first argument (a) must be a number under 9. Then its value is tested again after the memcopy and its value must equal 0x574f4c46. 

There are no possible value that would meet both requirements, so we need to use the memcpy overflow vulnerability to change the value of the first arg after the first test.

From the assembly code we can see the offset of the variable storing the first arg -> 0x3c(%esp) -> 60 bytes

We can also see the offset of the destination buffer of memcpy -> 0x14(%esp) -> 20

So the padding required to reach the first arg variable is 60 - 20 = 40.

---

Unfortunatly the number of bytes copied into the dest is based on the number given in the first arg (nb * 4). 

So we can't write more than 36 (9 * 4) bytes on the dest. 

But since this number is cast into a size_t, we can use a negative number that will be changed into a big positive number when casted as a size_t. 

The goal for this number is : 

x * 4 = 44

( 44 - 2^(32) ) / 4 = -1073741813

This is our first arg. 

The second arg is a padding of 40 and the little endian version of the required value 0x574f4c46.


This creates the following call : 

./bonus1 -2147483637 $(python -c 'print "A" * 40 + "\x46\x4c\x4f\x57"')
