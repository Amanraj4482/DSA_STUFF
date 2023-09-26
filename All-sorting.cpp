// 9 8 7 2 5 1 5

#include<bits/stdc++.h>
using namespace std;

//----------------------------------------------------------------------------------
// BUBBLE SORT => next two adjacent elements are to be compared
// it they are not sorted then make sorting
void bubble_sorting() {
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	for (int i = 0; i < n - 1 ; ++i) // n - 1 because the last element is not compared with any
	{
		for (int j = i; j < n  ; ++j)
		{
			if (v[i] > v[j]) {
				swap(v[i], v[j]);
			}
		}
	}
	for (auto i : v) {
		cout << i << " ";
	}
}

//---------------------------------------------------------------------------------------------
// SELECTION SORT:
// Approach: Selection Sort divides the array into two parts: the sorted part and the unsorted part.
// In each iteration, it finds the smallest (or largest) element from the unsorted part and swaps it with the element at the beginning of the unsorted part.
// Key Idea: It repeatedly selects the smallest (or largest) element and places it in the sorted part.
void selection_sorting() {
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int min = 0;
	for (int i = 0; i < n - 1 ; ++i) // n - 1 because the last element is not compared with any
	{
		min = i;
		for (int j = i; j < n  ; ++j) //unsorted subarray
		{
			if (v[min] > v[j]) {
				swap(v[i], v[j]);
			}
		}
	}
	for (auto i : v) {
		cout << i << " ";
	}
}
//-----------------------------------------------------------------------------
// INSERTION SORT => check for the sorted .. take one value from unsored part
// taking 1 varible as sorted part
// find the index for that and insert that element

// left -> sorted part (--1 loop)
// right -> sorted part (++1 loop)

//single element should be considered as the sorted part
void insertion_sorting() {
	int n; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	// skip the sorted single a[0] part of the array
	for (int i = 1; i < n; ++i) {             // increment for the unsorted value
		// we store the element which need to give the right place
		int key = v[i], j = i - 1;        // i=1 , j=0
		while (j >= 0 && v[j] > key) {    // decrement for the sorted value  //2nd element is greater than the current j elemnet
			v[j + 1] = v[j];        //shift the greater element front
			j--;
		}
		v[j + 1] = key; // i = 1
	}
	for (auto i : v) {
		cout << i << " ";
	}
}

/*-------------------------------------------------------------------------------*/
// QUICK SORT : choose the pivot element can be first or last / or any random element
// pivot = first element ... based on the divide and conquer technique [partion]
// left side elements < pivot < right side elements
// if less than the pivot the s++ ,  if greater than or equal then e--

int partition(vector<int> &v, int s, int e) {
	int pivot = v[s]; // Choose the first element as the pivot
	int i = s + 1; // Index for elements less than or equal to pivot

	for (int j = s + 1 ; j <= e; ++j) {
		if (v[j] <= pivot) {
			swap(v[i], v[j]);
			i++;
		}
	}
	// Place pivot in its correct position
	swap(v[s], v[i - 1]);
	return i - 1;
}
void quick_sort2(vector<int>&v , int s, int e) {
	if (s < e) {
		int pivot_index = partition(v, s, e);
		// sort the subarray
		quick_sort2(v, s, pivot_index - 1);
		quick_sort2(v, pivot_index + 1, e);
	}
}
void quick_sort1() {
	int n ; cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int s = 0, e = n - 1;
	quick_sort2(v, s, e);
	for (auto i : v) {
		cout << i << " ";
	}

}
/*-------------------------------------------------------------*/

void merge(vector<int>&v, int l , int h , int mid) {
	int k = 0;
	int left = l;
	int right = mid + 1;
	vector<int> temp(h - l + 1);
	while (left <= mid && right <= h) {
		if (v[left] <= v[right]) {
			temp[k++] = v[left++];
			/*temp.push_back(left++);*/
		}
		else {
			temp[k++] = v[right++];
		}
	}
	while (left <= mid) {
		temp[k++] = v[left++];
	}
	while (right <= h) {
		temp[k++] = v[right++];
	}
	for (int i = l; i <= h; ++i)
	{
		v[i] = temp[i - l];
	}
}
void merge_sort(vector<int>&v, int l  , int h) {
	if (l == h) return ;
	int mid = /*l + (h - l) / 2;*/ (l + h) / 2;
	merge_sort(v, l, mid);
	merge_sort(v, mid + 1, h);
	merge(v, l, h, mid);
}
void merge_sort1() {
	int n ; cin >> n;
	vector<int >v(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}
	int l = 0 , h = n - 1 ;
	merge_sort(v, l, h);
	for (auto i : v)cout << i << " ";
}
int main() {

	// bubble_sorting();
	// selection_sorting();
	// insertion_sorting();
	// insertion_sorting();
	// quick_sort1();
	merge_sort1();


	return 0;
}

