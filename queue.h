#include <iostream>

using namespace std;

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

class linkedList {
private:
    node<int>* headPtr;
    node<int>* tailPtr;
    int size = 0;
public:
    linkedList();
    void insertionSort();
    void push_back(int);
    void print();
    bool empty();
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

linkedList::linkedList(){
    headPtr = nullptr;
    tailPtr = nullptr;
    size = 0;
}

void linkedList::push_back(int value){
    node<int>* temp = new node<int>(value);
    temp->data = value;
    if(headPtr != nullptr){
        tailPtr->next = temp;
        temp->next = nullptr;
        tailPtr = temp; //update tail to new node
    }
    else{
        headPtr = temp;
        tailPtr = temp;
    }
    size++;

}

void linkedList::print(){
    node<int>* temp = headPtr;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool linkedList::empty() {
    if(headPtr == nullptr)
        return true;
    else
        return false;
}

void linkedList::insertionSort() {
    node<int>* start = new node<int>(-1);
    start->next = headPtr; //start before the head
    node<int>* cur = headPtr;
    node<int>* prev = start;

    while (cur) {
        if (cur->next && cur->next->data < cur->data) { // compare values of current and what to the right
            while (prev->next && prev->next->data < cur->next->data) {
                prev = prev->next; //update
            }
            node<int>* temp = prev->next;
            prev->next = cur->next;          //Updating the positions
            cur->next = cur->next->next;
            prev->next->next = temp;

            prev = start;
        } else {
            cur = cur->next; // carry on if values are already sorted
        }
    }
}