#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double v1,t1,v2,t2,v3,t3,T,s;
	cout<<"Введите скорости"<<endl;
	cin>>v1>>v2>>v3;
	cout<<"Введите время"<<endl;
	cin>>t1>>t2>>t3;
	s=(v1*t1+v2*t2+v3*t3)/2;
	if (v1*t1<s)
	{
		if (v1*t1+v2*t2<s)
		{
			T=t1+t2+(s-v1*t1-v2*t2)/v3;
		}
		else
		{
			T=t1+(s-v1*t1)/v2;
		}
	}
	else
	{
		T=s/v1;
	}
	cout<<"Путник пройдет половину пути за "<<T<<" часов."<<endl;
}
