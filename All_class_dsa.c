//LINKED ALL OPERATIONS------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node* next;
};
struct node* create_node(int value) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
void printing(struct node *head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}
void insert_end(struct node**head, int value) {
	struct node* new_node = create_node(value);
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	//if the head is filled
	struct node* current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
}
void insert_beg(struct node**head, int value) {
	struct node* new_node = create_node(value);
	new_node->next = *head;
	*head = new_node;
}
void insert_pos(struct node**head, int value, int pos) {
	if (pos < 0) return ;
	if (pos == 0) { //if the index is equal to the zero
		insert_beg(head, value);
		return ;
	}
	struct node* new_node = create_node(value);
	struct node* current = *head;
	//if the index is greater than the zero -----
	int i = 2;
	while (i < pos) { /(*head!NULL&&count<index-1)/ //empty list
		current = current->next;
		i++;//--pos;
	}
	//if (pos==NULL)
	new_node->next = current->next;
	current->next = new_node;
}
void delete_beg(struct node** head) {
	if (*head == NULL) {
		printf("LIST IS EMPTY");
		return;
	}
	struct node* current = *head;
	*head = current->next;
	free(current);
}
void delete_end(struct node** head) {//it needs two pointers
	struct node* current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	if (current == *head) {
		*head = NULL;
		free(current);
		return;
	}
	current->next = NULL;
	free(current->next);
}
void delete_pos(struct node **head, int pos) {
	struct node* current = *head, *temp;
	int i = 2;
	while (i < pos) {
		current = current->next;
		i++;
	}
	temp = current->next;
	current->next = temp->next;
	free(temp);
}
void delete_whole(struct node** head) {
	struct node* current = *head;
	while (current != NULL) {//until current becomes null
		current = current->next;
		free(*head);
		*head = current;
	}
}
void reverse_list(struct node **head) {
	//we cannot move our head pointer before updating the link part of the second node.
	struct node * current1 = NULL ;
	struct node *current = *head;
	struct node * current2 = NULL;

	while (current != NULL) {//stop when head becomes null
		current2 = current->next;
		current->next = current1;
		current1 = current;
		current = current2;
	}
	*head = current1;
}
int main() {
	struct node* head = NULL;
//insertion at the ending
	insert_end(&head, 10);
	insert_end(&head, 20);
	insert_end(&head, 30);
//insertion at the beginnig
	insert_beg(&head, 40);
	insert_beg(&head, 50);

//insertion at the any position
	int data = 60, pos = 2;
	insert_pos(&head, data, pos);

//delete from beginning
	delete_beg(&head);
// //delete from ending
	delete_end(&head);
//delete from specified position
	delete_pos(&head, pos); //pos=2;
delete_whole(&head);
	reverse_list(&head);//head will point to last of the list
	printing(head);
}
// 50 60 40 10 20 30
//delete from beg=60 40 10 20 30
//delete from end=60 40 10 20
//delete form the pos=60 10 20
// reversed =30 20 10 40 60 50


//STACK USING THE ARRAY---------------------------------------------------------------------------------------------------------------------------

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

//STACK USING THE LINKED LIST---------------------------------------------------------------------------------------------------------------------

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



//INFIX TO POSTFIX--------------------------------------------------------------------------------------------------------------------------

//K + L - M*N(O^P)*W / U / V*T + Q

//if the operators are between the oprands then it is knows as the infix
//if the operators are after the operands then it is knows as the postfix

//we need to scan only once to convert the infix expression to the postfix

