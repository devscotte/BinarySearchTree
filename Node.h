#pragma once

#include <iostream>
#include "NodeInterface.h"
using namespace std;

class Node : public NodeInterface {

public:
	Node(int my_data) {
		data = my_data;
		leftChild = NULL;
		rightChild = NULL;
	}
	virtual ~Node() {}

	/*
	* Returns the data that is stored in this node
	*
	* @return the data that is stored in this node.
	*/
	virtual int getData() const;

	/*
	* Returns the left child of this node or null if it doesn't have one.
	*
	* @return the left child of this node or null if it doesn't have one.
	*/
	virtual NodeInterface * getLeftChild() const;

	/*
	* Returns the right child of this node or null if it doesn't have one.
	*
	* @return the right child of this node or null if it doesn't have one.
	*/
	virtual NodeInterface * getRightChild() const;
	
	Node *& getLeft();
	Node *& getRight();
	Node *& changeData(int my_data);
	
	
protected:	
	Node *leftChild;
	Node *rightChild;
	int data;

};