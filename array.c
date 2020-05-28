#include <stdio.h>
#include <stdlib.h>

array array_new(void){
	array a = malloc(sizeof(struct _array));
	if(a == NULL) return NULL;
	a->vs = malloc(sizeof(int));
	if(a->vs == NULL){
		free(a);
		return NULL;
	}
	a->size = 0;
	a->heapsize = 1;
	return a;
}

void array_free(array a){
	free(a->vs);
	free(a);
	return;
}
