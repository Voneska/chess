#include <iostream>
#include <Windows.h>
#include <string>

#define DESK L"pictures\\desk3.bmp"
#define PESHKA L"pictures\\horsewhite.bmp"

using namespace std;

int cell[8][8] = {0};


HWND hWnd = GetConsoleWindow();
HDC hdc = GetDC(hWnd);
// создание memory DC для этого bitmap-а:
HDC bmpDC = CreateCompatibleDC(hdc);
int height = GetDeviceCaps(hdc, VERTRES);
int width = GetDeviceCaps(hdc, HORZRES);


//Координаты левого верхнего угла доски MAKEINTRESOURCE(IDB_DESK)  LR_LOADFROMFILE | LR_DEFAULTSIZE  L"pictures\\desk3.bmp" LR_DEFAULTCOLOR
int x = 300;
int y = 1;




void show(string position)
{
	// загрузка bitmap-а из файла:
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, PESHKA, IMAGE_BITMAP, 30, 34, LR_LOADFROMFILE);
	HBITMAP hBmp1 = (HBITMAP)LoadImage(NULL, DESK, IMAGE_BITMAP, 300, 300, LR_LOADFROMFILE);
	cout << GetLastError();
	SelectObject(bmpDC, hBmp1);
	// вывод (wndDC - HDC окна):
	BitBlt(hdc, x, y, width, height, bmpDC, 0, 0, SRCCOPY);

	SelectObject(bmpDC, hBmp);
	// вывод (wndDC - HDC окна):
	BitBlt(hdc, x+13+30, y+13+34*2, width, height, bmpDC, 0, 0, SRCCOPY);
	// освобождение ресурсов:           
	DeleteDC(bmpDC);
	DeleteObject(hBmp);
	DeleteObject(hBmp1);
}

void translatePosition(string position, int* pos)
{
	switch (position.at(0))
	{
	case 'A':
	case 'a': pos[0] = 0;
		break;
	case 'B':
	case 'b': pos[0] = 1;
		break;
	case 'C':
	case 'c': pos[0] = 2;
		break;
	case 'D':
	case 'd': pos[0] = 3;
		break;
	case 'E':
	case 'e': pos[0] = 4;
		break;
	case 'F':
	case 'f': pos[0] = 5;
		break;
	case 'G':
	case 'g': pos[0] = 6;
		break;
	case 'H':
	case 'h': pos[0] = 7;
		break;
	}
	pos[1] = position.at(1) - '0' - 1;
}



void gen()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++) cell[i][j] = rand();
	}
	cell[1][0] = 0;
}
void print()
{
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 0; j < 8; j++) cout<< cell[i][j]<<"   ";
		cout << endl;
	}
}

bool motionCheck(string position) // 1 - ход возможен, 0 - хода нет
{
	int i = 0;
	int j = 0;
	int step_j = 2;
	int step_i = 2;
	int i0[2] = { 0 };
	translatePosition(position, i0);
	int color = cell[i0[1]][i0[0]] / 10;  // определение цвета игрока
	i0[1] == 0 ? i = i0[1] : i = i0[1] - 1; // прописанные исключения
	i0[0] == 0 ? j = i0[0] : j = i0[0] - 1;
	i0[0] == 7 ? step_j = 1 : step_j = 2;
	i0[1] == 7 ? step_i = 1 : step_i = 2;
	for (; i < i0[1] + step_i; i++) 
	{
		for (; j < i0[0] + step_j; j++)
		{
			if (cell[i][j] == 0) return 1;
			else if (cell[i][j] % 10 != color)
			{
				//if(!proverka_bit_kletki()) return 1; Вызывается проверка битой клетки, если клетка не бьется, то return 1;
			}
		}
		if (i0[0] == 0 || i0[0] == 7) j -= 2;
		else j -= 3;
	}
	return 0;
}




int main()
{
	//gen();
	//print();
	//cout<< "\n" <<motionCheck("a8");
	show("0");
	cin.get();
}





/*
#include <iostream>
#include <Windows.h>

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
//class menu
class Menu {
private:
	int user_choise = 0;

	void menu_window() {
		system("cls");
		std::cout << "\tHello, stranger." << std::endl;
		std::cout << "1. New game" << std::endl;
		std::cout << "2. Reference" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "Your choise: ";
	}

public:
	void New_game() {
		system("cls");
		std::cout << "New game have been starting!" << std::endl;
		Sleep(1000);
	}
	void Reference() {
		system("cls");
		std::cout << "Write:" << std::endl;
		std::cout << "1. \"Pass\" to surrender." << std::endl;
		std::cout << "2. \"Draw\" to offer a draw." << std::endl;
		std::cout << "Type enter to exit reference.";
		std::cin.get();
		std::cin.get();
	}
	void Exit() {
		system("cls");
		std::cout << "Thanks for playing. Good bye." << std::endl;
	}
	void Err_choise() {
		system("cls");
		std::cout << "It's wrong!" << std::endl;
		Sleep(500);
	}

	int set_choise() {
		menu_window();
		std::cin >> user_choise;
		if (std::cin.fail()) { // check error flags
			std::cin.clear(); // clears error flags
			std::cin.ignore(2323, '\n'); // ~ while(cin.get() != '\n');
		}
		return user_choise;
	}
	int give_choise() { return user_choise; }
};


int main()
{
	Menu game_menu;

	switch (game_menu.set_choise()) {
	case 1:
		game_menu.New_game();
		main();
		break;
	case 2:
		game_menu.Reference();
		main();
		break;
	case 3:
		game_menu.Exit();
		break;
	default:
		game_menu.Err_choise();
		main();
	}


	return 0;
}*/