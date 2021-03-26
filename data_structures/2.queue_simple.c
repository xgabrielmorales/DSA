#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct queue {
	int items[MAX];
	int front;
	int rear;
} Queue;

void createEmptyQueue(Queue *q){
	(*q).front = -1;
	(*q).rear = -1;
}

int isFull(Queue* q){
	if ((*q).rear == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(Queue* q){
	if ((*q).front == -1)
		return 1;
	else
		return 0;
}

void enQueue(Queue* q, int newItem){
	if (isFull(q)){
		printf("QUEUE IS FULL!\n");
	} else {
		if ((*q).front == -1) (*q).front = 0;
		(*q).rear++;
		(*q).items[(*q).rear] = newItem;
	}
}

void deQueue(Queue* q){
	if (isEmpty(q)){
		printf("QUEUE IS EMPTY\n");
	} else {
		printf("Deleted: %d\n", (*q).items[(*q).front]);

		(*q).front++;

		if ((*q).front > (*q).rear)
			(*q).front = (*q).rear = -1;
	}
}

void printQueue(Queue *q){
	printf("Queue: ");
	for(int i = (*q).front; i < (*q).rear + 1; i++){
		printf("%d ", (*q).items[i]);
	}
	printf("\n");
}

int main(){
	Queue *q = malloc(sizeof(Queue));

	createEmptyQueue(q);
	enQueue(q, 2);
	enQueue(q, 6);

	printQueue(q);

	deQueue(q);

	printQueue(q);

	return 0;
}
