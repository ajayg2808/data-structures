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
        Node<T> *node = this->HEAD;
        do
        {
            node->setIsVisited(false);
            node = node->getNext();
            cout << "\n Not visited: " << data << endl
        } while (node != nullptr);
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
        Node<T> *p, *q = this->HEAD;
        p = q;
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
            if (p->getData() == dest)
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

    cout << "\n Setting not visited\n";
    this->markNotVisited();
    cout << "\n Marked not visited\n";
    Node<T> *q, *p = this->HEAD;
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
        return NULL;

    this->markNotVisited();

    Node<T> *p = this->HEAD;
    while (p != nullptr)
    {
        if (p->getIsVisited())
        {
            return p->getData();
        }

        p->setIsVisited(true);
        p = p->getNext();
    }
    return NULL;
}

template <typename T>
bool LoopList<T>::removeLoop()
{
    if (this->isEmpty())
        return false;

    this->markNotVisited();

    Node<T> *q, *p = this->HEAD;
    q = p->getNext();
    while (q != nullptr)
    {
        if (q->getIsVisited())
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