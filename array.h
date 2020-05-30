struct _array {
	int size, heapsize;
	int *vs;
} * array;

array array_new(void);
int push(array a, int val);
int pop(array a);
void array_free(array a);
