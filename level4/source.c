#include <stdio.h>
#include <stdlib.h>

void p(char *a0)
{
    printf(a0);
    return;
}

extern FILE_t *__bss_start;
extern unsigned int m;

void n(unsigned int a0)
{
    char v0[520];  // [bp-0x20c]

    fgets(&v0, 0x200, __bss_start);
    p(&v0);
    if (m != 16930116)
        return;
    system("/bin/cat /home/user/level5/.pass");
    return;
}

void main()
{
    char v0;  // [bp+0x0]

    n(&v0);
    return;
}