#include <iostream>
#include <stdlib.h>
#include <time.h>
#define LENGTH 10

// Generate an array contains random numbers
void genIntArr(int *arr)
{
    // Init random seed.
    srand(time(0));
    std::cout << "Gen Array: ";
    for (int i = 0; i < LENGTH; i++)
    {
        arr[i] = rand() % 100;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Node
class Node
{
public:
    // Store data, left ptr, right ptr.
    int data;
    Node *left;
    Node *right;

    // Constructor
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Tree part
class BT
{
public:
    Node *root;

    // constructor
    BT()
    {
        this->root = NULL;
    }

    // Generate a Sorted Binary Tree
    void genSortedBinaryTree(int *arr)
    {
        Node *root = new Node(arr[0]);
        this->root = root;
        for (int i = 1; i < LENGTH; i++)
            insertNode(this->root, arr[i]);
    }

    // Insert Node
    void insertNode(Node *current, int num)
    {
        // if num is smaller than current node's data, go to the left of current node
        if (num < current->data)
        {
            // if left child missing, then create a left child
            if (current->left == NULL)
                current->left = new Node(num);
            
            // Otherwise, check left child
            else
                insertNode(current->left, num);
        }
        // if num is larger than current node's data, go to the right of current node
        else
        {
            if (current->right == NULL)
                current->right = new Node(num);
            else
                insertNode(current->right, num);
        }
    }
};

// Use inorder traversal to run a sorted BT, output will be a sorted sequence
void inorder(Node *current)
{
    // Read sequence: left, current, right
    if (current == NULL)
        return;
    if (current->left)
        inorder(current->left);
    std::cout << current->data << " ";
    if (current->right)
        inorder(current->right);
}

int main(void)
{
    int *arr = new int[LENGTH];
    genIntArr(arr);
    //O(n)

    BT bt = BT();
    bt.genSortedBinaryTree(arr);
    //O(nlgn)

    std::cout << "BS Output: ";
    inorder(bt.root);
    std::cout << std::endl;
    //O(nlgn)
    return 0;
}