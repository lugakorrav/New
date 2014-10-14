#include<iostream>
using namespace std;
int main()
{
setlocale(LC_ALL, "RUS");
cout<<"Введите размерность матрицы"<<endl;
int n,i=0,j=0,a;
cin>>n;
if (cin.fail())
{
	cout<<"Введена некорректная размерность"<<endl;
	system("pause");
	return 0;
}
else
{
int *tab = new int[n*n];
bool *x = new bool[n];
bool *y = new bool[n];
for (i=0; i<n; i++)
x[i]=false;
cout<<"Введите элементы матрицы (по строчкам, слева направо)"<<endl;
for (i=0; i<n; i++)
{
for (j=0; j<n; j++)
{
cin>>a;
if ((cin.fail())||(a<1))
{
	cout<<"Введено некорректное значение"<<endl;
	system("pause");
	return 0;
}
*(tab+i*n+j)=a;
if ((a>=1)&&(a<=n))
    x[a-1]=true;
else
{
cout<<"Матрица не является латинским квадратом"<<endl;
system("pause");
return 0;
}
if (j==0)
	y[a-1]=true;
}
for (j=0; j<n; j++)
if (x[j])
x[j]=false;
else
{
cout<<"Матрица не является латинским квадратом"<<endl;
system("pause");
return 0;
}
}
for (i=0; i<n; i++)
if (y[i])
y[i]=false;
else
{
	cout<<"Матрица не является латинским квадратом"<<endl;
    system("pause");
    return 0;
}
cout<<"Матрица является латинским квадратом"<<endl;
system("pause");
return 0;
}
}
