#include"queueclass.h"
queue::queue()
{
	int writeindex=0;
	int readindex=0;
	cout<<"Введите максимальный размер очереди"<<endl;
	cin>>MaxSize;
	Arr = new string[MaxSize];
}
queue::~queue()
{
	delete[] Arr;
}
istream& operator >> (istream& in, queue& q)
{
	if (q.size==q.MaxSize)
		return in;
	q.size++;
	in>>q.Arr[q.writeindex++];
	if (q.writeindex==q.MaxSize)
		q.writeindex=0;
	return in;
}
ostream& operator <<(ostream& out, queue& q)
{
	if (q.size==0)
		return out;
	q.size--;
	out<<q.Arr[q.readindex++];
	if (q.readindex=q.MaxSize)
		q.readindex=0;
	return out;
}
void queue::printsize()
{
	cout<<size;
}
