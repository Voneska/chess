#include <iostream>
#include <Windows.h>
#include <string>
#include "pictures_of_figures.h"

using namespace std;

bool turn;
int k = 0;

class Chess
{
private:
	unsigned short cell[8][8], cell_from, cell_to;


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

	bool game_end()
	{
		return 1;
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
				else if (cell[i][j] / 10 != color) // можно ли съесть
				{
					//if(!proverka_bit_kletki()) return 1; Вызывается проверка битой клетки, если клетка не бьется, то return 1;
				}
			}
			if (i0[0] == 0 || i0[0] == 7) j -= 2;
			else j -= 3;
		}
		return 0;
	}

public:
	Chess()
	{
		cell_from = 0;
		cell_to = 0;
		for (int i = 0; i < 8; ++i) for (int j = 0; j < 8; ++j) cell[i][j] = 0;
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
		cell[cell_to / 10][cell_to % 10] = cell[cell_from / 10][cell_from % 10];
		cell[cell_from / 10][cell_from % 10] = 0;
		system("cls");
		show();
		if (k/2 < 2 && !game_end()) return 0;

		turn = !turn;
		k++;
		return 1;
	}

	unsigned short get_figure()
	{
		return (cell[cell_from/10][cell_from%10]%10);
	}

	unsigned short check() // 9 - err; если cell_to = 0, то это позиция [0],[0], если cell_to = 1, то это позиция [0],[1]
	{
		unsigned short i1[2];
		unsigned short i2[2];
		string from, to;
		cout << "Select the cell from which you will move: ";
		cin >> from;
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

	unsigned short condition_cell_to() { return cell[cell_to / 10][cell_to % 10]; }
	unsigned short condition_cell(int i, int j) { return cell[i][j]; }

	unsigned short* get_cell()
	{
		unsigned short mas[2] = { cell_from, cell_to };
		return (mas);
	}
	
	class Figure
	{
	public:
		bool check_pawn(unsigned short* mas, unsigned short condition_cell_to) // 0 - err, 1 - all is good
		{
			if (turn == 0)
			{
				if ((mas[1] / 10 - mas[0] / 10) == 1 && (condition_cell_to == 0)) return 1;
				else if (((mas[0] / 10) == 1) && ((mas[1] / 10 - mas[0] / 10) == 2) && (condition_cell_to == 0)) return 1;
				else if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1) && (condition_cell_to != 0)) return 1; 
				else if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1) && (condition_cell_to != 0)) return 1; 
			}
			else
			{
				if ((mas[0] / 10 - mas[1] / 10) == 1 && (condition_cell_to == 0)) return 1;
				else if (((mas[0] / 10) == 6) && ((mas[0] / 10 - mas[1] / 10) == 2) && (condition_cell_to == 0)) return 1;
				else if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10) == 1) && (condition_cell_to != 0)) return 1; 
				else if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10) == 1) && (condition_cell_to != 0)) return 1; 
			}
			return 0;
		}

		bool check_horse(unsigned short* mas)
		{
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

		bool check_bishop(unsigned short* mas)
		{
			return 1;
		}

		bool check_rook(unsigned short* mas)
		{
			return 1;
		}

		bool check_queen(unsigned short* mas)
		{
			return 1;
		}

		bool check_king(unsigned short* mas)
		{
			if ((mas[1] / 10 - mas[0] / 10) == 1) return 1;
			if ((mas[0] / 10 - mas[1] / 10) == 1) return 1;
			if ((mas[0] % 10 - mas[1] % 10) == 1) return 1;
			if ((mas[1] % 10 - mas[0] % 10) == 1) return 1;
			if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10))) return 1;
			if (((mas[1] / 10 - mas[0] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10))) return 1;
			if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[1] % 10 - mas[0] % 10))) return 1;
			if (((mas[0] / 10 - mas[1] / 10) == 1) && ((mas[0] % 10 - mas[1] % 10))) return 1;
			return 0;
		}
	};

	~Chess()
	{
		// освобождение ресурсов:
		DeleteDC(bmpDC);
	}
};


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
	void New_game() 
	{
		system("cls");
		Chess chess;
		Chess::Figure figure;
		bool flag = 0;
		turn = 0;
		k = 0;
		bool check = 0;
		chess.start_cell();
		do {
			if (flag) cout << "Err. Try again\n";
			if (chess.check() == 9) flag = 1;
			else {
				
				switch (chess.get_figure())
				{
				case 1: check = figure.check_pawn(chess.get_cell(), chess.condition_cell_to());
					break;
				case 2: check = figure.check_horse(chess.get_cell());
					break;
				case 3: check = figure.check_bishop(chess.get_cell());
					break;
				case 4: check = figure.check_rook(chess.get_cell());
					break;
				case 5: check = figure.check_queen(chess.get_cell());
					break;
				case 6: check = figure.check_king(chess.get_cell());;
					break;
				}
				if (check == 0)	flag = 1;
				else flag = 0;
			}
		} while (flag || chess.game_turn());

		//std::cout << "New game has been starting!" << std::endl;
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
}

