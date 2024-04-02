#include "array_queue.h"
#include <stdio.h>
#include <stdlib.h>

AQueue *AQueue_create(unsigned long size) {
	AQueue *queue = malloc(sizeof(*queue) + sizeof(int[size]));
	queue->head = -1;
	queue->tail = -1;
	queue->size = size;
	return queue;
}

bool AQueue_destroy(AQueue *queue) {
	free(queue);
	return true;
}

void AQueue_enqueue(AQueue *queue, int val) {
	if (AQueue_isEmpty(queue)) {
		queue->head = 0;
		queue->tail = 0;
	} else if (queue->tail + 1 == queue->size) {
		if (queue->head != 0)
			queue->tail = 0;
		else {
			perror("Failed to enqueue, AQueue is full.\n");
			exit(1);
		}
	} else if (queue->tail + 1 == queue->head) {
		perror("Failed to enqueue, AQueue is full.\n");
		exit(1);
	} else {
		queue->tail++;
	}

	queue->data[queue->tail] = val;
}

int AQueue_dequeue(AQueue *queue) {
	if (AQueue_isEmpty(queue)) {
		perror("Can't dequeue, AQueue is empty.\n");
		exit(1);
	} else if (queue->head == queue->tail) {
		int tmp = queue->data[queue->head];
		queue->head = -1;
		queue->tail = -1;
		return tmp;
	} else if (queue->head == queue->size) {
		queue->head = 1;
		return queue->data[0];
	} else {
		queue->head++;
		return queue->data[queue->head - 1];
	}
}

bool AQueue_isEmpty(AQueue *queue) {
	return queue->head == -1 && queue->tail == -1;
}
