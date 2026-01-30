#include "dll.h"

void insertDNode(dnode *&head, int index, int data)
{
    dnode* newNode = new dnode;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    
    if(index == 0)
    {
        newNode->next = head;
        if(head != nullptr)
            head->prev = newNode;
        head = newNode;
    }
    else
    {
        dnode* walker = head;
        int wIndex = 0;
        while(walker != nullptr && wIndex < index - 1)
        {
            walker = walker->next;
            wIndex++;
        }
        
        if(walker == nullptr)
        {
            cout << "Index too large" << endl;
            delete newNode;
            return;
        }
        
        newNode->next = walker->next;
        newNode->prev = walker;
        if(walker->next != nullptr)
            walker->next->prev = newNode;
        walker->next = newNode;
    }
}

void deleteDNode(dnode *&head, int index)
{
    if(head == nullptr)
    {
        cout << "List empty" << endl;
        return;
    }
    
    if(index == 0)
    {
        dnode* temp = head;
        head = head->next;
        if(head != nullptr)
            head->prev = nullptr;
        delete temp;
        return;
    }
    
    dnode* walker = head;
    int wIndex = 0;
    while(walker != nullptr && wIndex < index)
    {
        walker = walker->next;
        wIndex++;
    }
    
    if(walker == nullptr)
    {
        cout << "Index too large" << endl;
        return;
    }
    
    if(walker->prev != nullptr)
        walker->prev->next = walker->next;
    if(walker->next != nullptr)
        walker->next->prev = walker->prev;
    
    delete walker;
}
