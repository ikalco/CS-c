#include "deque.h"
#include <stdio.h>

#define ASSERT(a, b)                                                           \
	if (a != b) {                                                              \
		perror("Failed\n");                                                    \
		return 1;                                                              \
	}

int main() {
	Deque *deque = Deque_create();

	Deque_insertRear(deque, 2);
	Deque_insertRear(deque, 0);

	ASSERT(Deque_getRear(deque), 0);

	Deque_deleteRear(deque);

	ASSERT(Deque_getRear(deque), 2);

	Deque_insertFront(deque, 27);

	ASSERT(Deque_getFront(deque), 27);
	ASSERT(deque->size, 2);

	Deque_deleteFront(deque);

	ASSERT(Deque_getFront(deque), 2);

	Deque_insertFront(deque, 28);
	Deque_insertFront(deque, 29);
	Deque_insertRear(deque, 30);
	Deque_insertRear(deque, 31);

	ASSERT(Deque_getFront(deque), 29);
	ASSERT(Deque_getRear(deque), 31);

	Deque_erase(deque);

	ASSERT(Deque_getFront(deque), -1);
	ASSERT(Deque_getRear(deque), -1);
	ASSERT(deque->size, 0);

	ASSERT(Deque_destroy(deque), true);

	printf("Ran all tests succesfully!\n");

	return 0;
}
