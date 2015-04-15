#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

#include "useful.h"
#include "world.h"

int main()
{
	setlocale(LC_ALL, "russian");
	srand((int)time(NULL));
	World* w = 0;

	std::cout << "N - создать новое поле; L - загрузить из файла\n";
	char c = _getch();
	if (c == 'N' || c == 'n')
	{
		int x, y;
		std::cout << "Введите размеры поля\n";
		std::cin >> x >> y;
		w = new World(x, y);
	}
	else
		if (c == 'L' || c == 'l')
		{
			char* c = new char[200];
			std::cout << "Введите имя файла для чтения\n";
			std::cin.getline(c, 200);
			w = new World(c);
			delete[] c;
		};
	if (!w)
		return 0;
	std::cout << "S - сохранить\n";
	system("pause");
	while (1)
	{
		if (Pressed('S'))
		{
			char* c = new char[200];
			std::cout << "Введите имя файла для записи\n";
			std::cin.get();
			std::cin.getline(c, 200);
			w->SaveWorld(c);
			delete[] c;
			system("pause");
		};
		w->PerformStep();
		w->View();
	};
	delete w;
	return true;
}
