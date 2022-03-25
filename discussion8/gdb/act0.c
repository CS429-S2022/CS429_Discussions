#include <stdlib.h>
#include <stdio.h>

int findSquare(int a) {
	return a * a;
}

int main(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		int a = atoi(argv[i]);
		printf("%d\n", findSquare(a));
	}
	return 0;
}
