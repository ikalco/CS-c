#ifndef DEQUE_H
#define DEQUE_H

#include <stdbool.h>

typedef struct DequeNode {
	struct DequeNode *next;
	struct DequeNode *prev;
	int value;
} DequeNode;

typedef struct {
	DequeNode *head;
	DequeNode *tail;
	unsigned long size;
} Deque;

Deque *Deque_create();
bool Deque_destroy(Deque *deque);
void Deque_insertFront(Deque *deque, int val);
void Deque_insertRear(Deque *deque, int val);
int Deque_getFront(Deque *deque);
int Deque_getRear(Deque *deque);
void Deque_deleteFront(Deque *deque);
void Deque_deleteRear(Deque *deque);
void Deque_erase(Deque *deque);
bool Deque_isEmpty(Deque *deque);

#endif
