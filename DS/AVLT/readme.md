### AVL Tree

#### Introduction to AVL Tree

Think of the condition.

If your data is already sorted, and you convert it into a BST, what will happen?

The tree will become a link list, called skewed BST, which is very bad because your time complexity of Find, Insert, Delete will become $O(n)$ instead of $O(lgn)$.

Therefore, if we want to make a tree always in a "best" condition, i.e., tree with lowest height, we have to check if we need to make adjustment whenever we make changes to it.

AVL Tree is a Data structure that helps us to reach this goal, which is s a self-balancing binary tree.

#### How it works

After insertion and deletion(almost same as binary search tree), we check all nodes' left and right height difference on the "path", from root to the node we manipulate.

If there is a node, which $|height(Lchild) - height(Rchild)| >= 2$, we can tell the height is inbalanced, then we can adjust it into balanced condition.

### Conditions

There are four conditions that we care about:

1. LL condition: 
   A have a left Child B with a Left Child C, $height(A) = |height(B)-height(null)| = |1 - (-1)| = 2$. So we can do something like this to adjust: 

   1. Lift B up to become new root
   2. Set A as B's right child.

   After doing this, height(B) will become $1-1=0$, which is balanced.
2. RR Condition: 
   A have a Right Child B and a Right Child C, $height(A) = |height(null) - height(B)| = |-1-1| = 2$, which is imbalanced, then we can do:
   
   1. Lift B up to become new root
   2. Set A as B's left child.

   After doing this, height(b) = 0, balanced.

3. LR Condition:
   A have Left child B with Right child C, $height(B) = |-1-0| = 1, height(A) = |1-(-1)| = 2$, we can do:

   1. Lift C up to become B's parent.
   2. Set B as C's Left child.
   
   You might noticed, this leads to a LL condition.

4. RL Condition:

   Same Logic as LR condition, you can move your eye from screen and try to write your thought down. Then check if my words are same as yours.

   A have Right child B with Left child C, $height(B) = |0-(-1)| = 1, height(A) = |-1-1| = 2$, we can do:

   1. Lift C up to become B's parent.
   2. set B as C's Right child.
   
   You might noticed, this become a RR condition.

After handling these conditions, we can tell all L&R height difference are either 0 or 1, therefore, the tree's structure must remains an ideal condition. Which means, Find, Insert, Delete's time complexity remains about $O(lgn)$.

