#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	double N;
	int k,S=0,i=0,p=0;
	setlocale(LC_ALL, "Russian");
	cout<<"������� �����"<<endl;
	cin>>N;
	if((cin.fail())||(N<1)||(((int)(N*10)%10!=0)))
	{
		cout<<"������� ������������ ��������"<<endl;
	}
	else
	{
	    while (S<N)
	    {
		    p++;
		    k=p*p;
		    while (k>0)
		    {
			    k/=10;
			    i++;
		    }
		    S+=i;
		    i=0;
	    }
	    k=(p*p)/(pow(10,S-N));
	    k=k%10;
	    cout<<"�� "<<N<<" ����� ����� "<<k<<"."<<endl;
	    return 0;
    }
}
	
