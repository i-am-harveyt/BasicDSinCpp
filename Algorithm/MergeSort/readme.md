# Merge Sort

## Intro

Merge sort is one of the "advanced" sorting method, which is mainly used for sorting a large amount of data that cannot be loaded into memory at once.

To reach this goal, merge sort also used a "divide and conquer" strategy, divide data into small pieces and load them into memory, sort them and load them back to external memory.

## Implementation

We take recursive method, as example.

Things below is just one way of implementation.

### Controller:

1. Divide the current array into half.

2. Tackle on "left" one.

3. Tackle on "right" one.

4. Merge "left" and "right" one together.

5. Return the outcome of Merge.

### Merge:

1. Repeatedly do until one of "left" and "right" are entirely scanned:

    1. Compare the current number between "left" and "right" sub-array.

    2. Put the smaller one into output.

2. Put all left elements into output array.

3. Return output.

Merge Sort can also be implemented in iterative way, which seems like requires some calculation towards indexes. I've not figured out yet.

## Analysis

### Time

Merge Sort's time complexity is stably $O(lgn)$, no matter how data distributed.

### Space

Space complexity is $O(n)$. Since it use a array to store the divided sub-array.

### Stable

Merge Sort is a **stable** sorting algorithm.

