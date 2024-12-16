#pragma once
#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    int full;
    Node* next;
    Node* prev;

    Node() : data(0), full(0), next(nullptr), prev(nullptr) {}
    Node(T data) : data(data), full(1), next(nullptr), prev(nullptr) {}
};

template<class T>
class Array {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Array() : head(nullptr), tail(nullptr) {}

    void append();
    void append(T value);
    void Append(Array& obj);
    void removeLast();
    void print() const;
    bool search(T value) const;
    int GetSize();
    void SetSize(int size, int grow = 1);
    bool IsEmpty();
    void RemoveAll();
    const T GetAt(int index);
    void SetAt(int index, T elem);
    int GetUpperBound();
    void FreeExtra();
    T operator[](int indx);
    Node<T>& Get_data();
    void InsertAt(int indx, T value);

    ~Array();
};

#include "Array.inl"