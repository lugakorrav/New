#include<iostream>
#include<fstream>
#include<string.h>
#include"queueclass.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	queue q;
	cout<<"Введите 3 элемента очереди"<<endl;
	cin>>q>>q>>q;
	cout<<"Извлечение первых двух элементов: "<<endl;
	cout<<q<<" "<<q;
	cout<<"Текущий размер очереди: "<<endl;
	q.printsize();
	system("pause");
	return 0;
}
