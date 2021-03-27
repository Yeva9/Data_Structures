#ifndef BST.hpp
#define BST.hpp

#include <iostream>
//#include <algorithm>

struct Node
{	
	Node(int val);
   	int value;
    int	height;
	Node* leftChild;
	Node* rightChild;
	Node* parent;		
};

typedef Node* NodePtr;

class BST
{
private:
	NodePtr m_root;
private:	
  	NodePtr InsertHelper(NodePtr node, int val); // Insert helper
  	NodePtr SearchHelper(NodePtr node, int val); // Search helper
 	NodePtr RemoveHelper(NodePtr node, int val); // Remove helper
	int FindSuccessorHelper(NodePtr node); 		 // Find successor helper
	int FindPredecessorHelper(NodePtr node);	 // Find predecessor helper
	int FindMinHelper(NodePtr node);			 // Find min helper
	int FindMaxHelper(NodePtr node);  			 // Find max helper
	void PrintInOrderHelper(NodePtr node);		 // Print smallest to the greatest helper

public:
  	BinarySearchTree();			  // Ctor

  	void Insert(int val); 		  // Insert the node to the BST
  	bool Search(int val); 		  // Find the given value in BST
  	void Remove(int val);         // Remove the given value in BST
	int FindSuccessor(int val);   // Find the Successor of a given key
	int FindPredecessor(int val); // Find the Predecessor of a given key
	int FindMin();				  // Find the min
	int FindMax(); 				  // Find the max
  	void PrintInOrder(); //Print all the keys of BST sorted from smallest to the greatest key
};
#endif //BST.hpp

