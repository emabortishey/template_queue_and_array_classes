#pragma once
#include <iostream>

using namespace std;

template<class T>
class Node {
public:
    T data;
    // атрибут означающий заполнен узел или нет
    bool full;
    Node* next;
    Node* prev;

    Node() : data(0), full(false), next(nullptr), prev(nullptr) {}
    explicit Node(T data_P) : data(data_P), full(true), next(nullptr), prev(nullptr) {}
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
    void DeleteAt(int indx);

    ~Array();
};

#include "Array.inl"