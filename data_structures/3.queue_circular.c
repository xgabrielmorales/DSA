#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct queue {
	int items[MAX];
	int front;
	int rear;
} Queue;

void createEmptyQueue(Queue* q){
	(*q).front = -1;
	(*q).rear = -1;
}

int isFull(Queue* q){
	if (((*q).front == (*q).rear + 1) || ((*q).front == 0 && (*q).rear == MAX - 1)){
		return 1;
	} else {
		return 0;
	}
}

int isEmpty(Queue *q){
	if ((*q).front == -1){
		return 1;
	} else {
		return 0;
	}
}

void enQueue(Queue* q, int newItem){
	if (isFull(q)){
		printf("QUEUE IS FULL!\n");
	} else {
		if ((*q).front == -1)
			(*q).front = 0;

		(*q).rear = ((*q).rear + 1) % MAX;
		(*q).items[(*q).rear] = newItem;
		printf("Inserted: %d\n", (*q).items[(*q).rear]);
	}
}

void deQueue(Queue* q){
	int element;
	if (isEmpty(q)){
		printf("QUEUE IS EMPTY\n");
	} else {
		element = (*q).items[(*q).front];
		if ((*q).front == (*q).rear){
			// Si que da un solo elemento,
			// entonces reinciamos la queue.
			createEmptyQueue(q);
		} else {
			(*q).front = ((*q).front + 1) % MAX;
		}
		printf("Deleted: %d\n", element);

	}
}

void printQueue(Queue* q){
	int i;
	if (isEmpty(q)){
		printf("Queue is empty\n");
	} else {
		printf("Queue: ");
		for (i = (*q).front; i != (*q).rear; i = (i + 1) % MAX)
			printf("%d ", (*q).items[i]);
		printf("%d ", (*q).items[i]);

		printf("\n");
	}
}

int main(){
	Queue* q = malloc(sizeof(Queue));

	createEmptyQueue(q);

	enQueue(q,  5);
	enQueue(q, 10);
	enQueue(q, 15);
	enQueue(q, 20);
	enQueue(q, 25);

	printQueue(q);

	deQueue(q);
	enQueue(q, 30);

	printQueue(q);

	free(q);
	return 0;
}
