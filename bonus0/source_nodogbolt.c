#include <stdio.h>
#include <string.h>
#include <unistd.h>

char tiret[] = " - ";


// 1ere occurence	:	v(v1) = 0xbffff6b8
// 2nde occurence	:	v(v2) = 0xbffff6cb
void p(char *v, char *tiret) {
	char buf[0x1000];				// buf = 0xbfffe680
	puts(tiret);
	read(0, buf, 0x1000);
	
	// mettre un \0 a la place du \n dans buf
	char *back_0 = strchr(buf, '\n');
	*back_0 = 0;
	strncpy(v,buf, 20);
	return ;
}

// bp = 0xbffff6e8
// bp + 4 = 0xbffff6ec(eip -> 0x080485b9)
void pp(char *v0) {
	char v1[20];
	char v2[20];

	p(v1, tiret);
	p(v2, tiret);
	strcpy(v0, v1);
	v0[strlen(v1)] = ' ';
	v0[strlen(v1)+1] = '\0';
	strcat(v0, v2);
	return ;
}

// bp = 0xbffff738
int main(void) {
	char v0[0x2A];		// v0 = 0xbffff706
	pp(v0);
	puts(v0);
	return (0);
}
