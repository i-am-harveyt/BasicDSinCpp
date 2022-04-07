#include <iostream>
#include <stdlib.h>
#include <time.h>

// Node
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

class Queue
{
private:
    int front;
    int rear;
    int length;
    Node **items;

public:
    Queue(int length)
    {
        this->items = new Node *[length + 1];
        this->front = 0;
        this->rear = 0;
        this->length = length + 1;
    }
    void enqueue(Node *item)
    {
        this->front = (this->front + 1) % this->length;
        if (this->front == this->rear)
        {
            std::cout << "Queue is full" << std::endl;
            this->front = (this->front + this->length - 1) % this->length;
            return;
        }
        this->items[this->front] = item;
    }
    Node *dequeue(void)
    {
        if (this->rear >= this->front)
        {
            std::cout << "Queue is empty" << std::endl;
            this->rear = (this->rear + this->length - 1) % this->length;
            return NULL;
        }
        this->rear = (this->rear + 1) % this->length;
        return this->items[this->rear];
    }
    void all(void)
    {
        for (int i = 0; i < this->length; i++)
            if (this->items[i] != NULL)
                std::cout << (this->items[i])->data << " ";
        std::cout << std::endl;
    }
};

// Tree part
class BT
{
public:
    Node *root;
    BT(Queue q)
    {
        this->root = NULL;
        genNewTree(q);
    }
    void genNewTree(Queue q)
    {
        Node *root = new Node(0);
        this->root = root;
        q.enqueue(root);
        // set seed for ran() or it will return same sequence
        srand(time(0));
        for (int i = 1; i < 7; i++)
        {
            Node *current = q.dequeue();
            int param = rand() % 100 % 2;

            Node *newNode = new Node(i);
            if (param == 0)
            {
                if (current->left == NULL)
                    current->left = newNode;
                else
                    current->right = newNode;
            }
            else if (param == 1)
            {
                if (current->right == NULL)
                    current->right = newNode;
                else
                    current->left = newNode;
            }
            else
            {
                q.enqueue(current);
                continue;
            }
            if (!(current->left && current->right))
                q.enqueue(current);
            q.enqueue(newNode);
        }
    }
    void preorder(Node *current)
    {
        if (current == NULL)
            return;
        std::cout << current->data << " ";
        if (current->left)
            preorder(current->left);
        if (current->right)
            preorder(current->right);
    }
    void inorder(Node *current)
    {
        if (current == NULL)
            return;
        if (current->left)
            inorder(current->left);
        std::cout << current->data << " ";
        if (current->right)
            inorder(current->right);
    }
    void postorder(Node *current)
    {
        if (current == NULL)
            return;
        if (current->left)
            postorder(current->left);
        if (current->right)
            postorder(current->right);
        std::cout << current->data << " ";
    }
};

int main(void)
{
    Queue queue = Queue(20);
    BT tree = BT(queue);
    std::cout << "Preorder: ";
    tree.preorder(tree.root);
    std::cout << std::endl;
    std::cout << "Inorder: ";
    tree.inorder(tree.root);
    std::cout << std::endl;
    std::cout << "Postorder: ";
    tree.postorder(tree.root);
    std::cout << std::endl;

    return 0;
}
