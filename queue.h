#include <iostream>


template<typename T>
struct node{
    T data;
    node* next;
    node(T d){
        data = d;
        next = nullptr;
    }
};

template <typename T>
class queue {
private:
    int currSize = 0;
    node<T>* head = nullptr;
    node<T>* tail = nullptr;
public:
    void push(T);
    void pop();
    T front() { return head->data;}
    int size() { return currSize;}
    bool empty(){return currSize == 0;}
    void moveToRear();
};



// Function definitions below

template <typename T>
void queue<T>::push(T value){
    if(head == nullptr){
        head = new node<T>(value);
        tail = head;
    }
    else{
        node<T>* temp = new node<T>(value);
        tail->next = temp;
        tail = temp;
    }
    currSize += 1;
}

template<typename T>
void queue<T>::pop() {
    node<T>* temp = head->next;
    delete head;
    head = temp;
    currSize -= 1;
}

template<typename T>
void queue<T>::moveToRear() {
    push(front());
    pop();
}