The goal here is to execute the last line of the v function.

This line call the system function with /bin/bash, which is exactly what we need to retrieve the password of level4. 

This is because level4 is the owner of the level3 program and we have the s permission flag.

In order to execute this last line, the global variable m need to be equal to 64 instead of 0.

To change its value, we need to exploit the format string vulnerability present in the v function.

    #include  <stdio.h> 
    void main(int argc, char **argv)
    {
        // This line is safe
        printf("%s\n", argv[1]);

        // This line is vulnerable
        printf(argv[1]);
    }

/////////////

PAS SUR

/////////////

Je crois qu'il faut faire en sorte de override eip pour revenir a une ligne en dessous du test pour activer le reste du program.
