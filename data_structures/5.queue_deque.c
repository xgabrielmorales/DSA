#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int size = 0;

typedef struct queue {
	int items[MAX];
	int front, rear;
} Queue;

void createEmptyQueue(Queue *q){
	q->front = -1;
	q->rear  = -1;
}

int isFull(Queue* q){
	return ((q->rear == MAX - 1 && q->front == 0) || (q->front == q->rear + 1));
}

int isEmpty(Queue* q){
	return (q->front == -1);
}

void printQueue(Queue* q){
	if (isEmpty(q)){
		printf("Queue is empty\n");
	} else {
		int i;
		printf("Queue: ");
		for (i = q->front; i != q->rear; i = (i + 1) % MAX)
			printf("%d ", q->items[i]);
		printf("%d\n", q->items[i]);
	}
}

void addRear(Queue* q, int newItem){
	if (isFull(q)){
		printf("QUEUE IS FULL!\n");
	} else {

		if (isEmpty(q))
			q->front = q->rear = 0;
		else if (q->rear == size - 1)
			q->rear = 0;
		else
			q->rear++;

		q->items[q->rear] = newItem;
		size++;
	}
}

void addFront(Queue* q, int newItem){
	if (isFull(q)){
		printf("QUEUE IS FULL!\n");
	} else {

		if (isEmpty(q))
			q->front = q->rear = 0;
		else if (q->front < 1)
			q->front = MAX - 1;
		else
			q->front--;

		q->items[q->front] = newItem;
		size++;
	}
}


void delFront(Queue* q){
	if (isEmpty(q)){
		printf("QUEUE IS EMPTY\n");
	} else {
		if (q->front == q->rear)
			q->front = q->rear = - 1;
		else if (q->front == MAX - 1)
			q->front = 0;
		else
			q->front++;
	}
}

void delRear(Queue* q){
	if (isEmpty(q)){
		printf("QUEUE IS EMPTY\n");
	} else {
		if (q->rear == q->front)
			q->rear = q->front = 0;
		else if (q->rear = MAX - 1)
			q->rear = 0;
		else
			q->rear = q->rear - 1;
	}
}

int main(){
	Queue* q = calloc(1, sizeof(Queue));

	createEmptyQueue(q);

	addFront(q, 5);
	addFront(q, 10);
	addRear(q, 20);
	addFront(q, 20);
	printQueue(q);

	delRear(q);
	printQueue(q);

	delFront(q);
	printQueue(q);

	free(q);
	return 0;
}
