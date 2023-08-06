1.Write a program to explain all the operation of list which include searching of element reversinng the string?

#include<bits/stdc++.h>
using namespace std;
#define n 5
void displayList(int arr[], int size) {
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}


int searching(int arr[], int size, int search) {
	for (int i = 0; i < size; ++i)
	{
		if (search == arr[i]) {
			return i;
		}
	}
	// if not found then return -1
	return -1;
}

void reverseList(int arr[] , int size) {
	int i = 0, j = size - 1;
	while (i < j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++; j--;
	}
}
int main() {
// creating an array
	int arr[n] = {1, 2, 3, 4, 5};
// display the original list
	displayList(arr, n);
	printf("\n");

// search for an element in the list
	int search = 3;
	int index = searching(arr, n, search);
	if (index != -1) {
		printf("%d found at index %d \n" , search , index);
	}
	else {
		printf("%d not found int the list.\n ", search);
	}

	// Reverse the list
	reverseList(arr, n);
	displayList(arr, n);

	return 0;
}

1 2 3 4 5
3 found at index 2
5 4 3 2 1


2. Write a program array the element of array in assending and desecending order? in
~  using the bubble sort algorithm to sort in asceding and desending order
#include<bits/stdc++.h>
using namespace std;
void bubbleAscending(int arr[], int size) {
	int temp;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1]) {
				// swap the element if they are in wrong order
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void bubbleDecending(int arr[], int size) {
	int temp;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] < arr[j + 1]) {
				// swap the element if they are in wrong order
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void printing(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[] = {1, 3, 5, 6, 2, 8, 7};
	int size = sizeof(arr) / 4;
	printing(arr, size);
	bubbleAscending(arr, size);
	printing(arr, size);
	bubbleDecending(arr, size);
	printing(arr, size);
	return 0;
}
1 3 5 6 2 8 7
1 2 3 5 6 7 8
8 7 6 5 3 2 1



3.Write a program to add a element into an array? Write a program to add a element into an array?
#include <stdio.h>
int main()
{
	int arr[100] = { 0 };
	int i, x = 7, pos = 3, size = 5;
	for (i = 0; i < 10; i++)
		arr[i] = i + 1;
	size++;
	for (i = size - 1; i >= pos; i--)
		arr[i] = arr[i - 1];
	arr[pos - 1] = x;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	return 0;
}
// 1 2 3 4 5 //input
// 1 2 7 3 4 5 //output

4. write an program to push or delete element in stack by linked list and array

#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	struct node * next;
} Node;

typedef struct stack {
	Node * top;
} Stack;

Node * create_node(int value) {
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = value;
	return new_node;
}

Stack * create_stack() {
	Stack * new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->top = NULL;
	return new_stack;
}
int isEmpty(Stack * new_stack) {
	return new_stack->top == NULL;
}
void push_beg(Stack * new_stack, int value) {
	// creating a node
	Node * new_node = create_node(value);
	new_node->next = new_stack->top; // new_stack means the head
	new_stack->top = new_node;
}
int pop (Stack * new_stack) {
	// checking the underflow condition
	if (isEmpty(new_stack)) {
		printf("Underflow\n");
		return 0;
	}
	Node * temp = new_stack->top;
	int a = temp->data;
	new_stack->top = new_stack->top->next;
	free(temp);
	return a;
}
void printing(Stack * new_stack) {
	if (isEmpty(new_stack)) {
		printf(" Stack is empty");
		return ;
	}
	Node* current = new_stack->top;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}
int main() {
	Stack * new_stack = create_stack();
	push_beg(new_stack, 10);
	push_beg(new_stack, 20);
	push_beg(new_stack, 30);
	push_beg(new_stack, 40);

	printing(new_stack);
	printf("pop-> %d\n ", pop(new_stack));

	return 0;
}
40 30 20 10 pop-> 40


~stack using the array

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
	int top;
	int capacity;
	int * arr;
} Stack;
// creating a stack
Stack * create_stack(int capacity) {
	Stack * new_stack = (Stack*)malloc(sizeof(Stack));
	new_stack->top = -1;
	new_stack->capacity = capacity;
	new_stack->arr = (int*)malloc(sizeof(4));
	return new_stack;
}

int isFull(Stack * new_stack) {
	return new_stack->top == new_stack->capacity - 1;
}
int isEmpty(Stack * new_stack) {
	return new_stack->top == -1;
}
void push(Stack* new_stack, int value) {
//checking is it full
	if (isFull(new_stack)) {
		printf("full stack ");
		return;
	}
	// now assecing the array
	new_stack->arr[++new_stack->top] = value;
}
int pop(Stack * new_stack) {
	//checking is it empty
	if (isEmpty(new_stack)) {
		printf("empty stack");
		return 0;
	}
	//pop out the first element present in the stack
	//first pointing the top to the second last element then removing the last one
	return new_stack->arr[new_stack->top--];
}
void printing(Stack * new_stack) {
	//checking the empty stack
	if (isEmpty(new_stack))
		return;
	for (int i = new_stack->top; i > -1; i--) {//we have to traverse back
		printf("%d ", new_stack->arr[i]);
	}
}
int main() {
	//creating the new_stack with the creating_stack function and with the capacity
	Stack * new_stack = create_stack(100);
	push(new_stack, 10);
	push(new_stack, 20);
	push(new_stack, 30);
	push(new_stack, 40);
	pop(new_stack);
	printing(new_stack);
	return 0;
}
30 20 10
