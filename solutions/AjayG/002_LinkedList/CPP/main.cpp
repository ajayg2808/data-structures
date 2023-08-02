#include <iostream>
#include "SinglyLinkedList.h"
#include "Set.h"
#include "Loop.h"

using namespace std;

void printOptions()
{
    cout << "\n\n1. Add element" << endl;
    cout << "2. Add element at index" << endl;
    cout << "3. Display element" << endl;
    cout << "4. Remove element" << endl;
    cout << "5. Remove element at index" << endl;
    cout << "6. Search element" << endl;
    cout << "7. Revert" << endl;
    cout << "8. Revert (Recursive)" << endl;
}

int workWithSet()
{
    Set<int> *set = new Set<int>();
    int ch = -1;
    do
    {
        printOptions();
        cout << "9. Exit" << endl;
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
                result = set->add(element);
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
                result = set->add(index, element);
                if (result)
                    cout << "Element added successfully." << endl;
                else
                    cout << "Failed to add element." << endl;
                break;
            case 3:
                cout << "Set elements: ";
                set->display();
                break;
            case 4:
                cout << "Enter element to remove: ";
                cin >> element;
                element = set->remove(element);
                cout << "Removed element: " << element << endl;
                break;
            case 5:
                cout << "Enter index to remove element: ";
                cin >> index;
                element = set->removeAt(index);
                cout << "Removed element: " << element << endl;
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> element;
                index = set->search(element);
                cout << "Element found at index: " << index << endl;
                break;
            case 7:
                set->revert();
                cout << "Set reverted." << endl;
                set->display();
                break;
            case 8:
                set->revertRecursive();
                cout << "Set reverted." << endl;
                set->display();
                break;
            case 9:
                cout << "Exiting from Set." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Please enter valid choice." << endl;
                break;
            }
        }
    } while (ch != 9);
    delete set;
    return 0;
}

int workWithSinglyLinkedList()
{

    SinglyLinkedList<int> *list = new SinglyLinkedList<int>();
    int ch = -1;
    do
    {
        printOptions();
        cout << "9. Exit" << endl;
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
                result = list->add(element);
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
                result = list->add(index, element);
                if (result)
                    cout << "Element added successfully." << endl;
                else
                    cout << "Failed to add element." << endl;
                break;
            case 3:
                cout << "List elements: ";
                list->display();
                break;
            case 4:
                cout << "Enter element to remove: ";
                cin >> element;
                element = list->remove(element);
                cout << "Removed element: " << element << endl;
                break;
            case 5:
                cout << "Enter index to remove element: ";
                cin >> index;
                element = list->removeAt(index);
                cout << "Removed element: " << element << endl;
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> element;
                index = list->search(element);
                cout << "Element found at index: " << index << endl;
                break;
            case 7:
                list->revert();
                cout << "List reverted." << endl;
                list->display();
                break;
            case 8:
                list->revertRecursive();
                cout << "List reverted." << endl;
                list->display();
                break;
            case 9:
                cout << "Exiting from SLL." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Please enter valid choice." << endl;
                break;
            }
        }

    } while (ch != 9);

    delete list;
    return 0;
}

int workWithLoopList()
{

    LoopList<int> *list = new LoopList<int>();
    int ch = -1;
    do
    {
        printOptions();
        cout << "9. Create loop" << endl;
        cout << "10. Is loop present" << endl;
        cout << "11. Loop element" << endl;
        cout << "12. Remove loop" << endl;
        cout << "13. Exit" << endl;
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
                result = list->add(element);
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
                result = list->add(index, element);
                if (result)
                    cout << "Element added successfully." << endl;
                else
                    cout << "Failed to add element." << endl;
                break;
            case 3:
                cout << "List elements: ";
                list->display();
                break;
            case 4:
                cout << "Enter element to remove: ";
                cin >> element;
                element = list->remove(element);
                cout << "Removed element: " << element << endl;
                break;
            case 5:
                cout << "Enter index to remove element: ";
                cin >> index;
                element = list->removeAt(index);
                cout << "Removed element: " << element << endl;
                break;
            case 6:
                cout << "Enter element to search: ";
                cin >> element;
                index = list->search(element);
                cout << "Element found at index: " << index << endl;
                break;
            case 7:
                list->revert();
                cout << "List reverted." << endl;
                list->display();
                break;
            case 8:
                list->revertRecursive();
                cout << "List reverted." << endl;
                list->display();
                break;
            case 9:
                cout << "Enter destination element: ";
                cin >> element;
                list->createLoop(element);
                cout << "Loop created." << endl;
                break;
            case 10:
                if (list->isConnectedLoop())
                    cout << "Connected loop is present." << endl;
                else
                    cout << "Connected loop is not present." << endl;
                break;
            case 11:
                element = list->loopAt();
                cout << "Connected loop is present at: " << element << endl;
                break;
            case 12:
                if (list->removeLoop())
                    cout << "Connected loop is removed." << endl;
                else
                    cout << "Connected loop is not removed or not present." << endl;
                break;
            case 13:
                cout << "Exiting from Loop list." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Please enter valid choice." << endl;
                break;
            }
        }

    } while (ch != 13);

    delete list;
    return 0;
}

int main(int argc, char *argv[])
{
    int ch = -1;
    int retVal = 0;
    do
    {
        cout << "\n\n1. Singly Linked List" << endl;
        cout << "2. Set" << endl;
        cout << "3. Loop List" << endl;
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            retVal = workWithSinglyLinkedList();
            break;
        case 2:
            retVal = workWithSet();
            break;
        case 3:
            retVal = workWithLoopList();
            break;
        case 4:
            cout << "\nThank You!" << endl;
            return 0;
        default:
            cout << "\n Wrong choice" << endl;
            break;
        }
    } while (true);
    return retVal;
}