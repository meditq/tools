/*
    Copyright (c) 2020 medit
    Distributed under the MIT License. See ./LICENSE.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int size;
	if(argc < 2 || (size = strtol(argv[1], NULL, 10)) <= 0){
		fprintf(stderr, "error: invalid argument\n");
		return 1;
	}
	int w, t = size * size;
	for(w = 1; (t /= 10) != 0; w++);
	int i, j;
	for(i = 1; i <= size; i++){
		for(j = 1; j <= size; j++) printf(" %*d", w, i * j);
		printf("\n");
	}
	return 0;
}
