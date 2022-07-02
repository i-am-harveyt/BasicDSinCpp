#include <iostream>
#include <vector>

class Node {
public:
  int value, height;
  Node *left, *right;
  Node(int val, Node *nil) {
    value = val, height = 0;
    left = nil, right = nil;
  }
};

class AVLT {
public:
  Node *root, *nil;
  int size;
  AVLT() {
    nil = new Node(-1, nullptr);
    nil->height = -1;
    size = 0;
  }
  void insert(int val) {

    // if there is no node in tree
    if (size == 0)
      root = new Node(val, nil);

    Node *node = find(val);
    // if val existed, stop insert
    if (node != nil)
      return;

    node = root;
    std::vector<Node *> order;
    while (true) {
      order.push_back(node);
      if (val > node->value) {
        if (node->right) {
          node = node->right;
        } else
          break;
      } else if (val < node->value) {
        if (node->left)
          node = node->left;
        else
          break;
      }
    }
    Node *newNode = new Node(val, nil);
    if (val < node->value)
      node->left = newNode;
    else
      node->right = newNode;
    order.push_back(newNode);

    // fix all
    fix(order);

    // update size
    size++;
  }

  Node *find(int val) {
    Node *cur = root;
    while (cur->value != val) {
      if (val < cur->value)
        cur = cur->left;
      else if (val > cur->value)
        cur = cur->right;
      if (cur == nil)
        break;
    }
    return cur;
  }

  int updateHeight(Node *cur) {
    int leftH = cur->left->height;
    int rightH = cur->right->height;
    if (leftH > rightH)
      return leftH + 1;
    return rightH + 1;
  }

  void fix(std::vector<Node *> &order) {
    // update height
    int index = order.size() - 1;
    for (int i = index; i >= 0; i--)
      updateHeight(order[i]);

    // consider inbalance condition
    Node *a, *b, *c, *p;
  }

  void ll(Node *a, Node *b, Node *c, Node *p) {}
  void lr(Node *a, Node *b, Node *c, Node *p) {}
  void rl(Node *a, Node *b, Node *c, Node *p) {}
  void rr(Node *a, Node *b, Node *c, Node *p) {}
};

int main(void) { return 0; }
