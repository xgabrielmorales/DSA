#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} Node;

void printLinkedList(Node* node){
	printf("List: ");
	while (node != NULL){
		printf("%d -> ", node->value);
		node = node->next;
	}
	printf("NULL\n");
}

int main(){
	Node* head;
	Node* node1 = malloc(sizeof(Node));
	Node* node2 = malloc(sizeof(Node));
	Node* node3 = malloc(sizeof(Node));

	node1->value = 5;
	node1->next = node2;

	node2->value = 10;
	node2->next = node3;

	node3->value = 15;
	node3->next = NULL;

	head = node1;

	printLinkedList(head);

	free(node1);
	free(node2);
	free(node3);
}
