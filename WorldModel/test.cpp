#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "useful.h"
#include "world.h"

int main()
{
	//	settings
	setlocale(LC_ALL, "russian");
	srand((int)time(NULL));
	World* w = 0;

	_getch();
	system("CLS");
	if (GetKeyState(KEY_N))
	{
		int x, y;
		std::cout << "Enter the size of the world\n";
		std::cin >> x >> y;
		w = new World(x, y);
	}
	else
	if (GetKeyState(KEY_L))
	{
		char* c = new char[200];
		std::cout << "Enter the load file directory\n";
		std::cin.getline(c, 200);
		w = new World(c);
	};
	if (!w)
		return 0;

	while (1)
	{
		if (GetKeyState(KEY_Z))
		{
			_getch();
			Sleep(500);
			if (GetKeyState(KEY_S))
			{
				char* c = new char[200];
				std::cout << "Enter the save file directory\n";
				std::cin.getline(c, 200);
				w->SaveWorld(c);
			};
		};
		w->PerformStep();
		w->View();
	};

	_getch();
	return true;
}
