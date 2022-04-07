#include <iostream>

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

class XORList
{
public:
    Node *head;
    XORList(void)
    {
        head = new Node(0);
    }
    void add(int data)
    {
        Node *newNode = new Node(data);
        newNode->pointer = this->head;
        this->head->pointer = (Node *)((uintptr_t)(this->head->pointer) ^ (uintptr_t)newNode);
        this->head = newNode;
    }
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
    xorlist.all();
    return 0;
}
