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



	HPEN pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
	HBRUSH pen1 = CreateSolidBrush(RGB(137, 104, 37));
	SelectObject(hdc, pen);
	SelectObject(hdc, pen1);
	Rectangle(hdc, 60, 60, 200, 200);
	DeleteObject(pen);
	DeleteObject(pen1);
	getchar();

	return 0;
}


