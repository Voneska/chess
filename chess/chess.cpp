#include <iostream>
#include <Windows.h>
#include <ctime>
#include <string>
#include "pictures_of_figures.h"

using namespace std;

string white, black;
bool turn;
int k = 0;

class Chess
{
private:
	unsigned short cell[8][8], cell_from, cell_to;

	void victory()
	{
		if (turn == 0)
			cout << "Checkmate to the black King\n" << white << " wooooooon!!!\n";
		else if (turn == 1) cout << "Checkmate to the white King\n" << black << " wooooooon!!!\n";
	}

	void Draw() 
	{
		string answer;
		if (turn)
		{
			cout << "Player " << black << " offers a draw to you. \nDo you accept (Yes/No)? \n";
			cin >> answer;
			if (answer.at(0) == 'Y' || answer.at(0) == 'y') 
			{
				cout << "Draw!\n";
				k = 666;
			}
			else
			{
				cout << white << " do not agree.\n";
			}
		}
		else
		{
			cout << "Player " << white << " offers a draw to you. \nDo you accept (Yes/No)? \n";
			cin >> answer;
			if (answer.at(0) == 'Y' || answer.at(0) == 'y')
			{
				cout << "Draw!\n";
				k = 666;
			}
			else
			{
				cout << black << " do not agree.\n";
			}
		}
	}

	void Pass()
	{
		k = 666;
		if (turn) cout << "Player " << black << " has passed.\n" << white << " won!";
		else cout << "Player " << white << " has passed.\n" << black << " won!";
	}


public:
	bool check_cell(unsigned short hod[2]/*клетка потенциального удара*/, bool king/*учет удара короля*/)//vozvrashaet 0 v slychae esli cletca ne bietsa
	{
		//unsigned short hod[2];
		//translatePosition(s, hod);
		for (int i = hod[1] + 1; i < 8; i++)//n
		{
			if ((cell[i][hod[0]] / 10) == (turn + 1))  break;
			if ((cell[i][hod[0]] / 10) != 0)
				if (((cell[i][hod[0]] % 10) == 4) || ((cell[i][hod[0]] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[1] - 1; i >= 0; i--)//s
		{
			if ((cell[i][hod[0]] / 10) == (turn + 1))  break;
			if ((cell[i][hod[0]] / 10) != 0)
				if (((cell[i][hod[0]] % 10) == 4) || ((cell[i][hod[0]] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[0] + 1; i < 8; i++)//e
		{
			if ((cell[hod[1]][i] / 10) == (turn + 1))  break;
			if ((cell[hod[1]][i] / 10) != 0)
				if (((cell[hod[1]][i] % 10) == 4) || ((cell[hod[1]][i] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[0] - 1; i >= 0; i--)//w
		{
			if ((cell[hod[1]][i] / 10) == (turn + 1))  break;
			if ((cell[hod[1]][i] / 10) != 0)
				if (((cell[hod[1]][i] % 10) == 4) || ((cell[hod[1]][i] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[1] + 1, j = hod[0] + 1; j < 8 && i < 8; j++, i++)//n-e
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[1] - 1, j = hod[0] - 1; j >= 0 && i >= 0; j--, i--)//s-w
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[1] - 1, j = hod[0] + 1; j < 8 && i >= 0; j++, i--)//s-e
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) return 1;
				else break;
		}
		for (int i = hod[1] + 1, j = hod[0] - 1; j >= 0 && i < 8; j--, i++)//n-w
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) return 1;
				else break;
		}
		if ((hod[1] + 2 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 2][hod[0] + 1] % 10 == 2) && (cell[hod[1] + 2][hod[0] + 1] / 10 != turn + 1)) return 1;//horse
		if ((hod[1] + 1 < 8) && (hod[0] + 2 < 8) && (cell[hod[1] + 1][hod[0] + 2] % 10 == 2) && (cell[hod[1] + 1][hod[0] + 2] / 10 != turn + 1)) return 1;
		if ((hod[1] + 2 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 2][hod[0] - 1] % 10 == 2) && (cell[hod[1] + 2][hod[0] - 1] / 10 != turn + 1)) return 1;
		if ((hod[1] + 1 < 8) && (hod[0] - 2 >= 0) && (cell[hod[1] + 1][hod[0] - 2] % 10 == 2) && (cell[hod[1] + 1][hod[0] - 2] / 10 != turn + 1)) return 1;
		if ((hod[1] - 2 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 2][hod[0] + 1] % 10 == 2) && (cell[hod[1] - 2][hod[0] + 1] / 10 != turn + 1)) return 1;
		if ((hod[1] - 1 >= 0) && (hod[0] + 2 < 8) && (cell[hod[1] - 1][hod[0] + 2] % 10 == 2) && (cell[hod[1] - 1][hod[0] + 2] / 10 != turn + 1)) return 1;
		if ((hod[1] - 2 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 2][hod[0] - 1] % 10 == 2) && (cell[hod[1] - 2][hod[0] - 1] / 10 != turn + 1)) return 1;
		if ((hod[1] - 1 >= 0) && (hod[0] - 2 >= 0) && (cell[hod[1] - 1][hod[0] - 2] % 10 == 2) && (cell[hod[1] - 1][hod[0] - 2] / 10 != turn + 1)) return 1;

		if (king == 1)
		{
			if ((hod[1] + 1 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 1][hod[0] + 1] % 10 == 6) && (cell[hod[1] + 1][hod[0] + 1] / 10 != turn + 1)) return 1;//king
			if ((hod[1] + 1 < 8) && (cell[hod[1] + 1][hod[0]] % 10 == 6) && (cell[hod[1] + 1][hod[0]] / 10 != turn + 1)) return 1;
			if ((hod[1] + 1 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 1][hod[0] - 1] % 10 == 6) && (cell[hod[1] + 1][hod[0] - 1] / 10 != turn + 1)) return 1;
			if ((hod[1] - 1 >= 0) && (cell[hod[1] - 1][hod[0]] % 10 == 6) && (cell[hod[1] - 1][hod[0]] / 10 != turn + 1)) return 1;
			if ((hod[1] - 1 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 1][hod[0] + 1] % 10 == 6) && (cell[hod[1] - 1][hod[0] + 1] / 10 != turn + 1)) return 1;
			if ((hod[0] + 1 < 8) && (cell[hod[1]][hod[0] + 1] % 10 == 6) && (cell[hod[1]][hod[0] + 1] / 10 != turn + 1)) return 1;
			if ((hod[1] - 1 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 1][hod[0] - 1] % 10 == 6) && (cell[hod[1] - 1][hod[0] - 1] / 10 != turn + 1)) return 1;
			if ((hod[0] - 1 >= 0) && (cell[hod[1]][hod[0] - 1] % 10 == 6) && (cell[hod[1]][hod[0] - 1] / 10 != turn + 1)) return 1;
		}

		if (turn == 0)//peska
		{
			if ((hod[1] + 1 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 1][hod[0] + 1] % 10 == 1) && (cell[hod[1] + 1][hod[0] + 1] / 10 == 2)) return 1;
			if ((hod[1] + 1 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 1][hod[0] - 1] % 10 == 1) && (cell[hod[1] + 1][hod[0] - 1] / 10 == 2)) return 1;
		}
		else
		{
			if ((hod[1] - 1 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 1][hod[0] + 1] % 10 == 1) && (cell[hod[1] - 1][hod[0] + 1] / 10 == 1)) return 1;
			if ((hod[1] - 1 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 1][hod[0] - 1] % 10 == 1) && (cell[hod[1] - 1][hod[0] - 1] / 10 == 1)) return 1;
		}
		return 0;
	}
	Chess()
	{
		cell_from = 0;
		cell_to = 0;
		for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) cell[i][j] = 0;
	}
