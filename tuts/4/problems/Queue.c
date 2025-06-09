#include "Stack.h"
#include "Queue.h"

struct queue {
	Stack s1;
	Stack s2;
};

Queue QueueNew(void) {
	Queue q = malloc(sizeof(struct queue));
	q->s1 = StackNew();
	q->s2 = StackNew();
	return q;
}

void QueueFree(Queue q) {
	StackFree(q->s1);
	StackFree(q->s2);
	free(q);
}

void QueueEnqueue(Queue q, Item item) {
	// TODO
}

Item QueueDequeue(Queue q) {
    // TODO
}