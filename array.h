struct _array {
	int size, heapsize;
	int *vs;
} * array;

array array_new(void);
void array_free(array a);
