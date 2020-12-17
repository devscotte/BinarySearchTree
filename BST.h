#pragma once

#include "NodeInterface.h"
#include "Node.h"
#include "BSTInterface.h"

using namespace std;

class BST : public BSTInterface {
public:
	BST() {
		root = NULL;
	}
	virtual ~BST() {
		clear();
	}

	//Please note that the class that implements this interface must be made
	//of objects which implement the NodeInterface

	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	virtual NodeInterface * getRootNode() const;

	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	virtual bool add(int data);
	
	bool my_add(int data, Node*& my_node);

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	virtual bool remove(int data);
	
	bool my_remove(int data, Node*& my_node);
	
	void recursive_right(Node*& old_node, Node*& new_node);

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	virtual void clear();
	
	void my_clear(Node *ptr);
protected:
    Node *root;
};