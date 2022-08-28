# Extended Binary Tree

## Intro

Extended Binary tree treat null nodes as external nodes.

And treat nodes as internal nodes.

Therefore, we can calculate external and internal path as function:

$$External = \Sum_{i = 1}^{ k } level_{ i } * weight_{ i }$$
$$Internal = \Sum_{i = 1}^{ k } level_{ i } * weight_{ i }$$

The things that deeply related to this is Hoffmann's Algorithm, which I'll implement in couple days.
