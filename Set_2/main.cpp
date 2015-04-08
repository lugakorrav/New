#include "Set.h"
#include <string>
using namespace std;

void foo1()
{
	int arr[3];
	int check = 321;
	arr[0] = 123; arr[1] = 456; arr[2] = 789;
	MySet<int> S;
	S.add(arr[0]);
	S.add(arr[1]);
	S.add(arr[2]);
	S.add(arr[2]);
	MySet<int> S2(S);
	S.show();
	cout << endl << S.size() << endl;
	cout << boolalpha << S.contains(arr[1]) << endl;
	cout << boolalpha << S.contains(check) << endl;
	S.remove(arr[1]);
	S.show();
	cout << endl << S.size() << endl << endl;
	S = S2;
	S.show();
	cout << endl << endl;
};

void foo2()
{
	string arr[3];
	string check = "321";
	arr[0] = "123"; arr[1] = "456"; arr[2] = "789";
	MySet<string> S;
	S.add(arr[0]);
	S.add(arr[1]);
	S.add(arr[2]);
	S.add(arr[2]);
	MySet<string> S2(S);
	S.show();
	cout << endl << S.size() << endl;
	cout << boolalpha << S.contains(arr[1]) << endl;
	cout << boolalpha << S.contains(check) << endl;
	S.remove(arr[1]);
	S.show();
	cout << endl << S.size() << endl << endl;
	S = S2;
	S.show();
	cout << endl << endl;
};

int main()
{
	foo1();
	foo2();
	return 0;
}
