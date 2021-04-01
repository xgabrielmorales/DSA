#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* prev;
	struct node* next;
} Node;

Node* createNode(Node* node){
	node = NULL;
	return node;
}

void printForward(Node* node){
	/* Accepts the head of a list as input */

	printf("List: ");
	while (node != NULL){
		printf("%d -> ", node->value);
		node = node->next;
	}
	printf("NULL\n");
}

void printBackWard(Node* node){
	/* Accepts the last node in a list as input */
	printf("List: ");
	while (node != NULL){
		printf("%d -> ", node->value);
		node = node->prev;
	}
	printf("NULL\n");
}

int isEmpty(Node* list){
	return (list == NULL);
}

void add(Node** head, int newValue, int id){
	Node* tmp = (*head);
	Node* prev = NULL;

	Node* newNode = malloc(sizeof(Node));
	newNode->value = newValue;
	newNode->prev = NULL;
	newNode->next = NULL;

	if (isEmpty(*head)){
		(*head) = newNode;
	} else if (id == 0) {
		newNode->next = (*head);
		(*head) = newNode;
	} else {
		for (int i = 0; i < id; i++){
			if (tmp == NULL)
				return;
			prev = tmp;
			tmp = tmp->next;
		}

		prev->next = newNode;

		newNode->prev = prev;
		newNode->next = tmp;
	}
}

int main(){
	Node* head = createNode(head);

	add(&head, 5, 0);
	add(&head, 10, 1);

	printForward(head);
	printBackWard(head->next);

	return 0;
}
