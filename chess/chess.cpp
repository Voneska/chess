#include <iostream>
#include <Windows.h>

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

int main()
{

	printf("hello word");
	std::cout << "\nHello word2\n";
	return 0;
}


