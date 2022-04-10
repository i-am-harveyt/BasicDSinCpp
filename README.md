# BasicDSinCpp\(and some algorithm\)

## Intro

Basic Data Structure and Algorithm in C++, try to practice my C++ programming skill and implement those I've learned.

Maybe one day I'll update the content in README, but I'll put more emphasis on writing code instead.

### Currently uploaded\(04/10 2022\)

[Bubble Sort](#bs)

## Table of Content

### [Data Structure](#ds)

1. [Stack](#stack)

2. Queue

   1. [Array](#queueinarray)
   2. [Linked List](#queueinll)

3. [BinaryTree with Pre/In/Post-order traversal](#bttraversals)

4. [XOR Linked List](#xorll)

### [Algorithm](#ag)

1. [Selection Sort](#ss)
2. [Bubble Sort](#bs)

<a name="ds"></a>
## Data Structure

<a name="stack"></a>
### Stack

Implement Stack using Array. Also implemented push, pop, isEmpty, isFull functions.

<a name="queueinarray"></a>
### Queue implemented by Array

Implement Queue using Array. Also implemented enqueue and dequeue functions. The emptiness and fullness of queue will be notified when calling these functions.

<a name="queueinll"></a>
### Queue implemented by Linked List

The introduction is almost as same as [Queue implemented by Array](#queueinarray)

<a name="bttraversals"></a>
### BinaryTree with Pre/In/Post-order traversal

Implement BT, using Linked List, and three traversals. The tree will be created automatically and \(maybe\) numarical randomly.

<a name="xorll"></a>
### XOR Linked List

Implement XOR Linked List, I like this Data Structure persoanlly, 'cause I think this is a great use of XOR.

<a name="ag"></a>
## Algorithm

<a name="ss"></a>
### Selection Sort

The basic sorting algorithm, which (might be) the most intuitive one.

The basic thought is that, in my humble opinion, find the smallest element in the sub-array and place in the front.

<a name="bs"></a>
### Bubble Sort

Another basic algorithm, while I  personally think it is not as intuitive as [Selection Sort](#ss).

The thought is that, if there are two nearby elements are not sorted, then swap them. Repeatedly check all elements in the array until make sure they're all sorted.
