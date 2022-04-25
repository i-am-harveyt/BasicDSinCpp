# Basic Data Structure in Cpp\(and some Algorithms\)

## Intro

Basic Data Structure and Algorithm in C++, try to practice my C++ programming skill and implement those I've learned.

Maybe one day I'll update the content in README, but I'll put more emphasis on writing code instead.

### Currently uploaded\(04/25 2022\)

Midterm week finally ended!\(Cheers\)

[Maximum-Heap](#maximum_heap)

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

The thought is that, we can use a rule to create a binary tree first \-\- put smaller things left and larger things right. 

After that, we just use a in-order traversal run through them, and we'll get a sorted sequence.

Note: In-order traversal reads a tree in "left sub-tree -> center node -> right sub-tree" way, therefore, smaller one print first.
