#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int n;
	if(argc < 2 || (n = strtol(argv[1], NULL, 10)) <= 0){
		fprintf(stderr, "error: invalid argument\n");
		return 1;
	}
	int w, t = n;
	for(w = 1; (t /= 10) != 0; w++);
	for(int i = 1; i <= n; i++) printf("%*d\n", w, i);
	return 0;
}