private:

	bool check_cell(unsigned short hod[2]/*, bool king/*учет удара короля*/, unsigned short& attacker_kind, unsigned short* attacker_pos)//vozvrashaet 0 v slychae esli cletca ne bietsa
	{
		//unsigned short hod[2];
		//translatePosition(s, hod);
		for (int i = hod[1] + 1; i < 8; i++)//n
		{
			if ((cell[i][hod[0]] / 10) == (turn + 1))  break;
			if ((cell[i][hod[0]] / 10) != 0)
				if (((cell[i][hod[0]] % 10) == 4) || ((cell[i][hod[0]] % 10) == 5)) { attacker_kind = 4; attacker_pos[0] = hod[0]; attacker_pos[1] = i; return 1; }
				else break;
		}
		for (int i = hod[1] - 1; i >= 0; i--)//s
		{
			if ((cell[i][hod[0]] / 10) == (turn + 1))  break;
			if ((cell[i][hod[0]] / 10) != 0)
				if (((cell[i][hod[0]] % 10) == 4) || ((cell[i][hod[0]] % 10) == 5)) { attacker_kind = 4; attacker_pos[0] = hod[0]; attacker_pos[1] = i; return 1; }
				else break;
		}
		for (int i = hod[0] + 1; i < 8; i++)//e
		{
			if ((cell[hod[1]][i] / 10) == (turn + 1))  break;
			if ((cell[hod[1]][i] / 10) != 0)
				if (((cell[hod[1]][i] % 10) == 4) || ((cell[hod[1]][i] % 10) == 5)) { attacker_kind = 4; attacker_pos[0] = i; attacker_pos[1] = hod[1]; return 1; }
				else break;
		}
		for (int i = hod[0] - 1; i >= 0; i--)//w
		{
			if ((cell[hod[1]][i] / 10) == (turn + 1))  break;
			if ((cell[hod[1]][i] / 10) != 0)
				if (((cell[hod[1]][i] % 10) == 4) || ((cell[hod[1]][i] % 10) == 5)) { attacker_kind = 4; attacker_pos[0] = i; attacker_pos[1] = hod[1]; return 1; }
				else break;
		}
		for (int i = hod[1] + 1, j = hod[0] + 1; j < 8 && i < 8; j++, i++)//n-e
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) { attacker_kind = 3; attacker_pos[0] = j; attacker_pos[1] = i; return 1; }
				else break;
		}
		for (int i = hod[1] - 1, j = hod[0] - 1; j >= 0 && i >= 0; j--, i--)//s-w
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) { attacker_kind = 3; attacker_pos[0] = j; attacker_pos[1] = i; return 1; }
				else break;
		}
		for (int i = hod[1] - 1, j = hod[0] + 1; j < 8 && i >= 0; j++, i--)//s-e
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) { attacker_kind = 3; attacker_pos[0] = j; attacker_pos[1] = i; return 1; }
				else break;
		}
		for (int i = hod[1] + 1, j = hod[0] - 1; j >= 0 && i < 8; j--, i++)//n-w
		{
			if ((cell[i][j] / 10) == (turn + 1))  break;
			if ((cell[i][j] / 10) != 0)
				if (((cell[i][j] % 10) == 3) || ((cell[i][j] % 10) == 5)) { attacker_kind = 3; attacker_pos[0] = j; attacker_pos[1] = i; return 1; }
				else break;
		}
		if ((hod[1] + 2 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 2][hod[0] + 1] % 10 == 2) && (cell[hod[1] + 2][hod[0] + 1] / 10 != turn + 1))//horse
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] + 1; attacker_pos[1] = hod[1] + 2; return 1;
		}
		if ((hod[1] + 1 < 8) && (hod[0] + 2 < 8) && (cell[hod[1] + 1][hod[0] + 2] % 10 == 2) && (cell[hod[1] + 1][hod[0] + 2] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] + 2; attacker_pos[1] = hod[1] + 1; return 1;
		}
		if ((hod[1] + 2 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 2][hod[0] - 1] % 10 == 2) && (cell[hod[1] + 2][hod[0] - 1] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] - 1; attacker_pos[1] = hod[1] + 2; return 1;
		}
		if ((hod[1] + 1 < 8) && (hod[0] - 2 >= 0) && (cell[hod[1] + 1][hod[0] - 2] % 10 == 2) && (cell[hod[1] + 1][hod[0] - 2] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] - 2; attacker_pos[1] = hod[1] + 1; return 1;
		}
		if ((hod[1] - 2 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 2][hod[0] + 1] % 10 == 2) && (cell[hod[1] - 2][hod[0] + 1] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] + 1; attacker_pos[1] = hod[1] - 2; return 1;
		}
		if ((hod[1] - 1 >= 0) && (hod[0] + 2 < 8) && (cell[hod[1] - 1][hod[0] + 2] % 10 == 2) && (cell[hod[1] - 1][hod[0] + 2] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] + 2; attacker_pos[1] = hod[1] - 1; return 1;
		}
		if ((hod[1] - 2 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 2][hod[0] - 1] % 10 == 2) && (cell[hod[1] - 2][hod[0] - 1] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] - 1; attacker_pos[1] = hod[1] - 2; return 1;
		}
		if ((hod[1] - 1 >= 0) && (hod[0] - 2 >= 0) && (cell[hod[1] - 1][hod[0] - 2] % 10 == 2) && (cell[hod[1] - 1][hod[0] - 2] / 10 != turn + 1))
		{
			attacker_kind = 2; attacker_pos[0] = hod[0] - 2; attacker_pos[1] = hod[1] - 1; return 1;
		}

		//if (king == 1)
		//{
		//	if ((hod[1] + 1 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 1][hod[0] + 1] % 10 == 6) && (cell[hod[1] + 1][hod[0] + 1] / 10 != turn + 1)) return 1;//king
		//	if ((hod[1] + 1 < 8) && (cell[hod[1] + 1][hod[0]] % 10 == 6) && (cell[hod[1] + 1][hod[0]] / 10 != turn + 1)) return 1;
		//	if ((hod[1] + 1 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 1][hod[0] - 1] % 10 == 6) && (cell[hod[1] + 1][hod[0] - 1] / 10 != turn + 1)) return 1;
		//	if ((hod[1] - 1 >= 0) && (cell[hod[1] - 1][hod[0]] % 10 == 6) && (cell[hod[1] - 1][hod[0]] / 10 != turn + 1)) return 1;
		//	if ((hod[1] - 1 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 1][hod[0] + 1] % 10 == 6) && (cell[hod[1] - 1][hod[0] + 1] / 10 != turn + 1)) return 1;
		//	if ((hod[0] + 1 < 8) && (cell[hod[1]][hod[0] + 1] % 10 == 6) && (cell[hod[1]][hod[0] + 1] / 10 != turn + 1)) return 1;
		//	if ((hod[1] - 1 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 1][hod[0] - 1] % 10 == 6) && (cell[hod[1] - 1][hod[0] - 1] / 10 != turn + 1)) return 1;
		//	if ((hod[0] - 1 >= 0) && (cell[hod[1]][hod[0] - 1] % 10 == 6) && (cell[hod[1]][hod[0] - 1] / 10 != turn + 1)) return 1;
		//}

		if (turn == 0)//peska
		{
			if ((hod[1] + 1 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 1][hod[0] + 1] % 10 == 1) && (cell[hod[1] + 1][hod[0] + 1] / 10 == 2))
			{
				attacker_kind = 1; attacker_pos[0] = hod[0] + 1; attacker_pos[1] = hod[1] + 1; return 1;
			}
			if ((hod[1] + 1 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 1][hod[0] - 1] % 10 == 1) && (cell[hod[1] + 1][hod[0] - 1] / 10 == 2))
			{
				attacker_kind = 1; attacker_pos[0] = hod[0] - 1; attacker_pos[1] = hod[1] + 1; return 1;
			}
		}
		else
		{
			if ((hod[1] - 1 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 1][hod[0] + 1] % 10 == 1) && (cell[hod[1] - 1][hod[0] + 1] / 10 == 1))
			{
				attacker_kind = 1; attacker_pos[0] = hod[0] + 1; attacker_pos[1] = hod[1] - 1; return 1;
			}
			if ((hod[1] - 1 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 1][hod[0] - 1] % 10 == 1) && (cell[hod[1] - 1][hod[0] - 1] / 10 == 1))
			{
				attacker_kind = 1; attacker_pos[0] = hod[0] - 1; attacker_pos[1] = hod[1] - 1; return 1;
			}
		}
		return 0;
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
		BitBlt(hdc, X_START, Y_START, WIDTH, HEIGHT, bmpDC, 0, 0, SRCCOPY);
		for (int i = 7; i >= 0; i--) {
			for (int j = 0; j < 8; j++) {
				figure = cell[i][j];
				x = j * SIZECELL;
				y = (i - 7) * (-1) * SIZECELL; // inversion - beginning at the bottom
				if (figure == 0) continue;
				else if (figure / 10 == 1) { // color (white)
					switch (figure % 10) // type of figure
					{
					case 1:
						if (white_or_black_background(i, j)) hBmp = (HBITMAP)LoadImage(NULL, WHITE_PAWN_WHITE, IMAGE_BITMAP, 35, 35, LR_LOADFROMFILE);
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
				BitBlt(hdc, X_START + 17 + x, Y_START + 17 + y, WIDTH, HEIGHT, bmpDC, 0, 0, SRCCOPY);
			}
		}
		DeleteObject(hBmp);
	}

	void translatePosition(string position, unsigned short* pos) // 99 - err
	{
		if (size(position) == 2 && (position.at(1) > '0' && position.at(1) <= '8') && ((position.at(0) >= 'A' && position.at(0) <= 'H') || (position.at(0) >= 'a' && position.at(0) <= 'h')))
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
		else
		{
			pos[0] = 9;
			pos[1] = 9;
		}
	}

	bool motionCheck(unsigned short i0[2]) // 1 - ход возможен, 0 - хода нет --- работа с cell_from
	{
		unsigned short color = cell[i0[1]][i0[0]] / 10;  // определение цвета игрока
		unsigned buff = cell[i0[1]][i0[0]];
		cell[i0[1]][i0[0]] = 0;
		int i = 0;
		int j = 0;
		int step_j = 2;
		int step_i = 2;
		/*unsigned short i0[2] = { 0 };
		translatePosition(position, i0);*/
		i0[1] == 0 ? i = i0[1] : i = i0[1] - 1; // прописанные исключения; буквы - j, цифры - i
		i0[0] == 0 ? j = i0[0] : j = i0[0] - 1;
		i0[0] == 7 ? step_j = 1 : step_j = 2;
		i0[1] == 7 ? step_i = 1 : step_i = 2;
		for (; i < i0[1] + step_i; i++)
		{
			for (; j < i0[0] + step_j; j++)
			{
				if (cell[i][j] == 0)
				{
					unsigned short t[2] = { j,i };
					if (check_cell(t, 1) == 0) { cell[i0[1]][i0[0]] = buff; return 1; }
				}
				else if (cell[i][j] / 10 != color)
				{
					unsigned short mas[2] = { j,i };
					if (!check_cell(mas, 1)) { cell[i0[1]][i0[0]] = buff; return 1; } //Вызывается проверка битой клетки, если клетка не бьется, то return 1;
				}
			}
			if (i0[0] == 0 || i0[0] == 7) j -= 2;
			else j -= 3;
		}
		cell[i0[1]][i0[0]] = buff;
		return 0;
	}


	bool game_end()//не запускаеться при k/2 <= 2, при 1 - окончание игры
	{
		unsigned short king[2];
		turn = not(turn);
		for (int i = 0, t = 0; i < 8 && t == 0; i++)//функция поиска позиции короля
			for (int j = 0; j < 8 && t == 0; j++)
			{
				if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 == 6))
				{
					king[0] = j;
					king[1] = i;
					t = 1;
				}
			}
		
		unsigned short attacker_kind, attacker_pos[2];
		if (check_cell(king, attacker_kind, attacker_pos) == 1)//шах
		{

			if (motionCheck(king) == 0)//хода нет
			{
				
				if ((abs(attacker_pos[1] - king[1]) <= 1) && (abs(attacker_pos[0] - king[0]) <= 1) && (check_cell(attacker_pos, 1) == 0))//king
				{
					turn = not(turn);
					return 0;
				}
				if (attacker_kind <= 2)//pawn and horse
				{
					turn = not(turn);
					if (check_cell(attacker_pos, 0) == 1) { turn = not(turn); cell[attacker_pos[1]][attacker_pos[0]] = (turn + 1) * 10 + 2; }
					else { victory(); return 1; }

					if (check_cell(king, 0) == 1) { turn = not(turn); victory(); return 1; }
					else
					{
						turn = not(turn);
						if (turn == 1) cell[attacker_pos[1]][attacker_pos[0]] = 20 + attacker_kind;
						else  cell[attacker_pos[1]][attacker_pos[0]] = 10 + attacker_kind;
					}
				}
				else//bishop, rook, queen
				{
					turn = not(turn);
					unsigned short buff = 99;
					if (king[0] == attacker_pos[0])//n,s
					{
						if (king[1] < attacker_pos[1])//n
						{
							for (unsigned short pos[2] = { king[0],king[1] + 2 }; pos[1] <= attacker_pos[1]; pos[1]++)//n
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[1] = pos[1]; break; }
						}
						else//s
							for (unsigned short pos[2] = { king[0],king[1] - 2 }; pos[1] >= attacker_pos[1]; pos[1]--)//s
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]];  turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2;  attacker_pos[1] = pos[1]; break; }
					}
					else if (king[1] == attacker_pos[1])//e,w
					{
						if (king[0] < attacker_pos[0])//e
						{
							for (unsigned short pos[2] = { king[0] + 2,king[1] }; pos[0] <= attacker_pos[0]; pos[0]++)//e
								if (check_cell(pos, 0) == 1) { /*cout << "*";*/ buff = cell[pos[1]][pos[0]];  turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[0] = pos[0]; break; }
						}
						else
							for (unsigned short pos[2] = { king[0] - 2,king[1] }; pos[0] >= attacker_pos[0]; pos[0]--)//w
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]];  turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[0] = pos[0]; break; }
					}
					else
					{

						if ((king[0] < attacker_pos[0]) && (king[1] < attacker_pos[1]))
							for (unsigned short pos[2] = { king[0] + 2,king[1] + 2 }; pos[0] <= attacker_pos[0] && pos[1] <= attacker_pos[1]; pos[0]++, pos[1]++)//n-e
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]];  turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
						if ((king[0] > attacker_pos[0]) && (king[1] > attacker_pos[1]))
							for (unsigned short pos[2] = { king[0] - 2,king[1] - 2 }; pos[0] >= attacker_pos[0] && pos[1] >= attacker_pos[1]; pos[0]--, pos[1]--)//s-w
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
						if ((king[0] > attacker_pos[0]) && (king[1] < attacker_pos[1]))
							for (unsigned short pos[2] = { king[0] + 2,king[1] - 2 }; pos[0] <= attacker_pos[0] && pos[1] >= attacker_pos[1]; pos[0]++, pos[1]--)//s-e
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]];  turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
						if ((king[0] < attacker_pos[0]) && (king[1] > attacker_pos[1]))
							for (unsigned short pos[2] = { king[0] - 2,king[1] + 2 }; pos[0] >= attacker_pos[0] && pos[1] <= attacker_pos[1]; pos[0]--, pos[1]++)//n-w
								if (check_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]];  turn = not(turn); cell[pos[1]][pos[0]] = (turn + 1) * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
					}

					if (buff == 99) turn = not(turn);
					if (check_cell(king, 0) == 1) { turn = not(turn); victory(); return 1; }
					else { cell[attacker_pos[1]][attacker_pos[0]] = buff; return 0; }
				}
				return 0;
			}
			else { turn = not(turn); return 0; }
		}
		else if (k / 2 > 30)
		{
			if (motionCheck(king) == 0)
			{
				for (int i = 0; i < 8; i++)
					for (int j = 0; j < 8; j++)
					{
						if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 != 1) && (cell[i][j] % 10 != 6)) { turn = not(turn); return 0; }//по статистике смотрим только пешки
						else if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 == 1)) /*функция возможности маневра пешкой - возможно*/
						{
							if (turn == 0)
							{
								if (cell[i + 1][j] == 0)
								{
									cell_from = i * 10 + j; cell_to = (i + 1) * 10 + j;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
								else if ((i == 1) && (cell[i + 2][j] == 0) && (cell[i + 1][j] == 0))
								{
									cell_from = i * 10 + j; cell_to = (i + 2) * 10 + j;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
								else if ((j > 0) && (cell[i + 1][j - 1] / 10 != turn + 1) && (cell[i + 1][j - 1] / 10 != 0))
								{
									cell_from = i * 10 + j; cell_to = (i + 1) * 10 + j - 1;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
								else if ((j < 7) && (cell[i + 1][j + 1] / 10 != turn + 1) && (cell[i + 1][j + 1] / 10 != 0))
								{
									cell_from = i * 10 + j; cell_to = (i + 1) * 10 + j + 1;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
							}
							else
							{
								if (cell[i - 1][j] == 0)
								{
									cell_from = i * 10 + j; cell_to = (i - 1) * 10 + j;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
								else if ((i == 6) && (cell[i - 2][j] == 0) && (cell[i - 1][j] == 0))
									cell_from = i * 10 + j; cell_to = (i - 2) * 10 + j;
								if (last_check(1) == 0)
								{
									turn = not(turn); return 0;
								}
								else if ((j > 0) && (cell[i - 1][j - 1] / 10 != turn + 1) && (cell[i - 1][j - 1] / 10 != 0))
								{
									cell_from = i * 10 + j; cell_to = (i - 1) * 10 + j - 1;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
								else if ((j < 7) && (cell[i - 1][j + 1] / 10 != turn + 1) && (cell[i - 1][j + 1] / 10 != 0))
								{
									cell_from = i * 10 + j; cell_to = (i - 1) * 10 + j + 1;
									if (last_check(1) == 0)
									{
										turn = not(turn); return 0;
									}
								}
							}
						}
					}
				cout << "Drrrraw!!!\n";
				return 1;
			}
			turn = not(turn);
			return 0;
		}
		else { turn = not(turn); return 0; }
	}


public:

	bool last_check(bool pawn)//return 1 esli king pod ydarom; if pawn == 1 do not apply changes
	{
		unsigned short buff = cell[cell_to / 10][cell_to % 10];
		cell[cell_to / 10][cell_to % 10] = cell[cell_from / 10][cell_from % 10];
		cell[cell_from / 10][cell_from % 10] = 0;

		unsigned short king[2];
		for (int i = 0, t = 0; i < 8 && t == 0; i++)//функция поиска позиции короля
			for (int j = 0; j < 8 && t == 0; j++)
			{
				if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 == 6))
				{
					king[0] = j;
					king[1] = i;
					t = 1;
				}
			}
		/*cout << "*";*/
		if (check_cell(king, 0) == 1)
		{
			/*cout << "!";*/
			cell[cell_from / 10][cell_from % 10] = cell[cell_to / 10][cell_to % 10];
			cell[cell_to / 10][cell_to % 10] = buff;

			return 1;
		}
		else
		{
			if (pawn) {
				cell[cell_from / 10][cell_from % 10] = cell[cell_to / 10][cell_to % 10];
				cell[cell_to / 10][cell_to % 10] = buff;
			}
			return 0;
		}
	}

	void start_cell()
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
		show();
	}


	bool game_turn()
	{
		system("cls");
		show();
		if (k / 2 >= 2 && game_end()) return 0;
		turn = !turn;
		k++;
		return 1;
	}

	unsigned short get_figure()
	{
		return (cell[cell_from / 10][cell_from % 10] % 10);
	}

	unsigned short check() // 9 - err; если cell_to = 0, то это позиция [0],[0], если cell_to = 1, то это позиция [0],[1]
	{
		unsigned short i1[2];
		unsigned short i2[2];
		string from, to;
		cout << "Select the cell from which you will move: ";
		cin >> from;
		if (from == "Draw" || from == "draw") { Draw(); return 8; }
		else if (from == "Pass" || from == "pass") { Pass(); return 8; }
		cout << "Select the cell which you will move to: ";
		cin >> to;
		translatePosition(from, i1);
		translatePosition(to, i2);
		cell_from = i1[1] * 10 + i1[0];
		cell_to = i2[1] * 10 + i2[0];

		if (cell_from == 99 || cell_to == 99) return 9; // клетки нет
		else if (cell[i1[1]][i1[0]] == 0) return 9;  // выбранная клетка от куда ходиться -  пуста
		else if ((turn == 0 && cell[i1[1]][i1[0]] / 10 != 1) || (turn == 1 && cell[i1[1]][i1[0]] / 10 != 2)) return 9; // чужая фигура
		else
		{
			if ((turn == 0 && cell[i2[1]][i2[0]] / 10 == 1) || (turn == 1 && cell[i2[1]][i2[0]] / 10 == 2)) return 9;
			return (cell_to);
		}
	}

	unsigned short condition_cell(unsigned short cell1) { return cell[cell1 / 10][cell1 % 10]; } // Возвращает значение клетки доски

	void get_cell(unsigned short* mas)
	{
		mas[0] = cell_from;
		mas[1] = cell_to;
	}

	void set_cell_from(unsigned short condition) { cell[cell_from / 10][cell_from % 10] = condition; }

	void castling(bool r)//r-e, ne(r) - w
	{
		if (r)
		{
			if (turn == 0) { cell[0][7] = 0; cell[0][5] = 14; }
			else { cell[7][7] = 0; cell[7][5] = 24; }
		}
		else
		{
			if (turn == 0) { cell[0][0] = 0; cell[0][3] = 14; }
			else { cell[7][0] = 0; cell[7][3] = 24; }
		}
	}

	class Figure
	{
	public:
		virtual bool check_figure(Chess& chess) { return 1; }
	};
};

