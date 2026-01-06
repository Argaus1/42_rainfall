#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv, char** envp) {
    char buf[128];
    char *auth = NULL;
    char *service = NULL;

    while (true) {
        printf("%p, %p\n", auth, service);

        if (!fgets(buf, sizeof(buf), stdin))
            break;

        if (strncmp(buf, "auth ", 5) == 0) {
            auth = malloc(4);
            if (auth)
                auth[0] = '\0';

            char *suffix = buf + 5;
            size_t len = strnlen(suffix, 32);

            if (len <= 30) {
                strcpy(auth, suffix);
            }
        }

        if (strncmp(buf, "service", 6) == 0) {
            service = strdup(buf+7);
        }

        if (strncmp(buf, "login", 5) == 0) {
            if (!auth || !auth[0x20]) {
                fwrite("Password:\n", 1, 10, stdout);
            } else {
                system("/bin/sh");
            }
        }
    }

    return 0;
}
