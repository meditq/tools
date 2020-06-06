#ifndef ARRAY_H
#define ARRAY_H
typedef struct _array {
	int size, heapsize;
	int *vs;
} * array;

array array_new(void);
int push(array a, int val);
int pop(array a);
array array_dup(const array a);
void array_print(const array a);
void array_sort_bubble(array a);
void array_free(array a);
#endif
