#include <iostream>
#include<ctime>
#include<Windows.h>
using namespace std;
string white, black;
unsigned short cell[8][8]; 
unsigned short cell_from, cell_to;//возможно, массивы
int k = 0;//счетчик полуходов
bool turn = 0;//xod belix


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

void victory()
{
	if (turn == 0)
		cout << "Checkmate to the black King\n" << white << " wooooooon!!!\n";
	else if (turn == 1) cout << "Checkmate to the white King\n" << black << " wooooooon!!!\n";
}

bool chek_cell(unsigned short hod[2], bool king/*учет удара короля*/)//vozvrashaet 0 v slychae esli cletca ne bietsa
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
			if (((cell[i][j] % 10) == 3) || ((cell[hod[i]][j] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] - 1, j = hod[0] - 1; j >= 0 && i >= 0; j--, i--)//s-w
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[i]][j] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] - 1, j = hod[0] + 1; j < 8 && i >= 0; j++, i--)//s-e
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[i]][j] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] + 1, j = hod[0] - 1; j >= 0 && i < 8; j--, i++)//n-w
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[i]][j] % 10) == 5)) return 1;
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

bool chek_cell(unsigned short hod[2]/*, bool king/*учет удара короля*/, unsigned short& attacker_kind, unsigned short* attacker_pos)//vozvrashaet 0 v slychae esli cletca ne bietsa
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

bool motionCheck(unsigned short i0[2]) // 1 - ход возможен, 0 - хода нет --- работа с cell_from
{
	int i = 0;
	int j = 0;
	int step_j = 2;
	int step_i = 2;
	/*unsigned short i0[2] = { 0 };
	translatePosition(position, i0);*/
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
				cout << "-";
				unsigned short mas[2] = { i, j };//?
				if (!/*?*/chek_cell(mas, 1)) return 1; //Вызывается проверка битой клетки, если клетка не бьется, то return 1;
			}
		}
		if (i0[0] == 0 || i0[0] == 7) j -= 2;
		else j -= 3;
	}
	return 0;
}

bool game_end()//не запускаеться при k/2 <= 2, при 1 - окончание игры
{
	unsigned short king[2];
	turn = not(turn);
	for (int i = 0, t = 0; i < 8 && t == 0; i++)//функция поиска позиции короля
		for (int j = 0; j < 8 && t==0; j++)
		{
			if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 == 6))
			{
				king[0] = j;
				king[1] = i;
				t = 1;
			}
		}
	cout << king[0] << " " << king[1] << "\n";
	unsigned short attacker_kind, attacker_pos[2];
	if (chek_cell(king, attacker_kind, attacker_pos) == 1)//шах
	{
		cout << "*";
		if (motionCheck(king) == 0)//хода нет
		{
			cout << "*";
			if ((abs(attacker_pos[1] - king[1]) <= 1) && (abs(attacker_pos[0] - king[0]) <= 1) && (chek_cell(attacker_pos, 1) == 0))//king
			{
				turn = not(turn);
				return 0;
			}
			if (attacker_kind <= 2)//pawn and horse
			{
				turn = not(turn);
				if (chek_cell(attacker_pos, 0) == 1) { turn = not(turn); cell[attacker_pos[1]][attacker_pos[0]] = (turn + 1) * 10 + 2; }
				else { victory(); return 1; }
				turn = not(turn);
				if (chek_cell(king, 0) == 1) { victory(); return 1; }
				else
				{
					if (turn == 1) cell[attacker_pos[1]][attacker_pos[0]] = 20 + attacker_kind;
					else  cell[attacker_pos[1]][attacker_pos[0]] = 10 + attacker_kind;
				}
			}
			else//bishop, rook, queen
			{
				unsigned short buff;
				if (king[0] == attacker_pos[0])
				{
					if (king[1] < attacker_pos[1])
					{
						for (unsigned short pos[2] = { king[0],king[1] + 2 }; pos[1] <= attacker_pos[1]; pos[1]++)//n
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
					}
					else
						for (unsigned short pos[2] = { king[0],king[1] - 2 }; pos[1] >= attacker_pos[1]; pos[1]--)//s
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
				}
				else if (king[1] == attacker_pos[1])
				{
					if (king[0] < attacker_pos[0])
					{
						for (unsigned short pos[2] = { king[0] + 2,king[1] }; pos[0] <= attacker_pos[0]; pos[0]++)//e
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
					}
					else
						for (unsigned short pos[2] = { king[0] - 2,king[1] }; pos[0] >= attacker_pos[0]; pos[0]--)//w
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
				}
				else
				{
					if ((king[0] < attacker_pos[0]) && (king[1] < attacker_pos[1]))
						for (unsigned short pos[2] = { king[0] + 2,king[1] + 2 }; pos[0] <= attacker_pos[0] && pos[1] <= attacker_pos[1]; pos[0]++, pos[1]++)//n-e
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
					if ((king[0] > attacker_pos[0]) && (king[1] > attacker_pos[1]))
						for (unsigned short pos[2] = { king[0] - 2,king[1] - 2 }; pos[0] >= attacker_pos[0] && pos[1] >= attacker_pos[1]; pos[0]--, pos[1]--)//s-w
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
					if ((king[0] < attacker_pos[0]) && (king[1] > attacker_pos[1]))
						for (unsigned short pos[2] = { king[0] + 2,king[1] - 2 }; pos[0] <= attacker_pos[0] && pos[1] >= attacker_pos[1]; pos[0]++, pos[1]--)//s-e
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
					if ((king[0] > attacker_pos[0]) && (king[1] < attacker_pos[1]))
						for (unsigned short pos[2] = { king[0] - 2,king[1] + 2 }; pos[0] >= attacker_pos[0] && pos[1] <= attacker_pos[1]; pos[0]--, pos[1]++)//n-w
							if (chek_cell(pos, 0) == 1) { buff = cell[pos[1]][pos[0]]; cell[pos[1]][pos[0]] = turn * 10 + 2; attacker_pos[0] = pos[0]; attacker_pos[1] = pos[1]; break; }
				}
				if (chek_cell(king, 0) == 1) { turn = not(turn); victory(); return 1; }
				else { cell[attacker_pos[1]][attacker_pos[0]] = buff; return 0; }
			}
			turn = not(turn);
			return 0;
		}
		else {turn = not(turn); return 0;}
	}
	else if (k / 2 > 30)
	{
		if (motionCheck(king) == 0)
		{
			for(int i=0; i<8; i++)
				for (int j=0; j < 8; j++)
				{
					if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 != 1) && (cell[i][j] % 10 != 6)) { turn = not(turn); return 0; }//по статистике смотрим только пешки
					else if ((cell[i][j] / 10 == turn + 1) && (cell[i][j] % 10 == 1)) /*функция возможности маневра пешкой - возможно*/ { turn = not(turn); return 0; }
				}
			cout << "Drrrraw!!!\n";
			return 1;
		}
		turn = not(turn);
		return 0;
	}
	else { turn = not(turn); return 0; }
}



void gen_color()
{
	srand(time(0));
	if (rand() % 2 == 1) swap(white, black);
}

void choose_player()
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
}






int main()
{
	//start_cell();
	//cout << game_end()<<"\n";
	k = 18;
	turn = 0;
	cell[7][0] = 26; cell[6][0] = 21;
	cell[6][1] = 21; cell[7][2] = 15;
	cout << game_end() <<"  "<< turn<< "\n";
	return 0;
}