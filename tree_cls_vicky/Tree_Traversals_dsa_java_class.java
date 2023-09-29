<------------------------------PRE ORDER TRAVERSAL ALGORITHM------------------------------>
    
1.create nodes for the stack 
2.initilize the curr= root;
3.create result of Interger type
4. while(true)
    4.1. while(curr !=null)
          4.1.1. result.add(current.data)
	  4.1.2. st.push(current)
          4.1.3. curr = curr.left
    4.2 if(st.isEmpty()) break;
    4.3 curr = st.pop();
    4.4 curr = curr.right();
5.return result ;

------------------------------------------------------------------------------------------------------------------------
<------------------------------IN ORDER TRAVERSAL ALGORITHM------------------------------>
    
1.create nodes for the stack 
2.initilize the curr= root;
3.create result of Interger type
4. while(true)
    4.1. while(curr !=null)
	  4.1.1. st.push(current)
          4.1.2. curr = curr.left
    4.2 if(st.isEmpty()) break;
    4.3result.add(current.data)
    4.4 curr = st.pop();
    4.5 curr = curr.right();
5.return result ;


------------------------------------------------------------------------------------------------------------------------
<------------------------------POST ORDER TRAVERSAL ALGORITHM------------------------------>
    
1.create nodes for the stack 
2.initilize the curr= root;
3.initilze the (TreeNode) prev node = null ;
4. while(true)
    4.1. while(curr !=null)
          4.1.1. stack.push(curr)
          4.1.2. curr = curr.left
    4.2 if(st.isEmpty()) break;
    4.3 while(curr==null && st.isEmpty()!=0)
          4.3.1. curr = st.peek()
          4.3.2. if(curr.right == null || curr.right== prev)
                  4.3.2.1. result.add(curr)
                  4.3.2.2. stack.pop()
                  4.3.2.3. prev= curr;
                  4.3.2.4. curr = null 
          4.3.3. else 
                  4.3.3.1. curr = curr.right
5.return result ;

------------------------------------------------------------------------------------------------------------------------
<-------------------------------ARRAY REPRESENTATION IN THE JAVA OF THE BINARY TREE------------------>

import java.io.*;
import java.util.*;

class Node {
	int data;
	Node left, right;

	Node (int data) {
		this.data = data;
		left = right = null;
	}
}
class bt {
	static final int maxi = 100;
	static void printArray(int[] arr, int n ) {
		for (int i = 0 ; i < n ; i++ ) {
			if (arr[i] != -1) System.out.print(arr[i] + " ");
			else System.out.print("- ");
		}
		System.out.println();
	}
	public static void main(String[] args) throws IOException {
		int[] bt = new int[maxi];
		int size = 0; // current size of the array

		Arrays.fill(bt, -1); // initialize the array with -1 to represent empty nodes
		Node root = new Node(1);
		root.left = new Node(2);
		root.right = new Node(3);
		root.left.left = new Node(4);
		root.left.right = new Node(5);
		root.right.left = new Node(6);
		root.right.right = new Node(7);

		bt[size++] = root.data;
		bt[size++] = root.left.data;
		bt[size++] = root.right.data;
		bt[size++] = root.left.left.data;
		bt[size++] = root.left.right.data;
		bt[size++] = root.right.left.data;
		bt[size++] = root.right.right.data;

		printArray(bt, size);
	}
}
1 2 3 4 5 6 7

/*------------------------------------------------------------------------------------------------------------------*/
<-------------------------------------EVERY TRAVERSAL OF THE BINARY TREE -------->

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
class binary_trees_vignesh {
	public static List<Integer> Preorder_iterative(TreeNode root) {
		Stack<TreeNode> st = new Stack<TreeNode>();
		TreeNode current = root;
		List<Integer> result = new ArrayList<Integer>();
		while (true) {
			while (current != null) {
				result.add(current.data);
				st.push(current);
				current = current.left;
			}
			if (st.isEmpty()) break;
			current = st.pop();
			current = current.right;
		}
		return result;
	}
	public static List<Integer> Inorder_iterative(TreeNode root) {
		Stack<TreeNode> st = new Stack<TreeNode>();
		TreeNode current = root;
		List<Integer> result = new ArrayList<Integer>();
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
	public static List<Integer> PostOrder_iterative(TreeNode root) {
		Stack<TreeNode> st = new Stack<TreeNode>();
		TreeNode current = root , prev = null;
		List<Integer> result = new ArrayList<Integer>();
		while (true) {
			while (current != null) {
				st.push(current);
				current = current.left;
			}
			if (st.isEmpty())break;
			current = st.peek();
			if (current.right == null || current.right == prev) {
				result.add(current.data);
				st.pop();
				prev = current;
				current = null;
			} else current = current.right;
		}
		return result;
	}
	public static void inorder_recursion(TreeNode root) {
		if (root == null )return;
		inorder_recursion(root.left);
		System.out.print(root.data + " ");
		inorder_recursion(root.right);
	}
	public static void preorder_recursion(TreeNode root) {
		if (root == null )return;
		System.out.print(root.data + " ");
		preorder_recursion(root.left);
		preorder_recursion(root.right);
	}
	public static void postorder_recursion(TreeNode root) {
		if (root == null )return;
		postorder_recursion(root.left);
		postorder_recursion(root.right);
		System.out.print(root.data + " ");
	}
	public static void level_order(TreeNode root) {
		if (root == null) return;
		Queue<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			int levelSize = queue.size();
			for (int i = 0; i < levelSize; i++) {
				TreeNode node = queue.poll();
				System.out.print(node.data + " ");
				if (node.left != null) queue.offer(node.left);
				if (node.right != null)queue.offer(node.right);
			}
		}
	}
	public static void main(String[] args) throws IOException  {
		System.setOut(new PrintStream(new FileOutputStream("output.txt")));
		TreeNode root = new TreeNode(1);
		root.left = new TreeNode(2);
		root.right = new TreeNode(3);
		root.left.left = new TreeNode(4);
		root.left.right = new TreeNode(5);
		root.right.left = new TreeNode(6);
		root.right.right = new TreeNode(7);


		System.out.print("Preorder : ");
		preorder_recursion(root); System.out.println();
		System.out.print("Inorder : ");
		inorder_recursion(root); System.out.println();
		System.out.print("Postorder : ");
		postorder_recursion(root); System.out.println();
		System.out.print("Levelorder ");
		level_order(root); System.out.println();
		System.out.println();
		/*----------------------------------------*/
		List<Integer> result_Preorder = Preorder_iterative(root);
		System.out.print("PreOrder_iterative : ");
		System.out.println(result_Preorder);


		List<Integer> result_Inorder = Inorder_iterative(root);
		System.out.print("Inorder_iterative : ");
		System.out.println(result_Inorder);

		List<Integer> result_Postorder = PostOrder_iterative(root);
		System.out.print("PostOrder_iterative : ");
		System.out.println(result_Postorder);
	}
}
Preorder : 1 2 4 5 3 6 7 
Inorder : 4 2 5 1 6 3 7 
Postorder : 4 5 2 6 7 3 1 
Levelorder 1 2 3 4 5 6 7 

PreOrder_iterative : [1, 2, 4, 5, 3, 6, 7]
Inorder_iterative : [4, 2, 5, 1, 6, 3, 7]
PostOrder_iterative : [4, 5, 2, 6, 7, 3, 1]


