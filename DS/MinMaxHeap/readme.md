# Min Max Heap

Have you ever thought, when we use Min Heap or Max Heap, we can only access the min or max element in O(1) time, when in comes to access another, we have to use O(n) time, which is sometimes a little bit not efficient enough? Min Max Heap can help you!

## Basic Thought

Let's do some adjustment toward basic min or max heap:

1. Generally, we still want keep the complete binary tree property, but we want make the heap has both min heap and max heap exist inside this big heap as well.

2. Therefore, we divide the heap into Min layer and Max layer: min -> max -> min -> max... and so on.

3. In this condition, if we want to access min element, just access root, and the max element is root's left or right child. In this way, access time becomes O(1).

4. However, this means we have to consider the maintainence of min and max heap, which I'll discuss later.

## Functions

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

