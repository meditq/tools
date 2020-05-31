#include "array.h"
#include <stdio.h>
#include <stdlib.h>

int expand(array a);
int shrink(array a);

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

int expand(array a){
	if(a->size >= a->heapsize){
		int *vstmp = realloc(a->vs, sizeof(int) * a->heapsize * 2);
		if(vstmp == NULL) return 1;
		a->vs = vstmp;
		a->heapsize *= 2;
	}
	return 0;
}

int shrink(array a){
	if(a->size <= a->heapsize / 2 && a->heapsize > 1){
		int *vstmp = realloc(a->vs, sizeof(int) * a->heapsize / 2);
		if(vstmp == NULL) return 1;
		a->vs = vstmp;
		a->heapsize /= 2;
	}
	return 0;
}
	
int push(array a, int val){
	if(!expand(a)) return 1;
	a->vs[a->size++] = val;
	return 0;
}

int pop(array a){
	int val = a->vs[--a->size];
	shrink(a);
	return a;
}

void array_free(array a){
	free(a->vs);
	free(a);
	return;
}
