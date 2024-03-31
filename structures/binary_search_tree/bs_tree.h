#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include "../dynamic_array/dynamic_array.h"
#include <stdbool.h>

typedef struct BSTN {
	struct BSTN *left;
	struct BSTN *right;
	int value;
} BSTN;

typedef struct {
	BSTN *root;
	unsigned long height;
	unsigned long nodes;
} BST;

BST *BST_create();
bool BST_destroy(BST *bst);
bool BST_insert(BST *bst, int val);
bool BST_remove(BST *bst, int key);
BSTN *BST_search(BST *bst, int key);
DynamicArray *BST_inorder(BST *bst);

#endif
