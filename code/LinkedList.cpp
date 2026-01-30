#include "ll.h"

void insertNode(node *&head, int index, int data)
{
    node* newNode = new node;
    newNode->data = data;
    newNode->next = nullptr;

    if(index == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        node* walker = head;
        int wIndex = 0;
        while(walker != NULL && wIndex < index-1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr)
        {
            cout << "Index is too large, can't insert" << endl;
            return;
        }
        else
        {
            newNode->next = walker->next;
            walker->next = newNode;
        }

    }
}

void deleteNode(node *&head, int index) 
{
    // Check if the list is empty and there's nothing to delete

    if(head == nullptr)
    {
        cout << "List is empty, can't delete" << endl;
        return;
    }

    // Check if were are deleting at index 0 and handle accordingly
    if(index == 0)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    // Handle other index deletions
    else
    {
        node* walker = head;
        int wIndex = 0;
        while(walker != nullptr && wIndex < index - 1)
        {
            walker = walker->next;
            wIndex++;
        }
        if(walker == nullptr || walker->next == nullptr)
        {
            cout << "Index too large, can't delete" << endl;
            return;
        }
        else
        {
            node* temp = walker->next;
            walker->next = temp->next;
            delete temp;
        }
    }
 
}

void displayList(node *head) 
{
    node* walker = head;

    while(walker != nullptr)
    {
        cout << walker->data<<" ";
        walker = walker->next;
    }
    cout<<endl;

}

    node* searchNode(node *head, int key)
{
    node* walker = head;
    
    while(walker != nullptr)
    {
        if(walker->data == key)
        {
            return walker;
        }
        walker = walker->next;
    }
    
    return nullptr;
}

void reverseList(node *&head) //this takes the list and reverses the order of the index. 
{
    node* prev = nullptr;
    node* current = head;
    node* next = nullptr;
    
    while(current != nullptr)
    {
        next = current->next;      // Save next node
        current->next = prev;       // Reverse the link
        prev = current;             // Move prev forward
        current = next;             // Move current forward
    }
    
    head = prev;  // New head is the last node
}

