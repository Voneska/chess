#include <iostream>
#include <Windows.h>

using namespace std;

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);

bool turn;



class Chess
{
private:
	unsigned short cell[8][8] = { 0 }, cell_from = 0, cell_to = 0;

	void show()
	{

	}

	bool game_end()
	{

	}

public:

	bool game_turn()
	{

		return 0;
	}

	unsigned short Get_cell_from()
	{
		return cell_from;
	}

	unsigned short check()
	{

		cout << "12" << endl;
		return 11;
	}

	virtual bool check_to(unsigned short pos) { return 1; }

};

class Pawn : public Chess
{
public:
	bool check_to(unsigned short pos) override
	{

		return 1;
	}
};

class Horse : public Chess
{
public:
	bool check_to(unsigned short pos) override
	{

	}
};

class Bishop : public Chess
{
public:
	bool check_to(unsigned short pos) override
	{

	}
};


class Rook : public Chess
{
public:
	bool check_to(unsigned short pos) override
	{

	}
};

class Queen : public Chess
{
public:
	bool check_to(unsigned short pos) override
	{

	}
};


class King : public Chess
{
public:
	bool check_to(unsigned short pos) override
	{

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
	void New_game() {
		system("cls");
		Chess* figure = new Chess;
		bool flag = 1;
		turn = 0;	
		do{
			unsigned short t = figure->check();

			switch (figure->Get_cell_from() % 10)
			{
			case 1: figure = new Pawn;
				break;
			}

			if (figure->check_to(t) == 0)
			{
				flag = 1;
			}
			else flag = 0;
		} while (flag || figure->game_turn());

		std::cout << "New game has been starting!" << std::endl;
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
}