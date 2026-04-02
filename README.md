# welcome to my readme. 

### here are some notes. .




Task 1: Implement height() function that computes the height of a given node in
the BST for both BST_A and BST_P.
Task 2: Implement countNodes() function to count and return the total number
of nodes in the BST for both BST_A and BST_P.
Task 3: Implement isBalanced() function to check if the BST is balanced for
both BST_A and BST_P. It should return “Yes” if the BST is balanced, “Left-
heavy” if the tree is imbalanced and leans to the left, & “Right-heavy” if the tree is
imbalanced and leans to the right.
NOTE: Ensure to implement all three using recursion and do the
computations without using any stored values. Also modify the existing
insert() functions to check and handle duplicate insertions according to
the property of BSTs
Task 4: Add deleteNode() function to delete a node for BST_A.
Task 5: Implement BFS() function using queues to perform breadth-first traversal
of the BST for both BST_A and BST_P. [ Use the custom queue implementation
from prior assignments for this! ]


##  how to run:

```bash
cd BST_A
g++ -o bstA mainA.cpp bstA.cpp
./bstA inst.txt
```

```bash
cd BST_P
g++ -o bstP mainP.cpp bstP.cpp
./bstP inst.txt
```
