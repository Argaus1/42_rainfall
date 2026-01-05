#include <stdio.h>

char	a[] = "%p, %p \n";
char	b[] = "auth ";
char	c[] = "reset";

void	*x;
void	*y;

char	buf[0x80];

char	*auth;

int main() {
	while (1) {
		printf(a,x,y); 
		if (fgets(buf,0x80,stdin)==NULL)
			return (0);

		if (strncmp(buf, b, 5) == 0) {
    		auth = malloc(4);
			*auth = 0;
		}

		if (strlen(&buf[5]) <= 30)
			strcpy(auth, buf);			// exploit

		// main+222
		if (strncmp(buf, c, 5) == 0)
	}
	return (0);	
}
