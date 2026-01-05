int main(int argc, char** argv, char** envp) {
    char buf[128];
    char *auth = NULL;
    char *service = NULL;

    while (true) {
        printf("%p, %p\n", auth, service);

        if (!fgets(buf, sizeof(buf), stdin))
            break;

        // Check if input starts with "auth "
        if (strncmp(buf, "auth ", 5) == 0) {
            auth = malloc(4);
            if (auth)
                auth[0] = '\0';

            char *suffix = buf + 5;
            size_t len = strnlen(suffix, 32);  // max length 31

            if (len <= 30) {
                strcpy(auth, suffix);  // copy suffix into malloc'ed auth
            }
        }

        // Check if input starts with "reset"
        if (strncmp(buf, "reset", 5) == 0) {
            free(auth);
            auth = NULL;
        }

        // Check if input starts with "service"
        if (strncmp(buf, "service", 6) == 0) {
            char tmp[128];
            service = strdup(tmp);  // duplicate some local data
        }

        // Check if input starts with "login"
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
