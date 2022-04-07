#include <iostream>

class Queue
{
private:
    int front;
    int rear;
    int length;
    int *items;

public:
    Queue(int length)
    {
        this->items = new int[length + 1];
        this->front = 0;
        this->rear = 0;
        this->length = length + 1;
    }
    void push(int item)
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
    int pop(void)
    {
        if (this->rear >= this->front)
        {
            std::cout << "Queue is empty" << std::endl;
            this->rear = (this->rear + this->length -1) % this->length;
            return -1;
        }
        this->rear = (this->rear + 1) % this->length;
        return this->items[this->rear];
    }
    void all(void)
    {
        for (int i = 0; i < this->length; i++)
            std::cout << this->items[i] << " ";
        std::cout << std::endl;
    }
};

int main(void)
{
    Queue queue = Queue(5);
    queue.push(5);
    queue.push(4);
    queue.push(3);
    queue.push(2);
    queue.push(1);
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    std::cout << queue.pop() << std::endl;
    return 0;
}
