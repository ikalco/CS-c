#include "deque.h"
#include <stdlib.h>

Deque *Deque_create() {
	Deque *deque = malloc(sizeof(*deque));
	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
	return deque;
}

bool Deque_destroy(Deque *deque) {
	Deque_erase(deque);
	free(deque);
	return true;
}

void Deque_insertFront(Deque *deque, int val) {
	DequeNode *new = malloc(sizeof(*new));
	new->value = val;
	new->prev = NULL;
	new->next = NULL;

	if (deque->size == 0) {
		deque->head = new;
		deque->tail = new;
	} else {
		new->next = deque->head;
		deque->head = new;
	}

	deque->size++;
}

void Deque_insertRear(Deque *deque, int val) {
	DequeNode *new = malloc(sizeof(*new));
	new->value = val;
	new->prev = NULL;
	new->next = NULL;

	if (deque->size == 0) {
		deque->head = new;
		deque->tail = new;
	} else {
		new->prev = deque->tail;
		deque->tail = new;
	}

	deque->size++;
}

int Deque_getFront(Deque *deque) {
	if (deque->head == NULL) return -1;

	return deque->head->value;
}

int Deque_getRear(Deque *deque) {
	if (deque->tail == NULL) return -1;

	return deque->tail->value;
}

void Deque_deleteFront(Deque *deque) {
	if (deque->head == NULL) return;

	DequeNode *tmp = deque->head;
	deque->head = deque->head->next;
	free(tmp);

	deque->size--;
}

void Deque_deleteRear(Deque *deque) {
	if (deque->tail == NULL) return;

	DequeNode *tmp = deque->tail;
	deque->tail = deque->tail->prev;
	free(tmp);

	deque->size--;
}

void Deque_erase(Deque *deque) {
	if (deque->size == 0) return;

	DequeNode *tmp = NULL;
	DequeNode *next = deque->head;

	while (next != NULL) {
		tmp = next;
		next = next->next;
		free(tmp);
	}

	deque->head = NULL;
	deque->tail = NULL;
	deque->size = 0;
}

bool Deque_isEmpty(Deque *deque) { return deque->size == 0; }
