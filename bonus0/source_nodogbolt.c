#include <stdio.h>

char tiret[] = " - ";

void p(char *v, char *tiret) {
	puts(tiret);

	read(0, v, 0x1000);
}

void pp(char *ptr) {
	char *v1;
	char *v2;

	p(v1, tiret);
	p(v2, tiret);
	

}

int main(void) {
	char buf[0x40-0x16];
	pp(buf);
	puts(buf);
	return (0);
}
