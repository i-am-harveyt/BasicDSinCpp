# Symmetric Min Max Heap(SMMH)

## Intro

SMMH is also a variant of Heap, which means, it is also a complete binary tree. Same as some other variants, SMMH's root doesn't store value as well. It also make the access of Minimum and Maximum spends O(1) time.

## Properties

1. The value of a root's left child is smaller than right child.

2. If x has grandparent, the left child of grandparent must not larger than x.

3. If x has grandparent, the right child of grandparent mus not smaller than x.

Therefore, what we will do in functions below is to maintain these propertyies.

## Functions

1.insert(X):
  To insert X into a SMMH, we do things below:

  1. Like we've done in those kinds of heap, insert in the end of array.
  2. Considering Property 1, We check the relation between X and it's sibling, do adjustment if needed to make left sibling smaller than right.

  3. If X has grandparent, check the relation between X and it's parent and parent's sibling. To meet property 2 and 3, also , make adjustment if needed.

  After these steps, we can place X into a place that fits in these three properties.

2. deleteMin(void):

  In deletion, we also need to address on handling conditions.

  1. Remove the Minimum and keep it empty.

  2. Take the last element, put into space.

  3. Then repeatedly consider their relations:

    1. Space and it's sibling, swap space and sibling if needed.

    2. Space and it's left child, it's sibling's left child, swap them if needed.

    If there is a position that fits all property, that's where X belongs to.

