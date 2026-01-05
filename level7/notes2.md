ON ESSAYE DE REMPLACER 

0x08048400 (address LIBC de puts) 
par 0x080484f4 (address de m dans la stack)

au niveau de 0x8049928 (address de l'address de puts dans la Global offset table)


//////FINDING THE OFFSET


Start Addr   End Addr       Size         Offset     objfile
0x804a000    0x806b000      0x21000      0x0        [heap]

