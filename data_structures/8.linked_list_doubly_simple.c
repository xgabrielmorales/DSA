#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* prev;
	struct node* next;
} Node;

void printFoward(Node* node){
	printf("List: ");
	while (node != NULL){
		printf("%d -> ", node->value);
		node = node->next;
	}
	printf("NULL\n");
}

void printBackWard(Node* node){
	printf("List: ");
	while (node != NULL){
		printf("%d -> ", node->value);
		node = node->prev;
	}
	printf("NULL\n");
}

int main(){
	Node* head;
	Node* node1 = malloc(sizeof(Node));
	Node* node2 = malloc(sizeof(Node));
	Node* node3 = malloc(sizeof(Node));

	node1->value = 1;
	node1->next = node2;
	node1->prev = NULL;

	node2->value = 2;
	node2->next = node3;
	node2->prev = node1;

	node3->value = 3;
	node3->next = NULL;
	node3->prev = node2;

	head = node1;

	printFoward(head);
	printBackWard(node3);

	return 0;
}
