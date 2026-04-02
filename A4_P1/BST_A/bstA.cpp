#include "bstA.h"

BST::BST(int size)
{
    capacity = size;
    tree = new int[capacity];
    for(int i = 0; i < size; i++)
        tree[i] = INT_MIN;
}

BST::~BST()
{
    delete[] tree;
}

int BST::leftChild(int index)
{
    return 2 * index + 1;
}

int BST::rightChild(int index)
{
    return 2 * index + 2;
}

int BST::parent(int index)
{
    return (index - 1) / 2;
}

void BST::insertI(int data)
{
    if(tree[0] == INT_MIN)
    {
        tree[0] = data;
        return;
    }

    int index = 0;

    while(index < capacity)
    {
        if(data < tree[index])
        {
            if(leftChild(index) < capacity && tree[leftChild(index)] == INT_MIN)
            {
                tree[leftChild(index)] = data;
                return;
            }
            index = leftChild(index);
        } else {
            if(rightChild(index) < capacity && tree[rightChild(index)] == INT_MIN)
            {
                tree[rightChild(index)] = data;
                return;
            }
            index = rightChild(index);
        }
    }
}

void BST::insertR(int data)
{
    insertRhelper(0, data);
}

void BST::insertRhelper(int index, int data)
{
    // Base case
    if(index >= capacity)
        return;
    if(tree[index] == INT_MIN)
    {
        tree[index] = data;
        return;
    }

    // Recursive case
    if (data < tree[index])
        insertRhelper(leftChild(index), data);
    else
        insertRhelper(rightChild(index), data);
}

bool BST::searchI(int data)
{
    int index = 0;

    while(index < capacity)
    {
        if(tree[index] == INT_MIN)
            return false;
        if(tree[index] == data)
            return true;
        if(data < tree[index])
            index = leftChild(index); 
        else
            index = rightChild(index);
    }

    return false;
}

bool BST::searchR(int data)
{
    return searchRhelper(0, data);
}

bool BST::searchRhelper(int index, int data)
{
    // Base case
    if(index >= capacity || tree[index] == INT_MIN)
        return false;
    if(tree[index] == data)
        return true;

    // Recursive case
    if(data < tree[index])
        return searchRhelper(leftChild(index), data);
    else
        return searchRhelper(rightChild(index), data);
}

void BST::preorder(int index) // C-L-R
{
    // base case
    if (index >= capacity || tree[index] == INT_MIN)
        return;

    // recursive case
    cout << tree[index] << " ";
    preorder(leftChild(index));
    preorder(rightChild(index));
}

void BST::inorder(int index) // L-C-R
{
    // base case
    if (index >= capacity || tree[index] == INT_MIN)
        return;

    // recursive case
    inorder(leftChild(index));
    cout << tree[index] << " ";
    inorder(rightChild(index));
}

void BST::postorder(int index) // L-R-C
{
    // base case
    if (index >= capacity || tree[index] == INT_MIN)
        return;

    // recursive case
    postorder(leftChild(index));
    postorder(rightChild(index));
    cout << tree[index] << " ";
}

void BST::printTree(int index, int depth = 0)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return;
    
    printTree(rightChild(index), depth + 1);

    for(int i = 0; i < depth; i++)
        cout << "   "; // for indentation
    cout << tree[index] << endl;

    printTree(leftChild(index), depth + 1);
    
}

int BST::height(int index) // Height from given node , and we will default to root
{
    //here is our algorithm to find the hight. 
    // Base case
    if(index >= capacity || tree[index] == INT_MIN)
        return -1;
    
    // Recursive case
    int leftHeight = height(leftChild(index));
    int rightHeight = height(rightChild(index));
    
    return 1 + max(leftHeight, rightHeight);
}

int BST::countNodes(int index)
{

    // default to empty node
    if(index >= capacity || tree[index] == INT_MIN)
        return 0;
    
        // count current node + left and + right
    return 1 + countNodes(leftChild(index)) + countNodes(rightChild(index));
}

