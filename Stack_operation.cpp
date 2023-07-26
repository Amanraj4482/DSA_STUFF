//STACK USING THE ARRAY

#include<bits/stdc++.h>
using namespace std;

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

//STACK USING THE LINKED LIST


#include<bits/stdc++.h>
using namespace std;

typedef struct node {
	int data;
	struct node* next;

} _Node;   		//_Node has been typedef

typedef struct stack {
	_Node *top;

} _Stack;		//_Stack has been typedef

//creating a node of type struct node =_Node
_Node* create_node(int value) {
	_Node * new_node = (_Node*)malloc(sizeof(_Node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

//creating a stack of type struct stack =_Stack
_Stack* create_stack() {
	_Stack* new_stack = (_Stack*)malloc(sizeof(_Stack));
	new_stack->top = NULL;
	return new_stack;
}

int isEmpty(_Stack * new_stack) {
	return new_stack->top == NULL;
}

void push_beg(_Stack *new_stack, int value) { //passing the linked list head
	//creating a new_node for the pussing
	_Node* new_node = create_node(value);
	new_node->next = new_stack -> top;
	new_stack ->top = new_node;
	//pussing the element to the top of the stack
}

int pop(_Stack * new_stack) {
	if (isEmpty(new_stack)) {
		printf("UnderFlow");
		exit(1);
	}
	_Node* temp = new_stack->top;
	int data = temp-> data;

	new_stack->top = new_stack->top->next;
	free(temp);
	return data;
}

int peek(_Stack * new_stack) {
	if (isEmpty(new_stack)) {
		printf("Stack is Empty");
		exit(1);
	}
	return new_stack->top->data;
}

void printing (_Stack * new_stack) {
	if (isEmpty(new_stack)) {
		printf("Empty Stack");
		return;
	}
	_Node* current = new_stack->top;
	while (current != NULL) {
		printf("Push %d\n", current->data);
		current = current->next;
	}
}

void destroy_stack(_Stack * new_stack) {
	_Node * current = new_stack->top;
	while (current != NULL) {
		_Node * temp = current;
		current = current->next;
		free(temp);
	}
	free(new_stack);
}
int main() {
	_Stack * new_stack = create_stack(); //passing the address referencly
	push_beg(new_stack, 10);
	push_beg(new_stack, 20);
	push_beg(new_stack, 30);
	push_beg(new_stack, 40);

	printing(new_stack);

	printf("\nPop  %d\n", pop(new_stack));
	printf("Peek %d\n", peek(new_stack));

	destroy_stack(new_stack);

	return 0;
}





