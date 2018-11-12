/**********************************************
* Name: Joseph Webster *
* Date: February 25th, 2017*
* Assignment: Project 2 - Sequence and Order validation *
***********************************************
* This program is used for organizing user input (integers)
* into a Binary Search Tree using a user-defined data-type
* called a struct. All inserting, searching, and traversing
* is performed in the "bst.c" file, while all input/output
* is handled in the "io.c" file.
***********************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is a struct for constructing a BinaryTreeNode;
// Type-defined as a 'Node';
// Has a (int) key, (BinaryTreeNode *) left, (BinaryTreeNode *) right;
typedef struct BinaryTreeNode Node;

/*************************************************
* Description: NewNode creates a new node using the 'Node' struct *
* Precondition: key is a valid, 32-bit integer*
* Post condition: Returns a newly constructed node whose key value is equal to key argument; left & right children are NULL *
**************************************************/
Node * NewNode(int);

/*************************************************
* Description: Insert inserts a node with the associated key into the tree *
* Precondition: Node != NULL, key is a valid 32-bit int *
* Post condition: Returns a tree with the arguments added in their respective destinations; Will not add duplciate keys *
**************************************************/
Node * Insert(Node *, int);

/*************************************************
* Description: Search function is used for searching a given key in the node (tree)  *
* Precondition: Node != NULL; key is a valid 32-bit integer *
* Post condition: Return TRUE if the nodes key field is equivalent to argument key;
Return FALSE if the NODE is empty/NULL;
Recursively search right child if the NODES key field is less than the argument key
Recursively search left child if the NODES key field is greater than the argument key *
**************************************************/
bool Search(Node *, int);

/*************************************************
* Description: InorderTraversal prints the trees keys in ascending order (1, 2, 3, etc.) to a buffer/pointer/string *
* Precondition: NODE != NULL; buffer != NULL *
* Post condition: buffer will contain the values stored in the NODES of the tree inorder *
**************************************************/
void InorderTraversal(Node *, char *);

/*************************************************
* Description: Burn frees the memory at the given address *
* Precondition: A NODE is passed in *
* Post condition: The memory @ &NODE is freed *
**************************************************/
void Burn(Node *);