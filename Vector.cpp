#pragma <once>;
#include "pch.h"
#include <iostream>

class Vector
{
public:
	Vector();
	Vector(const int* container, const int size);
	~Vector();
	Vector(const Vector& V);
	int Get_Size() const { return m_size; }
	bool Is_Empty() const { return m_size == 0; }
	int Get_Element(int i) const { return m_container[i]; }
	void Push_Back(int value);
	void Pop_Back();
	void Print() const;

private:
	int m_size;
	int m_capacity;
	int* m_container;
};

Vector::Vector()
{
	m_size = 0;
	m_capacity = 1;
	m_container = new int[m_size];
}

Vector::Vector(const int* container, const int size)
	:m_size(size)
	, m_capacity(1)
	, m_container(new int[m_size])
{
	for (int i = 0; i < m_size; ++i)
	{
		m_container[i] = container[i];
	}
}

Vector::~Vector()
{
	delete[] m_container;
}

Vector::Vector(const Vector& V)
{
	m_size = V.m_size;
	m_capacity = V.m_capacity;
	m_container = new int [m_size];
	for (int i = 0; i < m_size; ++i)
	{
		m_container[i] = V.m_container[i];
	}


}

void Vector::Push_Back(int value)
{
	if (m_size < m_capacity)
	{
		m_container[m_size] = value;
		++m_size;
	}
	else
	{
		int nCapacity = 2 * m_capacity;
		int* nContainer = new int[nCapacity];
		for (int i = 0; i < m_size; ++i)
		{
			nContainer[i] = m_container[i];
		}
		m_capacity = nCapacity;
		int * tmp = m_container;
		m_container = nContainer;
		m_container[m_size] = value;
		++m_size;
		delete[] tmp;
	}
}

void Vector::Pop_Back()
{
	if (Is_Empty()) return;
	if (m_size * 4 > m_capacity)
	{
		--m_size;
	}
	else
	{
		int nCapacity = m_capacity / 2;
		int* nContainer = new int[nCapacity];
		for (int i = 0; i < m_size; ++i)
		{
			nContainer[i] = m_container[i];
		}
		m_capacity = nCapacity;
		int * tmp = m_container;
		m_container = nContainer;
		--m_size;
		delete[] tmp;
	}
}

void Vector::Print() const
{
	for (int i = 0; i < m_size; ++i)
	{
		std::cout << m_container[i] << " ";
	}
	std::cout << std::endl;
}

int main()
{
	const int n = 10;
	int A[n] = { 0,1,2,3,4,5,6,7,8,9 };

	Vector V1(A, n);
	/*V1.Pop_Back();
	V1.Push_Back(20);
	V1.Push_Back(20);
	V1.Print();


	Vector V2;
	V2.Push_Back(10);
	V2.Push_Back(10);
	V2.Print();*/
	Vector V3 = V1;
	V3.Print();
}