class Pawn : public Chess::Figure
{
private:
	bool transform(Chess& chess)
	{
		if (!chess.last_check(1)) {
			cin.get();
			unsigned short choice = 5;
			cout << "\nChoice figure to transform the pawn:\n1 - Horse; \t2 - Bishop;\n3 - Rook;\t4 - Queen;\nYour choice: ";
			while (choice > 4 || choice < 1)
			{
				cin >> choice;
			}
			chess.set_cell_from((turn + 1) * 10 + choice + 1);
			return 1;
		}
		else return 0;
	}
public:
	bool check_figure(Chess& chess) override// 0 - err, 1 - all is good
	{
		unsigned short mas[2] = { 0 };
		chess.get_cell(mas);
		//cout << mas[0] <<"\n"<< mas[1];
		unsigned short condition_cell_to = chess.condition_cell(mas[1]);
		if (turn == 0)
		{
			if (mas[1] / 10 == 7 && ((mas[1] / 10 - mas[0] / 10) == 1) && (mas[1] % 10 == mas[0] % 10) && (condition_cell_to == 0))
			{
				if (transform(chess)) return 1;
			}
			else if (mas[1] / 10 == 7 && ((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1) && (condition_cell_to != 0))
			{
				if (transform(chess)) return 1;
			}
			else if (mas[1] / 10 == 7 && ((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1) && (condition_cell_to != 0))
			{
				if (transform(chess)) return 1;
			}
			else if (((mas[1] / 10 - mas[0] / 10) == 1) && (mas[1] % 10 == mas[0] % 10) && (condition_cell_to == 0)) return 1;
			else if (((mas[0] / 10) == 1) && ((mas[1] / 10 - mas[0] / 10) == 2) && (mas[1] % 10 == mas[0] % 10) && (condition_cell_to == 0)) return 1;
			else if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1) && (condition_cell_to != 0)) return 1;
			else if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1) && (condition_cell_to != 0)) return 1;
		}
		else
		{
			if (mas[1] / 10 == 0 && ((mas[0] / 10 - mas[1] / 10) == 1) && (mas[1] % 10 == mas[0] % 10) && (condition_cell_to == 0))
			{
				if (transform(chess)) return 1;
			}
			else if (mas[1] / 10 == 0 && ((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1) && (condition_cell_to != 0))
			{
				if (transform(chess)) return 1;
			}
			else if (mas[1] / 10 == 0 && ((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1) && (condition_cell_to != 0))
			{
				if (transform(chess)) return 1;
			}
			else if (((mas[0] / 10 - mas[1] / 10) == 1) && (mas[1] % 10 == mas[0] % 10) && (condition_cell_to == 0)) return 1;
			else if (((mas[0] / 10) == 6) && ((mas[0] / 10 - mas[1] / 10) == 2) && (mas[1] % 10 == mas[0] % 10) && (condition_cell_to == 0)) return 1;
			else if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1) && (condition_cell_to != 0)) return 1;
			else if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1) && (condition_cell_to != 0)) return 1;
		}
		return 0;
	}
};

