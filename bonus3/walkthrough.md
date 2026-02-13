The begining of this program is meant to confuse us. 

only this part is important for the exploit: 


```
    iVar2 = atoi(*(char **)(param_2 + 4));
    local_98[iVar2] = '\0';
    fread(local_56,1,0x41,local_14);
    fclose(local_14);
    iVar2 = strcmp(local_98,*(char **)(param_2 + 4));
    if (iVar2 == 0) {
        execl("/bin/sh","sh",0);
    }

```

The program will compare argv[1] with local_98 which is a string whose value at iVar2 as been set to \0.

Hence by providing an empty string at argv[1], the atoi return will be 0.
Making the local_98 an empty string aswell because the line local_98[0] = '\0' will be executed.

The comparison is then passed and we can access the shell to retrieve the flag

--- 

Hence the exploit here is : 

```
bonus3@RainFall:~$ ./bonus3 ""
$ cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c
$ su end
Password:
end@RainFall:~$ cat end
Congratulations graduate!
```