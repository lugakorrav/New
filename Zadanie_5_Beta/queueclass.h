#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
class queue
{
private:
	int writeindex;
	int readindex;
	string* Arr;
public:
	int MaxSize;
	int size;
	queue(); //Конструктор
	~queue(); //Деструктор
	friend istream& operator >>(istream& in, queue& q); //Ввод из std::istream 
	friend ostream& operator <<(ostream& out, queue& q); //Вывод в std::ostream
	void printsize();
};
