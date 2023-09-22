#include <bits/stdc++.h>
using namespace std;

#define maxi 100
struct Node {
  int data;
  struct Node * left,*right;
};

struct Node * create_node (int data){
  struct Node * new_node = (struct  Node * )malloc(sizeof(struct Node ));
  new_node->data= data;
  new_node->left = new_node->right = NULL;
  return new_node;
}

void iniArray(int arr[],int n ){
  for(int i =0 ;i<n;i++){
    arr[i]=-1; // represent the empty node 
}
}
void insertArray(int arr[] , int n , int data, int index){
  if(index < n) arr[index] = data;
} 
void printArray(int arr[],int n ){
  for(int i=0;i<n;i++){
    if(arr[i]!=-1) printf("%d ",arr[i]); //-1 represent the empty Node
    else printf(" -");
    
  }
  printf("\n");
}

int main() 
{
  // int bt{size,-1};
    int bt[maxi];
    int size= 0; //current size of the array 
    iniArray(bt,maxi);
    struct Node * root  = create_node(1);
    root->left= create_node(2);
    root->right= create_node(3);
    root->left ->left= create_node(4);
    root->left->right =create_node(5);
    root->right ->left= create_node(6);
    root->right->right =create_node(7);
    
    insertArray(bt,maxi, root->data, size++);
    insertArray(bt,maxi,  root->left->data, size++);
    insertArray(bt,maxi,root->right->data, size++);
    insertArray(bt,maxi,  root->left->left->data, size++);
    insertArray(bt,maxi, root->left->right->data, size++);
    insertArray(bt,maxi,  root->right ->left->data, size++);
    insertArray(bt,maxi,  root->right->right->data, size++);
    
    
    
    printArray(bt,size);
    
    
    return 0;
}