class Horse : public Chess::Figure
{
public:
	bool check_figure(Chess& chess) override
	{
		unsigned short mas[2] = { 0 };
		chess.get_cell(mas);
		if (((mas[1] / 10 - mas[0] / 10) == 2) && ((mas[1] % 10 - mas[0] % 10) == 1)) return 1;
		if (((mas[1] / 10 - mas[0] / 10) == 2) && ((mas[0] % 10 - mas[1] % 10) == 1)) return 1;
		if (((mas[0] / 10 - mas[1] / 10) == 2) && ((mas[0] % 10 - mas[1] % 10) == 1)) return 1;
		if (((mas[0] / 10 - mas[1] / 10) == 2) && ((mas[1] % 10 - mas[0] % 10) == 1)) return 1;
		if (((mas[1] % 10 - mas[0] % 10) == 2) && ((mas[1] / 10 - mas[0] / 10) == 1)) return 1;
		if (((mas[1] % 10 - mas[0] % 10) == 2) && ((mas[0] / 10 - mas[1] / 10) == 1)) return 1;
		if (((mas[0] % 10 - mas[1] % 10) == 2) && ((mas[0] / 10 - mas[1] / 10) == 1)) return 1;
		if (((mas[0] % 10 - mas[1] % 10) == 2) && ((mas[1] / 10 - mas[0] / 10) == 1)) return 1;
		return 0;
	}
};

