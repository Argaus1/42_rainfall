# LEVEL 3

The v function initiates a locale with a globale, if the locale != 64, the program exits, but if it equal to 64, the program executes a shell with level4 user.

This program uses fgets and printf. Printf is called with only one argument, and no format specifier. The argument is the buffer filled with user input, gotten with fgets. This is a case of format string binary exploit : we will use printf to write to the stack.

When printf has no format specifier provided, if we write %x, printf will read the stack. If we write "AAAA%x %x %x %x %x etc", we see the stack displayed, and one of the arguments is "41414141", it means that it is our input (ascii hex value for A) stored here on the stack. A format specifier (%n) allows us to write to an address using printf. Normally it would write to an address specified in the arguments the number of character written, but since we did not provide any, it will seek for an address to write to in the stack.

We know that the fourth arg on the stack is the buffer we wrote, so if we wrtie an address instead of "AAAA", and ask printf to wrtie the nb of char (this nb would be 64) at the address located at the fourth arg, we can write the address of the global m to make it 64 ! 


(python -c 'print "\x8c\x98\x04\x08"+ "x"\*60 + "%4$n"' && cat) | ./level3
