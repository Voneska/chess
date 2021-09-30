/* 
Кодировка
_                      _ 
2 - пустая ячейка      3 - пешка
0 - черная фигура      4 - конь
1 - белая фигура	   ...

Например:
03 - черная пешка
*/


#include <iostream>
#include <Windows.h>

HWND hwnd = GetConsoleWindow();
HDC hdc = GetDC(hwnd);
//class menu
class Menu{
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

	void New_game() {
		system("cls");
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

public:
	int set_choise() {
		menu_window();
		std::cin >> user_choise;
		if (std::cin.fail()) { // check error flags
			std::cin.clear(); // clears error flags
			std::cin.ignore(2323, '\n'); // ~ while(cin.get() != '\n');
		}
		switch (user_choise) {
		case 1: 
			New_game();
			return user_choise;
			break;
		case 2: 
			Reference();
			return user_choise;
			break;
		case 3: Exit();
			return user_choise;
			break;
		default:
			Err_choise();
			return 4;
		}
	}
	int give_choise() { return user_choise; }
};


//function menu
/*
int menu() {
	int user_choise1 = 0;
	system("cls");
	std::cout << "\tHello, stranger." << std::endl;
	std::cout << "1. New game" << std::endl;
	std::cout << "2. Reference" << std::endl;
	std::cout << "3. Exit" << std::endl;
	std::cout << "Your choise: ";
	std::cin >> user_choise1;
	if (std::cin.fail()) { // check error flags
		std::cin.clear(); // clears error flags
		std::cin.ignore(2323, '\n'); // ~ while(cin.get() != '\n');
	}
	switch (user_choise1) {
	case 1:
		system("cls");
		return user_choise1;
		break;
	case 2:		
		system("cls");
		std::cout << "Write:" << std::endl;
		std::cout << "1. \"Pass\" to surrender." << std::endl;
		std::cout << "2. \"Draw\" to offer a draw." << std::endl;
		std::cout << "Type enter to exit reference.";
		std::cin.get();
		std::cin.get();
		return user_choise1;
		break;
	case 3: 
		system("cls");
		std::cout << "Thanks for playing. Good bye." << std::endl;
		return user_choise1;
		break;
	default:
		system("cls");
		std::cout << "It's wrong!" << std::endl;
		Sleep(500);
		return 4;
	}
}
*/

int main()
{
	Menu game;
	int a =0;
	while ((a = game.set_choise()) != 3){
		if (a == 4) continue;
		if (a == 2) continue;
		//if (a == 1) {

		std::cout << "Hey" << std::endl;
		Sleep(1000);
		//}

	}

	//for Function
	/*
	int a = 0;
	while ((a = menu()) != 3) {
		if (a == 4) continue;
		if (a == 2) continue;
		//if (a == 1) {

		std::cout << "Hey" << std::endl;
		Sleep(1000);
		//}
	}*/
	
	return 0;
}
