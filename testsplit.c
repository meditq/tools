#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "split.h"

int main(void){
	char *str, **list;
	int n;
	printf("Interactive test program for split\nCopyright (c) 2020 medit\n\n");
	while(1){
		str = readline("split> ");
		list = split(str, &n);
		if(n > 0){
			if(!strcmp(list[0], "exit")) break;
			for(int i = 0; i < n; i++) printf("%2d: %s\n", i, list[i]);
		}
		free(list);
		free(str);
	}
	puts("bye");
	return 0;
}
