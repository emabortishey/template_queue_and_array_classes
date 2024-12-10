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
class Array {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Array() : head(nullptr), tail(nullptr) {}

    void append(T value);
    void removeLast();
    void print() const;
    bool search(T value) const;
    int GetSize();
    void SetSize(int size, int grow = 1);
    bool IsEmpty();
    void RemoveAll();
    const T GetAt(int index);
    void SetAt(int index, T elem);

    ~Array();
};

#include "Array.inl"