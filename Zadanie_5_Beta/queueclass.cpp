#include"queueclass.h"
queue::queue()
{
	writeindex=0;
	readindex=0;
	size=0;
	cout<<"Введите максимальный размер очереди"<<endl;
	cin>>MaxSize;
	Arr = new string[MaxSize];
}
queue::~queue()
{
	delete[] Arr;
	writeindex=0;
	readindex=0;
	size=0;
	MaxSize=0;
}
istream& operator>> (istream& in, queue& q)
{
	if (q.size==q.MaxSize)
	{
		cout<<"Достигнут максимальный размер очереди"<<endl;
		return in;
	}
	q.size++;
	in>>q.Arr[q.writeindex++];
	if (q.writeindex==q.MaxSize)
		q.writeindex=0;
	return in;
}
ostream& operator<<(ostream& out, queue& q)
{
	if (q.size==0)
	{
		return out;
		cout<<"Очередь пуста"<<endl;
	}
	q.size--;
	out<<q.Arr[q.readindex++];
	if (q.readindex==q.MaxSize)
		q.readindex=0;
	return out;
}
int queue::queuesize()
{
	return size;
}
