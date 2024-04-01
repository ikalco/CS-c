#include "linked_list.h"
#include <stdio.h>

int test1() {
	LinkedList *ll = LinkedList_create();

	LinkedList_insertHead(ll, 1);
	LinkedList_insertTail(ll, 2);
	LinkedList_insertHead(ll, 0);
	LinkedList_remove(ll, 1);

	DynamicArray *values = LinkedList_getValues(ll);
	int expected[] = {0, 2};

	for (int i = 0; i < DynamicArray_getSize(values); i++) {
		if (DynamicArray_get(values, i) == expected[i]) continue;
		return 1;
	}

	if (DynamicArray_destroy(values) == false) return 1;

	return LinkedList_destroy(ll) != true;
}

int test2() {
	LinkedList *ll = LinkedList_create();

	LinkedList_insertHead(ll, 1);
	LinkedList_insertHead(ll, 2);

	if (LinkedList_get(ll, 5) != -1) {
		return 1;
	}

	return LinkedList_destroy(ll) != true;
}

int main() {
	int failed = 0;

	failed += test1();
	failed += test2();

	if (failed > 0)
		printf("Failed %d tests.\n", failed);
	else
		printf("Passed all tests!\n");

	return 0;
}
