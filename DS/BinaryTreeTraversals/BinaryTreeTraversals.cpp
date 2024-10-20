#include "./BT.hpp"
#include <iostream>
#include <queue>

using namespace BT;

void preorder(Node *current) {
  if (current == NULL)
    return;
  std::cout << current->data << " ";
  if (current->left)
    preorder(current->left);
  if (current->right)
    preorder(current->right);
}
void inorder(Node *current) {
  if (current == NULL)
    return;
  if (current->left)
    inorder(current->left);
  std::cout << current->data << " ";
  if (current->right)
    inorder(current->right);
}
void postorder(Node *current) {
  if (current == NULL)
    return;
  if (current->left)
    postorder(current->left);
  if (current->right)
    postorder(current->right);
  std::cout << current->data << " ";
}

int main(void) {
  BiTree tree = BiTree();
  std::cout << "Preorder: ";
  preorder(tree.get_root());
  std::cout << std::endl;
  std::cout << "Inorder: ";
  inorder(tree.get_root());
  std::cout << std::endl;
  std::cout << "Postorder: ";
  postorder(tree.get_root());
  std::cout << std::endl;

  return 0;
}
