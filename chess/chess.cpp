#include <iostream>
#include<ctime>
#include<Windows.h>
using namespace std;
string white, black;
unsigned short cell[8][8];
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
void victory()
{
	if (turn == 0)
		cout << "Checkmate to the black King\n" << white << " wooooooon!!!\n";
	else if (turn == 1) cout << "Checkmate to the white King\n" << black << " wooooooon!!!\n";
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

bool chek_cell(string s)//vozvrashaet 0 v slychae esli cletca ne bietsa
{
	unsigned short hod[2];
	translatePosition(s, hod);
	//krol + peski
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
	for (int i = hod[1] + 1, j = hod[0] + 1; j < 8, i < 8; j++, i++)//n-e
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[1]][i] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] - 1, j = hod[0] - 1; j >= 0, i >= 0; j--, i--)//s-w
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[1]][i] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] - 1, j = hod[0] + 1; j < 8, i >= 0; j++, i--)//s-e
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[1]][i] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] + 1, j = hod[0] - 1; j >= 0, i < 8; j--, i++)//n-w
	{
		if ((cell[i][j] / 10) == (turn + 1))  break;
		if ((cell[i][j] / 10) != 0)
			if (((cell[i][j] % 10) == 3) || ((cell[hod[1]][i] % 10) == 5)) return 1;
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

	if ((hod[1] + 1 < 8) && (hod[0] + 1 < 8) && (cell[hod[1] + 1][hod[0] + 1] % 10 == 6) && (cell[hod[1] + 1][hod[0] + 1] / 10 != turn + 1)) return 1;//king
	if ((hod[1] + 1 < 8) && (cell[hod[1] + 1][hod[0]] % 10 == 6) && (cell[hod[1] + 1][hod[0]] / 10 != turn + 1)) return 1;
	if ((hod[1] + 1 < 8) && (hod[0] - 1 >= 0) && (cell[hod[1] + 1][hod[0] - 1] % 10 == 6) && (cell[hod[1] + 1][hod[0] - 1] / 10 != turn + 1)) return 1;
	if ((hod[1] - 1 >= 0) && (cell[hod[1] - 1][hod[0]] % 10 == 6) && (cell[hod[1] - 1][hod[0]] / 10 != turn + 1)) return 1;
	if ((hod[1] - 1 >= 0) && (hod[0] + 1 < 8) && (cell[hod[1] - 1][hod[0] + 1] % 10 == 6) && (cell[hod[1] - 1][hod[0] + 1] / 10 != turn + 1)) return 1;
	if ((hod[0] + 1 < 8) && (cell[hod[1]][hod[0] + 1] % 10 == 6) && (cell[hod[1]][hod[0] + 1] / 10 != turn + 1)) return 1;
	if ((hod[1] - 1 >= 0) && (hod[0] - 1 >= 0) && (cell[hod[1] - 1][hod[0] - 1] % 10 == 6) && (cell[hod[1] - 1][hod[0] - 1] / 10 != turn + 1)) return 1;
	if ((hod[0] - 1 >= 0) && (cell[hod[1]][hod[0] - 1] % 10 == 6) && (cell[hod[1]][hod[0] - 1] / 10 != turn + 1)) return 1;

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
int main()
{
	start_cell();
	cout << chek_cell("b2") << endl; cout << chek_cell("b3") << endl; cout << chek_cell("b6") << endl; cout << chek_cell("h6") << endl; cout << chek_cell("e8") << endl;
	return 0;
}