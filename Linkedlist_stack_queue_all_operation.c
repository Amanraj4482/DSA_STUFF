//_______________________LINKED LIST______________________--

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
	int data;
	struct node * next;
} Node;

Node * create_node(int value) {
	Node * new_node = (Node * )malloc ( sizeof ( Node ));
	new_node->data = value;
	new_node-> next = NULL;
	return new_node;
}

void insert_at_beg(Node ** head, int value) {
	Node * new_node = create_node(value);
	new_node-> next = *head;
	*head = new_node;
}

void insert_at_end(Node ** head, int value) {
	Node * new_node = create_node(value);
	if (*head == NULL) {
		*head = new_node;
		return ;
	}
	Node * current = *head;
	while (current-> next != NULL) {
		current = current-> next;
	}
	current->next = new_node;
}

void insert_at_pos(Node **head, int value, int pos) {
	if (pos < 0) return ;
	if (pos < 0) {
		insert_at_beg(head, value);
		return;
	}
	Node * new_node = create_node(value);
	Node * current = *head;
	int i = 0;
	while (i < pos - 1) {
		current = current->next;
		i++;
	}
	new_node->next = current->next;
	current->next = new_node;
}
void printing(Node * head) {
	if (head == NULL) {
		printf("Empty Node ");
		return;
	}
	Node * current = head;
	while (current != NULL) {
		printf("%d " , current->data);
		current = current->next;
	}
}
void delete_beg(Node **head) {
	if (*head == NULL) {
		printf("List is empty");
		return  ;
	}
	Node * current = *head;
	*head = current->next;
	free(current);
}
void delete_end(Node ** head) {
	Node * current = *head;
	while (current->next->next != NULL) {
		current = current->next;
	}
	if (current == *head) {
		*head = NULL;
		free(current);
		return ;
	}
}
void delete_whole(Node **head){
	Node * current=*head;
	while(current!=NULL){
		current=current->next;
		free(*head);
		*head=current;

	}
}
int main() {
	Node * head = NULL;
	insert_at_beg(&head, 10);
	insert_at_end(&head, 30);
	insert_at_end(&head, 40);
	insert_at_beg(&head, 20);
	delete_beg(&head);
	insert_at_pos(&head, 23, 2);
	delete_end(&head);
	printing(head);
	return 0;
}

// 20 10 23 30 40



//_________________________ STACK USING THE ARRAY ________________________
// last in first out

#include<bits/stdc++.h>
using namespace std;

typedef struct stack {
	int top;
	int capacity;
	int * arr;
} Stack ;

//creating the stack of type struct stack
Stack * create_stack(int _capacity) {
	//creating a new stack
	Stack *new_stack = (Stack *)malloc( sizeof(Stack));
	new_stack->capacity = _capacity;
	new_stack->top = -1;
	new_stack->arr = (int* )malloc(sizeof(4));
	return new_stack;
}
int isFull(Stack * new_stack) {
	return new_stack->top == new_stack->capacity - 1; //due to the indexing of the top
}
int isEmpty(Stack * new_stack) {
	return new_stack->top == -1;
}

