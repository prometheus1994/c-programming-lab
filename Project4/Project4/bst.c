/**********************************************
* Name: Joseph Webster *
* Date: April 29, 2018*
* Assignment: Project 4 - Removing a node from a BST *
***********************************************
* This program is used for organizing user input (integers)
* into a Binary Search Tree using a user-defined data-type
* called a struct. All inserting, searching, and traversing
* is performed in the "bst.c" file, while all input/output
* is handled in the "io.c" file.
* This program may now remove a node from the tree.
***********************************************/
#include "bst.h"
#include "io.h"

// This is a struct for constructing a BinaryTreeNode;
// Type-defined as a 'Node';
// Has a (int) key, (BinaryTreeNode *) left, (BinaryTreeNode *) right;
typedef struct BinaryTreeNode {
	int key;
	struct BinaryTreeNode * left;
	struct BinaryTreeNode * right;
} Node;

/*************************************************
* Description: NewNode creates a new node using the 'Node' struct *
* Precondition: key is a valid, 32-bit integer*
* Post condition: Returns a newly constructed node whose key value is equal to key argument; left & right children are NULL *
**************************************************/
Node * NewNode(int key) {
	Node * node = malloc(sizeof(Node));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*************************************************
* Description: Insert inserts a node with the associated key into the tree *
* Precondition: Node != NULL, key is a valid 32-bit int *
* Post condition: Returns a tree with the arguments added in their respective destinations; Will not add duplciate keys *
**************************************************/
Node * Insert(Node * node, int key) {

	if ((node->key == 0 || node->key == NULL) && key != 0) {
		node->key = key;
		return node;
	}

	if (node->key == key) {
		return node;
	}

	else if (key > node->key) {
		if (node->right == NULL) {
			node->right = NewNode(key);
			return node;
		}
		else {
			Insert(node->right, key);
		}
	}

	else {
		if (node->left == NULL) {
			node->left = NewNode(key);
			return node;
		}
		else {
			Insert(node->left, key);
		}
	}

	return node;
}

/*************************************************
* Description: Search function is used for searching a given key in the node (tree)  *
* Precondition: Node != NULL; key is a valid 32-bit integer *
* Post condition: Return TRUE if the nodes key field is equivalent to argument key;
Return FALSE if the NODE is empty/NULL;
Recursively search right child if the NODES key field is less than the argument key
Recursively search left child if the NODES key field is greater than the argument key *
**************************************************/
bool Search(Node * node, int key) {
	if (!node) {
		return false;
	}
	else if (node->key == key) {
		return true;
	}
	// If not the root, then search the right or left child
	else if (node->key < key) {
		return Search(node->right, key);
	}
	else {
		return Search(node->left, key);
	}
}

/*************************************************
* Description: InorderTraversal prints the trees keys in ascending order (1, 2, 3, etc.) to a buffer/pointer/string *
* Precondition: NODE != NULL; buffer != NULL *
* Post condition: buffer will contain the values stored in the NODES of the tree inorder *
**************************************************/
void InorderTraversal(Node * node, char * buffer) {
	if (node != NULL) {
		InorderTraversal(node->left, buffer);
		sprintf(buffer, "%d", node->key);
		TraversalOutput(buffer);
		InorderTraversal(node->right, buffer);
	}
}

/*************************************************
* Description: Burn frees the memory at the given address *
* Precondition: A NODE is passed in *
* Post condition: The memory @ &NODE is freed *
**************************************************/
void Burn(Node * node) {
	free(node);
}

/*************************************************/
/****************PROJECT 4 METHODS****************/
/*************************************************/

/*************************************************
* Description: This function Removes a node
* Precondition: The node is not null and the key is a real number
* Post condition: The node with the associated key is removed
**************************************************/
Node * Remove(Node * node, int key) {

	if (node == NULL)
	{
		return node;
	}

	if (key < node->key) 
	{
		node->left = Remove(node->left, key);
	}
	else if (key > node->key) 
	{
		node->right = Remove(node->right, key);
	}

	else 
	{
		if (node->left == NULL) 
		{
			Node * temp_node = node->right;
			free(node);
			return temp_node;
		}
		else if (node->right == NULL) 
		{
			Node * temp_node = node->left;
			free(node);
			return temp_node;
		}

		Node * temp_node = minimumKeyValue(node);

		node->key = temp_node->key;

		node->right = Remove(node->right, temp_node->key);
	}
	return node;
}

/*************************************************
* Description: this method looks for the minimum key value
* Precondition: Node is not null
* Post condition: current holds the node with the smallest key value
**************************************************/
Node * minimumKeyValue(Node * node) {
	Node * current = node;

	while (current->left != NULL)
	{
		current = current->left;
	}

	return current;
}