#pragma once
#include <iostream>
#include "interfaces.h"

using namespace std;

class Exception {};

template <class T> class MySet : public ISet < T >
{
private:
	T* data;
	int Size;
	int FindElem(const T& elem, int min, int max);
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

template <class T> MySet<T>::MySet() // По умолчанию выделяется память под 1 элемент
{
	Size = 0;
};

template <class T> MySet<T>::~MySet()
{
	delete[] data;
};

template <class T> int MySet<T>::FindElem(const T& elem, int min, int max)
{
	if (min == Size - 1)
		return Size;
	int mid = (min + max) / 2;
	if (data[mid] == elem)
		return -1;
	if (min == max)
		return min;
	if (elem < mid)
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
		return;
	};
	int index;
	if (index = FindElem(elem, 0, Size - 1) < 0 == -1)
		throw Exception;
	T* newdata = new T[++Size];
	for (int i = 0; i < index; i++)
		newdata[i] = data[i];
	newdata[index] = elem;
	for (int i = index + 1; i < Size; i++)
		newdata[i] = data[i - 1];
	return;
};

template <class T> void MySet<T>::remove(const T& elem) // Производится поиск указанного элемента в множестве посредством 
{                                                       // перебора всех элементов. Сложность - О(N).
	
};

template <class T> bool MySet<T>::contains(const T& elem) const // Производится поиск указанного элемента в множестве 
{                                                               // посредством перебора всех элементов. Сложность - О(N).
	if (min == Size - 1)
		return false;
	int mid = (min + max) / 2;
	if (data[mid] == elem)
		return true;
	if (min == max)
		return false;
	if (elem < mid)
		return FindElem(elem, min, mid - 1);
	else
		return FindElem(elem, mid + 1, max);
};

template <class T> int MySet<T>::size() const
{
	return Size;
};

template <class T> void MySet<T>::show() // Для проверки.
{
	for (int i = 0; i < Size; i++)
		cout << data[i];
};
