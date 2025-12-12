#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	n(void) {
	system("/bin/cat /home/user/level7/.pass");
}

void	m(void) {
	puts("Nope");
}

int main(int argc, char **argv) {
	(void)argc;
	char *buf0 = malloc(0x40);	// stored on the stack at esp+0x1c
	char *buf1 = malloc(0x4);

	*(uint32_t*)buf1 = 0x401180;
	strcpy(buf0, argv[1]);

	void (*f)() = *(void (**)())buf1;
	f();

	return (0);
}
