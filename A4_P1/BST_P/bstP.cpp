#include "bstP.h"

node::node(int value)
{
    data = value;
    leftChild = nullptr;
    rightChild = nullptr;
}

BST::BST()
{
    root = nullptr;
}

BST::~BST()
{
    clearTree(root);
}

void BST::clearTree(node* node)
{
    if(node == nullptr)
        return;
    
    clearTree(node->leftChild);
    clearTree(node->rightChild);
    delete node;
}

void BST::insertNode(node*& root, int data)
{
    if(root == nullptr)
    {
        root = new node(data);
        return;
    }

    if(data < root->data)
        insertNode(root->leftChild, data);
    else 
        insertNode(root->rightChild, data);
}

node* BST::searchNode(node*& root, int data)
{
    if (root == nullptr || root->data == data)
        return root;
    if (data < root->data)
        return searchNode(root->leftChild, data);
    return searchNode(root->rightChild, data);
}

void BST::deleteNode(node*& root, int data)
{
    if (root == nullptr)
        return;

    if (data < root->data)
        deleteNode(root->leftChild, data);
    else if (data > root->data)
        deleteNode(root->rightChild, data);
    else {
        if (root->leftChild == nullptr) {
            node* temp = root->rightChild;
            delete root;
            root = temp;
        }
        else if (root->rightChild == nullptr) {
            node* temp = root->leftChild;
            delete root;
            root = temp;
        }
        else {
            node* temp = root->rightChild;
            while (temp->leftChild != nullptr)
                temp = temp->leftChild;
            root->data = temp->data;
            deleteNode(root->rightChild, temp->data);
        }
    }
}

void BST::preorder(node* root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->leftChild);
    preorder(root->rightChild);
}

void BST::inorder(node* root)
{
    if (root == nullptr)
        return;
    inorder(root->leftChild);
    cout << root->data << " ";
    inorder(root->rightChild);
}

void BST::postorder(node* root)
{
    if (root == nullptr)
        return;
    postorder(root->leftChild);
    postorder(root->rightChild);
    cout << root->data << " ";
}


void BST::printTree(node* root, int space)
{
    const int COUNT = 10;
    if (root == nullptr)
        return;
    space += COUNT;
    printTree(root->rightChild, space);
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->data << endl;
    printTree(root->leftChild, space);
}

int BST::height(node* root)
{
    if (root == nullptr)
        return -1;
    
    int leftHeight = height(root->leftChild);
    int rightHeight = height(root->rightChild);
    
    return 1 + max(leftHeight, rightHeight);
}

int BST::countNodes(node* root) //same as array, but we use the pointer for hte memeroy address. 
{
    if (root == nullptr)
        return 0;
    
    return 1 + countNodes(root->leftChild) + countNodes(root->rightChild);
}

string BST::isBalanced(node* root) //same logic as bst array, but with pointer based address finding logic
{
    //base case: empty node is balanced
    if (root == nullptr)
        return "yes";
    
    //get heights of left and right subtrees
    int leftHeight = height(root->leftChild);
    int rightHeight = height(root->rightChild);
    
    //check if current node is balanced
    if (abs(leftHeight - rightHeight) > 1)
        return (leftHeight > rightHeight) ? "Left heavy" : "Right heavy";
    
    //recursively check left and right subtrees
    string leftBalance = isBalanced(root->leftChild);
    string rightBalance = isBalanced(root->rightChild);
    
    //if either subtree is unbalanced, return that result
    if (leftBalance != "yes" || rightBalance != "yes")
        return leftBalance != "yes" ? leftBalance : rightBalance;
    
    //if we get here, the tree is balanced
    return "yes";
}


#include "queue.h"
//this is same logic as the array version, but we use pointers instead. 

void BST::BFS()
{
    if(root == nullptr) {
        cout << "Tree is empty" << endl;
        return;
    }
    
    Queue<node*> q(100);
    q.enqueue(root);  // Start with root pointer
    
    cout << "BFS traversal: ";
    
    while(!q.isEmpty()) {
        node* currentNode = q.dequeue();
        
        if(currentNode == nullptr)
            continue;
            
        cout << currentNode->data << " ";
        
        // Enqueue left child
        if(currentNode->leftChild != nullptr) {
            q.enqueue(currentNode->leftChild);
        }
        
        // Enqueue right child
        if(currentNode->rightChild != nullptr) {
            q.enqueue(currentNode->rightChild);
        }
    }
    
    cout << endl;
}