string BST::isBalanced(int index)
{
    //base case: epty node is balanced
    if(index >= capacity || tree[index] == INT_MIN)
        return "yes";

        //needs to get the heights of the left and right subtrees as varables in this algorithm. 
        int leftHeight = height(leftChild(index));
        int rightHeight = height(rightChild(index));
        
        //now, that we have all the variables, we can start checking balance conditions. 
        if(abs(leftHeight - rightHeight) > 1) //checks the heights.. and if they are not 0, than we know. 
            return (leftHeight > rightHeight) ? "Left heavy" : "Right heavy";
        
        //some recurrsion through the subtrees
        string leftBalance = isBalanced(leftChild(index));
        string rightBalance = isBalanced(rightChild(index));

        //if a subtree is unblaanced, we result on it
        if(leftBalance != "yes" || rightBalance != "yes")
            return leftBalance != "yes" ? leftBalance : rightBalance;   
        
        //if we get here, the tree is balanced
        return "yes";

//         Algorithm Summary
// Core Logic: Tree is balanced if for every node: |height(left) - height(right)| ≤ 1

// Recursive Strategy:

// Base Case: Empty node = balanced
// Current Node: Check height difference
// Recursive Step: Check both subtrees
// Propagation: Return first unbalance found
// Time Complexity: O(n²) worst case (unbalanced tree) Space Complexity: O(h) where h = tree height (recursion stack)
}



void BST::deleteNode(int data)
{
    int index = findNode(0, data);
    if(index == -1) {
        cout << data << " not found" << endl;
        return;
    }
    tree[index] = INT_MIN;
    cout << "Deleted: " << data << endl;
}

// Helper functions for deletion
int BST::findNode(int index, int data)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return -1;
    
    if(tree[index] == data)
        return index;
    
    if(data < tree[index])
        return findNode(leftChild(index), data);
    else
        return findNode(rightChild(index), data);
}

int BST::findParent(int index, int data, int parent)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return -1;
    
    if(tree[index] == data)
        return parent;
    
    if(data < tree[index])
        return findParent(leftChild(index), data, index);
    else
        return findParent(rightChild(index), data, index);
}

bool BST::isLeaf(int index)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return false;
    
    int leftIdx = leftChild(index);
    int rightIdx = rightChild(index);
    
    return (leftIdx >= capacity || tree[leftIdx] == INT_MIN) && 
           (rightIdx >= capacity || tree[rightIdx] == INT_MIN);
}

bool BST::hasOnlyLeftChild(int index)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return false;
    
    int leftIdx = leftChild(index);
    int rightIdx = rightChild(index);
    
    return (leftIdx < capacity && tree[leftIdx] != INT_MIN) && 
           (rightIdx >= capacity || tree[rightIdx] == INT_MIN);
}

bool BST::hasOnlyRightChild(int index)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return false;
    
    int leftIdx = leftChild(index);
    int rightIdx = rightChild(index);
    
    return (leftIdx >= capacity || tree[leftIdx] == INT_MIN) && 
           (rightIdx < capacity && tree[rightIdx] != INT_MIN);
}

int BST::findMin(int index)
{
    if(index >= capacity || tree[index] == INT_MIN)
        return -1;
    
    // Keep going left until we hit a leaf
    while(leftChild(index) < capacity && tree[leftChild(index)] != INT_MIN)
        index = leftChild(index);
    
    return index;
}



#include "queue.h" //bringing in the cusome queueu template i made. 

//our queue will start at index 0
//we are processing all nodes at depth d before d + 1.  
//we terminate when the queue is empty, and all nodes are processed. 

void BST::BFS()
{
    if(tree[0] == INT_MIN) {
        cout << "Tree is empty" << endl;
        return;
    }
    
    Queue<int> q(capacity);
    q.enqueue(0);  // Start with root index
    
    cout << "BFS traversal: ";
    
    while(!q.isEmpty()) {
        int currentIndex = q.dequeue();
        
        if(currentIndex >= capacity || tree[currentIndex] == INT_MIN)
            continue;
            
        cout << tree[currentIndex] << " ";
        
        // Enqueue left child
        int leftIdx = leftChild(currentIndex);
        if(leftIdx < capacity && tree[leftIdx] != INT_MIN) {
            q.enqueue(leftIdx);
        }
        
        // Enqueue right child
        int rightIdx = rightChild(currentIndex);
        if(rightIdx < capacity && tree[rightIdx] != INT_MIN) {
            q.enqueue(rightIdx);
        }
    }
    
    cout << endl;
}