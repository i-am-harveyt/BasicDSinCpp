#include <iostream>

// List node, have data and only one pointer, initialized by NULL
class Node
{
public:
    int data;
    Node *pointer;
    Node(int data)
    {
        this->data = data;
        this->pointer = NULL;
    }
};

// XORList, contains a headNode pointer and some utility functions
class XORList
{
public:
    Node *head;
    XORList(void)
    {
        head = new Node(0);
    }

    // create a new Node, setup newNode's pointer points to head, and set head's pointer by new^prev
    void add(int data)
    {
        Node *newNode = new Node(data);
        newNode->pointer = this->head;
        this->head->pointer = (Node *)((uintptr_t)(this->head->pointer) ^ (uintptr_t)newNode);

        // update new head.
        this->head = newNode;
    }

    // remove head
    void remove(void)
    {
        Node *removeNode = this->head;
        
        // new head is the previous(or in some perspective, next) of current head.
        Node *newHead = (Node *)((uintptr_t)removeNode->pointer ^ (uintptr_t)NULL);

        // update the new head's pointer
        newHead->pointer = (Node *)((uintptr_t)newHead->pointer ^ (uintptr_t)removeNode);
        delete removeNode;

        // update head
        this->head = newHead;
    }

    // the function to view all data in this list, use the characteristic of A^(A^B) = B, the spirit of XOR
    void all(void)
    {
        Node *current = this->head;
        Node *prev = (Node *)NULL;
        Node *temp;
        while (current)
        {
            std::cout << current->data << " ";
            temp = current;
            current = (Node *)((uintptr_t)current->pointer ^ (uintptr_t)prev);
            prev = temp;
        }
        std::cout << std::endl;
    }
};

int main(void)
{
    XORList xorlist = XORList();
    for (int i = 1; i < 10; i++)
        xorlist.add(i);
    xorlist.remove();
    xorlist.add(100);
    xorlist.all();
    return 0;
}
