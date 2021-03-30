#include <iostream>
#include <exception>

template <typename T>
class Stack
{
private:
	static int const s_maxsize = 20;

	int m_maxsize;
	int m_top;
	T* m_data;

private:
	void AllocateAndInitialize(const T* = nullptr);
	void Deallocate();
	void CheckEmpty() const;

public:
	Stack(); 			 	// Default ctor
	Stack(const T*, int); 	// Ctor with parameters
	Stack(const Stack<T>&); // Copy ctor
	~Stack(); 				// Dtor
	Stack<T>& operator=(const Stack<T>&); // Assignment operator

	int GetSize() const; 	// Returns the number of elements in the stack.
	bool IsEmpty() const;	// Returns whether the stack is empty.

	T& Top(); 			    // Removes the element on top of the stack,\
   			 				   effectively reducing its size by one
	const T& Top() const;   // For const 
	void Push(const T&);    // Inserts a new element at the top of the stack,\
   						 	    above its current top element
	void Pop();			    // Returns a reference to the top element in the stack.

};

