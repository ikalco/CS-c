#include "array_queue.h"
#include <stdio.h>

#define ASSERT(a, b)                                                           \
	if (a != b) {                                                              \
		perror("Failed\n");                                                    \
		return 1;                                                              \
	}

#define NASSERT(a, b)                                                          \
	if (a == b) {                                                              \
		perror("Failed\n");                                                    \
		return 1;                                                              \
	}

int test1() {
	AQueue *q = AQueue_create(10);

	ASSERT(AQueue_isEmpty(q), true);

	AQueue_enqueue(q, 1);
	AQueue_enqueue(q, 2);
	AQueue_enqueue(q, 3);
	AQueue_enqueue(q, 4);
	AQueue_enqueue(q, 5);
	AQueue_enqueue(q, 6);
	AQueue_enqueue(q, 7);
	AQueue_enqueue(q, 8);
	AQueue_enqueue(q, 9);
	AQueue_enqueue(q, 10);

	ASSERT(AQueue_dequeue(q), 1);
	ASSERT(AQueue_dequeue(q), 2);
	ASSERT(AQueue_dequeue(q), 3);
	ASSERT(AQueue_dequeue(q), 4);
	ASSERT(AQueue_dequeue(q), 5);
	ASSERT(AQueue_dequeue(q), 6);
	ASSERT(AQueue_dequeue(q), 7);
	ASSERT(AQueue_dequeue(q), 8);
	ASSERT(AQueue_dequeue(q), 9);
	ASSERT(AQueue_dequeue(q), 10);

	ASSERT(AQueue_isEmpty(q), true);

	ASSERT(AQueue_destroy(q), true);

	return 0;
}

int test2() {
	AQueue *q = AQueue_create(10);

	ASSERT(AQueue_isEmpty(q), true);

	AQueue_enqueue(q, 2);
	AQueue_enqueue(q, 5);
	AQueue_enqueue(q, 7);

	ASSERT(AQueue_dequeue(q), 2);

	AQueue_enqueue(q, 3);
	AQueue_enqueue(q, 1);
	AQueue_enqueue(q, 9);
	AQueue_enqueue(q, 10);
	AQueue_enqueue(q, 4);
	AQueue_enqueue(q, 6);

	ASSERT(AQueue_dequeue(q), 5);

	AQueue_enqueue(q, 2);
	AQueue_enqueue(q, 15);

	ASSERT(AQueue_isEmpty(q), false);

	ASSERT(AQueue_dequeue(q), 7);
	ASSERT(AQueue_dequeue(q), 3);
	ASSERT(AQueue_dequeue(q), 1);
	ASSERT(AQueue_dequeue(q), 9);

	AQueue_enqueue(q, 99);

	ASSERT(AQueue_dequeue(q), 10);
	ASSERT(AQueue_dequeue(q), 4);
	ASSERT(AQueue_dequeue(q), 6);
	ASSERT(AQueue_dequeue(q), 2);
	ASSERT(AQueue_dequeue(q), 15);

	ASSERT(AQueue_dequeue(q), 99);

	ASSERT(AQueue_isEmpty(q), true);

	ASSERT(AQueue_destroy(q), true);

	return 0;
}

int main() {
	int failed = 0;

	failed += test1();
	failed += test2();

	if (failed == 0) {
		printf("Passed all tests!\n");
	} else {
		printf("Failed %d tests.\n", failed);
	}

	return 0;
}
