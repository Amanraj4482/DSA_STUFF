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
	//if the index is greater than the zero --------------
	int i = 2;
	while (i < pos) { /*(*head!NULL&&count<index-1)*/ //empty list
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
//delete whole node
        delete_whole(&head);

	printing(head);
}
// 50 60 40 10 20 30
//delete from beg=60 40 10 20 30
//delete from end=60 40 10 20
//delete form the pos=60 10 20
