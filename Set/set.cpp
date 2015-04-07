#include <iostream>
#include "set.h"

using namespace std;

template <class T> MySet<T> ::MySet()
{
	Size = 0;
	Capacity = 0;
};

template <class T> MySet<T> ::MySet(int StartCapacity)
{
	Size = 0;
	data = new T[StartCapacity];
};

template <class T> MySet<T> ::~MySet()
{
	delete[] data;
};

template <class T> void MySet<T> ::add(const T& elem)
{
	T* newdata;
	if (Size == Capacity)
	{
		Capacity *= 2;
		newdata = new T[Capacity];
		for (int i = 0; i < Size; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
	};
	Size++;
	data[Size] = elem;
};

template <class T> void MySet<T> ::remove(const T& elem)
{
	int i;
	for (i = 0; data[i] != elem && i < Size; i++);
	if (i == Size && data[Size] != elem)
	{
		cout << "Not exist" << endl;
		return;
	};
	for (int j = i; j < Size - 1; j++)
		j[i] = j[i + 1];
	Size--;
};

template <class T> bool MySet<T> ::contains(const T& elem) const
{
	for (i = 0;; i++)
	{
		if (data[i] == elem)
			return true;
	};
	return false;
};

template <class T> int MySet<T> ::size() const
{
	return Size;
};

template <class T> void MySet<T> ::show()
{
	for (int i = 0; i < Size; i++)
		cout << data[i];
};
