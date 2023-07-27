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

    Node<T> *revert(Node<T> *p);

public:
    SinglyLinkedList();
    bool add(T data);
    bool add(int index, T data);
    int size();
    bool isEmpty()
    {
        if (this->HEAD == nullptr)
            return true;
        return false;
    }
    T remove(T data);
    T removeAt(int index);
    void revert();
    void revertRecursive();
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
    if (this->isEmpty())
    {
        this->HEAD = t;
        return true;
    }
    else
    {
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
bool SinglyLinkedList<T>::add(int index, T data)
{
    Node<T> *t = new Node<T>(data);
    Node<T> *p = this->HEAD;
    if (index == 0)
    {
        t->setNext(p);
        this->HEAD = t;
        return true;
    }
    else
    {
        while (p->getNext() != nullptr && --index > 0)
        {
            p = p->getNext();
        }
        if (index > 1)
            return false;

        t->setNext(p->getNext());
        p->setNext(t);
        return true;
    }
    return false;
}

template <typename T>
int SinglyLinkedList<T>::size()
{
    int count = 0;
    Node<T> *p = this->HEAD;
    while (p != nullptr)
    {

        count++;
        p = p->getNext();
    }
    return count;
}

template <typename T>
T SinglyLinkedList<T>::remove(T data)
{
    if (!this->isEmpty())
    {
        Node<T> *q, *p = this->HEAD;
        do
        {
            if (p->getData() == data)
            {

                if (p == this->HEAD)
                {
                    this->HEAD = p->getNext();
                }
                else
                {
                    q->setNext(p->getNext());
                }
                T value = p->getData();
                delete (p);
                return value;
            }
            q = p;
            p = p->getNext();
        } while (p != nullptr);
    }
    return (T) nullptr;
}

template <typename T>
T SinglyLinkedList<T>::removeAt(int index)
{
    if (!this->isEmpty())
    {
        Node<T> *q, *p;
        q = p = this->HEAD;
        if (index == 0)
        {
            T data = p->getData();
            this->HEAD = p->getNext();
            delete p;
            return data;
        }
        while (p != nullptr && --index >= 0)
        {
            q = p;
            p = p->getNext();
        }
        if (p == nullptr)
            return (T) nullptr;

        T data = p->getData();
        q->setNext(p->getNext());
        delete p;
        return data;
    }
    else
        return (T) nullptr;
}

template <typename T>
void SinglyLinkedList<T>::revert()
{
    if (!this->isEmpty())
    {
        Node<T> *q = nullptr, *r = nullptr, *p = this->HEAD;
        while (p != nullptr)
        {
            r = p->getNext();
            p->setNext(q);
            q = p;
            p = r;
        }
        this->HEAD = q;
    }
}

template <typename T>
void SinglyLinkedList<T>::revertRecursive()
{
    if (!this->isEmpty())
    {
        this->HEAD = this->revert(this->HEAD);
    }
}

template <typename T>
Node<T> *SinglyLinkedList<T>::revert(Node<T> *p)
{
    if (p == nullptr || p->getNext() == nullptr)
        return p;

    Node<T> *q = this->revert(p->getNext());
    p->getNext()->setNext(p);
    p->setNext(nullptr);
    return q;
}
template <typename T>
void SinglyLinkedList<T>::display()
{
    Node<T> *p = this->HEAD;
    cout << "[ ";
    while (p != nullptr)
    {
        T t = p->getData();
        cout << t << " ";
        p = p->getNext();
    }
    cout << "]" << endl;
}

int main(int argc, char *argv[])
{
    int ch = -1;
    SinglyLinkedList<int> list;
    do
    {

        cout << "\n\n1. Add element" << endl;
        cout << "2. Add element at index" << endl;
        cout << "3. Display element" << endl;
        cout << "4. Remove element" << endl;
        cout << "5. Remove element at index" << endl;
        cout << "6. Revert list" << endl;
        cout << "7. Revert list (Recursive)" << endl;
        cout << "8. Exit" << endl;
        cout << "Select option: ";
        cin >> ch;

        int element;
        int index;
        bool result;
        switch (ch)
        {
            {
            case 1:
                cout << "Enter element to add: ";
                cin >> element;
                result = list.add(element);
                if (result)
                    cout << "Element added successfully." << endl;
                else
                    cout << "Failed to add element." << endl;
                break;
            case 2:
                cout << "Enter element to add: ";
                cin >> element;
                cout << "Enter index: ";
                cin >> index;
                result = list.add(index, element);
                if (result)
                    cout << "Element added successfully." << endl;
                else
                    cout << "Failed to add element." << endl;
                break;

            case 3:
                cout << "List elements: ";
                list.display();
                break;

            case 4:
                cout << "Enter element to remove: ";
                cin >> element;
                element = list.remove(element);
                cout << "Removed element: " << element << endl;
                break;
            case 5:
                cout << "Enter index to remove element: ";
                cin >> index;
                element = list.removeAt(index);
                cout << "Removed element: " << element << endl;
                break;

            case 6:
                list.revert();
                cout << "List reverted." << endl;
                list.display();
                break;

            case 7:
                list.revertRecursive();
                cout << "List reverted." << endl;
                list.display();
                break;

            case 8:
                cout << "Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Please enter valid choice." << endl;
                break;
            }
        }

    } while (ch != 8);

    return 0;
}