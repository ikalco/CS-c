#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <stdbool.h>

typedef struct {
	unsigned long head;
	unsigned long tail;
	unsigned long size;
	int data[];
} AQueue;

AQueue *AQueue_create(unsigned long size);
bool AQueue_destroy(AQueue *queue);
void AQueue_enqueue(AQueue *queue, int val);
int AQueue_dequeue(AQueue *queue);
bool AQueue_isEmpty(AQueue *queue);

#endif