void push(Stack * new_stack, int value) {
	//checking is it full
	if (isFull(new_stack)) {
		printf("full stack ");
		return;
	}
	//by accesing the array
	new_stack->arr[++new_stack->top] = value;
	//first increase the index of the top and then put the value of the array that has to be increased
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
int peek(Stack * new_stack) {
	//checking is it empty
	if (isEmpty(new_stack)) {
		printf("empty stack ");
		return 0;
	}
	//pop out thing the top to the second last element then removing the last one
	return new_stack->arr[new_stack->top];
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
	Stack * new_stack = stack(100);
	push(new_stack, 10);
	push(new_stack, 20);
	push(new_stack, 30);
	push(new_stack, 40);
	pop(new_stack);
	printing(new_stack);
	return 0;
}



// ________________________________STACK USING THE LINKED LIST______________


#include<bits/stdc++.h>
using namespace std;

typedef struct node {
	int data;
	struct node * next;
} Node ;

typedef struct stack {
	Node * top ;
} Stack;

//creating a node
Node * creating_node(int value) {
	Node * new_node = (Node * )malloc(sizeof(Node));
	new_node->next = NULL;
	new_node->data = value;
	return new_node;
}

//creating a struct
Stack * creating_stack() {
	Stack * new_stack = (Stack * )malloc(sizeof(Stack));
	new_stack->top = NULL;
	return new_stack;
}

int isEmpty(Stack * new_stack) {
	return new_stack->top == NULL;
}

void push_beg(Stack *new_stack, int value) {
	//creating a node
	Node * new_node = creating_node(value);
	new_node->next = new_stack->top;
	//giving the add of the last node to the first node that is up node
	// the address of the last node is contained by the stack->top
	new_stack->top = new_node;
	// and then update the address of the top and give the address of the new_node
}
int pop(Stack * new_stack) {
	// checking the empty
	if (isEmpty(new_stack)) {
		printf(" Stack is empty");
		return 0;
	}
	// traversal is needed
	Node * temp = new_stack->top;
	int data = temp->data;
	new_stack->top = new_stack->top->next;
	free(temp);
	return data;
	//giving the addres of the last second to the last
}
int peek(Stack * new_stack) {
	// checking the empty
	if (isEmpty(new_stack)) {
		printf(" Stack is empty");
		return 0;
	}
	return new_stack->top->data;
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
	Stack * new_stack = creating_stack();
	push_beg(new_stack, 10);
	push_beg(new_stack, 20);
	push_beg(new_stack, 30);
	push_beg(new_stack, 40);

	printing(new_stack);

	printf("pop-> %d\n ", pop(new_stack));
	printf("\npeek-> %d\n ", peek(new_stack));

	printing(new_stack);
	return 0;
}




// ____________________________INFIX TO POSTFIX___________________________________

#include<bits/stdc++.h>
using namespace std;
#define max 100

typedef struct stack {
	int capacity;
	int top;//index of the top element in the stack
	char * arr;//A pointer to a character array that will be used to store the elements of the stack
} Stack ;

//creating a stack
Stack * create_stack(int capacity) {
	Stack * new_stack = (Stack * )malloc(sizeof(Stack));
	new_stack->capacity = capacity;
	new_stack->top = -1 ; // indicating the empty stack
	// dynamic allocation of the array
	new_stack->arr = (char*)malloc(new_stack->capacity * sizeof(char));
	return new_stack;
}

int isFull(Stack * new_stack) {
	return new_stack->top == new_stack->capacity - 1;
	// the top element is at maximum capacity
}

int isEmpty(Stack * new_stack) {
	return new_stack->top == -1;
}
void push(Stack * new_stack, char value) {
	if (isFull(new_stack)) {
		printf("Stack is full\n");
		return;
	}
	new_stack->arr[++new_stack->top] = value;
	// increamenting the top and assigning the value to the arr[top]
	// the top element is returned , and the 'top' is decremented to point to th next element
}

char pop(Stack * new_stack) {
// The 'pop' function is used to remove and return the top element from the stack
	if (isEmpty(new_stack)) {
		printf("Stack is empty\n");
		return '\0' ;
	}
	return new_stack->arr[new_stack->top--];
}

char peek(Stack * new_stack) {
// The 'pop' function is used to remove and return the top element from the stack
	if (isEmpty(new_stack)) {
		printf("Stack is empty\n");
		return '\0' ;
	}
	return new_stack->arr[new_stack->top];
}
int isOperand(char ch ) {
	return isalnum(ch);
	//  if the char is alphanumeric returns 1 otherwise 0
}

int precedence( char op) {
	switch (op) {
	case'+':
	case'-':
		return 1;
	case'*':
	case'/':
	case'%':
		return 2;
	case'^':
		return 3;
	}
	return -1;
}

void infixtoPostfix(const char* infix, char * postfix) {
	// postfix=>a pointer to  an empty character array where th postfix expression will be stored

	// creation  of a new stack with the capacity max
	Stack * new_stack = create_stack(max);
	int i , j = 0 ;
	// i=> traverse the infix expression
	// j=> is used to store the characters in the postfix expression
	char ch, x;
	for (i = 0; infix[i] != '\0'; i++)
		// iterate through each character of the infix expression
	{
		ch = infix[i]; // the current character is store in the varible ch

		//checking the operand or not

		if (isOperand(ch)) {
			postfix[j++] = ch;
			// if it is and operand then the character is directly added to the postfix
			// and j is increamented to point the next position in the postfix array
		}

		else if (ch == '(') {
			push(new_stack, ch); // if it is open then pussed to the stack
		}

		else if (ch == ')') {
			while ((x = pop(new_stack)) != '(') {
				postfix[j++] = x;
				// if the current char is a closing parenthesis
				// if it is a loop is entered which continues until the openting parenthesis is encounted in the stack
				// during the each iteration of the loop character are popped through the stack and added to the postfix expression intil and opening parenthesis is encountred
				// the opening parenthesis is not added to the postfix expression
			}
		}

		else {

			while (!isEmpty(new_stack) && precedence(ch) <= precedence(peek(new_stack))) {
				postfix[j++] = pop(new_stack);
			}
			push(new_stack, ch);
			//  if the current char is operator the else block is executed
			// in this block a loop is entered until the stack is not empty and also check
			// the precedance of the current operator ch is less than or equal to the precedence of the top operator in the stack
			// for the checking purpose we are using the peek
			// during the each iteration of the loop operators are popeed from the stack and added to the posfix expression until above condition is not longer true

			// after the loop ends the current char ch is pussed into the stack
		}
	}
	while (!isEmpty(new_stack)) {
		postfix[j++] = pop(new_stack);
	}
	// after processing all characters in the infix expression, a final loop is used to to pop any remaining operators from the stack and add them to the posfix expression

	postfix[j] = '\0';
	// The postfix expression is terminated with a null char to mark the end of the string


	// the dynamic allocated memory for the new_stack and char arr
	// free(new_stack->arr);
	// free(new_stack);
	// the stack are freed to avoid the memory leaks

}

int evaluatePostfix(char * postfix) {
	Stack * new_stack = create_stack(max);
	int i , val_1 , val_2 , result;
	// val_1 and val_2 is stored value popped from the stack during the evalution
	char ch;
	// A char variable used to store each char of the postfix of the posfix expression during iteration

	for (int i = 0 ; postfix[i] != '\0'; i++) {
		ch = postfix[i]; // iterate through the each char of the postfix

		if (isdigit(ch)) {
			//if it s digit it means it is an operand (these are the char ) so converting the chars into the integrers by substracting the value '0'
			push(new_stack, ch - '0');
			// checking the current is digit using the isdigit
			// if it is digit, it is converted to and integer and pushed onto the new_stack using the push function
		}
		else {
			// if the current char is not digit it means it is operator
			// two operands are popped from the stack using the pop function to perform the operation
			val_1 = pop (new_stack);
			val_2 = pop (new_stack);
			switch  (ch) {
			case '+':
				result = val_2 + val_1;
				break;

			case '-':
				result = val_2 - val_1;
				break;

			case '*':
				result = val_2 * val_1;
				break;

			case '/':
				result = val_2 / val_1;
				break;

			case '%':
				result = val_2 % val_1;
				break;

			case '^':
				result = pow((double)val_2, (double)val_1);
				break;

			default :
				printf("invalid operator\n");
			}
			push(new_stack, result);
			// the result is pussed back into the stack
		}
	}
	// after for loop has processed all the characters in the posfix expression, the final result of the expression reamisn at the top of the stack
	// this result is obtained by popping it from the strack using the pop fxn
	// the result is then returned representing the final evalution of the postfix expression
	result = pop(new_stack);
	return result;
}
int main() {
	char infix[max], postfix[max];

	// fgets(infix, sizeof(infix), stdin);
	// int len = strlen(infix);
	// infix[len - 1] = '\0'; // Replace the newline character with '\0'
	gets(infix);

	infixtoPostfix(infix, postfix);

	printf("%s \n", postfix);

	printf("Solution = %d\n", evaluatePostfix(postfix));

	return 0;
}

// (5 + 3) * 2 - 9 / 3
// 53+2*93/-

// Solution = 13



// _______________________________QUEUE WITH LINKED LIST___________________________

#include<bits/stdc++.h>
using namespace std;

typedef struct node {
	int data;
	struct node * next;
} Node;

typedef struct queue {
	Node * front;
	Node * rear;
} Queue;

//direct initilization of the queue
void initilize(Queue * Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

int isEmpty(Queue * Q) {
	// to check the null we should the check that front null or not
	return Q->front == NULL;
}

void enqueue(Queue * Q, int value) {
	//creation of node
	Node * new_node = (Node *)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;


	//there are two condition either empty queue or there is something in the queue
	if (isEmpty(Q)) {
		// pointing the front and rear to the new_node because it is the first node
		Q->front = new_node;
		Q->rear = new_node;
	}
	// otherwise the new_node is added to the end of the queue pointed by the rear
	// and rear is updated to point to the new node
	else {
		Q->rear->next = new_node;
		Q->rear = new_node;
	}

}

int dequeue(Queue * Q) {
	// it remove and return the front element of the queue
	if (isEmpty(Q)) {
		printf("Queue is empty");
		return 0;
	}
	// it removes the front node from the queue and stores the data in data
	// and frees the memory of the removed node.
	// if the queue becomes empty after dequeuing the element both front and rear are set to null
	else {
		Node * temp = Q-> front;
		int data = temp->data;
		Q->front = Q->front ->next;// the front pointer of the queue is updated to point the next node
		free(temp);

		// after removing the front node we need to check if the queue has becomme empty
		// if the front pointer become null it means there are no elemets left in the queue
		// in this case the rear pointer should also be set to the null to indicate and empty queue
		if (Q->front == NULL) {
			Q->rear = NULL;
		}
		return data;
	}
}

int peek(Queue * Q) {
	if (isEmpty(Q)) {
		printf("Empty Q");
		exit(1);
	}
	else {
		return Q->front->data;
	}
}

void printing (Queue * Q) {
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
void destroy_stack(Queue* Q) {
	Node* current = Q->front;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		free(temp);
	}
	Q->front = NULL;
	Q->rear = NULL;
}

int main() {
	Queue Q;
	initilize(&Q);

	enqueue(&Q, 10);
	enqueue(&Q, 20);
	enqueue(&Q, 30);

	printing(&Q);

	printf("peek %d\n", peek(&Q));
	printf("dequeued %d\n", dequeue(&Q));

	return 0;
}
//(current->next!=NULL)=>(meaning) This condition is commonly used to traverse a linked list up to the second-to-last element,
// as current will be pointing to the last element when the loop ends.



// __________________QUEUE WITH ARRAY____________


#include<bits/stdc++.h>
using namespace std;

#define cap 5

typedef struct queue {
	int front ; // index of the front element of the queue
	int rear ; // index of the rear element of the queue
	int size ; // current size of the queue
	int arr[cap];
} Queue;

void initilize (Queue * Q) {
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

void enqueue (Queue * Q , int value) {
	if (isFull(Q)) {
		printf("overflow");
		return ;
	}
	Q->rear = (Q->rear + 1) % cap; //to handle circular movement
	// and assigns the value to the array at the updated rear index
	Q->arr[Q->rear] = value;
	Q->size++;
	// it also increments the size to keep track of the number of elements in the queue
}

int dequeue(Queue * Q) {
	if ( isEmpty(Q)) {
		printf("its empty");
		exit(1);
	}
	// storing the front element in the ans
	int ans = Q->arr[Q->front];
	Q->front = (Q->front + 1) % cap;
	Q->size--;
	return ans;
}
int peek(Queue * Q) { //peeking through front
	if (isEmpty(Q)) {
		printf("Emtpy stack\n");
		return 0;
	}
	return Q->arr[Q->front];
	// returns the element at the front index of the array.
}

void printing (Queue * Q) {
	if (isEmpty(Q)) {
		printf("Empty Stack\n");
		return ;
	}
	for (int i = 0; i < Q->size ; ++i) {
		printf("%d ", Q->arr[Q->front + i % cap]);
	}
}

int main() {
	Queue Q;
	initilize(&Q);
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


//_________________________________ CIRCULAR LINKED LIST_______________________

#include<bits/stdc++.h>
using namespace std;


typedef struct node {
	int data;
	struct node * next;
} Node;

// creating a node
Node * create_node (int value) {
	Node * new_node = (Node* )malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}

void insert_at_beg(Node **head , int value) {
	Node *new_node = create_node(value);
	if (*head == NULL) {
		*head = new_node;// the new_node becomes the head node
		new_node->next = *head;// and it's head pointer is set to point itself
		return;
	}
	// traversing the list to find the last node(whose next points to the head)
	// and updates its next pointer to point to the new node
	// then it updates then the new node's next pointer to point the current head
	// and updates the head pointer to the new node
	Node * current = *head;
	while (current->next != *head) {
		current = current->next;
	}
	current->next = new_node;
	new_node->next = *head;
	*head = new_node;
}

void insert_at_end(Node **head, int value) {
	Node * new_node = create_node( value );
	if (*head == NULL) {
		*head = new_node;// the new node becomes the head node
		new_node->next = *head;// its next pointer is set to points itself
		return;
	}
	// traversing the list to find the last node(whose next points to the head)
	// and updates its next pointer to point to the new node

	// which means the loop will traverse the entire linked list and stop when it reaches the last node.
	Node * current = *head;
	while (current->next != *head) {
		current = current->next;
	}
	// When the loop exits it means current is pointing to the last node of the circular linked list
	// the next pointer of the last node current->next is updated to point to new node, making the new node the new last node of the linked list.
	// Additionaly the next pointer of the new node is set to point to the *head making the linked list cirulcar the last node points back to the hed , forming a circular structure.

	// this function inserts a new node with the given value at the end of a circular linked list.
	//If the list is empty, it creates a new circular linked list with a single node. If the list is not empty
	// it traverses the list to find the last node and then adds the new node after it, making the list circular.
	current->next = new_node;
	new_node->next = *head;
}
void insert_at_pos(Node ** head, int value, int index) {
	Node * new_node = create_node(value);
	Node * current = *head;
	int i = 0;
	while (i == index - 1 && current->next != *head) {
		// reaches the node before hte desired position
		current = current->next;
		i++;
	}
	new_node->next = current->next;
	// it updated the new node's next pointer to point to the node at the desired position
	// i.e current->next and updates the previous node's next pointer to point to the new node.
	current->next = new_node;
}
void printing(Node *head ) {
	if (head == NULL) {
		return;
	}
	Node * current = head;
	while (1) {
		printf("%d ", current->data);
		current = current->next;
		if (current == head) {
			break;
			// existing the loop when we reach the head again
		}
	}
}
int main() {
	Node * head = NULL;
	insert_at_end(&head, 10);
	insert_at_end(&head, 20);
	insert_at_beg(&head, 30);
	insert_at_beg(&head, 40);
	insert_at_pos(&head, 70, 2);
	printing(head);
	return 0;
}



// ________________________________DOUBLY CIRCULAR LINKED LIST__________________________________

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
	printing(head);
	return 0;
}
