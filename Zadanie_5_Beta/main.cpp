#include<iostream>
#include<fstream>
#include<string.h>
#include"queueclass.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	queue q;
	string str;
	const int N = 3;
	int M=0;
	cout<<"Введите "<<N<<" элементов очереди"<<endl;
	for (int i=0; i<N; i++)
		cin>>q;
	cout<<"Введите число элементов для извлечения"<<endl;
	cin>>M;
	cout<<"Извлечение первых "<<M<<" элементов: "<<endl;
	for (int i=0; i<M; i++)
	cout<<q<<" "<<endl;
	cout<<"Текущий размер очереди: "<<q.queuesize()<<endl;
	return 0;
}
