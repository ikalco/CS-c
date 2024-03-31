#include "bs_tree.h"
#include <stdio.h>

#define ASSERT(a, b)                                                           \
	if (a != b) {                                                              \
		perror("Failed\n");                                                    \
		return 1;                                                              \
	}

#define NASSERT(a, b)                                                          \
	if (a == b) {                                                              \
		perror("Failed Assert\n");                                             \
		return 1;                                                              \
	}

#define EQUALS(bst, expected) ASSERT(equals(bst, expected), 0);

int equals(BST *bst, int *expected) {
	DynamicArray *inorder = BST_inorder(bst);

	NASSERT(inorder, NULL);

	for (int i = 0; i < bst->nodes; i++) {
		ASSERT(DynamicArray_get(inorder, i), expected[i]);
	}

	ASSERT(DynamicArray_destroy(inorder), true);

	return 0;
}

int test_insert() {
	BST *bst = BST_create();

	ASSERT(BST_insert(bst, 22), true);
	ASSERT(BST_insert(bst, 12), true);
	ASSERT(BST_insert(bst, 8), true);
	ASSERT(BST_insert(bst, 20), true);
	ASSERT(BST_insert(bst, 30), true);
	ASSERT(BST_insert(bst, 25), true);
	ASSERT(BST_insert(bst, 40), true);

	EQUALS(bst, ((int[]){8, 12, 20, 22, 25, 30, 40}));

	ASSERT(BST_destroy(bst), true);

	return 0;
}

int test_search() {
	BST *bst = BST_create();

	ASSERT(BST_insert(bst, 22), true);
	ASSERT(BST_insert(bst, 12), true);
	ASSERT(BST_insert(bst, 8), true);
	ASSERT(BST_insert(bst, 20), true);
	ASSERT(BST_insert(bst, 30), true);
	ASSERT(BST_insert(bst, 25), true);
	ASSERT(BST_insert(bst, 40), true);

	NASSERT(BST_search(bst, 22), NULL);
	NASSERT(BST_search(bst, 12), NULL);
	NASSERT(BST_search(bst, 8), NULL);
	NASSERT(BST_search(bst, 20), NULL);
	NASSERT(BST_search(bst, 30), NULL);
	NASSERT(BST_search(bst, 25), NULL);
	NASSERT(BST_search(bst, 40), NULL);

	ASSERT(BST_search(bst, 200), NULL);
	ASSERT(BST_search(bst, 41), NULL);

	ASSERT(BST_destroy(bst), true);

	return 0;
}

int test_remove0() {
	BST *bst = BST_create();

	ASSERT(BST_insert(bst, 50), true);
	ASSERT(BST_insert(bst, 30), true);
	ASSERT(BST_insert(bst, 20), true);
	ASSERT(BST_insert(bst, 40), true);
	ASSERT(BST_insert(bst, 70), true);
	ASSERT(BST_insert(bst, 60), true);
	ASSERT(BST_insert(bst, 80), true);

	EQUALS(bst, ((int[]){20, 30, 40, 50, 60, 70, 80}));

	ASSERT(BST_remove(bst, 20), true);

	EQUALS(bst, ((int[]){30, 40, 50, 60, 70, 80}));

	ASSERT(BST_destroy(bst), true);

	return 0;
}

int test_remove1() {
	BST *bst = BST_create();

	ASSERT(BST_insert(bst, 50), true);
	ASSERT(BST_insert(bst, 30), true);
	ASSERT(BST_insert(bst, 20), true);
	ASSERT(BST_insert(bst, 40), true);
	ASSERT(BST_insert(bst, 70), true);
	ASSERT(BST_insert(bst, 80), true);

	EQUALS(bst, ((int[]){20, 30, 40, 50, 70, 80}));

	ASSERT(BST_remove(bst, 70), true);

	EQUALS(bst, ((int[]){20, 30, 40, 50, 80}));

	ASSERT(BST_destroy(bst), true);

	return 0;
}

int test_remove2() {}

int run_tests() {
	int failed = 0;

	// failed += test_insert();
	// failed += test_search();
	failed += test_remove0();
	failed += test_remove1();
	// failed += test_remove2();

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
