# LEVEL 5

When connecting to level5, one can see the protections applied to this level5's binary. Level5 bin's stack isnt protected. Addresses are not randomized, everything is well set for the exploit. No RELRO = GOT table can be rewritten, this is an executable stack. And the binary isnt PIE (position independant), which mean we can hardcode every GOT/instruction address into our exploit

Looking at objdump -d, we guess that we want to use format string exploit to call o. The good thing is that exit is called at the end of n, which means that we could manipulate the **global offset table** and make the call to exit be a call to o.

This is what's done here :
[Format String Exploit and overwrite the Global Offset Table](https://www.youtube.com/watch?v=t1LH9D5cuK4)

The address of o is : 080484a4
The address of exit is : in the GOT 0x8049838 (disas 0x80483d0)

We can reuse the script fr; level4 to do this exploit. Instead of writing a nb to a global variable, we'll just write the address of o where the address of exit should be, in the GOT.

Easy!!!!!!!!
