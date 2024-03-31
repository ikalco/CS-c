#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef struct {
	unsigned long capacity;
	unsigned long length;
	int data[];
} DynamicArray;

DynamicArray *DynamicArray_create(int capacity);
bool DynamicArray_destroy(DynamicArray *array);
int DynamicArray_get(DynamicArray *array, int i);
void DynamicArray_set(DynamicArray *array, int i, int n);
DynamicArray *DynamicArray_pushback(DynamicArray *array, int n);
int DynamicArray_popback(DynamicArray *array);
DynamicArray *DynamicArray_resize(DynamicArray *array);
int DynamicArray_getSize(DynamicArray *array);
int DynamicArray_getCapacity(DynamicArray *array);

#endif
