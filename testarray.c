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
	printf("Interactive test program for array\nCopyright (c) 2020 medit\n\n");
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
		if(n >= 1){
			if(!strcmp(list[0], "exit")) break;
			else if(!strcmp(list[0], "push")){
				if(n >= 2){
					char *p;
					long val = strtol(list[1], &p, 10);
					if(p != list[1] && val >= INT_MIN && val <= INT_MAX){
						if(push(a, val)){
							puts("push failed");
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
					puts("push failed");
				}
				array_print(a);
			}else if(!strcmp(list[0], "pop") || !strcmp(list[0], "o")){
				if(a->size > 0){
					printf("%d\n", pop(a));
					array_print(a);
				}else{
					puts("empty");
				}
			}else if(!strcmp(list[0], "add")){
				if(n >= 2){
					char *p;
					long val = strtol(list[1], &p, 10);
					if(p != list[1] && val > 0 && val <= INT_MAX){
						for(int i = 1; i <= val; i++){
							if(push(a, rand() % 10000)){
								printf("push #%d failed\n", i);
								break;
							}
						}
						array_print(a);
					}else{
						puts("invalid argument");
					}
				}else{
					puts("insufficient argument");
				}
			}else if(!strcmp(list[0], "print")){
				array_print(a);
			}else if(!strcmp(list[0], "size")){
				printf("Size: %d, Heap size: %d\n", a->size, a->heapsize);
			}else if(!strcmp(list[0], "help")){
				if(n >= 2) puts("Individual help for each command is not implemented.");
				printf("Available commands are:\nexit, push, pop, i, o, add, print, size, help\n");
			}else{
				puts("unknown command");
			}
		}
		free(list);
		free(str);
	}
	puts("bye");
	return 0;
}
