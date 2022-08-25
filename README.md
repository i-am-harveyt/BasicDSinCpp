# Basic Data Structure and some Algorithms in CPP

## Intro

Basic Data Structure and Algorithm in C++, practice my C++ programming skill and implement those thing I've learned.

### Currently uploaded\(08/24. 2022\)

Update [Deap](#deap) part.

## Table of Content

### [Data Structure](#data_structure)

1. [Stack](#stack)

2. [Queue](#queue)

3. [BinaryTree with Pre/In/Post-order traversal](#binary_tree_traversal)

4. [Doubly Linked List](#doubly_linked_list)

5. [XOR Linked List](#xor_linked_list)

6. [Maximum Heap](#maximum_heap)

7. [Thread Binary Tree](#thread_binary_tree)

8. [AVL Tree](#avl_tree)

9. [DisJoint Set](#disjoint_set)

10. [Min Max Heap](#min_max_heap)

11. [Deap](#deap)

### [Algorithm](#ag)

1. [Selection Sort](#selection_sort)

2. [Bubble Sort](#bubble_sort)

3. [Binary Tree Sort](#binary_tree_sort)

<a name="data_structure"></a>
## Data Structure

<a name="stack"></a>
### Stack

#### Introduction

Stack is one of the most basic Data Structure. Which main property is LIFO(Last In First Out).

The use of Stack is quite common. For example, Recursion is one of Stack application, and Depth-First-Search is also well-known one, we'll also cover this topic later.

In our daily life, think of taking elevator, what will happen if an elevator overload? Generally, the last one who enter will go out.

#### Implementation

To implement stack, we can use array or link list. But mainly, we support:

1. push(x): to push x into top of the stack.
2. pop(void): to remove x from top of the stack.
3. top(void): to access the top of the stack.

And make sure that they can be done in O(1) time.

<a name="queue"></a>
### Queue

Compare to [Stack](#stack), Queue is a FIFO(First In First Out) data structure.

You can think of waiting in line, and some sequential condition, they based on FIFO idea as well.

In DS and Algorithm, Bredth-First-Search(BFS) or Level order traversal is the apllication of Queue. We may cover BFS later, but I may not discuss Level-order traversal here.

#### Implementation

We can also implement it by array or linkedlist. And I split into two files to store my implementation. And they basically support:

1. enqueue(x): push x into queue from rear(back of the queue).
2. dequeue(): remove the element in front of the queue.

Both of them work in O(1) time.

Stack and Queue can implement each other, however I didn't put this DS design into this repo.

<a name="binary_tree_traversal"></a>
### BinaryTree with Pre/In/Post-order traversal

To travel through all data stored in tree. There are mainly four ways, mainly differs in access sequence:

1. Pre-order: root -> left -> right.
2. In-order: left -> root -> right. If the tree is a Binary Search Tree, the output will be a sorted sequence.
3. Post-order: left -> right -> root.
4. Level-order: from root to leaf and from left to right.

The traversal way above mostly mainly implemented by the use of [Stack](#stack), while the last one is by the use of [Queue](#queue).

Implement them using recursive way is quite intuitive, while in iterative way is a little bit more complicated.

Generally, the thought I come up with is something below:

```
while stack is not empty or current Node is not null:
   while current node is not null:
     stack.push(current node)
     update current by current's left child

   stack.pop()

   update current by current's right child
```

But between these three order,the logic of push, pop will be a little bit defferent. In this repo, I implement them in recursive way. While I wrote them iterative way in [MyLeetCodePractice](https://github.com/i-am-harveyt/MyLeetCodePractice) repo, but if you want to find them out, you may refer to LeetCode problem ID, which is a little bit time-wasting. And you may come up with those ideas before you found it, haha!

The thought of level-order implementation is:

```
while queue is not empty:
   size = queue.size()
   while size > 0 :
      queue.push(queue.front.leftChild) if needed
      queue.push(queue.front.rightChild) if needed
      queue.pop()
      size--
```

this will run a "from root to leaf and from left to rifght way".

I also implement this in MyLeetCodePractice repo.

<a name="doubly_linked_list"></a>
### Doubly Linked List

Structure:

```
+------+-----+------+
| prev | val | next |
+------+-----+------+
```

Differs from Singly link list, we store two pointers that respectively points to previous and next node.

Therefore, we can access previous and next node as we want.

Though it makes access convenient, however, it also sometimes make maintainance of pointers not very intuitive.

<a name="xor_linked_list"></a>
### XOR Linked List

#### Introduction

When using a normal singly linked list, you only points to next or prev which is really a little bit inconvenient. 

However, using a vanilla doubly linked list, you have to maintain two pointers, which sometimes make mantainance complicated.

I personally think that XOR link list is a great way to combine two pointers into one, with the use of XOR operation.

#### Basic XOR property

Basic:

```
+---+---+---------+
| A | B | A XOR B |
+---+---+---------+
| T | T |    F    |
| T | F |    T    |
| F | T |    T    |
| F | F |    F    |
+---+---+---------+
```

So what can we do with this? 

When it comes to (A XOR B), the property is $$(A \oplus B) \oplus A = B$$

Therefore, we can only maintain a ptr = $prev \oplus next$. Getting previous/next node using our tamporary stored next/previous node, and do XOR operation with ptr, we can get what we're looking for.

<a name="maximum_heap"></a>
### Maximum Heap

#### Introduction

When it comes to frequently access the minimum and maximum element inside a binary tree, it would be quite inefficient since we spend O(lgn) time for Binary Search Tree and O(n) time for Binary Tree when for doing this.

Heap is a data structure that can solve this odd condition. Because it is designed as placing the maximum/minimum in root, therefore we can spend only O(1) time to access it.

#### Basic Property

1. Heap is a complete binary tree.
2. For each subtree, root is the biggest among it's left and right child. Which means each subtree is also a heap

#### Function

1. insert(x): Insert x into heap, and adjust x into it's proper place.
2. getMax(void): return maximum, if it's a minimum heap, return minimum.
3. delete(void): delete root(maximum/minimum) in this heap, and fix the structure.

#### Implementation

Since Heap is a complete binary tree, we prefer using array to implement it.

1. insert(x):
   We put the element at the last of the array, then repeatedly let it "challenge" it's parent, to see if we need to swap it and it's parent. Until it become root or it's challenge fail.
2. getMax(void):
   Just return the first elment in the array.
3. delete(void):
   Remove the root and place the last element into root.
   Then repeatedly see if it's child is larger than it, if yes, swap them, if not, exit.

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

<a name="Deap"></a>
### Deap

Deap is also a vriation of heap, which also provide an easy way to access minimum and maximum element.

Differs from Min-Max-Heap, Deap maintain Min/Max Heap property by maintaining two heaps, respectively in root's left and right subtree. And Deap does not store data in root.

#### Functions

1. getMin(void): Return Minimum element from Deap, i.e., data[1].
2. getMax(void): Return Maximum element from Deap, i.e., data[2].
3. insert(int x): Insert x into deap.

   Steps:

   1. Put x into last number
   2. Compare to correspond node, which means, 
      the node with same realative position in opposite heap.
   3. Swap them if needed.
   4. Adjust the heap to meet the rule.

4. deleteMin(void): Remove Minimum element from Deap.

   Steps:

   1. Make root data as a space, temporary save last node data as x then remove last data.
   2. Repeatedly swap the space and the minimum in subtree's root, until space located in leaf.
   3. Do Step 2 ~ 4 in insertion step  s. Just like the last node is that leaf.

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


Author: Harvey Tung
