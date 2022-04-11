#include <iostream>
#define LENGTH 20

// define ListNode, with next and prev pointer.
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int item)
    {
        this->data = item;
        this->next = NULL;
        this->prev = NULL;
    }
};

// define doubly linked list
class DoublyLinkedList
{
public:
    Node *root;
    DoublyLinkedList(void)
    {
        // give a dummy Node
        this->root = new Node(-1);
    }

    // insert node from root
    void insert(int item)
    {
        Node *oldRoot = this->root;
        Node *newNode = new Node(item);
        newNode->next = oldRoot;
        oldRoot->prev = newNode;
        this->root = newNode;
    }

    // read data from every Node.
    void all(void)
    {
        Node *current = this->root;
        while (current->next != NULL)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    DoublyLinkedList dbl = DoublyLinkedList();

    for (int i = 0; i < LENGTH; i++)
        dbl.insert(i);

    dbl.all();
    return 0;
}