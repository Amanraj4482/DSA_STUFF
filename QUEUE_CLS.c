//QUEUE WITH LINKED LIST 

#include<bits/stdc++.h>
using namespace std;

//front and rare should be null at the initial stage
//if am adding the first element then my front and rare becomes the first element]

//increamenting the rare part if enqueueing
typedef struct node {
	int data;
	struct node* next;
} _Node;

typedef struct queue {
	_Node * front;
	_Node * rear ;
} _Queue ;

void initilize(_Queue * Q) {
	Q->front = NULL;
	Q->rear = NULL;
}

int isEmpty(_Queue * Q) {
	return Q->front == NULL;
}

void enqueue(_Queue * Q, int value) {
	//no conditions to check
	//memory for the node
	_Node * new_node = (_Node *)malloc(sizeof(_Node));
	new_node->data = value;
	new_node->next = NULL;

	//two conditions
	if (isEmpty(Q)) {
		Q->front = new_node;
		Q->rear = new_node;
	}
	else {
		Q->rear->next = new_node;
		Q->rear = new_node;
	}
}

int dequeue(_Queue * Q) {
	if (isEmpty(Q)) {
		printf("Underflow");
		exit(1);
	}
	else {
		_Node * temp = Q->front; //temprory pointer for pointing at the first node
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

int peek(_Queue * Q) {
	//topmost element is front data part
	if (isEmpty(Q)) {
		printf("Empty Q");
		exit(1);
	}
	else {
		return Q->front->data;
	}
}


void printing(_Queue * Q) {
	if (isEmpty(Q)) {
		printf("Empty Q");
		return ;
	}
	_Node * current = Q->front;
	while (current != NULL) {
		printf("Enqueue %d\n", current->data);
		current = current->next;
	}
}

void destroy_stack(_Queue * Q) {
	_Node * current = Q->front;
	while (current != NULL) {
		_Node * temp = current;
		current = current->next;
		free(temp);
	}
	//because we don't have created the memory allocation for the _Queue part
	Q->front = NULL;
	Q->rear = NULL;
}
int main() {
	_Queue Q ;
	initilize(&Q);//call by reference

	enqueue(&Q, 10);
	enqueue(&Q, 20);
	enqueue(&Q, 30);

	printing(&Q);

	printf("peek %d\n", peek(&Q) );
	printf("dequeued %d\n", dequeue(&Q) );


	return 0;
}

Enqueue 10
Enqueue 20
Enqueue 30
peek 10
dequeued 10



//QUEUE WITH ARRAYS

//front -> 0  rear -> -1  size=0
#include<bits/stdc++.h>
using namespace std;

#define cap 100
//circular queue
typedef struct Queue {
	int front;
	int rear;
	int size;
	int arr[cap];//static memeory allocation
} __Queue;

void initilize(Queue* Q) {
	Q->front = 0;
	Q->rear = -1;
	Q->size = -1;
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
	Q->rear = (Q->rear + 1) % cap;
	Q->arr[Q->rear] = value;
	//deque then size decreaese
	Q->size++;
}
int main() {

	return 0;
}

