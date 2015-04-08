#pragma once
#include <iostream>
#include "interfaces.h"

using namespace std;

template <class T> class MySet : public ISet < T >
{
private:
	T* data;
	int Size;
	int Capacity;
public:
	MySet();
	MySet(int StartCapacity);
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

template <class T> MySet<T>::MySet() // По умолчанию выделяется память под 1 элемент
{
	Size = 0;
	Capacity = 1;
	data = new T[1];
};

template <class T> MySet<T>::MySet(const MySet<T>& S)
{
	data = new T[S.Capacity];
	Capacity = S.Capacity;
	Size = S.Size;
	for (int i = 0; i < Size; i++)
		data[i] = S.data[i];
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

template <class T> MySet<T>& MySet<T>::operator = (const MySet<T>& S)
{
	if (Capacity > 0)
		delete[] data;
	Capacity = S.Capacity;
	Size = S.Size;
	data = new T[Size];
	for (int i = 0; i < Size; i++)
		data[i] = S.data[i];
	return *this;
};

template <class T> void MySet<T>::add(const T& elem) // Перед добавлением проверяется наличие указанного элемента в множестве                                                   
{                                                    // перебором всех элементов. Сложность - О(N).
	for (int i = 0; i < Size; i++)               // При нехватке места выделяемая под множество память увеличивается вдвое.                   
		if (data[i] == elem)                 // Сложность - О(N).
		{                                    // При копировании данных в новую область памяти временно храним старую.
			cout << "Already exist" << endl;
			return;
		};
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

template <class T> void MySet<T>::remove(const T& elem) // Производится поиск указанного элемента в множестве посредством 
{                                                       // перебора всех элементов. Сложность - О(N).
	int i;
	for (i = 0; data[i] != elem && i < Size; i++);
	if (i == Size && data[Size] != elem)
	{
		cout << "Not exist" << endl;
		return;
	};
	for (int j = i; j < Size - 1; j++) // Для удаления элемента производится сдвиг всех элементов, стоящих после него путем 
		data[j] = data[j + 1];         // перебора. Сложность - О(N).
	Size--;
};

template <class T> bool MySet<T>::contains(const T& elem) const // Производится поиск указанного элемента в множестве 
{                                                               // посредством перебора всех элементов. Сложность - О(N).
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

template <class T> void MySet<T>::show() // Для проверки.
{
	for (int i = 0; i < Size; i++)
		cout << data[i];
};

// Всего в методах множества используется 5 алгоритмов сложностью О(N). Посредством удвоения размера множества вместо 
// выделения памяти при каждом добавлении элемента получена более высокая производительность за счет увеличения
// требуемого объема памяти.
