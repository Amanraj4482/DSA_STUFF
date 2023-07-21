

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

//inserting the new node to the beg
void insert_at_beg(struct node** head, int value) {
//create a new node
	struct node* new_node = create_node(value);
	new_node->next = *head;
	*head = new_node;
}
void insert_at_end(struct node** head, int value) {
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
	current->next = new_node;//forward most link has been updated
	new_node->prev = current;//updating the new_node -> prev will be the current
	current = new_node;

}
void printing(struct node* head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}
int main() {
	struct node* head = NULL;
	insert_at_beg(&head, 23);
	insert_at_end(&head, 19);
	insert_at_end(&head, 21);
	insert_at_end(&head, 22);
	printing(head);
	return 0;
}
