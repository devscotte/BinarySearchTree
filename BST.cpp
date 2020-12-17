#include "BST.h"
#include "Node.h"
using namespace std;


	/*
	* Returns the root node for this tree
	*
	* @return the root node for this tree.
	*/
	
	
	NodeInterface * BST::getRootNode() const{
		return root;
	}

	void BST::recursive_right(Node*& old_node, Node*& new_node){
		if(new_node->getRight() != NULL){
			recursive_right(old_node, new_node->getRight());
		}
		else{
			int my_num;
			my_num = new_node->getData();
			old_node->changeData(my_num);
			my_remove(my_num, old_node->getLeft());
		}
	}
	/*
	* Attempts to add the given int to the BST tree
	*
	* @return true if added
	* @return false if unsuccessful (i.e. the int is already in tree)
	*/
	bool BST::add(int data){
	    return my_add(data, this->root);
	}
	
	bool BST::my_add(int data, Node*& my_node){
		if(my_node == NULL){
			my_node = new Node(data);
			return true;
		}
		else if(my_node->getData() == data){
			return false;
		}
		else if(my_node->getData() > data){
			return my_add(data, my_node->getLeft());
		}
		else if(my_node->getData() < data){
			return my_add(data, my_node->getRight());
		}
		else{
			return false;
		}
	}

	/*
	* Attempts to remove the given int from the BST tree
	*
	* @return true if successfully removed
	* @return false if remove is unsuccessful(i.e. the int is not in the tree)
	*/
	bool BST::remove(int data){
		return my_remove(data, this->root);
	}
	
	bool BST::my_remove(int data, Node*& my_node){
		if(my_node == NULL){
			return false;
		}
		else if(my_node->getData() > data){
			return my_remove(data, my_node->getLeft());
		}
		else if(my_node->getData() < data){
			return my_remove(data, my_node->getRight());
		}
		else{
			if(my_node->getLeft() == NULL && my_node->getRight() == NULL){
				delete my_node;
				my_node = NULL;
				return true;
			}
			else if(my_node->getLeft() == NULL || my_node->getRight() == NULL){
				Node* temp_node;
				temp_node = my_node->getLeft();
				if(my_node->getLeft() == NULL){
					temp_node = my_node->getRight();
				}
				delete my_node;
				my_node = temp_node;
				return true;
			}
			else{
				Node* temp_node;
				temp_node = my_node->getLeft();
				
				recursive_right(my_node, temp_node);
				
				return true;
				
				
			}
		}
	}
	
	

	/*
	* Removes all nodes from the tree, resulting in an empty tree.
	*/
	void BST::clear(){
		my_clear(root);
		root = NULL;
	}
	
	void BST::my_clear(Node *ptr){
		if(ptr != NULL){
			my_clear(ptr->getLeft());
			my_clear(ptr->getRight());
			delete ptr;
		}
	}