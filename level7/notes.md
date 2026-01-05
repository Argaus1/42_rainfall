# LEVEL 7

What we want:
- use strcpy for the exploit
- replace the call to puts by a call to m()


dest 2e strcpy 0xbffff8f2

address b1 = esp+0x1c - 0x0804a008
addr b1+4 = 

addr b2 = 0x0804a018


addr b3= 0x0804a028
addr b3+4=

addr puts @0x8049928 (il faut modifier ca a cette addresse, le vrai puts = 0x08048406)

addresse de l'argument de puts = 0x8048703
