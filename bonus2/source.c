extern unsigned int language;

void greetuser(void)
{
    char v0[4];  // [bp-0x4c], Other Possible Types: unsigned int
    unsigned int v1;  // [bp-0x48]
    unsigned int v2;  // [bp-0x44]
    unsigned int v3;  // [bp-0x40]
    unsigned short v4;  // [bp-0x3c]
    char flag;  // [bp-0x3a]
    char v6;  // [bp+0x4]

    if (language == 1)
    {
        v0 = 3279321416;
        v1 = 547668900;
        v2 = 1772405616;
        v3 = 3282355062;
        v4 = 8356;
        flag = 0;
    }
    else if (language == 2)
    {
        strncpy(&v0, "Goedemiddag! ", 13);
    }
    else if (!language)
    {
        strncpy(&v0, "Hello ", 6);
    }
    strcat(&v0, &v6);
    puts(&v0);
    return;
}

extern unsigned int language;

int main(unsigned int a0, char **a1)
{
    unsigned int *cur;  // edi
    unsigned int v5;  // ecx
    char iter[4];  // edi
    char j[4];  // esi
    unsigned int v8;  // ecx
    void* v0;  // [bp-0xb0]
    char v1[40];  // [bp-0x60]
    char v2[36];  // [bp-0x38]
    void* v3;  // [bp-0x14]

    if (a0 != 3)
        return 1;
    cur = &v1;
    for (v5 = 19; v5; cur += 1)
    {
        v5 -= 1;
        *(cur) = 0;
    }
    strncpy(&v1, a1[1], 40);
    strncpy(&v2, a1[2], 32);
    v0 = "LANG";
    v3 = getenv("LANG");
    if (v3)
    {
        if (!memcmp(v3, "fi", 2))
        {
            language = 1;
            v0 = v3;
        }
        else
        {
            v0 = v3;
            if (!memcmp(v0, "nl", 2))
            {
                language = 2;
                v0 = v3;
            }
        }
    }
    iter = &v0;
    j = &v1;
    for (v8 = 19; v8; j += 1)
    {
        v8 -= 1;
        *(iter) = *(j);
        iter += 1;
    }
    return (unsigned int)greetuser();
}