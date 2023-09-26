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


    Here is a simple algorithm for iterative inorder, preorder, and postorder traversal of a binary search tree (BST) using a stack:

**Inorder Traversal:**
1. Create an empty stack.
2. Initialize the current node as the root.
3. While the current node is not null or the stack is not empty:
   1. If the current node is not null, push it to the stack and set the current node to its left child.
   2. If the current node is null and the stack is not empty:
      1. Pop the top item from the stack and print its data.
      2. Set the current node to its right child.
4. Repeat steps 3 and 4 until the current node is null and the stack is empty.

**Preorder Traversal:**
1. Create an empty stack.
2. Initialize the current node as the root.
3. While the current node is not null or the stack is not empty:
   1. If the current node is not null:
      1. Print its data.
      2. Push the current node to the stack.
      3. Set the current node to its left child.
   2. If the current node is null and the stack is not empty:
      1. Pop the top item from the stack and set the current node to its right child.
4. Repeat steps 3 and 4 until the current node is null and the stack is empty.

**Postorder Traversal:**
1. Create an empty stack.
2. Initialize the current node as the root.
3. While the current node is not null or the stack is not empty:
   1. If the current node is not null:
      1. Push the current node to the stack.
      2. Set the current node to its left child.
   2. If the current node is null and the stack is not empty:
      1. Peek the top item from the stack.
      2. If the right subtree is not yet visited and the peeked node has a right child, set the current node to its right child.
      3. Otherwise, pop the top item from the stack, print its data, and set the last visited node to the popped node.
4. Repeat steps 3 and 4 until the current node is null and the stack is empty.

Here is the Java code for the iterative inorder, preorder, and postorder traversal of a BST using the above algorithms:

```java
import java.util.Stack;

class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {
    Node root;

    void inorder() {
        if (root == null)
            return;

        Stack<Node> stack = new Stack<>();
        Node curr = root;

        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }

            curr = stack.pop();
            System.out.print(curr.data + " ");

            curr = curr.right;
        }
    }

    void preorder() {
        if (root == null)
            return;

        Stack<Node> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            Node curr = stack.pop();
            System.out.print(curr.data + " ");

            if (curr.right != null)
                stack.push(curr.right);
            if (curr.left != null)
                stack.push(curr.left);
        }
    }

    void postorder() {
        if (root == null)
            return;

        Stack<Node> stack = new Stack<>();
        Node curr = root;
        Node lastVisited = null;

        while (curr != null || !stack.isEmpty()) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }

            Node peekNode = stack.peek();

            if (peekNode.right != null && lastVisited != peekNode.right) {
                curr = peekNode.right;
            } else {
                System.out.print(peekNode.data + " ");
                lastVisited = stack.pop();
            }
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(1);
        tree.root.left = new Node(2);
        tree.root.right = new Node(3);
        tree.root.left.left = new Node(4);
        tree.root.left.right = new Node(5);

        System.out.println("Inorder traversal:");
        tree.inorder();

        System.out.println("\nPreorder traversal:");
        tree.preorder();

        System.out.println("\nPostorder traversal:");
        tree.postorder();
    }
}
```

This code will output the inorder, preorder, and postorder traversals of the given BST:

```
Inorder traversal:
4 2 5 1 3 
Preorder traversal:
1 2 4 5 3 
Postorder traversal:
4 5 2 3 1 
```

Citations:
[1] https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
[2] https://www.geeksforgeeks.org/implementing-inorder-preorder-postorder-using-stack-in-java/
[3] https://saturncloud.io/blog/fixing-my-implementation-of-inorder-tree-traversal-algorithm-with-a-stack/
[4] https://stackoverflow.com/questions/64859360/binary-search-tree-inorder-traversal-cant-understand-solution
[5] https://www.educative.io/answers/how-to-perform-an-iterative-inorder-traversal-of-a-binary-tree
[6] https://www.enjoyalgorithms.com/blog/iterative-binary-tree-traversals-using-stack/
