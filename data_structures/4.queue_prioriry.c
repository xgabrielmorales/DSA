#include <stdio.h>

int size = 0;

void swap(int* a, int* b){
	int temp = *b;
	*b = *a;
	*a = temp;
}

void printArray(int* array){
	printf("Array: ");
	for (int i = 0; i < size; i++)
		printf("%d ", array[i]);
	printf("\n");
}

void heapify(int* array, int size, int index){
	if (size == 1){
		printf("Single element in the heap!\n");
	} else {
		// find the largest among root, left child and right child
		int largest = index;
		int leftChild  = (2*index) + 1; // index
		int rightChild = (2*index) + 2; // index

		if (array[leftChild]  > array[largest] && leftChild  < size)
			largest = leftChild;
		if (array[rightChild] > array[largest] && rightChild < size)
			largest = rightChild;

		// Swap and continue heapifying if root isn't largest
		if (largest != index){
			swap(&array[index], &array[largest]);
			heapify(array, size, largest);
		}
	}
}

void insert(int* array, int newItem){
	if (size == 0){
		array[size] = newItem;
		size++;
	} else {
		array[size] = newItem;
		size++;

		for (int index = (size/2)-1; index >= 0; index--)
			heapify(array, size, index);
	}
}

void deleteRoot(int* array, int item){
	int index;
	for (index = 0; index < size; index++)
		if (item == array[index])
			break;

	// Move the number to the last position
	swap(&array[index], &array[size - 1]);
	size--;

	for (int index = (size/2)-1; index >= 0; index--)
		heapify(array, size, index);
}


int main(){
	int array[10];

	insert(array, 3);
	insert(array, 4);
	insert(array, 9);
	insert(array, 7);
	insert(array, 5);
	insert(array, 2);

	printArray(array);

	deleteRoot(array, 3);

	printArray(array);

	return 0;
}
