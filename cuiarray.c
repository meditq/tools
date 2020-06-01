#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <limits.h>
#include <unistd.h>
#include <readline/readline.h>
#include "split.h"
#include "array.h"

int main(int argc, char **argv){
	printf("Test program for array\nCopyright (c) 2020 medit, MIT License\n\n");
	array a = array_new();
	if(a == NULL){
		fprintf(stderr, "error: array_new() failed\n");
		return 1;
	}
	char *str, **list;
	int n;
	srand(time(NULL));
	while(1){
		str = readline("array> ");
		list = split(str, &n);
		if(n > 0){
			if(!strcmp(list[0], "exit")) break;
			else if(!strcmp(list[0], "push")){
				if(n > 1){
					char *p;
					long val = strtol(list[1], &p, 10);
					if(p != list[1] && val >= INT_MIN && val <= INT_MAX){
						if(push(a, val)){
							fprintf(stderr, "error: push failed\n");
							return 1;
						}
						array_print(a);
					}else{
						puts("invalid argument");
					}
				}else{
					puts("insufficient argument");
				}
			}else if(!strcmp(list[0], "i")){
				if(push(a, rand() % 10000)){
					fprintf(stderr, "error: push failed\n");
					return 1;
				}
				array_print(a);
			}else if(!strcmp(list[0], "pop") || !strcmp(list[0], "o")){
				if(a->size > 0){
					printf("%d\n", pop(a));
					array_print(a);
				}else{
					puts("pop failed");
				}
			}else if(!strcmp(list[0], "print")){
				array_print(a);
				printf("Size: %d, Heap size: %d\n", a->size, a->heapsize);
			}else{
				puts("unknown command");
			}
		}
		free(list);
		free(str);
	}
	puts("Bye");
	return 0;
}
