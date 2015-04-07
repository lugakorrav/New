#include <iostream>
#include <string.h>
#include "set.h"

using namespace std;

int main()
{
	int arr[3];
	int check = 321;
	arr[0] = 123; arr[1] = 456; arr[2] = 789;
	MySet<int> S(2);
	S.add(arr[0]);
	S.add(arr[1]);
	S.add(arr[2]);
	S.show();
	S.size();
	cout << boolalpha << S.contains(arr[1]) << endl;
	cout << boolalpha << S.contains(check) << endl;
	S.remove(arr[1]);
	S.show();
	S.size();
}
