//doubly linked list

#include<bits/stdc++.h>
using namespace std;

//for the doubly linked list just add one more prev node
struct node {
	int data;
	struct node* prev;
	struct node* next;
};
//creatin a node
struct node* create_node(int value) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;
	return new_node;
}

void insert_at_beg(struct node** head, int value) {
//create a new node
	struct node* new_node = create_node(value);
	new_node->next = *head;
	*head = new_node;
}
void insert_at_end(struct node** head, struct node** tail, int value) {
	struct node* new_node = create_node(value);
	if (*head == NULL) {
		*tail = * head = new_node; //head poiting to the new_node
		return;
	}
	(*tail)->next = new_node;
	new_node->prev = *tail;
	*tail = new_node;
}

void insert_at_pos(struct node** head, struct node** tail, int value, int index) {
	struct node* new_node = create_node(value);
	struct node* current = *head;
	int i = 0;
	while (i < index - 1) {
		current = current->next;
		i++;
	}
	//i have the index at 2
	new_node->prev = current;
	new_node->next = current->next;
	current->next = new_node;
	new_node->next->prev = new_node;
}

//THERE IS MISTAKE IN THIS CODE IT'S PRINING THE FIRST NODE DATA
void reverse(struct node** head, struct node** tail) {
//swapping the prev and next value of the current node
	struct node* current = *head;
	struct node* next_node;
	while (current != NULL) {
		next_node = current->next;//next_node is pointing just after the current node
		current->next = current->prev;
		current->prev = next_node;
		current = next_node;
	}
	current = *head; 	//current pointing to the head
	*head = *tail; 		//head points to the tail
	*tail = current; 	//tail points to the head


	//REVERSE PRINTING OF THE DOUBLLY LINKED LIST
	// struct node* temp = *tail;
	// while (temp != NULL) {
	// 	printf("%d ", temp->data);
	// 	temp = temp->prev;
	// }
}

void printing(struct node* head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
}
int main() {
	struct node* head  = NULL;
	struct node* tail = NULL;
	insert_at_end(&head, &tail, 19);
	insert_at_end(&head, &tail, 20);
	insert_at_end(&head, &tail, 21);
	insert_at_beg(&head,  22);
	insert_at_beg(&head,  24);

	int index = 2;
	insert_at_pos(&head, &tail, 60, index);
	reverse(&head, &tail);
	printing(head);
	return 0;
}

//24 22 60 19 20 21 without reversing
// 21 20 19 60 22	with reversing

