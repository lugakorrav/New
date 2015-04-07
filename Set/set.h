#pragma once

using namespace std;

template <class T> class ISet
{
public:
	// добавить элемент
	virtual void add(const T& elem) = 0;
	// удалить элемент
	virtual void remove(const T& elem) = 0;
	// содержится ли элемент
	virtual bool contains(const T& elem) const = 0;
	// узнать размер множества
	virtual int size() const = 0;
};

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
	void add(const T& elem);
	// удалить элемент
	void remove(const T& elem);
	// содержится ли элемент
	bool contains(const T& elem) const;
	// узнать размер множества
	int size() const;
	void show();
};
