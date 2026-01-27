# LEVEL 4

The principle is exactly the same as the previous level. The difference is that the comparison is against a much higher number, way over the limit of our buffer, 0x200.

[Source](https://blog.1nf1n1ty.team/hacktricks/binary-exploitation/format-strings)

objdump -D ./level4 gives the address of m : 0x8049810

We need to find where in the stack is our buffer located. We do as in lvl3, we enter AAAAAAAA %x ... enough %x until printf reads the stack deep enough to get to the address of the fgets buffer. This is 12.

To overwrite the input of gets, we need to access the 12th argument in printf.

The issue we have now is that this time, m is compared against a much higher nb : 16930116. As said before, this exceeds the depth of our buffer.
To get through this difficulty, we will use the %n specifier as in level3, but with the short int specifier (h): Since the nb is very long to print at the address, we'll also write the lower bytes and the higher bytes separately. We then have to write two addresses in our buffer.

The nb we want to write at the addr of m in hex is 0x1025544 in our python script we isolate the lower and higher bytes -> we get two short ints : 5544 for the low bytes, that we'll write at 0x8049810 (little endianness), and 0102 written at 0x8049812.

Our input we'll be :
1. **addresses.** 0x8049810 and 0x8049812
2. Nb of characters to write to the first addresses. 0x5544-8. 8 is the length of our two addresses. `%.0x5544-8x`. x is to specify to write random hex values.
3. Nb of characters to write to the scnd addr.
4. Offset/arg nb. We start by the 12th, where we'll write the low bytes, at the 12th arg in the stack (printf vulnerability). The 12th arg is 0x8049810.
5. Specifiers `$hn` -> write 0x5544 characters (since it is the nb of char we wrote so far) at the address in the 12th arg. The nb is a short int.
6. To get nb 0x0102 to be written at 0x8049812, we do sthg similar.

`[0x8049810][0x8049812]%.[0x5544-8]x%[12]$hn%.[HOB-LOB]x%[13]`