class Bishop : public Chess::Figure
{
public:
	bool check_figure(Chess& chess) override
	{
		unsigned short check_bishop;
		unsigned short mas[2] = { 0 };
		chess.get_cell(mas);
		if ((mas[1] / 10 - mas[0] / 10) > 0 && (mas[1] / 10 - mas[0] / 10) == (mas[1] % 10 - mas[0] % 10)) check_bishop = 1; //n-e from +=11
		else if ((mas[1] / 10 - mas[0] / 10) > 0 && (mas[1] / 10 - mas[0] / 10) == (mas[0] % 10 - mas[1] % 10)) check_bishop = 2; //n-w from +=9
		else if ((mas[0] / 10 - mas[1] / 10) > 0 && (mas[0] / 10 - mas[1] / 10) == (mas[1] % 10 - mas[0] % 10)) check_bishop = 3; // s-e from -=9
		else if ((mas[0] / 10 - mas[1] / 10) > 0 && (mas[0] / 10 - mas[1] / 10) == (mas[0] % 10 - mas[1] % 10)) check_bishop = 4; // s-w from -=11
		else return 0;
		unsigned short  j;
		j = mas[0];
		if (check_bishop != 0)
		{
			while (mas[1] != j)
			{
				switch (check_bishop) {
				case 1: j += 11;
					break;
				case 2: j += 9;
					break;
				case 3: j -= 9;
					break;
				case 4:j -= 11;
					break;
				}
				if (j != mas[1] && chess.condition_cell(j) != 0)
				{
					return 0;
				}
			}
			if (mas[1] == j && chess.condition_cell(mas[1]) / 10 != turn + 1) return 1;
		}
		else return 0;
	}
};

