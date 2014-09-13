#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a;
	cout<<"Введите длину в дюймах"<<endl;
	cin>>a;
	if (a<0)
	{
		cout<<"Введено некорректное значение."<<endl;
	}
	else
	{
	double m=a*0.0254;
	double sm=a*2.54;
	cout<<(int)m<<"m"<<(int)(sm-(int)m*100)<<"sm"<<(a*25.4-(int)sm*10)<<"mm"<<endl;
	}
	system("pause");
	return 0;
}
