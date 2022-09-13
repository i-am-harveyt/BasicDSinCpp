# Quick Sort

## Intro

Quick Sort is a advanced sorting method, which uses the "divide and conquer" strategy. 
One of the features is that, it does not need to ask much memory from system, instead, it consume some Stack space, due to it's recursive property.

## Implement

Since left bound and left bound does not collide(conquer):

1. Choose a pivot, I choose leftest element in this implementation.
2. Scan the subarray, from left to right, to find element that is bigger than pivot.
3. Scan the subarray, from right to left, to find element that is smaller than pivot.
4. swap them.

When two pointers meet, swap pivot and the pointer that points to left bound.

At this moment, pivot will at the absolutely right place, it will be there 'till the end. And the elements at left side are not larger than pivot, the elements at right side are not smaller than pivot.

Then tackle on both sides(division).

## Analysis

### Time

### Space

### Stable

Not stable.
