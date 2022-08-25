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

