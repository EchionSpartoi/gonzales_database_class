/*
 * Works Cited:
 * AI Language Model. "SWE-1.5"
 * Conversation with Christian Gonzales, 5 April 2026.
 * 
 * Note: AI assistance used for BST debugging and recursive algorithm guidance.
 */

#include "reserve.h"
#include <cmath>

reservation::reservation(int t) {
    time = t;
    left = nullptr;
    right = nullptr; 
    subtreeSize = 1; //adding this guy here to support my subtreeSize object. 
}


BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    clearTree(root);
}

void BST::clearTree(reservation* node)
{
    if (node == nullptr) //changed this from root to node due to an infinite loop it caused i guess. 
        return;

    clearTree(node->left);
    clearTree(node->right);
    delete node;
}

// reserve new landing time
bool BST::reserve(int time) 
{
    if (checkConflict(root, time)) {
        return false; // conflict - reservation fails
    }
 
    insert(root, time); 
    return true; // no conflict - reservation successful
}

// check for landing time conflicts within 3 minutes (Use recursion)
bool BST::checkConflict(reservation* node, int time) 
{
    //going to implement a full tree traversal for this conflict check method. 

    if (node == nullptr) {

        return false; //checking to see if the pointer is null, for some defensive coding. 
    }

    //check the current node that we are on, 
    if (abs(node->time - time) < 3) { //using the abs() to determine absolute difference between the current node time and the time we are trying to reserve
        return true; // conflict found
    }

    //now we need to check both subtrees. 
    return checkConflict(node->left, time) || checkConflict(node->right, time); //here, we recusrivly call our checkconflict method with separate arguments. 

 
}

// insert new reservation and update subtree size (make sure to avoid inserting duplicates)
void BST::insert(reservation*& node, int time) 
{
    // same as before - just make sure to update subtree size for inserted node

    if (node == nullptr) {
        node = new reservation(time); //setting node variable to a new reservation object with the time argument. 
        node->subtreeSize = 1; //setting subtree size to 1
        return;
    }

    if (time < node->time) {
        insert(node->left, time);
    } else if (time > node->time) {
        insert(node->right, time);
    } else {
        // Duplicate time - don't insert
        return;
    }
    
   // update subtree size for current node
   int leftSize = (node->left != nullptr) ? node->left->subtreeSize : 0; //get the size of the left subtree, and if the left node exists (its not null) then we use its subtree size. 
   int rightSize = (node->right != nullptr) ? node->right->subtreeSize : 0; //same as above but for the right subtree
   node->subtreeSize = 1 + leftSize + rightSize; //update the subtree size for the current node
}

// Count nodes with times <= t
int BST::countPlanes(reservation* node, int t) 
{
    if (node == nullptr) {
        return 0; //this is for an empty subtree. checking for degenerate cases. 
    }

    if (node->time <= t) {
        // we will count and search both subtrees left and right to the root
        return 1 + countPlanes(node->left, t) + countPlanes(node->right, t);
    } else {
        //if a node does not count and we need to check only the left substree due to degenerate tree
        return countPlanes(node->left, t);
    }

}

void BST::inorder(reservation* root)
{
    if (root == nullptr)
        return;
    
    inorder(root->left);
    cout << root->time << " ";
    inorder(root->right);
}