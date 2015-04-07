#pragma once
#include <iostream>
#include "interfaces.h"

using namespace std;

template <class T> class MySet : public ISet<T>
{
private:
	T* data;
	int Size;
	int Capacity;
public:
	MySet();
	~MySet();
	MySet(int StartCapacity);
	// добавить элемент
	virtual void add(const T& elem);
	// удалить элемент
	virtual void remove(const T& elem);
	// содержится ли элемент
	virtual bool contains(const T& elem) const;
	// узнать размер множества
	virtual int size() const;
	void show();
};

template <class T> MySet<T>::MySet()
{
	Size = 0;
	Capacity = 0;
};

template <class T> MySet<T>::MySet(int StartCapacity)
{
	Size = 0;
	Capacity = StartCapacity;
	data = new T[StartCapacity];
};

template <class T> MySet<T>::~MySet()
{
	delete[] data;
};

template <class T> void MySet<T>::add(const T& elem)
{
	if (Size == Capacity)
	{
		T* newdata;
		Capacity *= 2;
		newdata = new T[Capacity];
		for (int i = 0; i < Size; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
	};
	data[Size] = elem;
	Size++;
	
};

template <class T> void MySet<T>::remove(const T& elem)
{
	int i;
	for (i = 0; data[i] != elem && i < Size; i++);
	if (i == Size && data[Size] != elem)
	{
		cout << "Not exist" << endl;
		return;
	};
	for (int j = i; j < Size - 1; j++)
		data[j] = data[j + 1];
	Size--;
};

template <class T> bool MySet<T>::contains(const T& elem) const
{
	for (int i = 0; i < Size; i++)
	{
		if (data[i] == elem)
			return true;
	};
	return false;
};

template <class T> int MySet<T>::size() const
{
	return Size;
};

template <class T> void MySet<T>::show()
{
	for (int i = 0; i < Size; i++)
		cout << data[i];
};
