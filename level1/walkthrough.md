Decompiling the level1 program, we notice a vulnerable usage of the gets function. 
This function reads from the standard input and does not perform bound checks. 
Hence it is vulnerable for buffer overflow.

Looking at the decompiled code, we can see that the buffer used is of 64 bits.

Our goal here is to override the eip of the gets function, (EIP being the address to return to after the function execution)
in order to return to the "run" function, which executes system("/bin/sh").

So we approximate the PAD starting at 64 and check when the function seg faults. 
We then capture the address of the run function first instruction and add it in the correct format after the pad.
(cf exploit.py)