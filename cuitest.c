#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "../split.h"

int main(void){
	char *str, **list;
	int n;
	printf("Test for CUI\nCopyright (c) 2020 medit, MIT License\n\n");
	while(1){
		str = readline("Test> ");
		list = split(str, &n);
		if(n > 0 && !strcmp(list[0], "exit")) break;
		for(int i = 0; i < n; i++) printf("%2d: %s\n", i, list[i]);
		free(list);
		free(str);
	}
	puts("Bye");
	return 0;
}
