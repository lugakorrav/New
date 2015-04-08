#pragma once
#include <iostream>
#include "interfaces.h"

using namespace std;

template <class T> class MySet : public ISet < T >
{
private:
	T* data; // Отсортированный массив
	int Size;
	int FindElem(const T& elem, int min, int max) const; // Бинарный поиск
public:
	MySet();
	MySet(const MySet<T>& S);
	~MySet();
	MySet& operator = (const MySet<T>& S);
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

template <class T> MySet<T>::MySet(const MySet<T>& S)
{
	data = new T[S.Size];
	Size = S.Size;
	for (int i = 0; i < Size; i++)
		data[i] = S.data[i];
};

template <class T> MySet<T>::~MySet()
{
	delete[] data;
};

template <class T> MySet<T>& MySet<T>::operator = (const MySet<T>& S)
{
	if (Size > 0)
		delete[] data;
	Size = S.Size;
	data = new T[Size];
	for (int i = 0; i < Size; i++)
		data[i] = S.data[i];
	return *this;
};

template <class T> int MySet<T>::FindElem(const T& elem, int min, int max) const
{

	int mid = (min + max) / 2;
	if (data[mid] == elem)
		return mid*(-1);
	if (elem > data[max])
		return max + 1;
	if (elem < data[min])
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
	int index = FindElem(elem, 0, Size - 1); // Сложность - O(log[2](N))
	if (index <= 0)
	{
		cout << "Already exist\n";
		return;
	};
	T* newdata = new T[++Size];
	for (int i = 0; i < index; i++) // Сложность - O(N), память выделяется при каждом добавлении/удалении элемента
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
	int index = FindElem(elem, 0, Size - 1); // Сложность - O(log[2](N))
	if (index > 0)
		return;
	index *= (-1);
	T* newdata = new T[--Size];
	for (int i = 0; i < index; i++) // Сложность - O(N)
		newdata[i] = data[i];
	for (int i = index; i < Size; i++)
		newdata[i] = data[i + 1];
	delete[] data;
	data = newdata;
	return;
};

template <class T> bool MySet<T>::contains(const T& elem) const
{
	if (FindElem(elem, 0, Size - 1) <= 0) // Сложность - O(log[2](N))
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
