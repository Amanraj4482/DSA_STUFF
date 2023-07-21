//Implemeting the data by the array
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//we should have the array to store the data of the stack

//The blueprint of stack
struct Stack {
	int capacity;
	int top;
	int *arr;//this is the pointer and it will point the where my array is
};

//creating a stack
struct Stack* create_stack(int _capacity) {
	struct Stack* new_stack = (struct Stack*)malloc(sizeof(struct Stack));
	new_stack-> capacity = _capacity;
	new_stack->top = -1; //to denote the stack is NULL means having the zero element
	new_stack->arr = (int*)malloc(new_stack->capacity * (sizeof(4))); //accessing the stack capacity

	return new_stack;
}

int isFull(struct Stack* new_stack) {
	return new_stack->top == new_stack-> capacity - 1; //stack is full
}

int isEmpty(struct Stack* new_stack) {
	return new_stack->top == -1; //stack is empty
}
//nothing to return for the pushing
void Push(struct Stack* new_stack, int value) {
	//is it full?
	if (isFull(new_stack)) {
		printf("This is overflow");
		return;
	}
	//accessing the array
	new_stack->arr[++new_stack->top] = value; //top has been increamented and put the value inside it.
	// printf("size =>%d \nThe value =>%d\n", new_stack->top, value);

}
//here the last elemeted is pointed by the pop
int Pop(struct Stack* new_stack) {
	//is it Empty?
	if (isEmpty(new_stack)) {
		printf("This is Empty");
		return 0;
	}
	return new_stack->arr[new_stack->top--]; //top is first point to the second last element
	//so that top will be the last element by decreamenting it
}

int Peek(struct Stack * new_stack) {
	//if the underflow is there we cannot peek it
	if (isEmpty(new_stack)) {
		printf("Empty stack");
	}
	return new_stack->arr[new_stack->top];//we don't have to delete it
}

void printing(struct Stack* new_stack) {
	//if the stack is empty i cannot print anything
	if (isEmpty(new_stack)) {
		printf("Emtpy stack not print");
		return ;
	}
	//inside the stack in the array
	//data inside the array printing
	for (int i = new_stack->top; i > -1; i--) {
		printf("%d ", new_stack->arr[i]);
	}
}

void destroy_stack(struct Stack* new_stack) {
	//1st freeing of the memory of the array then stack
	free(new_stack->arr);
	free(new_stack);
}
int main() {
	//checking the conditions
	//1. overflow
	//2. underflow


	struct Stack* new_stack = create_stack(100);
	//pushing element
	Push(new_stack, 10);
	Push(new_stack, 20);
	Push(new_stack, 30);
	//poping out the element
	Pop(new_stack);
	//printing the stack value
	printing(new_stack);
	//destroing the stack
	destroy_stack(new_stack);
	return 0;
}
