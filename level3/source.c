#include <stdio.h>
#include <stdlib.h>

int m = 0;

int v()
{
    char buf[0x208];
    fgets(buf, 0x200, stdin);
    printf(buf); //Use of Format String Vulnerability : inject string with % that can acces or read memory
    //int m_1 = m;
    
    if (m != 0x40) //0x40 = 64
        return m;
    
    fwrite("Wait what?!\n", 1, 0xc, stdout);
    return system("/bin/sh");
}

int main(int argc, char** argv, char** envp)
{
    return v();
}
