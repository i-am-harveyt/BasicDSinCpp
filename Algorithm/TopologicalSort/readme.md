# Topological Sort

## Introduction

Imagine that, you just woke up, and you found that you were almost late.

At this moment however, you still have a lot of things to do:

1. Wearing clothes
2. Wearing socks
3. Wearing shoes
4. Apply hair wax and style your hair

Among these tasks, you may found that if you want to save as much time as you can,
you should wear cloth before style your hair 'cause you may destroy your hairstyle when wearing clothes, and, you may want to wear your socks before you wear shoes.
However, it does not matter whether you do "4 -> 1" first or do "2 -> 3" first.

"Before B, must do A", this is the basic thought of Topological sort.

Also, this is what system do when building your project, because some of the dependencies has their prerequisites. Therefore, the system must find the "order" to build it successfully.

## Steps

1. Choose a Node
2. Mark it as "visited".
3. Traverse it's prerequisites

    1.   If the node is visited, do nothing

    2.   If the node is not visited, do step 2 & 3.

4. After traverse all it's prerequisites, push it into stack.

After all nodes are traversed, pop all elements from stack.
