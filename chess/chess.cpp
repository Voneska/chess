/* 
Кодировка
_                      _ 
0 - пустая ячейка      3 - пешка
1 - черная фигура      4 - конь
2 - белая фигура	   ...

Например:
13 - черная пешка
*/


#include <iostream>
#include <Windows.h>

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

class Figures {
private:
	int color;
public:
	Figures(int color0 = 2) : color(color0) { };
	int checkcolor() { return color; }
};

int main()
{
	Figures BlackHorse(1), WhiteHorse;
	std::cout << BlackHorse.checkcolor() << "\t" << WhiteHorse.checkcolor()<< std::endl;


	return 0;
}


