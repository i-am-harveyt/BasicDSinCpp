#include <iostream>
#include <vector>

// TreeNode Stuucture
class Node {
public:
  int value;
  Node *left, *right;
  Node(int val) {
    value = val;
    left = nullptr, right = nullptr;
  }
};

// binary search tree
class BST {
public:
  Node *root;
  int numOfNodes; // size
  int size(void) { return numOfNodes; }

  // constructer
  BST(void) {
    root = nullptr;
    numOfNodes = 0;
  }

  // tree init
  void genNewTree(std::vector<int> &nums) {
    int i = 1;
    numOfNodes = nums.size();
    root = new Node(nums[0]);
    Node *cur;
    while (i < numOfNodes) {
      cur = root;
      while (true) {
        if (nums[i] <= cur->value) {
          if (cur->left == nullptr) {
            cur->left = new Node(nums[i++]);
            break;
          } else {
            cur = cur->left;
            continue;
          }
        } else {
          if (cur->right == nullptr) {
            cur->right = new Node(nums[i++]);
            break;
          } else {
            cur = cur->right;
            continue;
          }
        }
      }
    }
  }

  // print all nodes' value
  void all(void) {
    Node *cur = root;
    std::vector<Node *> stack;
    while (stack.size() || cur) { // iterative dfs method
      while (cur) {
        stack.push_back(cur);
        cur = cur->left;
      }

      cur = stack.back();
      std::cout << cur->value << " ";
      stack.pop_back();

      cur = cur->right;
    }
    std::cout << std::endl;
  }
};

// Thread Binary tree node structure
class TNode {
public:
  int value;
  TNode *left, *right;
  bool leftNull, rightNull;
  TNode(int val) {
    value = val;
    left = nullptr, right = nullptr;
    leftNull = true, rightNull = true;
  }
};

// Thread Binary Tree
class ThreadBT {
public:
  TNode *head;
  ThreadBT() { head = new TNode(-9999); } // head node init

  // find inorder successor
  TNode *insuc(TNode *x) {
    TNode *temp = x->right;
    if (!x->rightNull)
      while (!temp->leftNull)
        temp = temp->left;
    return temp;
  }
  // find inorder predecessor
  TNode *inpre(TNode *x) {
    TNode *temp = x->left;
    if (!x->leftNull)
      while (!temp->rightNull)
        temp = temp->right;
    return temp;
  }

  // insert node
  void insertRight(TNode *node, TNode *newNode) {
    newNode->right = node->right;
    newNode->rightNull = node->rightNull;
    newNode->left = node;
    newNode->leftNull = true;
    node->rightNull = false;
    node->right = newNode;
    // update successor's leftptr
    if (!newNode->rightNull) {
      TNode *temp = insuc(newNode);
      temp->left = newNode;
    }
  }
  void insertLeft(TNode *node, TNode *newNode) {
    newNode->left = node->left;
    newNode->leftNull = node->leftNull;
    newNode->right = node;
    newNode->rightNull = true;
    node->leftNull = false;
    node->left = newNode;
    // update predecessor's right ptr
    if (!newNode->leftNull) {
      TNode *temp = inpre(newNode);
      temp->right = newNode;
    }
  }

  // copy a binary search tree and turn into thread bt
  void copyBST(BST tree) {
    std::vector<Node *> st;
    std::vector<TNode *> stt;
    Node *cur = tree.root, *next;
    TNode *curT = new TNode(cur->value), *nextT;
    head->leftNull = false;
    head->left = curT;

    while (!st.empty() || cur) {

      while (cur) {
        st.push_back(cur);
        stt.push_back(curT);
        cur = cur->left;
        if (cur) {
          curT->left = new TNode(cur->value);
          curT->leftNull = false;
          curT = curT->left;
        }
      }

      cur = st.back();
      curT = stt.back();
      st.pop_back();
      stt.pop_back();

      cur = cur->right;
      if (cur) {
        curT->right = new TNode(cur->value);
        curT->rightNull = false;
        curT = curT->right;
      }
    }
  }

  // tackle on links
  void linking() {
    std::vector<TNode *> st;
    std::vector<TNode *> order;
    TNode *cur = head->left;

    // in order
    while (!st.empty() || cur) {
      while (cur) {
        st.push_back(cur);
        cur = cur->left;
      }

      cur = st.back();
      st.pop_back();
      order.push_back(cur);

      cur = cur->right;
    }

    // link all in order
    TNode *headNode = order[0], *tailNode = order[order.size() - 1];
    headNode->left = head;
    tailNode->right = head;
    int size = order.size();

    for (int i = 1; i < size - 1; i++) {
      if (order[i]->leftNull)
        order[i]->left = order[i - 1];
      if (order[i]->rightNull)
        order[i]->right = order[i + 1];
    }
  }

  // print all
  void all(void) {
    TNode *leftist = head->left;
    while (!leftist->leftNull) {
      leftist = leftist->left;
    }
    while (leftist != head) {
      std::cout << leftist->value << " ";
      leftist = insuc(leftist);
    }
    std::cout << std::endl;
  }
};

int main(void) {
  BST bst = BST();
  std::vector<int> nums;
  nums.push_back(5);
  nums.push_back(1);
  nums.push_back(2);
  nums.push_back(6);
  nums.push_back(3);
  nums.push_back(5);
  nums.push_back(7);
  nums.push_back(8);
  nums.push_back(3);
  nums.push_back(6);
  nums.push_back(9);
  bst.genNewTree(nums);
  bst.all();
  ThreadBT tbt = ThreadBT();
  tbt.copyBST(bst);
  tbt.linking();
  tbt.all();
  return 0;
}
