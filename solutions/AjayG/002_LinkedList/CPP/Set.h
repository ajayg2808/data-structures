#ifndef SET_H
#define SET_H

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
        Node<T> *p = this->HEAD;
        while (p->getNext() != nullptr)
        {
            p = p->getNext();
        }
        p->setNext(t);
        return true;
    }
    return false;
}

template <typename T>
bool Set<T>::add(int index, T data)
{
    if (this->search(data) != -1)
        return false;
    return super.add(index, data)
}

#endif