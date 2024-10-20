#include <iostream>

namespace BT {
// Node
struct Node {
  int data;
  Node *left;
  Node *right;
  Node(int data) {
    this->data = data;
    this->left = this->right = nullptr;
  }
};

// Tree part
class BiTree {
private:
  Node *root;
  void init(void) {
    root = new Node(5);
    /* left subtree */
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    /* right subtree */
    root->right = new Node(7);
    root->right->left = new Node(6);
    root->right->right = new Node(10);
  }

public:
  BiTree() {
    this->root = nullptr;
    init();
  }
  Node *get_root(void) { return this->root; }
};
} // namespace BT
