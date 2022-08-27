# XOR Linked List

## Introduction

When using a normal singly linked list, you only points to next or prev which is really a little bit inconvenient. 

However, using a vanilla doubly linked list, you have to maintain two pointers, which sometimes make mantainance complicated.

I personally think that XOR link list is a great way to combine two pointers into one, with the use of XOR operation.

## Basic XOR property

Basic:

```
+---+---+---------+
| A | B | A XOR B |
+---+---+---------+
| T | T |    F    |
| T | F |    T    |
| F | T |    T    |
| F | F |    F    |
+---+---+---------+
```

So what can we do with this? 

When it comes to (A XOR B), the property is $$(A \oplus B) \oplus A = B$$

Therefore, we can only maintain a ptr = $prev \oplus next$. Getting previous/next node using our tamporary stored next/previous node, and do XOR operation with ptr, we can get what we're looking for.

