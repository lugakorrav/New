#include<iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	double a;
	cout<<"Введите длину в дюймах"<<endl;
	cin>>a;
	cout<<(int)(a*0.0254)<<"m"<<(int)(a*2.54-(int)(a*0.0254)*100)<<"sm"<<(a*25.4-(int)(a*0.0254)*100-(int)(a*2.54)*10)<<"mm"<<endl;
	return 0;
}
