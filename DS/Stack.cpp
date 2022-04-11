#include <iostream>
#include <vector>
#define LENGTH 100


class Stack{
private: 
    int topIndex;
    int length;
    // int* items;
    std::vector<int> items;

public:
    Stack(int length){
        this->topIndex = 0;
        this->length = length;
        // this->items = new int[length];
        std::vector<int> vect(20);
        this->items = vect;
    }
    bool isEmpty(void);
    bool isFull(void);
    void push(int item);
    int pop(void);
};

bool Stack::isEmpty(void){
    return this->topIndex==0;
}

bool Stack::isFull(void){
    return this->topIndex==this->length;
}

void Stack::push(int item){
    if(this->isFull()){
        std::cout << "Stack is Full!" << std::endl;
        return;
    }
    this->items[this->topIndex++] = item;
}

int Stack::pop(void){
    if(this->isEmpty()){
        std::cout << "Stack is empty!" << std::endl;
        return -1;
    }
    return this->items[--this->topIndex];
}


// main function
int main(void){

    Stack stack(LENGTH);
    for(int i = 0; i<= LENGTH; i++){
        stack.push(i);
    }
    for(int i = 0; i<= LENGTH; i++){
        std::cout << stack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
