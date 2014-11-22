#include <iostream>
#include <string>
#include <windows.h>
#include <locale.h>
using namespace std;
const int N=22;
int main()
{
	setlocale(0,"");
	int cp=GetConsoleCP();
	string str,buffer;
	char ch[N+1]="авекмнорстхАВЕКМНОРСТХ";
	bool a,b;
	cout<<"Введите текст"<<endl<<endl;
	SetConsoleCP(1251);
	getline(cin,str);
	SetConsoleCP(cp);
	cout<<endl<<"Результат:"<<endl<<endl;
	for (int i=0; i<=str.size(); )
	{
		a=1;
		while (((str[i]>='а')&&(str[i]<='я'))||((str[i]>='А')&&(str[i]<='Я')))
		{
			b=0;
			for (int k=0; k<N; k++)
			{
				if (str[i]==ch[k])
				{
					buffer+=str[i];
					b=1;
					break;
				}
			}
			if (b==0)
				a=0;
			if (++i>=str.size())
				break;
		}
		if (a==1)
			cout<<buffer<<" ";
		buffer="";
		i++;
	}
	cout<<endl<<endl;
	return 0;
}
