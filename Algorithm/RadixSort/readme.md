# Radix Sort

## Intro

There are some ways to sort data in linear time. Radix Sort is one of them.

However, there is a prerequisite: <font color=red>We need to know the range first</font>.

After that, our runs become a constant, therefore we can realize a sorting algorithm in linear time.

The idea of Radix Sort is that:

1. We can step-by-step sort data in the size of certain digits.

2. When it comes to the size of certain digit is same, we use FIFO(First In First Out) way to store them.

For example:

+ Run 1 : 2<u>7</u> 1<u>7</u> 2<u>1</u> => 21 27 17

+ Run 2 : <u>2</u>1 <u>2</u>7 <u>1</u>7 => 17 21 27


## Implementation

### Prepare

As we've discussed above, we need:

1. A table that is "long" enough that includes all numbers in range of digit.

2. Some structure that can maintain a FIFO property.

Therefore, in my implementation, I use a `vector` with length = range_of_digit, and each element is a `queue`.

### Steps

In each round (range from 1 to d):

1. Scan every element and target it's round $i^{th}$ digit.

2. Push the element into the queue corresponds it's $i^{th}$ digit number.

3. Sequentailly pop them out and put into array.

## Analysis

### Time

Linear time: $O(n)$

### Space

$O(n+k)$, k stands for the largest element among the $d^{th}$ place elements.

In my implementation, d is 10.

### Stable or not

Stable.
