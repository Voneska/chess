#include <iostream>
#include<ctime>
#include<Windows.h>
using namespace std;
string white, black;
unsigned short cell[8][8];
bool turn = 0;//xod belix
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
//void start_cell()
//{
//	cell[0][0] = 14; cell[0][1] = 12; cell[0][2] = 13; cell[0][3] = 15;
//	cell[0][4] = 16; cell[0][5] = 13; cell[0][6] = 12; cell[0][7] = 14;
//	for (int i = 0; i < 8; i++)
//	{
//		cell[1][i] = 11;
//		cell[6][i] = 21;
//	}
//	cell[7][0] = 24; cell[7][1] = 22; cell[7][2] = 23; cell[7][3] = 25;
//	cell[7][4] = 26; cell[7][5] = 23; cell[7][6] = 22; cell[7][7] = 24;
//}
bool chek_cell(unsigned short hod[])//vozvrashaet 0 v slychae esli cletca ne bietsa
{
	//krol + peski
	for (int i = hod[1]; i < 8; i++)//up
	{
		unsigned short cvert = hod[0] - 1;
		if ((cell[i][cvert] / 10) == (turn + 1))  break;
		if ((cell[i][cvert] / 10) != 0)
			if (((cell[i][cvert] % 10) == 4) || ((cell[i][cvert] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[1] - 2; i >= 0; i--)//down
	{
		unsigned short cvert = hod[0] - 1;
		if ((cell[i][cvert] / 10) == (turn + 1))  break;
		if ((cell[i][cvert] / 10) != 0)
			if (((cell[i][cvert] % 10) == 4) || ((cell[i][cvert] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[0]; i < 8; i++)//->
	{
		unsigned short chor = hod[1] - 1;
		if ((cell[chor][i] / 10) == (turn + 1))  break;
		if ((cell[chor][i] / 10) != 0)
			if (((cell[chor][i] % 10) == 4) || ((cell[chor][i] % 10) == 5)) return 1;
			else break;
	}
	for (int i = hod[0] - 2; i >= 0; i--)//<-
	{
		unsigned short chor = hod[1] - 1;
		if ((cell[chor][i] / 10) == (turn + 1))  break;
		if ((cell[chor][i] / 10) != 0)
			if (((cell[chor][i] % 10) == 4) || ((cell[chor][i] % 10) == 5)) return 1;
			else break;
	}

	return 0;
}
int main()
{

	return 0;
}
