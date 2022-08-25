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


