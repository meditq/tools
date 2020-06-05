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
	if(expand(a)) return 1;
	a->vs[a->size++] = val;
	return 0;
}

int pop(array a){
	int val = a->vs[--a->size];
	shrink(a);
	return val;
}

array array_dup(const array a){
	array b = array_new();
	if(b == NULL) return NULL;
	b->vs = realloc(b->vs, sizeof(int) * a->heapsize);
	if(b->vs == NULL){
		array_free(b);
		return NULL;
	}
	b->heapsize = a->heapsize;
	for(int i = 0; i < a->size; i++) b->vs[i] = a->vs[i];
	b->size = a->size;
	return b;
}

void array_print(const array a){
	printf("[");
	if(a->size > 0){
		printf("%d", a->vs[0]);
		for(int i = 1; i < a->size; i++) printf(", %d", a->vs[i]);
	}
	printf("]\n");
	return;
}

void array_free(array a){
	free(a->vs);
	free(a);
	return;
}