//if opening bracket come then direct push without checking
//~if any oprands come then we will directly write it into the output
//~if the operator then push into the stack
//______ if the operator is of higher precedance then the operator which is on the top of the stack then direct & associativity should be left to right
//in case of right to left & same operators then associativity we keep pushing into the stack without thinking
//________if the operator is lesser precedance then pop out the operator which is at top of the stack and again check it
//_______if the precedance is equal or lesser then again pop it..if higher is then push it..
//no need to check any precedance while pussing the operator in the stack coming after the opening brackets
//if we get the right bracket then pop out all the operators till the opening brackets


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
	struct Stack * new_stack = (struct Stack*)malloc (sizeof(struct Stack));
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
		printf("Stack is full\n");
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
	for ( i = 0; infix[i] != '\0'; i++)
	{
		ch = infix[i];
		if (isOperand(ch)) {
			postfix[j++] = ch;
		}
		else if (ch == '(') {
			push(new_stack, ch);
		}
		else if (ch == ')') {
			while ((x = pop(new_stack)) != '(') { //here we are poping the elements until
        //we have reached in the opening paranthesis in the stack
				postfix[j++] = x;
			}
		}
		else {
			while (!isEmpty(new_stack) && precedance(ch) <= precedance(peek(new_stack)))
        { //that should not be empty then only it will go inside
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
int evaluatePostfix(char *postfix)
{
	struct Stack *newstack = createStack(N);
	int i,val1,val2,result;
	char ch;
	for(i=0;postfix[i]!='\0';i++)
	{
		ch = postfix[i];
		if(isdigit(ch))
		{
			push(newstack,ch-'0');
		}
		else
		{
			val1=pop(newstack);
			val2=pop(newstack);
			switch(ch)
			{
				case '+':
					result=val2+val1;
					break;
				case '-':
					result=val2-val1;
					break;
				case '*':
					result=val2*val1;
					break;
				case '/':
					result=val2/val1;
					break;
				case '%':
					result=val2%val1;
					break;
				case '^':
					result=val2^val1;
					break;
				default :
					printf("Invalid operator\n");
					
			}
			push(newstack,result);
		}
	}
	result = pop(newstack);
	return result;
}
int main() {

	char infix[max], postfix[max];
	fgets(infix, sizeof(infix), stdin);
	infixTopostfix(infix, postfix);
	printf("%s\n", postfix);
  printf("Solution = %d",evaluatePostfix(postfix));
	return 0;
}

//input ->  ((p+(q*r))-s)
//output ->  pqr*+s-




//QUEUE WITH LINKED LIST ------------------------------------------------------------------------------------------------------------------------

// // QUEUE WITH LINKED LIST

#include<bits/stdc++.h>
using namespace std;

//front and rare should be null at the initial stage
//if am adding the first element then my front and rare becomes the first element]

//increamenting the rare part if enqueueing
typedef struct node {
	int data;
	struct node* next;//towards itself referencing
} Node;

typedef struct queue {
	Node * front;
	Node * rear ;
} Queue ;

void initialize(Queue * Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

int isEmpty(Queue * Q) {
	return Q->front == NULL;
}

void enqueue(Queue * Q, int value) {
	//creation of a node memory for the node without any checking
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;

	//two conditions either empty or having nodes already
	if (isEmpty(Q)) {
		Q->front = new_node;
		Q->rear = new_node;
	}
	else {
		Q->rear->next = new_node;
		Q->rear = new_node;
	}
}

int dequeue(Queue * Q) {//bother about the front because happends in the front
	if (isEmpty(Q)) {
		printf("Queue is Empty");
		exit(1);
	}
	else {
		//have to be returned the data that has to be deleted
		Node * temp = Q->front; //temprory pointer for pointing at the first node
		int data = temp->data;
		Q->front = Q->front->next;
		free(temp);

		//for the single node q -> front is already is null
		if (Q->front == NULL) {
			Q->rear = NULL;
		}
		return data;
	}
}

int peek(Queue * Q) {
	//topmost element is front data part
	if (isEmpty(Q)) {
		printf("Empty Q");
		exit(1);
	}
	else {
		return Q->front->data;
	}
}


void printing(Queue * Q) {
	if (isEmpty(Q)) {
		printf("Empty Q");
		return ;
	}
	Node * current = Q->front;
	while (current != NULL) {
		printf("Enqueue %d\n", current->data);
		current = current->next;
	}
}

void destroy_stack(Queue * Q) {
	Node * current = Q->front;
	while (current != NULL) {
		Node * temp = current;
		current = current->next;
		free(temp);
	}
	//because we don't have created the memory allocation for the Queue part
	Q->front = NULL;
	Q->rear = NULL;
}
int main() {
	Queue Q ;
	initialize(&Q);//call by reference

	enqueue(&Q, 10);
	enqueue(&Q, 20);
	enqueue(&Q, 30);

	printing(&Q);

	printf("peek %d\n", peek(&Q) );
	printf("dequeued %d\n", dequeue(&Q) );


	return 0;
}

// Enqueue 10
// Enqueue 20
// Enqueue 30
// peek 10
// dequeued 10



//QUEUE WITH ARRAYS

//front -> 0  rear -> -1  size=0
//circular queue

#include<bits/stdc++.h>
using namespace std;

#define cap 5
//circular queue
typedef struct queue {
	int front;//index
	int rear;//index
	int size;
	int arr[cap];//static memeory allocation
} Queue;

void initilize(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
	Q->size = 0;
}
int isEmpty(Queue * Q ) {
	return Q->size == 0;
}

int isFull(Queue * Q ) {
	return Q->size == cap;
}

void enqueue(Queue * Q, int value) {
	if (isFull(Q)) {
		printf("Overflow");
		return;
	}
	//normal queue
	// Q->rear = Q->rear + 1;
	//for the circular queue
	Q->rear = (Q->rear + 1) % cap;//wrapping the last index to the first
	//will come back to the zero again
	Q->arr[Q->rear] = value;
	//deque then size decreaese
	Q->size++;
}
int dequeue(Queue * Q) {
	if (isEmpty(Q)) {
		printf("its empty");
		exit(1);
	}
	int ans = Q->arr[Q->front];
	Q->front = (Q->front + 1) % cap;//circular queue
	Q->size--;
	return ans;
}

int peek(Queue * Q) { //peeking through front
	if (isEmpty(Q)) {
		printf("Emtpy stack\n");
		return 0;
	}
	return Q->arr[Q->front];
}
void printing(Queue * Q) {
	//if the stack is empty i cannot print anything
	if (isEmpty(Q)) {
		printf("Emtpy stack\n");
		return ;
	}
	for (int i = 0; i < Q->size; ++i)
	{
		printf("%d ", Q->arr[(Q->front + i % cap)]);
	}
}

//there is nothing to free in the function because of the static array
int main() {
	Queue Q; initilize(&Q);//call by reference

	enqueue(&Q, 10);
	enqueue(&Q, 20);
	enqueue(&Q, 30);
	enqueue(&Q, 40);
	printing(&Q);
	printf("\nDequeued->%d\n", dequeue(&Q));
	printf("\npeek % d\n", peek(&Q));
	printing(&Q);
	return 0;
}




//CIRCULAR LINKED LIST==================================================================================================================


//LAST NEXT =HEAD
#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	struct node * next;
} Node;

Node * create_node(int value) {
	Node * new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
//METHOD 1 ----------
// void insert_at_beg(Node **head, int value) {
// 	Node *new_node = create_node(value);
// 	if (*head == NULL) {
// 		*head = new_node;
// 		new_node->next = *head;
// 	} else {
// 		new_node->next = (*head)->next;
// 		(*head)->next = new_node;
// 	}
// 	*head = new_node;
// }
// update the next pointers of the current head node and the last node to include the new node.

//METHOD 2------------
void insert_at_beg(Node ** head, int value) {
	Node *new_node = create_node(value);
	if (*head == NULL) {
		*head = new_node;
		//my head is the new node is created
		new_node->next = *head;//new_node =*head same thing
		return;
	}
	//if linked list has some nodes
	//current is acting as the last node
	Node* current = *head;
	while (current->next != *head) {
		current = current->next;
	}
	//updating the last node next pointer to point the new node
	current->next = new_node; //not to create the last node

	//update the next pointer of the new node to point to the current head
	new_node->next = *head;

	//update the head pointer to the point the new node
	*head = new_node;
}
void insert_at_end(Node ** head, int value ) {
	Node * new_node = create_node(value);
	if (*head == NULL) {
		*head = new_node;
		new_node->next = *head;
		return;
	}
	Node * current = *head;
	while (current->next != *head) {
		current = current->next;
	}
	current->next = new_node;
	new_node->next = *head;

}
void printing(Node * head) {
	if (head == NULL) {
		return;
	}
	Node *current = head;
	while (1) {
		printf("%d ", current->data);
		current = current->next;
		if (current == head) {
			break;
			//exiting the loop when we reach the head again
		}
	}
}
void insert_at_pos(Node ** head, int value, int index) {
	Node * new_node = create_node(value);
	Node * current = *head;
	int i = 0;
	while (i == index - 1 && current->next != *head) {
		current = current->next;
		i++;
	}
	new_node->next = current->next;
	current->next = new_node;

}
int main() {
	Node * head = NULL;
	insert_at_end(&head, 10);
	insert_at_end(&head, 20);
	insert_at_beg(&head, 30);
	insert_at_beg(&head, 40);
	insert_at_pos(&head, 70, 2);

	printing(head);
}
//When inserting at end, you need to link the last node's 'next' pointer to the new node, and then update the 'next'pointer of the new node to point back to the head



//DOUBLY CIRCULAR LINKED LIST==================================================================================================================
#include<bits/stdc++.h>
using namespace std;
typedef struct node {
	int data;
	struct node * next;
	struct node * prev;
} Node ;

Node * create_node (int value) {
	Node * new_node = (Node* )malloc ( sizeof(Node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = value;
	return new_node;
}
void insert_at_beg(Node ** head, int value) {
	Node * new_node = create_node(value);
	//cheking if the linked list is empty if empty then we are inserting the
	//first node
	if (*head == NULL) {
		*head = new_node; //as this the only node in the list
		//set the 'next' and 'prev' to point itself because of only node in the list
		new_node->next = new_node;
		new_node->prev = new_node;
		return;
	}
	//if the linked list is not empty containg the a node
	//find the last node of the list

	//1.create the last node next -> point to the * head -> prev
	Node * last_node = (*head)->prev;
	//give the first node address to the new_node
	new_node->next = *head;
	//point the address of the new_node to the current head prev
	(*head)->prev = new_node;
	//linking the new_node to the last node
	new_node->prev = last_node;
	//and also last node next should pointes to the new_node
	last_node->next = new_node;
	//make the head pointer to point to the first node which is new node
	*head = new_node;
}

void insert_at_end(Node ** head, int value) {
	//create a new node
	Node * new_node = create_node(value);
	//if the list is empty then we are inserting the first node
	if (*head == NULL) {
		*head = new_node;
		//since there is single node they are pointing to itself
		new_node->next = new_node;
		new_node->prev = new_node;
		return;
	}
	//list containg the single node
	//find the last node it should be point to the *head ->prev
	Node * last_node = (*head)->prev;
	//giving the address of the new_node to last node next
	//effectively inserting the node at the end
	last_node->next = new_node;
	//point the new_node  prevto the last node
	new_node->prev = last_node;
	//new_node next should point to the current head node
	new_node->next = *head;
	//update the *head prev to the new_node next which is last
	(*head)->prev = new_node;
}
void destroy_beg(Node ** head) {
	Node * current = *head;
	Node * last_node = (*head)->prev;
	// for the single node present in the list
	if ((*head)->next == *head) {
		*head = last_node = NULL;
		free(current);
	}
	// more than one node present in the list
	else {
		*head = (*head)->next;
		(*head)->prev = last_node;
		last_node->next = *head;
		free(current);
	}
}
void destroy_end(Node ** head) {
	Node * last_node = (*head)->prev;
	Node * current = last_node;
	// for the single node present in the list
	if ((*head)->next == *head) {
		*head = last_node = NULL;
		free(current);
	}
// more than one node present in the list
	last_node = last_node->prev;
	// last_node is pointing to the second last node
	// we will store the address of the first node
	last_node->next = (*head);
	(*head)->prev = last_node;
	free(current);
}
void destroy_pos(Node ** head, int pos ) {
	Node * current = *head;
	Node * last_node = (*head)->prev;
	int i = 1;
	while (i < pos) {
		current = current->next;
		i++;
	}
	// i am at pos =2
	current->prev->next = current->next;
	current->next->prev = current->prev;
	// the node which i want to delete is the last node pos
	if (current->next == *head) {
		last_node = current->prev;
		free(current);
	}
	else {
		free(current);
	}
}
void printing(Node * head) {
	Node * current = head;
	while (1) {
		printf("%d\n", current->data);
		current = current->next;
		if (current == head) {
			break;
		}
	}
}
int main() {
	Node * head = NULL;
	insert_at_beg(&head, 10);
	insert_at_beg(&head, 20);
	insert_at_beg(&head, 30);
	insert_at_end(&head, 50);
	insert_at_end(&head, 60);
	destroy_beg(&head);
	destroy_end(&head);
	destroy_pos(&head, 2);
	printing(head);
	return 0;
}
