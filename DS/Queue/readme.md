### Queue

Compare to [Stack](#stack), Queue is a FIFO(First In First Out) data structure.

You can think of waiting in line, and some sequential condition, they based on FIFO idea as well.

In DS and Algorithm, Bredth-First-Search(BFS) or Level order traversal is the apllication of Queue. We may cover BFS later, but I may not discuss Level-order traversal here.

#### Implementation

We can also implement it by array or linkedlist. And I split into two files to store my implementation. And they basically support:

1. enqueue(x): push x into queue from rear(back of the queue).
2. dequeue(): remove the element in front of the queue.

Both of them work in O(1) time.

Stack and Queue can implement each other, however I didn't put this DS design into this repo.

