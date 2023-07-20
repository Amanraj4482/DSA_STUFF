
//INFIX TO POSTFIX

#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#define max 100
struct Stack {
	int capacity;
	int top;
	char *arr;
};
struct Stack* create_stack(int _capacity) {
	struct Stack * new_stack = (struct Stack*)malloc (sizeof(char));
	new_stack->capacity = _capacity;
	new_stack->top = -1;
	new_stack->arr = (char*)malloc(new_stack->capacity * (sizeof(char)));
	return new_stack;
}
int isFull(struct Stack * new_stack) {
	return new_stack->top == new_stack->capacity - 1;
}
void push(struct Stack* new_stack, char value) {
	//is it full?
	if (isFull(new_stack)) {
		printf("Stack is full");
		return;
	}
	new_stack->arr[++new_stack->top] = value;
}
int isEmpty(struct Stack * new_stack) {
	return new_stack->top == -1;
}
char pop(struct Stack* new_stack) {
	// is it empty
	if (isEmpty(new_stack)) {
		printf("Yes it is Empty\n");
		return '\0';
	}
	return new_stack->arr[new_stack->top--];
}
char peek(struct Stack * new_stack) {
	// is it empty?
	if (isEmpty(new_stack)) {
		printf("Yes its Empty");
		return '\0';
	}
	return new_stack->arr[new_stack->top];
}

//whether it is operand or operator?
int isOperand(char ch) {
	return isalnum(ch);
}
//gives the return the oprator precedance
int precedance(char op) {
	switch (op) {

	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
	case '%':
		return 2;

	case '^':
		return 3;

	}
	return -1;
}
void infixTopostfix(const char* infix , char* postfix) {
	struct Stack* new_stack = create_stack(max);
	int i, j = 0;
	char ch, x;
	for (int i = 0; infix[i] != '\0'; ++i)
	{
		ch = infix[i];
		if (isOperand(ch)) {
			postfix[j++] = ch;
		}
		if (ch == '(') {
			push(new_stack, ch);
		}
		else if (ch == ')') {
			while ((x = pop(new_stack)) != '(') { //here we are poping the elements until we have reached in the opening paranthesis in the stack
				postfix[j++] = x;
			}
		}
		else {
			while (!isEmpty(new_stack) && precedance(ch) <= precedance(peek(new_stack))) { //that should not be empty then only it will go inside
				postfix[j++] = pop(new_stack); //pop char should be pussed inside the postfix
			}
			push(new_stack, ch);
		}
	}
	while (!isEmpty(new_stack)) {
		postfix[j++] = pop(new_stack);
	}
	postfix[j] = '\0';

	//destroying the stack
	free(new_stack->arr);
	free(new_stack);
}
int main() {
	
	char infix[max], postfix[max];
	fgets(infix, sizeof(infix), stdin);
	infixTopostfix(infix, postfix);
	printf("%s\n", postfix);

	return 0;
}
