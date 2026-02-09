void p(char *a0, char *a1)
{
    char v0;  // [bp-0x100c]

    puts(a1);
    read(0, &v0, 0x1000);
    *(strchr(&v0, 10)) = 0;
    strncpy(a0, &v0, 20);
    return;
}

void int operator++(char *ptr)
{
    char *v3;  // edi
    unsigned int result;  // [bp-0x40]
    char v1[20];  // [bp-0x34]
    char v2[20];  // [bp-0x20]

    p(&v1, " - ");
    p(&v2, " - ");
    strcpy(ptr, &v1);
    result = 4294967295;
    v3 = ptr;
    ptr[1] = ' ';
    ptr[2] = '\0';
    strcat(ptr, &v2);
    return;
}

unsigned int main(void)
{
    char v0[42];  // [bp-0x2e]

    int operator++(&v0);
    puts(&v0);
    return 0;
}


////

// v1 = 0xbffff6b8
// v2 = 0xbffff6cb
// v0 = 0xbffff706

