#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
using namespace std;
bool ch;
char lang(char t)
{
	if (ch!=0)
	{
	setlocale(LC_ALL, "Russian");
	if (((int)t==(-15))||(((int)t>=(-96))&&((int)t<=(-81)))||(((int)t>=(-32))&&((int)t<=(-17))))
		if ((int)t==-15)
			t-=57;
		else
			if (((int)t>=(-32))&&((int)t<=(-17)))
				t+=16;
			else
				t+=64;
	else
		if (((int)t==(-16))||(((int)t>=(-128))&&((int)t<=(-97))))
			if ((int)t==(-16))
				t-=72;
			else
				t+=64;
	}
	return t;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	string word;
	char t[1];
	char min1=('а'), min2=('А'), max1=('я'), max2=('Я');
	cout<<"Исправлять ввод русских букв? Ввести '1' - да; '0'- нет"<<endl;
	cin>>ch;
	cin.get(t[0]);
	cout<<"Введите текст"<<endl;
	t[0]=0;
	while ((int)t[0]!=10)
	{
		cin.get(t[0]);
		t[0]=lang(t[0]);
		while (((t[0]>=min1)&&(t[0]<=max1))||((t[0]>=min2)&&(t[0]<=max2)))
		{
			word+=t[0];
			cin.get(t[0]);
			t[0]=lang(t[0]);
		}
		for (int i=0; i<word.size(); i++)
		{
			if (!((word[i]=='а')||(word[i]=='в')||(word[i]=='е')||(word[i]=='к')||(word[i]=='м')||(word[i]=='н')||
				(word[i]=='о')||(word[i]=='р')||(word[i]=='с')||(word[i]=='т')||(word[i]=='х')||
				(word[i]=='А')||(word[i]=='В')||(word[i]=='Е')||(word[i]=='К')||(word[i]=='М')||
				(word[i]=='Н')||(word[i]=='О')||(word[i]=='Р')||(word[i]=='С')||(word[i]=='Т')||(word[i]=='Х')))
			{
				word="";
				break;
			}
		}
		if (word.size()>0)
		{
			cout<<word<<" ";
			word="";
		}
	}
	cout<<endl;
	return 0;
}
