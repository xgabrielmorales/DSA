#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int value;
	struct node* next;
} Node;

Node* createNode(Node* node){
	node = NULL;
	return node;
}

int isEmpty(Node* list){
	return (list == NULL);
}

void delNode(Node* node){
	free(node);
}

void printLinkedList(Node* list){
	if (isEmpty(list)){
		printf("Linked list is empty\n");
	} else {
		printf("Linked List: ");
		while (list != NULL){
			printf("%d -> ", list->value);
			list = list->next;
		}
		printf("NULL\n");
	}
}

void addAtEnd(Node** head, int newValue){
	Node* newNode = malloc(sizeof(Node));
	Node* temp = (*head);

	newNode->value = newValue;
	newNode->next = NULL;

	if (isEmpty(*head)){
		(*head) = newNode;
	} else {
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}

}

void addAfter(Node** head, int newValue, int id){
	Node* newNode = malloc(sizeof(Node));
	newNode->value = newValue;
	newNode->next = NULL;

	if (isEmpty(*head)){
		(*head) = newNode;
	} else {
		Node* tmp = (*head);
		Node* prev;

		for (int i = 0; i <= id; i++){
			if (tmp == NULL)
				return;
			prev = tmp;
			tmp = tmp->next;
		}

		prev->next = newNode;
		newNode->next = tmp;
	}
}

void addAtBeginning(Node** head, int newValue){
	Node* newNode = malloc(sizeof(Node));
	newNode->value = newValue;
	newNode->next = NULL;

	if (isEmpty(*head)){
		(*head) = newNode;
	} else {
		newNode->next = (*head);
		// Reasigno la cabeza de la lista
		(*head) = newNode;
	}
}

void delFirst(Node** head){
	if (isEmpty(*head))
		return;

	if ((*head)->next == NULL) {
		// if there is only one element.
		(*head) = NULL;
	} else {
		// if there is more than one element.
		Node* tmp = (*head);

		(*head) = (*head)->next;
		delNode(tmp);
	}
}

void del(Node** head, int id){
	if (isEmpty(*head))
		return;

	Node* toDel = (*head);
	Node* prev;

	for (int i = 0; i < id; i++){
		if (toDel == NULL)
			return;
		prev  = toDel;
		toDel = toDel->next;
	}

	prev->next = toDel->next;
	delNode(toDel);
}

void delLast(Node** head){
	if (isEmpty(*head))
		return;

	if ((*head)->next == NULL) {
		// if there is only one element.
		(*head) = NULL;
	} else {
		// if there is more than one element.
		Node* tmp = (*head);

		while((tmp->next)->next != NULL)
			tmp = tmp->next;

		delNode(tmp->next);
		tmp->next = NULL;
	}
}

int main(){
	Node* head = createNode(head);

	addAtBeginning(&head, 3);
	addAtBeginning(&head, 2);
	addAtBeginning(&head, 1);
	addAtEnd(&head, 4);

	addAfter(&head, 100 , 3);
	del(&head, 1);

	printLinkedList(head);

	return 0;
}
