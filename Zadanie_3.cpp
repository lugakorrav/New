#include<iostream>
using namespace std;
void fail()
{
	cout<<"Матрица не является латинским квадратом"<<endl;
	system("pause");
}
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
		int *tab = new int[n*n],b;
		bool *x = new bool[n];
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
				if (!((a>=1)&&(a<=n)))
				{
					fail();
					return 0;
				}
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<n; j++)
				x[*(tab+i*n+j)]=true;
			for (i=1; i<=n; i++)
				if (!(x[i]))
				{
					fail();
					return 0;
				}
				else
					x[i]=false;
		}
		for (j=0; j<n; j++)
		{
			for (i=0; i<n; i++)
				x[*(tab+i*n+j)]=true;
			for (i=1; i<=n; i++)
				if (!(x[i]))
				{
					fail();
					return 0;
				}
				else
					x[i]=false;
		}
	}
	cout<<"Матрица является латинским квадратом"<<endl;
	system("pause");
	return 0;
}
