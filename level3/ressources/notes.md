pour gdb : set disable-randomization on

stack pointer esp printf entry = 0xbffff50c

quand on est dans printf : commande pour trouver l'address de notre buffer = x *(unsigned int *)($esp + 4) (p a la place de x pour afficher l'adresse en decimal)

pour printf, la liste des arguments de formattage = esp + 8, esp + 12 etc

esp return address = 134513882/0x080484da
esp + 4 buf_addr = 3221222688/0xbffff520
esp + 8 first_format = 512/0x200
esp + 12 sec_format = 3017408/0x002e0ac0

addresse de l'instruction fwrite = 0x08048507
