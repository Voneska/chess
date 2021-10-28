#include <iostream>
#include <Windows.h>
#include <string>
#include "pictures_of_figures.h"

using namespace std;

unsigned short cell[8][8] = {0};


HWND hWnd = GetConsoleWindow();
HDC hdc = GetDC(hWnd);
// создание memory DC для этого bitmap-а:
HDC bmpDC = CreateCompatibleDC(hdc);
int height = GetDeviceCaps(hdc, VERTRES);
int width = GetDeviceCaps(hdc, HORZRES);


//Координаты левого верхнего угла доски 
int x_start = 300;
int y_start = 1;




void translatePosition(string position, unsigned short* pos)
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

bool white_or_black_background(unsigned short i, unsigned short j) // 1 - white background of figure, 0 - black background of figure
{
	if (i % 2 == 0)
	{
		if (j % 2 == 0) return 0;
		else return 1;
	}
	else
	{
		if (j % 2 == 0) return 1;
		else return 0;
	}
}

void show() // сначало модифицируем массив cell, затем вызываем данную функцию
{
	unsigned short x = 0;
	unsigned short y = 0; 
	unsigned short figure = 0;  
	HBITMAP hBmp = (HBITMAP)LoadImage(NULL, BOARD, IMAGE_BITMAP, 350, 350, LR_LOADFROMFILE);
	SelectObject(bmpDC, hBmp);
	// вывод (wndDC - HDC окна):  chessboard
	BitBlt(hdc, x_start, y_start, width, height, bmpDC, 0, 0, SRCCOPY);
	for (int i = 7; i >= 0; i--) {
		for(int j = 0; j <8; j++){
			figure = cell[i][j];
			x = j * SIZECELL;
			y = (i - 7) * (-1)* SIZECELL; // inversion - beginning at the bottom
			if (figure == 0) continue;
			else if (figure / 10 == 1) { // color (white)
				switch (figure % 10) // type of figure
				{
					case 1:
						if (white_or_black_background(i,j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_PAWN_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, WHITE_PAWN_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 2:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_HORSE_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, WHITE_HORSE_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 3:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_BISHOP_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, WHITE_BISHOP_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 4:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_ROOK_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, WHITE_ROOK_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 5:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_QUEEN_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, WHITE_QUEEN_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 6:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_KING_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, WHITE_KING_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
				}
			}
			else if (figure / 10 == 2) // color (black)
			{
				switch (figure % 10) // type of figure
				{
					case 1:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, BLACK_PAWN_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, BLACK_PAWN_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 2:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, BLACK_HORSE_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, BLACK_HORSE_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 3:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, BLACK_BISHOP_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, BLACK_BISHOP_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 4:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, BLACK_ROOK_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, BLACK_ROOK_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 5:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, BLACK_QUEEN_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, BLACKE_QUEEN_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
					case 6:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, BLACK_KING_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
						else hBmp = (HBITMAP)LoadImage(NULL, BLACK_KING_BLACK, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
					break;
				}
			}
			
			// загрузка bitmap-а из файла:
			SelectObject(bmpDC, hBmp);
			// вывод (wndDC - HDC окна):
			BitBlt(hdc, x_start + 17 + x, y_start + 17 + y, width, height, bmpDC, 0, 0, SRCCOPY);
		}
	}
	// освобождение ресурсов:
	DeleteObject(hBmp);
	DeleteDC(bmpDC);
}


bool motionCheck(string position) // 1 - ход возможен, 0 - хода нет
{
	int i = 0;
	int j = 0;
	int step_j = 2;
	int step_i = 2;
	unsigned short i0[2] = { 0 };
	translatePosition(position, i0);
	unsigned short color = cell[i0[1]][i0[0]] / 10;  // определение цвета игрока
	i0[1] == 0 ? i = i0[1] : i = i0[1] - 1; // прописанные исключения; буквы - j, цифры - i
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
	cell[0][0] = 14; cell[0][1] = 12; cell[0][2] = 13; cell[0][3] = 15;
	cell[0][4] = 16; cell[0][5] = 13; cell[0][6] = 12; cell[0][7] = 14;
	for (int i = 0; i < 8; i++)
	{
		cell[1][i] = 11;
		cell[6][i] = 21;
	}
	cell[7][0] = 24; cell[7][1] = 22; cell[7][2] = 23; cell[7][3] = 25;
	cell[7][4] = 26; cell[7][5] = 23; cell[7][6] = 22; cell[7][7] = 24;

	cout<< "\n" <<motionCheck("e5");
	show();
	cin.get();
	
}
