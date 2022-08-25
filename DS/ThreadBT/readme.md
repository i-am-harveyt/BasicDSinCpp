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