class Rook : public Chess::Figure
{
public:
	bool check_figure(Chess& chess) override
	{
		unsigned short mas[2] = { 0 };
		chess.get_cell(mas);
		if (mas[0] % 10 == mas[1] % 10)//n,s
		{
			unsigned short word = mas[0] % 10;
			/*if (mas[0] / 10 == mas[1] / 10) return 0;
			else*/ if (mas[0] / 10 < mas[1] / 10) for (int i = mas[0] / 10 + 1; i < mas[1] / 10; i++) if (chess.condition_cell(i * 10 + word) / 10 != 0) return 0;
			else for (int i = mas[0] / 10 - 1; i > mas[1] / 10; i--) if (chess.condition_cell(i * 10 + word) / 10 != 0) return 0;
		}
		else if (mas[0] / 10 == mas[1] / 10)//e,w
		{
			unsigned short number = mas[0] / 10;
			/*if (mas[0] % 10 == mas[1] % 10) return 0;
			else*/ if (mas[0] % 10 < mas[1] % 10) for (int i = mas[0] % 10 + 1; i < mas[1] % 10; i++) if (chess.condition_cell(number * 10 + i) / 10 != 0) return 0;
			else for (int i = mas[0] % 10 - 1; i > mas[1] % 10; i--) if (chess.condition_cell(number * 10 + i) / 10 != 0) return 0;
		}
		else return 0;
		return 1;
	}
};

