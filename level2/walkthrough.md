# LEVEL2

The main calls a p() function.

This level also is a gets exploitation, which means we will try to overflow the buffer to chage the return value of our p function.

Finding the offset is made little by little, with gdb, adding more and more 'a' until segfault.

The difference is that there is an if condition that prevents us from replacing the return of the p function with shell code on the stack.
What it does is that if the addr starts with b, it prints the addr and kill the process by calling exit, which quits the program without loading EIP.

But if EIP is not loaded with an address starting with b, we dont go into the if condition. Puts is called on our buffer, and strdup too. That's the key :
- strdup copies our buff on the heap and returns its address, that starts with '8'
- we can write shellcode in our buffer (see lev9 walkthrough to know how to write shellcode)
- the shellcode will do "execve('/bin/sh')"
- instead of overwriting the ret address to load EIP with the start of our buffer/shellcode (0xbff..) we will overwrite it with the address returned by strdup (0x8..)
- to get the addr returned by strdup, set a bp after the call in gdb, once you're there, type "x $eax", this register is loaded with the return value of strdup

