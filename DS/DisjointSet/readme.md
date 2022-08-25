### Disjoint set

If we want to check connected components, what might we do? The intuitive one is to lined them.

Disjoint set provide us a way to do things like this.

#### Structure

We use an array to store them, of course we can use a HashMap as well, the idea is basically identical.

In the array, index represents node's data, value of a node represents parent's index, if the node is root, value stores the size in negative number of the set.

#### Functions

Disjoint set basically provides two actions:

1. Union(A, B): To combine two sets: A & B.
2. Find(A): To find the root of set that A in.

However, think of the condition that we've mentioned in discussion of AVL Tree... the manipulation toward points building a tree may leads to a skewd tree, right? We want to avoid that condition too.

To prevent this tree from becoming a skewd tree, instead of arbitrary -- ignore that height and size matters -- Union two sets and just Find root along the long long path. We can make adjustment to them:

1. Union(A, B): Consider that height and size matter, we can determine height and size first, then think of which root becomes new root. Therefore, the height or size of the tree may grow slower.
2. Find(A): Do an action called Path compression, each time we to the Find method, we update the on-path-node's parent by root. In this way, distence between these nodes and root becomes 1.

