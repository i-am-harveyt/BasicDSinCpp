#include <iostream>

class Node
{
private:
    int data;
    Node *next;

public:
    Node(int item)
    {
        this->setData(item);
        this->setNext(NULL);
    }
    void setData(int item)
    {
        this->data = item;
    }
    int getData(void)
    {
        return this->data;
    }
    void setNext(Node *next)
    {
        this->next = next;
    }
    Node *getNext(void)
    {
        return this->next;
    }
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue(void)
    {
        this->front = NULL;
        this->rear = NULL;
    }
    void enqueue(int item)
    {
        Node *newNode = new Node(item);
        if (this->front == NULL)
        {
            this->front = newNode;
        }
        else
        {
            Node *tail = this->rear;
            tail->setNext(newNode);
        }
        this->rear = newNode;
    }
    int dequeue(void)
    {
        if (this->front == NULL)
        {
            std::cout << "The Queue is empty" << std::endl;
            return -1;
        }
        Node *removeNode = this->front;
        int ret = removeNode->getData();

        // std::cout << this->rear << " " << this->front << std::endl;

        if (this->rear != this->front)
        {
            Node *nextNode = removeNode->getNext();
            this->front = nextNode;
        }
        else
        {
            this->front = NULL;
            this->rear = NULL;
        }
        delete removeNode;
        return ret;
    }
};

int main(void)
{
    Queue queue = Queue();
    queue.enqueue(5);
    queue.enqueue(10);
    queue.enqueue(15);
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;
    std::cout << queue.dequeue() << std::endl;

    return 0;
}