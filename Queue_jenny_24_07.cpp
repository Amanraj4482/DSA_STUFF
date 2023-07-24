//what is queue?
//stack was =>last in first out_
//queue is =>first in first out_
//Rule-> Insertion => (rear)tail(right)(top) => enqueue  | push (stack)
//Rule-> Deletion  => (head)front(left)=> Dequeue  | pop(stack)
//Rule-> front/peek to see the element without removing it~
//is full & if empty~

//rear= max capacity -1
//queue has two open ends,where as in stack there only one open end


//nothing in the queue then front/ rear=-1 => for the empty queue

//when we (enqueue =2) then front/rear++ then front and rear both pointing to the 0 index
//for inserting the data we will not move the front
// inserting will be always from the rear part and will be move the rear variable
//again inserting the 10 i.e~ enqueue  the rear++ , then rear=-1
//dequeue =>(front++)



//overflow when we try to insert the data more than its capacity
//underflow when we try to dequeue the data which is empty

//the connections of 5 pc's with the one printer
//all the request and commnads given to the printer will be saved as queue


//Queue can be implemented using the stack , linked list , array

//---------------------------------------
//front->(DELETION)		(INSERTION)<-rear
//---------------------------------------


//FIFO  => FIRST IN FIRST OUT

//OPERATIONS ON QUEUE

#include<bits/stdc++.h>
using namespace std;
//the blueprint of the queue
#define max 100
struct Queue {
	int front;
	int capacity;
	int rear;
	int *arrQ;//this is the pointer it will point where my array is
};

//creating a Queue
struct Queue* create_queue(int _capacity) {
	struct Queue* new_queue = (struct Queue*)malloc(sizeof(struct Queue));
	new_queue-> front = -1;
	new_queue-> rear = -1;
	new_queue->capacity = max;
	new_queue->arrQ = (int*)malloc(new_queue->capacity * (sizeof(4)));;
	return new_queue;
}
int isFull(struct Queue* new_queue) {
	return new_queue-> rear == new_queue->capacity - 1;
}
void enqueue(struct Queue * new_queue, int value) {

	if (isFull(new_queue)) {
		printf("There is overflow\n");
		return ;
	}
	else if (new_queue->front == -1 && new_queue->rear == -1) {
		new_queue->front = new_queue->rear = 0;
		new_queue->arrQ[new_queue->rear] = value;
	}
	else {//queue has some data and i want to insert
		//insert from the rear end
		new_queue->arrQ[++new_queue->rear] = value;
	}
}
int isEmpty(struct Queue* new_queue) {
	return new_queue->rear == -1 && new_queue->front == -1;
}

int dequeue(struct Queue* new_queue) {
	if (isEmpty(new_queue)) {
		printf("This is Empty");
		return 0;
	}
	else if (new_queue->front == new_queue-> rear) {
		//when front and rear are pointing on the same index
		//then there is only one element in the whole queue
		//after deleting the element queue will be empty
		new_queue-> front = new_queue->rear = -1;
	}
	//queue is not empty more than 1 elements are present
	//the dequeued element from the queue is
	printf("dequeued=> 	%d\n", new_queue->arrQ[new_queue->front]);
	return new_queue->front++;
}

void printing(struct Queue* new_queue) {
	if (isEmpty(new_queue)) {
		printf("Cannot print its empty\n");
		return;
	}
	int i;
	for (i = new_queue->front; i <= new_queue->rear; i++) {
		printf("Enqueue=> 	%d\n", new_queue->arrQ[i]);
	}
}
void peek(struct Queue* new_queue) {
	if (isEmpty(new_queue)) {
		printf("Empty");
		return;
	}
	printf("Peek=> 		%d\n", new_queue->arrQ[new_queue->front]);

}
int main() {
	struct Queue* new_queue = create_queue(max);
	enqueue(new_queue, 2);
	enqueue(new_queue, 3);
	enqueue(new_queue, 4);
	enqueue(new_queue, 5);

	printing(new_queue);

	peek(new_queue);//front or leftmost value present

	dequeue(new_queue);

	peek(new_queue);//front or leftmost value present

	printing(new_queue);
	return 0;
}
//(rear+1)%capacity=>0  for the circular queue




