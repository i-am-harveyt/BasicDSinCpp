### Stack

#### Introduction

Stack is one of the most basic Data Structure. Which main property is LIFO(Last In First Out).

The use of Stack is quite common. For example, Recursion is one of Stack application, and Depth-First-Search is also well-known one, we'll also cover this topic later.

In our daily life, think of taking elevator, what will happen if an elevator overload? Generally, the last one who enter will go out.

#### Implementation

To implement stack, we can use array or link list. But mainly, we support:

1. push(x): to push x into top of the stack.
2. pop(void): to remove x from top of the stack.
3. top(void): to access the top of the stack.

And make sure that they can be done in O(1) time.

