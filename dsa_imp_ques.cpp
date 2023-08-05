1.Write a program to explain all the operation of list which include searching of element reversinng the string?

#include<bits/stdc++.h>
using namespace std;
#define n 5
void displayList(int arr[], int size) {
	for (int i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}


int searching(int arr[], int size, int search) {
	for (int i = 0; i < size; ++i)
	{
		if (search == arr[i]) {
			return i;
		}
	}
	// if not found then return -1
	return -1;
}

void reverseList(int arr[] , int size) {
	int i = 0, j = size - 1;
	while (i < j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++; j--;
	}
}
int main() {
// creating an array
	int arr[n] = {1, 2, 3, 4, 5};
// display the original list
	displayList(arr, n);
	printf("\n");

// search for an element in the list
	int search = 3;
	int index = searching(arr, n, search);
	if (index != -1) {
		printf("%d found at index %d \n" , search , index);
	}
	else {
		printf("%d not found int the list.\n ", search);
	}

	// Reverse the list
	reverseList(arr, n);
	displayList(arr, n);

	return 0;
}

1 2 3 4 5
3 found at index 2
5 4 3 2 1


2. Write a program array the element of array in assending and desecending order? in


using the bubble sort algorithm to sort in asceding and desending order


#include<bits/stdc++.h>
using namespace std;
void bubbleAscending(int arr[], int size) {
	int temp;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] > arr[j + 1]) {
				// swap the element if they are in wrong order
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void bubbleDecending(int arr[], int size) {
	int temp;
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			if (arr[j] < arr[j + 1]) {
				// swap the element if they are in wrong order
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void printing(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}
int main() {
	int arr[] = {1, 3, 5, 6, 2, 8, 7};
	int size = sizeof(arr) / 4;
	printing(arr, size);
	bubbleAscending(arr, size);
	printing(arr, size);
	bubbleDecending(arr, size);
	printing(arr, size);
	return 0;
}
1 3 5 6 2 8 7
1 2 3 5 6 7 8
8 7 6 5 3 2 1
