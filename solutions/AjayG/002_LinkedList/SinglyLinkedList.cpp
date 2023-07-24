#include <iostream>
using namespace std;
template <typename T>
class Node
{
    T data;
    Node *next;

public:
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
    }

    T getData()
    {
        return this->data;
    }

    Node *getNext()
    {
        return this->next;
    }

    void setData(T data)
    {
        this->data = data;
    }

    void setNext(Node *node)
    {
        this->next = node;
    }
};

template <typename T>
class SinglyLinkedList
{
private:
    Node<T> *HEAD;

public:
    SinglyLinkedList();
    bool add(T data);
    bool add(int index, T data);
    // T delete(T data);
    // T delete(int index);
    void display();
    ~SinglyLinkedList();
};
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    this->HEAD = nullptr;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    Node<T> *temp = this->HEAD;
    while (temp != nullptr)
    {
        Node<T> *p = temp->getNext();
        delete temp;
        temp = p;
    }
}

template <typename T>
bool SinglyLinkedList<T>::add(T data)
{
    Node<T> *t = new Node<T>(data);
    Node<T> *p = this->HEAD;
    Node<T> *q = nullptr;
    while (p != nullptr)
    {
        q = p;
        p = p->getNext();
    }
    if (q == nullptr)
    {
        this->HEAD = t;
        return true;
    }
    else
    {
        q->setNext(t);
        return true;
    }
    return false;
}

template <typename T>
bool SinglyLinkedList<T>::add(int index, T data)
{
    Node<T> *q, *p = this->HEAD;
    int i = 0;
    if (p == nullptr && index == 0)
    {
        this->HEAD = new Node<T>(data);
    }
    else
    {
        while (p->getNext() != nullptr && i < index)
        {
            i++;
            q = p;
            p = p->getNext();
        }
        if (p != nullptr && i == index)
        {
            q->setNext(new Node<T>(data));
            q->getNext()->setNext(p);
        }
    }
}

template <typename T>
void SinglyLinkedList<T>::display()
{
    Node<T> *p = this->HEAD;
    while (p != nullptr)
    {
        T t = p->getData();
        cout << t << " ";
        p = p->getNext();
    }
}

int main(int argc, char *argv[])
{
    SinglyLinkedList<int> list;
    cout << "Signly Linked List created" << endl;
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(5);
    list.add(6);
    cout << "Elements in linked list: ";
    list.display();
    list.add(3, 4);
    cout << "\n\nElements in linked list: ";
    list.display();
    return 0;
}