class Queen : public Chess::Figure
{
public:
	bool check_figure(Chess& chess) override
	{
		unsigned short mas[2] = { 0 };
		chess.get_cell(mas);
		if (mas[0] % 10 == mas[1] % 10)//n,s
		{
			unsigned short word = mas[0] % 10;
			if (mas[0] / 10 == mas[1] / 10) return 0;
			else if (mas[0] / 10 < mas[1] / 10) for (int i = mas[0] / 10 + 1; i < mas[1] / 10; i++) if (chess.condition_cell(i * 10 + word) / 10 != 0) return 0;
			else for (int i = mas[0] / 10 - 1; i > mas[1] / 10; i--) if (chess.condition_cell(i * 10 + word) / 10 != 0) return 0;
		}
		else if (mas[0] / 10 == mas[1] / 10)//e,w
		{
			unsigned short number = mas[0] / 10;
			if (mas[0] % 10 < mas[1] % 10) for (int i = mas[0] % 10 + 1; i < mas[1] % 10; i++) if (chess.condition_cell(number * 10 + i) / 10 != 0) return 0;
			else for (int i = mas[0] % 10 - 1; i > mas[1] % 10; i--) if (chess.condition_cell(number * 10 + i) / 10 != 0) return 0;
		}
		else if (abs(mas[0] % 10 - mas[1] % 10) == abs(mas[0] / 10 - mas[1] / 10))//raznosti kletok po bykvam i chislam
		{
			unsigned short pos_to[2] = { mas[1] / 10, mas[1] % 10 };//pos_to[0]-chifra  pos_to[1]-bykva
			if ((mas[0] / 10 < pos_to[0]) && (mas[0] % 10 < pos_to[1]))
				for (unsigned short pos[2] = { mas[0] / 10 + 1,mas[0] % 10 + 1 }; pos[0] < pos_to[0] && pos[1] < pos_to[1]; pos[0]++, pos[1]++)//n-e
					if (chess.condition_cell(pos[0] * 10 + pos[1]) / 10 != 0) return 0;
			if ((mas[0] / 10 > pos_to[0]) && (mas[0] % 10 > pos_to[1]))
				for (unsigned short pos[2] = { mas[0] / 10 - 1,mas[0] % 10 - 1 }; pos[0] > pos_to[0] && pos[1] > pos_to[1]; pos[0]--, pos[1]--)//s-w
					if (chess.condition_cell(pos[0] * 10 + pos[1]) / 10 != 0) return 0;
			if ((mas[0] % 10 < pos_to[1]) && (mas[0] / 10 > pos_to[0]))
				for (unsigned short pos[2] = { mas[0] / 10 - 1,mas[0] % 10 + 1 }; pos[0] > pos_to[0] && pos[1] < pos_to[1]; pos[0]--, pos[1]++)//s-e
					if (chess.condition_cell(pos[0] * 10 + pos[1]) / 10 != 0) return 0;
			if ((mas[0] % 10 > pos_to[1]) && (mas[0] / 10 < pos_to[0]))
				for (unsigned short pos[2] = { mas[0] / 10 + 1,mas[0] % 10 - 1 }; pos[0] < pos_to[0] && pos[1] > pos_to[1]; pos[0]++, pos[1]--)//n-w
					if (chess.condition_cell(pos[0] * 10 + pos[1]) / 10 != 0) return 0;
		}
		else return 0;
		return 1;
	}
};

