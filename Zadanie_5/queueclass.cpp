#include"queueclass.h"
queue::queue(int MaxSize)
{
	writeindex=0;
	readindex=0;
	size=0;
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
bool queue::putstr (string str) // Помещение в очередь
{
	if (size==MaxSize)
	{
		cout<<"Достигнут максимальный размер очереди"<<endl;
		return false;
	}
	size++;
	Arr[writeindex++]=str;
	if (writeindex==MaxSize)
		writeindex=0;
	return true;
}
ostream& operator<<(ostream& out, queue& q)
{
	if (q.size==0)
	{
		cout<<"Очередь пуста"<<endl;
		return out;
	}
	q.size--;
	out<<q.Arr[q.readindex++];
	if (q.readindex==q.MaxSize)
		q.readindex=0;
	return out;
}
bool queue::getstr (string* container) // Извлечение из очереди
{
	if (size==0)
	{
		cout<<"Очередь пуста"<<endl;
		return false;
	}
	size--;
	*container=Arr[writeindex++];
	if (writeindex==MaxSize)
		writeindex=0;
	return true;
}
int queue::queuesize()
{
	return size;
}
