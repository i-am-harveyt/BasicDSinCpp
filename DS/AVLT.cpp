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
  Node *nil, *dummy; // left of dummy is root;
  int size;
  AVLT() {
    nil = new Node(-1, nullptr);
    nil->height = -1;
    size = 0;
    dummy = new Node(-1, nil);
  }
  void insert(int val) {
    std::cout << "Insert: " << val << std::endl;
    // if there is no node in tree
    if (size == 0) {
      dummy->left = new Node(val, nil);
      size++;
      return;
    }

    Node *node = find(val);
    // if val existed, stop insert
    if (node != nil) {
      std::cout << "Value " << val << " existed!" << std::endl;
      return;
    }

    // Insert Node
    node = dummy->left;
    std::vector<Node *> order;
    order.push_back(dummy);
    while (true) {
      order.push_back(node);
      if (val > node->value) {
        if (node->right != nil) {
          node = node->right;
        } else
          break;
      } else if (val < node->value) {
        if (node->left != nil)
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

  // Delete Node, delete as BST, then adjust those in finding path
  void deleteNode(int val) {
    std::vector<Node *> order;
    order.push_back(dummy);
    Node *cur = dummy->left;

    while (cur != nil) {
      order.push_back(cur);
      if (val < cur->value)
        cur = cur->left;
      else if (val > cur->value)
        cur = cur->right;
      else
        break;
    }
    if (cur == nil)
      return;

    // delete as BST
    Node *del = order.back();
    order.pop_back();
    Node *preDel = order.back();
    if (del->left != nil) {
      // take the largest node to replace
      Node *largest;
      largest = del->left;
      if (largest->right == nil) {
        if (del == preDel->left)
          preDel->left = largest;
        else
          preDel->right = largest;
      } else {
        // if there is node has bigger value than root of left stubtree
        Node *preLarge;
        while (largest->right != nil) {
          preLarge = largest;
          largest = largest->right;
        }
        preLarge->right = largest->left;
      }
      order.push_back(largest);
    } else {
      // take smallest node to replace
      Node *smallest;
      smallest = del->right;
      if (smallest->left == nil) {
        if (del == preDel->left)
          preDel->left = smallest;
        else
          preDel->right = smallest;
      } else {
        // if there is node has bigger value than root of right subtree
        Node *preSmall;
        while (smallest->left != nil) {
          preSmall = smallest;
          smallest = smallest->left;
        }
        preSmall->left = smallest->right;
      }
      order.push_back(smallest);
    }
    delete del;

    // fix those in 'order'
    fix(order);
  }

  // find if value in the AVLT or not
  Node *find(int val) {

    Node *cur = dummy->left;
    while (cur->value != val) {
      if (cur == nil)
        break;
      else if (val < cur->value)
        cur = cur->left;
      else if (val > cur->value)
        cur = cur->right;
    }
    return cur;
  }

  void updateHeight(Node *cur) {
    int leftH = cur->left->height;
    int rightH = cur->right->height;
    if (leftH > rightH)
      cur->height = leftH + 1;
    else
      cur->height = rightH + 1;
  }

  // trace order and check imbalance condition
  void fix(std::vector<Node *> &order) {
    // update height
    int index = order.size() - 1;
    for (int i = index; i > 0; i--)
      updateHeight(order[i]);

    // consider inbalance condition
    Node *a, *b, *p;
    int lh, rh;
    for (int i = index; i > 0; i--) {
      lh = order[i]->left->height, rh = order[i]->right->height;
      if (lh - rh > 1) { // left sub-tree is higher
        a = order[i], b = order[i + 1], p = order[i - 1];
        lh = b->left->height, rh = b->right->height;
        if (lh > rh) // ll condiion
          ll(a, b, b->left, p);
        else // lr condition
          lr(a, b, b->right, p);
      } else if (lh - rh < -1) { // right subtree is higher
        a = order[i], b = order[i + 1], p = order[i - 1];
        lh = b->left->height, rh = b->right->height;
        if (lh > rh) // rl condition
          rl(a, b, b->left, p);
        else // rr condition
          rr(a, b, b->right, p);
      }
    }
  }

  void ll(Node *a, Node *b, Node *c, Node *p) {
    a->left = b->right;
    updateHeight(a);
    b->right = a;
    updateHeight(b);
    if (a == p->left)
      p->left = b;
    else
      p->right = b;
    updateHeight(p);
  }
  void rr(Node *a, Node *b, Node *c, Node *p) {
    a->right = b->left;
    updateHeight(a);
    b->left = a;
    updateHeight(b);
    if (a == p->left)
      p->left = b;
    else
      p->right = b;
    updateHeight(p);
  }
  void lr(Node *a, Node *b, Node *c, Node *p) {
    b->right = c->left;
    updateHeight(b);
    c->left = b;
    updateHeight(c);
    a->left = c;
    updateHeight(a);
    ll(a, c, b, p);
  }
  void rl(Node *a, Node *b, Node *c, Node *p) {
    b->left = c->right;
    updateHeight(b);
    c->right = b;
    updateHeight(c);
    a->right = c;
    updateHeight(a);
    rr(a, c, b, p);
  }

  // In-order traversal
  void all() {

    std::cout << "All : ";

    Node *cur = dummy->left;
    std::vector<Node *> stack;
    while (!stack.empty() || cur != nil) {
      while (cur != nil) {
        stack.push_back(cur);
        cur = cur->left;
      }

      cur = stack.back();
      stack.pop_back();
      std::cout << cur->value << " ";

      cur = cur->right;
    }
    std::cout << std::endl;
  }

  // Pre-order traversal
  void preorder() {
    std::cout << "Preorder: ";
    Node *cur = dummy->left;
    std::vector<Node *> stack;
    while (!stack.empty() || cur != nil) {
      while (cur != nil) {
        std::cout << cur->value << " ";
        stack.push_back(cur);
        cur = cur->left;
      }
      cur = stack.back();
      stack.pop_back();
      cur = cur->right;
    }
    std::cout << std::endl;
  }
};

int main(void) {
  AVLT avlt = AVLT();
  std::vector<int> seq;
  seq.push_back(40);
  seq.push_back(20);
  seq.push_back(10);
  seq.push_back(25);
  seq.push_back(30);
  seq.push_back(22);
  seq.push_back(50);
  for (int i = 0; i < seq.size(); i++) {
    avlt.insert(seq[i]);
  }
  avlt.all();
  avlt.preorder();
  return 0;
}
