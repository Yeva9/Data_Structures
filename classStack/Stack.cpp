#include "Stack.hpp"

template <typename T>
Stack<T>::Stack()
	: m_maxsize(s_maxsize)
	, m_top(-1)
	, m_data(nullptr) 
{
	AllocateAndInitialize();
}

template <typename T>
Stack<T>::Stack(const T* data, int size)
	: m_maxsize((size > s_maxsize) ? size :s_maxsize)
	, m_top(-1)
	, m_data(nullptr) 
{
	AllocateAndInitialize(data);
}

template <typename T>
Stack<T>::Stack(const Stack<T>& S)
	: m_maxsize(S.m_maxsize)
	, m_top(S.m_top)
	, m_data(nullptr) 
{
	AllocateAndInitialize(S.m_data);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& S) 
{
	if (this != &S) {
		Deallocate();
		m_maxsize = S.m_maxsize;
		m_top = S.m_top;
		AllocateAndInitialize(S.m_data);
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack() 
{
	Deallocate();
}

template <typename T>
T& Stack<T>::Top() 
{
	CheckEmpty();
	return m_data[m_top];
}

template <typename T>
const T& Stack<T>::Top() const 
{
	CheckEmpty();
	return m_data[m_top];
}

template <typename T>
void Stack<T>::Push(const T& element) 
{
	if (m_top == m_maxsize - 1) {
		m_maxsize *= 2;

		T* tmp = new T[m_maxsize]{};

		for (int i = 0; i <= m_top; ++i) {
			tmp[i] = m_data[i];
		}
		Deallocate();
		m_data = tmp;
	}
	m_data[++m_top] = element;
}

template <typename T>
void Stack<T>::Pop() 
{
	CheckEmpty();
	--m_top;
}

template <typename T>
int Stack<T>::GetSize() const
{
	return 1 + m_top;
}

template <typename T>
bool Stack<T>::IsEmpty() const
{
	return (m_top == -1);
}

template <typename T>
void Stack<T>::AllocateAndInitialize(const T* data) 
{
	m_data = new T[m_maxsize]{};

	if (nullptr != data) {
		for (int i = 0; i <= m_top; ++i) {
			m_data[i] = data[i];
		}
	}
}

template <typename T>
void Stack<T>::Deallocate()
{
	delete[] m_data;
}

template <typename T>
void Stack<T>::CheckEmpty() const 
{
	if (IsEmpty()) 
	{
		std::cout << "The stack is empty." << std::endl;
		return;
		//throw std::exception("The stack is empty.");
	}
}

int main()
{
	/*************testing*************/
	Stack<int> S;
	S.Push(5);
	std::cout << S.Top() << " ";
	S.Push(51);
	S.Push(55);
	S.Push(15);
	S.Push(85);
	S.Push(65);
	S.Push(15);
	S.Push(95);
	S.Push(55);
	std::cout << S.Top() << " ";	
	std::cout << S.GetSize() << " ";
	std::cout << std::endl;

}
