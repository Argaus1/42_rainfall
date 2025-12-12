#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void o(void) {
	system("/bin/sh");
	exit(1);
}

void n(void) {
	char buf[0x208];
	fgets(buf, 0x200, stdin);
	printf(buf);
	exit(0x1);
}

int main(void) {
	n();
	return (0);
}
