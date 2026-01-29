#include <unistd.h>
#include <string.h>

class N{
public:
	N(int) {}
	
	void	setAnnotation(char *argv) {
		size_t	n;

		n = strlen(argv);
		memcpy(this+4, argv, n);
	}
};

int main(int argc, char **argv) {
	if (argc <= 1)
		_exit(1);

	N* a = new N(5); 	 
	N* b = new N(6);

	a->setAnnotation(argv[1]);
	*a + *b; // b->add(a);
	return (0);
}
