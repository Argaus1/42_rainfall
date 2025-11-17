# LEVEL0

We have a level0 file, with setuid bit: anything launched by the programm will have level0's owner rights (given than level0 user is part of the "user" group, like level1) = level1.

Using GDB, we disassemble the main, and we can see all functions called. The first one is atoi on argv[1], which explains the segfault if no argument is given.
If atoi's result is different than 423, fwrite is used to print "no !\n" to stderr.

If atoi == 423, an array is created, with "/bin/sh" and a NULL pointer.

Then getegid and geteuid are used to get the process's effective group and user ids. Because of level0's specific rights, those functions will return level1 ids. Setresgid and setresuid are used to change the id for the process to be called, and /bin/sh is launched with execv.

Finally, we are in a new shell, connected as level1. We just have to cat /home/user/level1/.pass.

## source.c

Use scp to put this file in /tmp/. **Be careful**: ``cc source.c && chmod 4755 a.out`` to set the executable's rights accordingly.
