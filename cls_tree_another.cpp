#include <bits/stdc++.h>
using namespace std;
#define maxi 100
struct Node{
  int data;
};
struct Node * create_node (int data){
  struct Node * new_node= (struct Node*)malloc(sizeof(struct Node));
  new_node->data= data;
  return new_node;
}
void printArray(struct Node * treeArray, int n ){
  for(int i =0;i<n;i++){
    if(treeArray[i].data!=-1){
      printf("%d ",treeArray[i].data);
    }
    else {
      printf("- ");
    }
  }
  printf("\n");
}

int main() 
{
  struct Node treeArray = [maxi];// storing the nodes
  for(int i =0;i<n;i++) 
  treeArray[i].data=-1;
   
   
   treeArray[0]=*(create_node(1));
   treeArray[1]=*(create_node(2));
   treeArray[2]=*(create_node(3));
   treeArray[3]=*(create_node(4));
   treeArray[4]=*(create_node(5));
   treeArray[5]=*(create_node(6));
   
   printArray(treeArray,6);
    return 0;
}
