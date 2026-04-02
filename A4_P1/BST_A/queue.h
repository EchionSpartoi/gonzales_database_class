#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

//this is a template class i made for the generic queue. 
//it is a circullar array implementation. 
//annnnd standard queue operations are in here ie. enqueue, dequeue, and isempty

template <typename T>
class Queue {
private:
    T* data;
    int front;
    int rear;
    int capacity;
    int size;

public:
    Queue(int cap = 100);
    ~Queue();
    
    void enqueue(T item);
    T dequeue();
    bool isEmpty();
    bool isFull();
};

template <typename T>
Queue<T>::Queue(int cap) : capacity(cap), front(0), rear(-1), size(0) {
    data = new T[capacity];
}

template <typename T>
Queue<T>::~Queue() {
    delete[] data;
}

template <typename T>
void Queue<T>::enqueue(T item) {
    if (isFull()) return;
    rear = (rear + 1) % capacity;
    data[rear] = item;
    size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) throw runtime_error("Queue empty");
    T item = data[front];
    front = (front + 1) % capacity;
    size--;
    return item;
}

template <typename T>
bool Queue<T>::isEmpty() { return size == 0; }

template <typename T>
bool Queue<T>::isFull() { return size == capacity; }

#endif
