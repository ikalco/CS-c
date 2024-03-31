#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../dynamic_array/dynamic_array.h"
#include <stdbool.h>

typedef struct LinkedListNode {
	struct LinkedListNode *next;
	int value;
} LinkedListNode;

typedef struct {
	LinkedListNode *head;
	unsigned long size;
} LinkedList;

LinkedList *LinkedList_create();
bool LinkedList_destroy(LinkedList *ll);
int LinkedList_get(LinkedList *ll, int i);
void LinkedList_insertHead(LinkedList *ll, int val);
void LinkedList_insertTail(LinkedList *ll, int val);
bool LinkedList_remove(LinkedList *ll, int i);
DynamicArray *LinkedList_getValues(LinkedList *ll);

#endif
