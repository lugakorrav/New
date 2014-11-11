#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <windows.h>
#include <locale.h>
using namespace std;
const int N=22;
int main()
{
	setlocale(0,"");
	int cp=GetConsoleCP();
	string str,buffer;
	char ch[N];
	bool b;
	ch[0]='а';ch[1]='в';ch[2]='е';ch[3]='к';ch[4]='м';ch[5]='н';ch[6]='о';ch[7]='р';ch[8]='с';ch[9]='т';ch[10]='х';
	ch[11]='А';ch[12]='В';ch[13]='Е';ch[14]='К';ch[15]='М';ch[16]='Н';ch[17]='О';ch[18]='Р';ch[19]='С';ch[20]='Т';ch[21]='Х';
	cout<<"Введите текст"<<endl<<endl;
	SetConsoleCP(1251);
	getline(cin,str);
	SetConsoleCP(cp);
	cout<<endl;
	for (int i=0; i<=str.size(); )
	{
		b=1;
		while (((str[i]>='а')&&(str[i]<='я'))||((str[i]>='А')&&(str[i]<='Я')))
		{
			for (int k=0; k<N; k++)
			{
				if (str[i]==ch[k])
				{
					buffer+=str[i];
					cout<<buffer<<endl;
					b=0;
					break;
				}
			}
			if (b=0)
				buffer="";
			if (++i>=str.size())
				break;
		}
		i++;
		cout<<buffer<<" ";
		buffer="";
	}
	cout<<endl<<endl;
	system("pause");
	return 0;
}
