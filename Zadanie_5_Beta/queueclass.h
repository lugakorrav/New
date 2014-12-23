#pragma once
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
class queue
{
private:
	int MaxSize;
	int size;
	int writeindex;
	int readindex;
	string* Arr;
public:
	queue(); //Конструктор
	~queue(); //Деструктор
	friend istream& operator >>(istream& in, queue& q); //Ввод из std::istream 
	friend ostream& operator <<(ostream& out, queue& q); //Вывод в std::ostream
	int queuesize();
};
