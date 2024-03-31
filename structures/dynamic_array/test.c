#include "dynamic_array.h"
#include <stdio.h>

#define ASSERT(a, b)                                                           \
	if (a != b) {                                                              \
		perror("Failed Assert\n");                                             \
		return 1;                                                              \
	}

#define NASSERT(a, b)                                                          \
	if (a == b) {                                                              \
		perror("Failed Assert\n");                                             \
		return 1;                                                              \
	}

int test1() {
	DynamicArray *array = DynamicArray_create(1);

	NASSERT(array, NULL);
	ASSERT(DynamicArray_getSize(array), 0);
	ASSERT(DynamicArray_getCapacity(array), 1);

	ASSERT(DynamicArray_destroy(array), true);

	return 0;
}

int test2() {
	DynamicArray *array = DynamicArray_create(1);

	NASSERT(array, NULL);

	array = DynamicArray_pushback(array, 1);

	ASSERT(DynamicArray_getCapacity(array), 1);

	array = DynamicArray_pushback(array, 2);

	ASSERT(DynamicArray_getCapacity(array), 2);

	ASSERT(DynamicArray_destroy(array), true);

	return 0;
}

int test3() {
	DynamicArray *array = DynamicArray_create(1);

	NASSERT(array, NULL);

	ASSERT(DynamicArray_getSize(array), 0);
	ASSERT(DynamicArray_getCapacity(array), 1);

	array = DynamicArray_pushback(array, 1);

	ASSERT(DynamicArray_getSize(array), 1);
	ASSERT(DynamicArray_getCapacity(array), 1);

	array = DynamicArray_pushback(array, 2);

	ASSERT(DynamicArray_getSize(array), 2);
	ASSERT(DynamicArray_getCapacity(array), 2);
	ASSERT(DynamicArray_get(array, 1), 2);

	DynamicArray_set(array, 1, 3);

	ASSERT(DynamicArray_get(array, 1), 3);
	ASSERT(DynamicArray_popback(array), 3);

	ASSERT(DynamicArray_getSize(array), 1);
	ASSERT(DynamicArray_getCapacity(array), 2);

	ASSERT(DynamicArray_destroy(array), true);

	return 0;
}

int run_tests() {
	int failed = 0;

	failed += test1();
	failed += test2();
	failed += test3();

	return failed;
}

int main() {
	int num_failed = run_tests();

	if (num_failed == 0) {
		printf("Succesfully ran all tests!\n");
	} else {
		printf("Failed %d tests.\n", num_failed);
	}

	return 0;
}
