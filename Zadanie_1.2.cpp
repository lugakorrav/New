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
	if ((t1<0)||(t2<0)||(t3<0)||(v1<0)||(v2<0)||(v3<0))
	{
		cout<<"Введены некорректные значения."<<endl;
	}
	else
	{
	double s1=v1*t1,s2=v2*t2,s3=v3*t3;
	s=(s1+s2+s3)/2;
	if (s1<s)
	{
		if (s1+s2<s)
		{
			T=t1+t2+(s-s1-s2)/v3;
		}
		else
		{
			T=t1+(s-s1)/v2;
		}
	}
	else
	{
		T=s/v1;
	}
	cout<<"Путник пройдет половину пути за "<<T<<" часов."<<endl;
	}
	system("pause");
	return 0;
}
