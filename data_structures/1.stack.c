#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int count = 0;

typedef struct stack {
	int items[MAX];
	int top;
} st;

void createEmptyStack(st* s){
	(*s).top = -1;
}

int isFull(st* s){
	if ((*s).top == MAX - 1)
		return 1;
	else
		return 0;
}

int isEmpty(st* s){
	if ((*s).top == -1)
		return 1;
	else
		return 0;
}

// Add elements into stack
void push(st* s, int newItem){
	if (isFull(s)){
		printf("STACK FULL\n");
	} else {
		(*s).top++;
		(*s).items[(*s).top] = newItem;
	}
	count++;
}

// Remove element from stack
void pop(st* s){
	if (isEmpty(s)){
		printf("STACK EMPTY\n");
	} else {
		printf("Item popped = %d\n", (*s).items[(*s).top]);
		(*s).top--;
	}
	count--;
}

void printStack(st* s){
	printf("Stack: ");
	for (int i = 0; i < count; i++){
		printf("%d ", (*s).items[i]);
	}
	printf("\n");
}

int main(){
	st *s = malloc(sizeof(st));
	createEmptyStack(s);

	push(s, 2);
	push(s, 6);
	printStack(s);

	pop(s);

	printStack(s);

	return 0;
}
