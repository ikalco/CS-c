#include "bs_tree.h"
#include <stdio.h>
#include <stdlib.h>

BSTN *create_node(int val) {
	BSTN *new_node = malloc(sizeof(*new_node));
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->value = val;
	return new_node;
}

BST *BST_create() {
	BST *root = malloc(sizeof(*root));
	root->root = NULL;
	root->height = 0;
	return root;
}

void inorder_destroy(BSTN *root, BSTN **arr, int *index) {
	if (root == NULL) return;

	inorder_destroy(root->left, arr, index);

	arr[*index] = root;
	(*index)++;

	inorder_destroy(root->right, arr, index);
}

bool BST_destroy(BST *bst) {
	BSTN **arr = malloc(sizeof(BSTN *) * bst->nodes);

	int index = 0;
	inorder_destroy(bst->root, arr, &index);

	if (index != bst->nodes) return false;

	for (index -= 1; index >= 0; index--) {
		if (arr[index] == NULL) continue;
		free(arr[index]);
	}

	free(arr);

	free(bst);

	return true;
}

bool BST_insert(BST *bst, int val) {
	if (bst->root == NULL) {
		bst->root = create_node(val);
		bst->height = 1;
		bst->nodes = 1;
		return true;
	}

	BSTN *parent = NULL;
	BSTN *root = bst->root;
	unsigned long height = 1;

	while (root != NULL) {
		if (root->value > val) {
			parent = root;
			root = root->left;
			height++;
		} else if (root->value < val) {
			parent = root;
			root = root->right;
			height++;
		} else {
			return false;
		}
	}

	if (parent->value > val) {
		parent->left = create_node(val);
	} else if (parent->value < val) {
		parent->right = create_node(val);
	}

	if (height > bst->height) bst->height = height;
	bst->nodes++;

	return true;
}

BSTN *BST_search(BST *bst, int key) {
	BSTN *root = bst->root;

	while (root != NULL) {
		if (root->value > key) {
			root = root->left;
		} else if (root->value < key) {
			root = root->right;
		} else {
			return root;
		}
	}

	return NULL;
}

bool BST_remove(BST *bst, int key) {
	BSTN *parent = NULL;
	BSTN *root = bst->root;

	while (root != NULL && root->value != key) {
		if (root->value > key) {
			parent = root;
			root = root->left;
		} else if (root->value < key) {
			parent = root;
			root = root->right;
		}
	}

	// we didn't find the node
	if (root == NULL) return false;

	if (root->right == NULL && root->left == NULL) {
		// the node has no children
		if (parent->value > key)
			parent->left = NULL;
		else
			parent->right = NULL;
	} else if (root->left == NULL) {
		// the node has 1 child
		if (parent->value > key)
			parent->left = root->right;
		else {
			parent->right = root->right;
		}
	} else if (root->right == NULL) {
		// the node has 1 child
		if (parent->value > key)
			parent->left = root->left;
		else
			parent->right = root->left;
	} else {
		// the node has 2 children
		BSTN *new_root = root->right;

		while (new_root->left != NULL) {
			new_root = new_root->left;
		}

		int value = new_root->value;
		BST_remove(bst, new_root->value);

		root->value = value;
		bst->nodes--;
		return true;
	}

	free(root);
	bst->nodes--;
	return true;
}

void inorder(BSTN *root, DynamicArray *arr) {
	if (root == NULL) return;

	inorder(root->left, arr);

	DynamicArray_pushback(arr, root->value);

	inorder(root->right, arr);
}

DynamicArray *BST_inorder(BST *bst) {
	DynamicArray *arr = DynamicArray_create(bst->nodes);

	inorder(bst->root, arr);

	return arr;
}
