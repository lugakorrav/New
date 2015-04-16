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

	std::cout << "1 - создать новое поле; 2 - загрузить из файла\n";
	char c = _getch();
	switch (c)
	{
	case '1':
	{
		int x, y;
		std::cout << "Введите размеры поля\n";
		std::cin >> x >> y;
		w = new World(x, y);
		break;
	};
	case '2':
	{
		char* c = new char[200];
		std::cout << "Введите имя файла для чтения\n";
		std::cin.getline(c, 200);
		w = new World(c);
		delete[] c;
		break;
	};
	};
	if (!w)
		return 0;
	std::cout << "1 - сохранить; 2 - пауза; Esc - выход\n";
	system("pause");
	while (1)
	{
		if (_kbhit())
		{
			char buf = _getch();
			switch (buf)
			{
			case '1':
			{
				char* c = new char[200];
				std::cout << "Введите имя файла для записи\n";
				std::cin.get();
				std::cin.getline(c, 200);
				bool is_saved = w->SaveWorld(c);
				delete[] c;
				std::cout << "Сохранено\n";
				system("pause");
				break;
			};
			case '2':
			{
				std::cout << "1 - сохранить\n";
				char buf = _getch();
				switch (buf)
				{
				case '1':
				{
					char* c = new char[200];
					std::cout << "Введите имя файла для записи\n";
					std::cin.get();
					std::cin.getline(c, 200);
					bool is_saved = w->SaveWorld(c);
					delete[] c;
					switch (is_saved)
					{
					case 1:
					{
						std::cout << "Сохранено\n";
						break;
					};
					case 0:
					{
						std::cout << "Не сохранено\n";
						break;
					};
					};
					system("pause");
					break;
				};
				case 27:
					return 0;
				};
				break;
			};
			case 27:
				return 0;
			};
		};
		w->PerformStep();
		w->View();
	};
	delete w;
	return true;
}
