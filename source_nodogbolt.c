#include <stdio.h>

int m = 0;						// mov eax,ds:0x8049810

void p(char *buf) {
	// mov eax,DWORD PTR [ebp+0x8] <--- recupere en dessous du nv base pointer le buffer passe en parametre de p
	// mov DWORD PTR [esp],eax <--- place le buffer sur la frame actuelle pour printf
	printf(buf);
}

void n(void) {
	char buf[0x208];			// lea eax,[ebp-0x208]; mov DWORD PTR [esp], eax
	fgets(buf, 0x200, stdin);
	p(buf);

	int loc = m;				// mov eax,ds:0x8049810

	if (loc != 16930116)		// if loc != 0x1025544 OU cmp eax,0x1025544
		return ;
	
	system("/bin/cat /home/user/level5/.pass");	// mov DWORD PTR [esp],0x8048590; call 0x8048360 <system@plt>
}

int main(void) {
	n();
	return (0);
}
