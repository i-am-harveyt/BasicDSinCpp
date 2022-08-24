# Basic Data Structure and some Algorithms in CPP

## Intro

Basic Data Structure and Algorithm in C++, try to practice my C++ programming skill and implement those I've learned.

Maybe one day I'll update the content in README, but I'll put more emphasis on writing code instead.

### Currently uploaded\(08/24 2022\)

Update [Min Max Heap](#min_max_heap) part.

## Table of Content

### [Data Structure](#data_structure)

1. [Stack](#stack)

2. Queue

   1. [Array](#queue_in_array)
   2. [Linked List](#queue_in_linked_list)

3. [BinaryTree with Pre/In/Post-order traversal](#binary_tree_traversal)

4. [XOR Linked List](#xor_linked_list)

5. [Doubly Linked List](#doubly_linked_list)

6. [Maximum Heap](#maximum_heap)

7. [Thread Binary Tree](#thread_binary_tree)

8. [AVL Tree](#avl_tree)

9. [DisJoint Set](#disjoint_set)

10. [Min Max Heap](#min_max_heap)

### [Algorithm](#ag)

1. [Selection Sort](#selection_sort)

2. [Bubble Sort](#bubble_sort)

3. [Binary Tree Sort](#binary_tree_sort)

<a name="data_structure"></a>
## Data Structure

<a name="stack"></a>
### Stack

Implement Stack using Array. Also implemented push, pop, isEmpty, isFull functions.

<a name="queue_in_array"></a>
### Queue implemented by Array

Implement Queue using Array. Also implemented enqueue and dequeue functions. The emptiness and fullness of queue will be notified when calling these functions.

<a name="queue_in_linked_list"></a>
### Queue implemented by Linked List

The introduction is almost as same as [Queue implemented by Array](#queue_in_array)

<a name="binary_tree_traversal"></a>
### BinaryTree with Pre/In/Post-order traversal

Implement BT, using Linked List, and three traversals. The tree will be created automatically and \(maybe\) numarical randomly.

<a name="xor_linked_list"></a>
### XOR Linked List

Implement XOR Linked List, I like this Data Structure persoanlly, 'cause I think this is a great use of XOR.

<a name="doubly_linked_list"></a>
### Doubly Linked List

Implement Doubly Linked List, use two pionter to save the address of previous and next Node.

<a name="maximum_heap"></a>
### Maximum Heap

Implemented Maximum-Heap, using a vector and support add, findMax and deleteMax functions.

Heap is a type of Complete Binary Tree, and it maintains it structure if we properly implemented it.

Add and deleteMax function's time complexity are both $O(logN)$, N = size of data, $logN$ is it's height. Due to it's complete Binary Tree property.

<a name="thread_binary_tree"></a>
### Thread Binary Tree

Implemented Thread Binary Tree.

#### Introduction to Thread BT

Note that, every time we build a binary tree, we waste n + 1 pointers points to null, what if we can make use of it?

This is why Thread Binary Tree comes.

#### Structure

```
+-------------------------------------------------------+
| leftptr | leftIsNull | value | rightIsNull | rightptr |
+-------------------------------------------------------+
```

We use two tags to present if the pointer is a null pointer.

If ptr is not nullptr, then it points to left or right child.

Otherwise, the right pointer points to the inorder successor, i.e. in inorder list, the next one.

Whereas the left pointer points to the inorder predecessor, i.e. in inorder list, the previous one.

The "head" and "tail" will points to null node, which means the "really" null pointer. 

In this way, we only waste two pointer as nullptr instead of n+1.

<a name="avl_tree"></a>
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

<a name="disjoint_set"></a>
### Disjoint set

If we want to check connected components, what might we do? The intuitive one is to lined them.

Disjoint set provide us a way to do things like this.

#### Structure

We use an array to store them, of course we can use a HashMap as well, the idea is basically identical.

In the array, index represents node's data, value of a node represents parent's index, if the node is root, value stores the size in negative number of the set.

#### Functions

Disjoint set basically provides two actions:

1. Union(A, B): To combine two sets: A & B.
2. Find(A): To find the root of set that A in.

However, think of the condition that we've mentioned in discussion of AVL Tree... the manipulation toward points building a tree may leads to a skewd tree, right? We want to avoid that condition too.

To prevent this tree from becoming a skewd tree, instead of arbitrary -- ignore that height and size matters -- Union two sets and just Find root along the long long path. We can make adjustment to them:

1. Union(A, B): Consider that height and size matter, we can determine height and size first, then think of which root becomes new root. Therefore, the height or size of the tree may grow slower.
2. Find(A): Do an action called Path compression, each time we to the Find method, we update the on-path-node's parent by root. In this way, distence between these nodes and root becomes 1.

<a name="min_max_heap"></a>
### Min Max Heap

Have you ever thought, when we use Min Heap or Max Heap, we can only access the min or max element in O(1) time, when in comes to access another, we have to use O(n) time, which is sometimes a little bit not efficient enough? Min Max Heap can help you!

#### Basic Thought

Let's do some adjustment toward basic min or max heap:

1. Generally, we still want keep the complete binary tree property, but we want make the heap has both min heap and max heap exist inside this big heap as well.

2. Therefore, we divide the heap into Min layer and Max layer: min -> max -> min -> max... and so on.

3. In this condition, if we want to access min element, just access root, and the max element is root's left or right child. In this way, access time becomes O(1).

4. However, this means we have to consider the maintainence of min and max heap, which I'll discuss later.

#### Functions

1. getMin(void): access root.
2. getMax(void): access root's left or right child, if root has no child, which means this tree only have root node, access root.
3. insert(int x): insert x into min-max-heap. Steps:
   1. Place x into the end of array.
   2. Check parent is in min or max layer.
   3. Challenge parent(smaller or larger than parent).
   4. (Swap) and maintain the min or max heap property.
4. deleteMin(void): remove minimum element in this heap. Steps:
   1. Remove root.
   2. Temporary save last element as tmp, and remove it.
   3. Verify (if needed means, tmp is larger than min)(I put this paret into delHelper(int root, int x) method):
      1. If root has no child, put tmp into root if needed, then exit.
      2. If has child, check the minimum is in child or grandchildren:
         1. In child, swap min into root and place tmp into that cihld if needed, then exit.
         2. In grandchild: 
            1. Put grandchild into root.
            2. Put child and tmp into right place
            3. Do step3 again with grandchlid index treated as root.
            
   Deletion is quite complicated, it is recommend to read this part and my code at the same time.

<a name="ag"></a>
## Algorithm

<a name="selection_sort"></a>
### Selection Sort

The basic sorting algorithm, which (might be) the most intuitive one.

The basic thought is that, in my humble opinion, find the smallest element in the sub-array and place in the front.

<a name="bubble_sort"></a>
### Bubble Sort

Another basic algorithm, while I  personally think it is not as intuitive as [Selection Sort](#selection_sort).

The thought is that, if there are two nearby elements, are not sorted, then swap them to make them sorted. Repeatedly check all elements in the array until they're all sorted.

<a name="binary_tree_sort"></a>
### Binary Tree Sort

Also quite basic one, in my opinion.

The thought is that, we can use a rule to create a Binary Search Tree first \-\- put smaller things left and larger things right. 

After that, we just use a in-order traversal run through them, and we'll get a sorted sequence.

Note: In-order traversal reads a tree in "left sub-tree -> center node -> right sub-tree" way, therefore, smaller one print first.
