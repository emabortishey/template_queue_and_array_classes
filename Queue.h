#pragma once
#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template<class T>
class Queue {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    void append(T value);
    void removeLast();
    void print() const;
    bool search(T value) const;

    ~Queue();
};

#include "Queue.inl"