#ifndef BST_HPP
#define BST_HPP

#include <iostream>
#include <cassert> // for assert()
//#include <algorithm>

struct Node
{	
	Node(int val);
   	int value;
	int height;
	Node* leftChild;
	Node* rightChild;
	Node* parent;		
};

typedef Node* NodePtr;

class BinarySearchTree
{
private:
	int m_size;
	NodePtr m_root;
protected:	
  	NodePtr InsertHelper(NodePtr root, int val); // Insert helper
  	NodePtr SearchHelper(NodePtr root, int val); // Search helper
 	NodePtr RemoveHelper(NodePtr root, int val); // Remove helper
	int FindSuccessorHelper(NodePtr root); 		 // Find successor helper
	int FindPredecessorHelper(NodePtr root);	 // Find predecessor helper
	int FindMinHelper(NodePtr root);			 // Find min helper
	int FindMaxHelper(NodePtr root);  			 // Find max helper
	void PrintInOrderHelper(NodePtr root);		 // Print smallest to the greatest helper
	void PrintPreOrderHelper(NodePtr root);		 // Print PreOrder
	void PrintPostOrderHelper(NodePtr root);	 // Print PostOrder
	bool IsLeaf(NodePtr) const;					 // Check is leaf?
	bool HasRightChild(NodePtr) const;			 // Check has right child?	
	bool HasLeftChild(NodePtr) const;			 // Check has left child?		
	bool HasBoth(NodePtr) const;				 // Check has both children?	
  	
public:
  	BinarySearchTree();			  				 // Ctor
	BinarySearchTree(int* arr,const int size);	 // Ctor	

  	void Insert(int val); 		  				 // Insert the node to the BST
  	bool Search(int val); 		  				 // Find the given value in BST
  	void Remove(int val);        				 // Remove the given value in BST
	int FindSuccessor(int val);  				 // Find the Successor of a given key
	int FindPredecessor(int val);				 // Find the Predecessor of a given key
	int FindMin();				 				 // Find the min
	int FindMax(); 				 				 // Find the max
	int GetSize() const;						 // Get size		
	
	void PrintInOrder();  // Print all the keys of BST sorted from smallest to the greatest key
	void PrintPreOrder(); // Print PreOrder
	void PrintPostOrder();// Print PostOder
};
#endif //BST_HPP

