#include "split.h"
#include <stdlib.h>
#include <string.h>

char **split(char *str, int *n){
	char **list = NULL, **tmp, *t;
	int i = 0;
	while(1){
		if(str == NULL) break;
		while(*str == ' ') str++;
		if(*str == '\0') break;
		t = strchr(str, ' ');
		if(t != NULL) *t = '\0';
		tmp = (char **)realloc(list, sizeof(char *) * (i + 1));
		if(tmp == NULL) break;
		list = tmp;
		list[i++] = str;
		str = t != NULL ? t + 1 : t;
	}
	*n = i;
	return list;
}
