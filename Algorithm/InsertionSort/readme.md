# Insertion Sort

## Intro

Insertion sort is one of the basic sorting algorithm.

The main thought is that, to place the number into the place that it should be in **current subset**.

Therefore, in each round, the where the numbers placed may not be the place it would be consequently.

## Implementation

```
// index range: 0 to n-1
for i=1 to n-1, do:
  j=i;
  while (j > 0), do:
    if (vec[j] < vec[j-1]) // vec[j] should move to front
      swap(vec[j], vec[j-1]);
    else // vecp[j] is in right place
      break;
    j--;
  end while
end for
```

## Analysis

### Time

Time should be $O(n^2)$ since it runs $1 + 2 + 3 + ... + n-1$ times comparison.

### Space

Space is constant, what you need is only a `int j`.
