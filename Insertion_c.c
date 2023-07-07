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
	struct node* new_node = create_node(value);
	struct node* current = *head;
	int i = 2;
	while (i < pos) {
		current = current->next;
		i++;
	}
	new_node->next = current->next;
	current->next = new_node;
}
void printing(struct node *head) {
	struct node* current = head;
	while (current != NULL) {
		printf("%d ", current->data);
		current = current->next;
	}
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

	printing(head);
}
// 50 60 40 10 20 30
