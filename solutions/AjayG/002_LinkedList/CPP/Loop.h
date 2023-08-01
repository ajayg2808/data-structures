#ifndef LOOP_H
#define LOOP_H

#include "SinglyLinkedList.h"

template <typename T>
class LoopList : public SinglyLinkedList<T>
{
private:
    void markNotVisited();

public:
    void createLoop(T dest);
    bool isConnectedLoop();
    T loopAt();
    bool removeLoop();
};

template <typename T>
void LoopList<T>::markNotVisited()
{
    if (!this->isEmpty())
    {
        Node *node = this->HEAD;
        while (node != nullptr)
        {
            node->setIsVisited(false);
            node = node->getNext();
        }
    }
}

template <typename T>
void LoopList<T>::createLoop(T dest)
{
    if (!this->isEmpty())
    {
        if (this->search(dest) == -1)
        {
            cout << "\nDestination: " << dest << " not present in list" << endl;
            return;
        }

        bool isDestPresent = false;
        Node *p = *q = this->HEAD;

        do
        {
            if (p->getData() == dest)
            {
                q = p;
            }
            p = p->getNext();
        } while (p->getNext() != nullptr);
        if (p == nullptr)
        {
            p = this->HEAD;
        }
        else
        {
            if (p->getData() == data)
                q = p;
        }
        p->setNext(q);
    }
}

template <typename T>
bool LoopList<T>::isConnectedLoop()
{
    if (this->isEmpty())
        return false;

    Node *q, *p = this->HEAD;
    q = p->getNext();

    while (p != nullptr && q != nullptr)
    {
        p = p->getNext();
        q = q->getNext();
        if (q != nullptr)
        {
            q = q->getNext();
        }
        if (p == q)
        {
            return true;
        }
    }
    return false;
}

template <typename T>
T LoopList<T>::loopAt()
{
    if (this->isEmpty())
        return (T) nullptr;

    Node *p = this->HEAD;
    while (p != nullptr)
    {
        if (p->isVisited())
        {
            return p->getData();
        }

        p->setIsVisited(true);
    }
    return (T) nullptr;
}

template <typename T>
bool LoopList<T>::removeLoop()
{
    if (this->isEmpty())
        return false;

    Node *p = this->HEAD;
    q = p->getNext();
    while (q != nullptr)
    {
        if (q->isVisited())
        {
            p->setNext(nullptr);
            return true;
        }

        q->setIsVisited(true);
        p = q;
        q = p->getNext();
    }
    return false;
}

#endif