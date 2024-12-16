#pragma once

template<class T>
void Array<T>::append()
{
    Node<T>* newNode = new Node<T>;

    if (tail == nullptr)
    {
        head = tail = newNode;
        size = 1;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }
}

template<class T>
void Array<T>::append(T value)
{
    Node<T>* newNode = new Node<T>(value);

    if (tail == nullptr)
    {
        head = tail = newNode;
        size = 1;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }
}

template<class T>
void Array<T>::Append(Array& obj)
{
    T buff;

    for (int i = 0; i<obj.GetSize(); i++)
    {
        buff = obj[i];
        append(buff);
        size++;
    }
}

template<class T>
int Array<T>::GetSize()
{
    return size;
}

template<class T>
void Array<T>::SetSize(int size_P, int grow)
{
    size = size_P;

    if (size>GetSize())
    {
        int diff = size - GetSize();

        for (int i = 0; i < diff; i++) 
        {
            for (int j = 0; j < grow; j++)
            {
                append(); 
            }
        }
    }
    else
    {
        int diff = GetSize()-size;
        int size_buff = 1;
        Node<T>* buff = head;

        while (size_buff!=diff)
        {
            size_buff++;
            buff = buff->next;
        }
        buff->next = nullptr;
    }
}

template<class T>
bool Array<T>::IsEmpty()
{
    return head == nullptr;
}

template<class T>
void Array<T>::RemoveAll()
{
    head = tail = nullptr;
}

template<class T>
const T Array<T>::GetAt(int index)
{
    if (index < GetSize() && index >= 0)
    {
        int size_buff = 0;
        Node<T>* buff = head;

        while (size_buff != index)
        {
            size_buff++;
            buff = buff->next;
        }

        return buff->data;
    }
    else
    {
        return T();
    }
}

template<class T>
void Array<T>::SetAt(int index, T elem)
{
    if (index < GetSize() && index >= 0)
    {
        int size_buff = 0;
        Node<T>* buff = head;

        while (size_buff != index)
        {
            size_buff++;
            buff = buff->next;
        }

        buff->data = elem;
        buff->full = 1;
    }
}

template<class T>
int Array<T>::GetUpperBound()
{
    Node<T>* buff = head;
    int buff_indx = -1;

    while (buff->full != 0)
    {
        buff_indx++;
        buff = buff->next;
    }

    return buff_indx;
}

template<class T>
void Array<T>::FreeExtra()
{
    int UpperBound = GetUpperBound();
    Node<T>* buff = head;

    for (int i = 0; i < UpperBound; i++)
    {
        buff = buff->next;
    }

    buff->next = nullptr; 
}

template<class T>
T Array<T>::operator[](int indx)
{
    int size_buff = 0;
    Node<T>* buff = head;

    while (size_buff != indx)
    {
        size_buff++;
        buff = buff->next;
    }

    return buff->data;
}

template<class T>
Node<T>& Array<T>::Get_data()
{
    return head;
}

template<class T>
void Array<T>::InsertAt(int indx, T value)
{
    Node<T>* newnode = new Node<T>;
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
    Node<T>* buff = head;
    Node<T>* buff_indx = head;
    T buff_value;

    for (int i = 0; i < indx-1; i++)
    {
        buff = buff->next;
    }

    buff_indx = buff;

    for (int i = indx; i < GetSize() && buff->next!=nullptr; i++)
    {
        buff_value = buff->next->data;
        buff->next->data = buff->data;
        buff = buff->next;
        buff->data = buff_value;
    }

    buff_indx->data = value;
}

template<class T>
void Array<T>::removeLast()
{
    if (head == nullptr)
    {
        cout << "Список пуст. Удаление невозможно.\n";
        return;
    }
    else if (head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* temp = tail;

        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
    }
}

template<class T>
void Array<T>::print() const
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

template<class T>
bool Array<T>::search(T value) const
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        if (current->data == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

template<class T>
Array<T>::~Array()
{
    Node<T>* current = head;

    while (current != nullptr)
    {
        Node<T>* nextNode = current->next;

        delete current;
        current = nextNode;
    }
}