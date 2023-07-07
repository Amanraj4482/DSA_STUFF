#include<stdio.h>
#include<stdlib.h>
struct node {
	int data;
	struct node *next;
};
struct node*creating_node(int value) {
	struct node* new_node = (struct node*)malloc (sizeof(struct node));
	new_node->data = value;
	new_node->next = NULL;
	return new_node;
}
void add_at_end(struct node**head , int value) {
	struct node* new_node = creating_node(value);
	if (*head == NULL) {
		*head = new_node;
		return;
	}
	//2nd case having element inside the node
	struct node* current = *head; //this is also poiting the head
	while (current->next != NULL) {
		current = current->next;//for finding the null part
	}
	current->next = new_node;
}
void add_at_beg(struct node** head, int value) {
	struct node* new_node = creating_node(value);
	new_node->next = *head;//address of the first node or head pointer address
	*head = new_node;//pointing the head to the new_node
}
void add_at_pos(struct node **head, int value, int pos) {
	struct node* new_node = creating_node(value);
	struct node* current = *head;//traversal
	int i = 2;
	while (i < pos) {
		current = current->next;
		i++;
	}//extablish right most link
	new_node->next = current->next;
	current->next = new_node;
}
void printing(struct node* head) {
	struct node*current = head;
	while (current != NULL) {//this loop is for the traversal of list
		printf("%d ", current->data);
		current = current->next;
	}
}
int main() {
	struct node* head = NULL;
	creating_node(10);
	//add at the end
	add_at_end(&head, 20);
	add_at_end(&head, 30);
	add_at_end(&head, 40);

	// adding at the beginning
	add_at_beg(&head, 50);

	//adding at the specific pos
	int data = 60; int pos = 3;
	add_at_pos(&head, data, pos);

	//printing the data
	printing(head);

}
//50 20 60 30 40
