#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>

char c[0x44];

void m(void) {
	time_t	t;
	t = time(0x0);

	printf("%s - %d\n",c,(int)t);
}

int main(int argc, char **argv) {
	(void)argc;
	uint32_t *b1 = malloc(8);
	uint32_t *b2 = malloc(8);
	uint32_t *b3 = malloc(8);
	uint32_t *b4 = malloc(8);
	
	*b1 = 0x1;
	*(b1+4)=(uint32_t)b2;
	*b3 = 0x2;
	*(b3+4)=(uint32_t)b4;

	strcpy((char*)b1+4, argv[1]);
	strcpy((char*)b3+4, argv[2]);

	FILE* f = fopen("/home/user/level8/.pass", "r");

	fgets(c, 0x44, f);

	puts("~~");
	return (0);
}
