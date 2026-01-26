#include <stdio.h>

int main(void) {
	char buff[0x40];
	gets(buff);
	puts(buff);
	return (0);
}
