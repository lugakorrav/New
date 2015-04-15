#include "useful.h"

int random(int min, int max)
{
	return (min + rand() % (max - min + 1));
}

bool Pressed(char key)
{
	if (_kbhit())
	{
		char c = _getch();
		return (c == key || c == key + 32);
	};
	return false;
};
