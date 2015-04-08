#pragma once
#include <iostream>
#include "interfaces.h"

using namespace std;

template <class T> class MySet : public ISet < T >
{
private:
	T* data;
	int Size;
	int FindElem(const T& elem, int min, int max) const;
public:
	MySet();
	~MySet();
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
};

template <class T> MySet<T>::~MySet()
{
	delete[] data;
};

template <class T> int MySet<T>::FindElem(const T& elem, int min, int max) const
{

	int mid = (min + max) / 2;
	if (data[mid] == elem)
		return (-1);
	if (min == Size - 1)
		return Size;
	if (min == max)
		return min;
	if (elem < data[mid])
		return FindElem(elem, min, mid - 1);
	else
		return FindElem(elem, mid + 1, max);
};

template <class T> void MySet<T>::add(const T& elem)
{
	if (Size == 0)
	{
		data = new T[1];
		data[0] = elem;
		Size++;
		return;
	};
	int index = FindElem(elem, 0, Size - 1);
	if (index == -1)
	{
		cout << "Already exist\n";
		return;
	};
	T* newdata = new T[++Size];
	for (int i = 0; i < index; i++)
		newdata[i] = data[i];
	newdata[index] = elem;
	for (int i = index + 1; i < Size; i++)
		newdata[i] = data[i - 1];
	delete[] data;
	data = newdata;
	return;
};

template <class T> void MySet<T>::remove(const T& elem)
{
	if (Size == 0)
		return;
	int index = FindElem(elem, 0, Size - 1);
	if (index != -1)
		return;
	T* newdata = new T[--Size];
	for (int i = 0; i < index; i++)
		newdata[i] = data[i];
	for (int i = index; i < Size; i++)
		newdata[i] = data[i + 1];
	delete[] data;
	data = newdata;
	return;
};

template <class T> bool MySet<T>::contains(const T& elem) const
{
	if (FindElem(elem, 0, Size - 1) == -1)
		return true;
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
