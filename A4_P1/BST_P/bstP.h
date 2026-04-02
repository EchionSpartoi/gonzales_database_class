#ifndef BSTP_H
#define BSTP_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/*
 * Binary Search Tree - Pointer Implementation  
 * Author: Christian Gonzales
 * Date: April 2026
 * 
 * Works Cited:
 * AI Language Model. "SWE-1.5"
 * Conversation with Christian Gonzales, 2 April 2026.
 * 
 * Note: AI assistance used for conceptual understanding and debugging
 * guidance, similar to Stack Overflow usage. All implementation 
 * decisions and coding done by author.
 */

struct node
{
    int data;
    node* leftChild;
    node* rightChild;

    node(int value);
};

class BST
{
    public:
        node* root;

        BST();
        ~BST();
        void clearTree(node* node);

        void insertNode(node*& root, int data);
        node* searchNode(node*& root, int data);
        void deleteNode(node*& root, int data);

        void preorder(node* root);
        void inorder(node* root);
        void postorder(node* root);
        void BFS();  // Breadth-first traversal using queue

        void printTree(node* root, int space);

        int height(node* root = nullptr);  // Height from given node using pointer. 
        int countNodes(node* root = nullptr); // Count nodes from a given node using pointer.

        string isBalanced(node* root = nullptr);  // Check balance from given node
};

#endif