#include "linked_list.h"
#include <stdlib.h>

LinkedList *LinkedList_create() {
	LinkedList *ll = malloc(sizeof(*ll));

	ll->head = NULL;
	ll->size = 0;

	return ll;
}

bool LinkedList_destroy(LinkedList *ll) {
	LinkedListNode *next = ll->head;

	for (int j = 0; j < ll->size; j++) {
		LinkedListNode *tmp = next;
		next = next->next;
		free(tmp);
	}

	free(ll);

	return true;
}

int LinkedList_get(LinkedList *ll, int i) {
	if (i < 0 || i >= ll->size) return -1;

	LinkedListNode *next = ll->head;

	for (int j = 0; j < i; j++) {
		next = next->next;
	}

	return next->value;
}

void LinkedList_insertHead(LinkedList *ll, int val) {
	LinkedListNode *new_head = malloc(sizeof(*new_head));
	new_head->next = ll->head;
	new_head->value = val;

	ll->head = new_head;
	ll->size++;
}

void LinkedList_insertTail(LinkedList *ll, int val) {
	LinkedListNode *new_tail = malloc(sizeof(*new_tail));
	new_tail->next = NULL;
	new_tail->value = val;

	LinkedListNode *tail = ll->head;

	for (int j = 0; j < ll->size - 1; j++) {
		tail = tail->next;
	}

	tail->next = new_tail;

	ll->size++;
}

bool LinkedList_remove(LinkedList *ll, int i) {
	if (i < 0 || i >= ll->size) return false;

	LinkedListNode *prev = NULL;
	LinkedListNode *next = ll->head;

	for (int j = 0; j < i; j++) {
		prev = next;
		next = next->next;
	}

	prev->next = next->next;
	free(next);

	ll->size--;

	return true;
}

DynamicArray *LinkedList_getValues(LinkedList *ll) {
	DynamicArray *values = DynamicArray_create(ll->size);

	LinkedListNode *next = ll->head;

	for (int i = 0; i < ll->size; i++) {
		DynamicArray_pushback(values, next->value);
		next = next->next;
	}

	return values;
};
