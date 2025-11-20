#include <stdio.h>
#include <stdlib.h>

// run
void run(void) {
	char bin[] = "/bin/sh";
	char luck[] = "goodluck!\n";
	fwrite(luck,1,10,stdout);
	system(bin);
}

int main(void) {
	char buf[64];
	gets(buf);
	return 0;
}
