#include "dynamic_array.h"

#include <stdlib.h>

DynamicArray *DynamicArray_create(int capacity) {
	DynamicArray *array = malloc(sizeof(*array) + sizeof(int[capacity]));
	array->capacity = capacity;
	array->length = 0;

	return array;
}

bool DynamicArray_destroy(DynamicArray *array) {
	free(array);
	return true;
}

int DynamicArray_get(DynamicArray *array, int i) { return array->data[i]; }

void DynamicArray_set(DynamicArray *array, int i, int n) { array->data[i] = n; }

DynamicArray *DynamicArray_pushback(DynamicArray *array, int n) {
	if (array->length + 1 > array->capacity) {
		array = DynamicArray_resize(array);
	}

	array->data[array->length] = n;
	array->length++;

	return array;
}

int DynamicArray_popback(DynamicArray *array) {
	return array->data[--array->length];
}

DynamicArray *DynamicArray_resize(DynamicArray *array) {
	DynamicArray *_array = realloc(
		array, sizeof(DynamicArray) + sizeof(int[array->capacity * 2]) + 1
	);
	_array->capacity *= 2;

	return _array;
}

int DynamicArray_getSize(DynamicArray *array) { return array->length; }

int DynamicArray_getCapacity(DynamicArray *array) { return array->capacity; }
