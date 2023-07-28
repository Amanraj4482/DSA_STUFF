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

