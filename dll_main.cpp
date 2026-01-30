#include "dll.h"
#include <iostream>

void displayDList(dnode *head) 
{
    dnode* walker = head;
    while(walker != nullptr)
    {
        cout << walker->data << " ";
        walker = walker->next;
    }
    cout << endl;
}

int main()
{
    dnode *head = nullptr;
    int choice, data, index;
    
    do {
        cout << endl;
        cout << "=== DOUBLY LINKED LIST TEST (Task 3) ===" << endl;
        cout << "1. Insert a new node" << endl;
        cout << "2. Remove a node" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Exit" << endl << endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "What value do you want to insert:  ";
                cin >> data;
                cout << "Which index do want to insert at:  ";
                cin >> index;
                insertDNode(head, index, data);
                break;
            case 2:
                cout << "Which index do you want to remove:  ";
                cin >> index;
                deleteDNode(head, index);
                break;
            case 3:
                displayDList(head);
                break;
            case 4:
                cout << "See you" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << "Current list: ";
        displayDList(head);
    } while (choice != 4);

    return 0;
}