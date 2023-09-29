// this is the java code working fine 
import java.util.Arrays;

class Main {
    static class Node {
        int data;
    }

    static Node create_node(int data) {
        Node new_node = new Node();
        new_node.data = data;
        return new_node;
    }

    static void printArray(Node[] treeArray, int n) {
        for (int i = 0; i < n; i++) {
            if (treeArray[i].data != -1) {
                System.out.print(treeArray[i].data + " ");
            } else {
                System.out.print("- ");
            }
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int maxi = 100;
        Node[] treeArray = new Node[maxi];
        Arrays.fill(treeArray, new Node());
        for (int i = 0; i < maxi; i++)
            treeArray[i].data = -1;
        treeArray[0] = create_node(1);
        treeArray[1] = create_node(2);
        treeArray[2] = create_node(3);
        treeArray[3] = create_node(4);
        treeArray[4] = create_node(5);
        treeArray[5] = create_node(6);
        printArray(treeArray, 6);
    }
}


//1 2 3 4 5 6

#include <bits/stdc++.h>
using namespace std;
#define maxi 100

struct Node {
  int data;
};

struct Node create_node(int data) {
  struct Node new_node;
  new_node.data = data;
  return new_node;
}

void printArray(struct Node* treeArray, int n) {
  for (int i = 0; i < n; i++) {
    if (treeArray[i].data != -1) {
      printf("%d ", treeArray[i].data);
    } else {
      printf("- ");
    }
  }
  printf("\n");
}

int main() {
  struct Node treeArray[maxi];  // storing the nodes
  for (int i = 0; i < maxi; i++)
    treeArray[i].data = -1;

  treeArray[0] = create_node(1);
  treeArray[1] = create_node(2);
  treeArray[2] = create_node(3);
  treeArray[3] = create_node(4);
  treeArray[4] = create_node(5);
  treeArray[5] = create_node(6);

  printArray(treeArray, 6);
  return 0;
}


//algorithm for the inorder traversal
1. create a stack 
2. initilize the curr= root;
3. while(1)
    3.1 while(curr!=null) 
        3.1.1 st.push = curr-data;
        3.1.2  curr = curr ->left;
    3.2 if(st.empty())  break
    3.3 curr = st.pop()
    3.4 result = curr->data;
    3.5 curr = curr->right
4. return result 



algorithm for the preorder traversal
1. create a stack 
2. initilize the curr= root;
3. while(1)
    3.1 while(curr!=null) 
        3.1.1  result = curr->data;
        3.1.2  st.push = curr-data;
        3.1.3  curr = curr->left;
    3.2 if(st.empty()) break
    3.2 curr = st.pop()
    3.4 curr = curr->right
   
4. return result 



    ----------------------------------------------------------------------------------------------------------------------------------
    ------------------------------------------------------------------------------------------------------------------------------

import java.io.*;
import java.util.*;
class TreeNode {
	int data;
	TreeNode left, right;

	TreeNode(int data) {
		this.data = data;
		this.right = this.left = null;
	}
}
class Test  {
	public static List<Integer> inorder(TreeNode root) {
		List<Integer> result = new ArrayList<>();
		TreeNode current = root;
		Stack<TreeNode> st = new Stack<>();
		while (true) {
			while (current != null) {
				st.push(current);
				current = current.left;
			}
			if (st.isEmpty()) break;
			current = st.pop();
			result.add(current.data);
			current = current.right;
		}
		return result;
	}
	public static void main(String[] args) throws IOException {
		System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		TreeNode root = new TreeNode(1);
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(5);
		root.right.left = new TreeNode(6);
		root.right.right = new TreeNode(7);

		List<Integer> result = inorder(root);
		System.out.print("Inorder : ");
		for (int i = 0; i <  result.size(); i++ ) {
			System.out.print(result.get(i) + " ");
		}
	}
}
// Inorder : 4 2 5 1 6 3 7


--------------------------------------------------------------------------------------------------
	29.09
	
