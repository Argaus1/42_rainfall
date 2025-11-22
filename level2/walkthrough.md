# LEVEL2

Quand on arrive dans une fonction, $esp = stack pointer. A cette address, on a l'addresse de retour de cette fonction, cad que quand on arrivera a ret, eip va etre charge avec la valeur a esp. A esp + 4: on a l'addresse du premier argument. Le deuxieme argument est a esp+8 etc.

Cette facon de passer les arguments vaut pour l'architecture 32-bits.

```
Breakpoint 2, 0x0017a060 in system () from /lib/i386-linux-gnu/libc.so.6
(gdb) x/xw $esp
0xbffff730:	0x0016dbe0
(gdb) x/xw $esp+4
0xbffff734:	0xbffff91b
(gdb) x 0xbffff91b
0xbffff91b:	0x6e69622f
(gdb) x/s 0xbffff91b
0xbffff91b:	 "/bin/bash"
```
Ici dans la fonction system, on voit que l'adresse de retour sera exit(), cela vient directement du fait qu'on a insere cette addresse dans le buffer de gets(). A esp+4, on a bien /bin/bash, donc ca devrait bien s'executer.

On peut ajouter une cmd dans l'env. Complique de trouver l'addresse.
