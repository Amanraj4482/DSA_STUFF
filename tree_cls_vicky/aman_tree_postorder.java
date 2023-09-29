// post order traversal using the stack 
// 1.create nodes for the stack -->
// 2.initilize the curr= root;
// 3.initilze the (TreeNode) prev node = null ;
// 4. while(true)
//     4.1. while(curr !=null)
//           4.1.1. stack.push(curr)
//           4.1.2. curr = curr.left
//     4.2 if(st.isEmpty()) break;
//     4.3 while(curr==null && st.isEmpty()!=0)
//           4.3.1. curr = st.peek()
//           4.3.2. if(curr.right == null || curr.right== prev)
//                   4.3.2.1. result.add(curr)
//                   4.3.2.2. stack.pop()
//                   4.3.2.3. prev= curr;
//                   4.3.2.4. curr = null 
//           4.3.3. else 
//                   4.3.3.1. curr = curr.right
// 5.return result ;

import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

public class PostOrderTraversal {
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null)
            return result;

        Stack<TreeNode> stack = new Stack<>();
        TreeNode curr = root;
        TreeNode prev = null;

        while (true) {
            while (curr != null) {
                stack.push(curr);
                curr = curr.left;
            }

            if (stack.isEmpty())
                break;

            curr = stack.peek();

            if (curr.right == null || curr.right == prev) {
                result.add(curr.val);
                stack.pop();
                prev = curr;
                curr = null;
            } else {
                curr = curr.right;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        // Create a binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // Perform post-order traversal
        PostOrderTraversal traversal = new PostOrderTraversal();
        List<Integer> result = traversal.postorderTraversal(root);

        // Print the result
        System.out.println("Post-order traversal: " + result);
    }
}
