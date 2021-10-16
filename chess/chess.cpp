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
}