class King : public Chess::Figure
{
private:
	static int king_move[2];//0 - white

public:
	void set_king_move()
	{
		king_move[0] = 0; king_move[1] = 0;
	}
	bool check_figure(Chess& chess) override
	{


		unsigned short mas[2] = { 0 };
		chess.get_cell(mas);
		if ((mas[1] / 10 - mas[0] / 10) == 1 && (mas[0] % 10 == mas[1] % 10)) { king_move[turn]++; return 1; }
		if ((mas[0] / 10 - mas[1] / 10) == 1 && (mas[0] % 10 == mas[1] % 10)) { king_move[turn]++; return 1; }
		if ((mas[0] % 10 - mas[1] % 10) == 1 && (mas[0] / 10 == mas[1] / 10)) { king_move[turn]++; return 1; }
		if ((mas[1] % 10 - mas[0] % 10) == 1 && (mas[0] / 10 == mas[1] / 10)) { king_move[turn]++; return 1; }
		if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1)) { king_move[turn]++; return 1; }
		if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1)) { king_move[turn]++; return 1; }
		if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1)) { king_move[turn]++; return 1; }
		if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1)) { king_move[turn]++; return 1; }

		unsigned short check_pos[] = { mas[0] % 10, mas[0] / 10 };//castling
		if (turn == 0)
		{
			if ((king_move[0] == 0) && (mas[0] / 10 == 0) && (mas[0] % 10 == 4) && (chess.check_cell(check_pos, 0) == 0))
			{
				if ((mas[1] / 10 == 0) && (mas[1] % 10 == 6) && (chess.condition_cell(7) == 14))
				{
					for (check_pos[0] = 5; check_pos[0] < 7; check_pos[0]++)
					{
						if ((chess.condition_cell(check_pos[0] + check_pos[1] * 10) != 0) || (chess.check_cell(check_pos, 1) == 1)) break;
						if (check_pos[0] == 6) { chess.castling(1); king_move[0]++; return 1; }
					}
				}
				else if ((mas[1] / 10 == 0) && (mas[1] % 10 == 2) && (chess.condition_cell(0) == 14))
				{
					for (check_pos[0] = 3; check_pos[0] > 0; check_pos[0]--)
					{
						if ((chess.condition_cell(check_pos[0] + check_pos[1] * 10) != 0) || ((check_pos[0] != 1) && (chess.check_cell(check_pos, 1) == 1))) break;
						if (check_pos[0] == 1) { chess.castling(0); king_move[0]++; return 1; }
					}
				}
			}
		}
		else
		{
			if ((king_move[1] == 0) && (mas[0] / 10 == 7) && (mas[0] % 10 == 4) && (chess.check_cell(check_pos, 0) == 0))
			{
				if ((mas[1] / 10 == 7) && (mas[1] % 10 == 6) && (chess.condition_cell(77) == 24))
				{
					for (check_pos[0] = 5; check_pos[0] < 7; check_pos[0]++)
					{
						if ((chess.condition_cell(check_pos[0] + check_pos[1] * 10) != 0) || (chess.check_cell(check_pos, 1) == 1)) break;
						if (check_pos[0] == 6) { chess.castling(1); king_move[1]++; return 1; }
					}
				}
				else if ((mas[1] / 10 == 7) && (mas[1] % 10 == 2) && (chess.condition_cell(70) == 24))
				{
					for (check_pos[0] = 3; check_pos[0] > 0; check_pos[0]--)
					{
						if ((chess.condition_cell(check_pos[0] + check_pos[1] * 10) != 0) || ((check_pos[0] != 1) && (chess.check_cell(check_pos, 1) == 1))) break;
						if (check_pos[0] == 1) { chess.castling(0); king_move[1]++; return 1; }
					}
				}
			}
		}
		return 0;
	}
};
int King::king_move[2] = { 0 };

//class menu
class Menu {
private:
	int user_choice = 0;

	void gen_color()
	{
		srand(time(0));
		if (rand() % 2 == 1) swap(white, black);
	}


	void choice_player()
	{
		string choose, choose_c1, choose_c2;
		cout << "-------Welcome chess fans!-------\n";
		cout << "What is your name, Player 1 ?\n";
		cin >> white;
		cout << "And your, Player 2 ?\n";
		cin >> black;
		while (true)
		{
			system("cls");
			cout << "Do you want to choose a color?(Yes/No)\n";
			cin >> choose;
			if ((choose[0] == 'y') || (choose[0] == 'Y'))
			{
				cout << "What color does " << white << " choose?(White/Black)\n";
				cin >> choose_c1;
				if ((choose_c1[0] == 'B') || (choose_c1[0] == 'b')) swap(white, black);
				else if ((choose_c1[0] != 'w') && (choose_c1[0] != 'W'))
				{
					cout << "And what does " << black << " think?(White/Black)\n";
					cin >> choose_c2;
					if ((choose_c2[0] == 'w') || (choose_c2[0] == 'W')) swap(white, black);
					else if ((choose_c2[0] != 'B') && (choose_c2[0] != 'b'))
					{
						cout << "Ok, I get it\n";
						gen_color();
					}
				}
				break;
			}
			else if ((choose[0] == 'N') || (choose[0] == 'n'))
			{
				gen_color();
				break;
			}
			else
			{
				cout << "Error";
				Sleep(500);
			}
		}
		cout << white << " playes with white pieces\n";
		cout << black << " playes with black pieces\n";
		getchar(); getchar(); system("cls");
	}

	void menu_window() {
		system("cls");
		std::cout << "\tHello, stranger." << std::endl;
		std::cout << "1. New game" << std::endl;
		std::cout << "2. Reference" << std::endl;
		std::cout << "3. Exit" << std::endl;
		std::cout << "Your choise: ";
	}


public:
	void New_game()
	{
		system("cls");
		Chess chess;
		Chess::Figure* figure = nullptr;
		unsigned short f = 0;
		bool flag = 0;
		turn = 0;
		k = 0;
		bool check = 0, king_cond = 0;
		choice_player();
		chess.start_cell();
		do {
			if (flag && f != 8) cout << "Err. Try again\n";
			if ((f = chess.check()) == 9) flag = 1;
			else {
				if (k == 666) break;
				if (f != 8)
				{
					switch (chess.get_figure())
					{
					case 1: figure = new Pawn;
						break;
					case 2: figure = new Horse;
						break;
					case 3: figure = new Bishop;
						break;
					case 4: figure = new Rook;
						break;
					case 5: figure = new Queen;
						break;
					case 6: if (king_cond == 0) { King a; a.set_king_move(); king_cond = 1; } figure = new King;
					}
					check = figure->check_figure(chess);
					if (check == 0)	flag = 1;
					else {
						if (chess.last_check(0)) flag = 1;
						else flag = 0;
					}
				}
				else flag = 1;
			}
		} while (flag || chess.game_turn());
		cin.get();
		cin.get();
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
	void Err_choice() {
		system("cls");
		std::cout << "It's wrong!" << std::endl;
		Sleep(500);
	}

	int set_choice() {
		menu_window();
		std::cin >> user_choice;
		if (std::cin.fail()) { // check error flags
			std::cin.clear(); // clears error flags
			std::cin.ignore(2323, '\n'); // ~ while(cin.get() != '\n');
		}
		return user_choice;
	}

	~Menu()
	{
		DeleteObject(bmpDC);
		DeleteObject(hdc);
	}
};





int main()
{
	Menu game_menu;
	switch (game_menu.set_choice()) {
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
		game_menu.Err_choice();
		main();
	}
}