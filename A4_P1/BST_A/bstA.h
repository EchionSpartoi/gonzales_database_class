#ifndef BSTA_H
#define BSTA_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

/*
 * Binary Search Tree - Array Implementation
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

class BST
{
    private:
        int* tree;
        int capacity;

        int leftChild(int index);
        int rightChild(int index);
        int parent(int index);


        //have to add these to support my over the top deletenode method
        int findNode(int index, int data);
        int findParent(int index, int data, int parent = -1);
        bool isLeaf(int index);
        bool hasOnlyLeftChild(int index);
        bool hasOnlyRightChild(int index);
        int findMin(int index);

    public:
        BST(int size); //constructor
        ~BST(); //destructor

        void insertI(int data);
        void insertR(int data);
        void insertRhelper(int index, int data);

        bool searchI(int data);
        bool searchR(int data);
        bool searchRhelper(int index, int data);

        void preorder(int index = 0);
        void inorder(int index = 0);
        void postorder(int index = 0);
        void BFS();  // Breadth-first traversal using queue
        //no return type, no parameter since it operates on teh entire tree. 

        void printTree(int index, int depth);

        int height(int index = 0);  // Height from given node (default root)
        int countNodes(int index = 0); //count nodes from a given index in an array. 

        string isBalanced(int index = 0);  // Check balance from given index
        //returns string type for "yes, left heavy, or right heavy"
        //function declaration. 
        //entry point for the algorithm for chekcing. balance. 


        void deleteNode(int data); //delete node using given value. 
        //no return value. voided. 
};

#endif