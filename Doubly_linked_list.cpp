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
void printing(struct node* head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d\n", current->data);
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
	printing(head);
	return 0;
}

