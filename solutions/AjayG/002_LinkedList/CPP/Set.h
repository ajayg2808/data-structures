#ifndef SET_H
#define SET_H

#include "SinglyLinkedList.h"

template <typename T>
class Set : public SinglyLinkedList<T>
{
public:
    bool add(T data);
    bool add(int index, T data);
};

template <typename T>
bool Set<T>::add(T data)
{
    Node<T> *t = new Node<T>(data);
    if (this->isEmpty())
    {
        this->HEAD = t;
        return true;
    }
    else
    {
        if (this->search(data) != -1)
            return false;
        return SinglyLinkedList<T>::add(data);
    }
    return false;
}

template <typename T>
bool Set<T>::add(int index, T data)
{
    if (this->search(data) != -1)
        return false;
    return SinglyLinkedList<T>::add(index, data);
}

#endif