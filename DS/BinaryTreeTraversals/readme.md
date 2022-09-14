# BinaryTree with Pre/In/Post-order traversal

To travel through all data stored in tree. There are mainly four ways, mainly differs in access sequence:

1. Pre-order: root -> left -> right.
2. In-order: left -> root -> right. If the tree is a Binary Search Tree, the output will be a sorted sequence.
3. Post-order: left -> right -> root.
4. Level-order: from root to leaf and from left to right.

The traversal way above mostly mainly implemented by the use of [Stack](DS/Stack), while the last one is by the use of [Queue](/DS/Queue/).

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


