#include <stdio.h>

int32_t v()
{
    char var_20c[0x208];
    fgets(&var_20c, 0x200, stdin);
    printf(&var_20c); //Use of Format String Vulnerability : inject string with % that can acces or read memory
    int32_t m_1 = m;
    
    if (m_1 != 0x40) //0x40 = 64
        return m_1;
    
    fwrite("Wait what?!\n", 1, 0xc, stdout);
    return system("/bin/sh");
}

int32_t main(int32_t argc, char** argv, char** envp)
{
    return v();
}
