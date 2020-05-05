#include <iostream>
#include <string>
#include "Game.h"
void displayMainMenu()
{
	cout << "\t\t\t\tWelcome to peg Solitaire Game\n\n";
	cout << "\t\t\t\t\tNew Game:(n)\n" << endl;
	cout << "\t\t\t\t\tLoad Game:(l)\n" << endl;
	cout << "\t\t\t\t\tHow to Play:(h)\n" << endl;
}
int main()
{
	displayMainMenu();
	string cmd;
	bool B = true;
	while (B) {
		cout<<"\t\tPress a button: ";
		getline(std::cin, cmd);
		if (cmd == "n")
		{
			system("cls");
			Game game;
   			game.run();
			B=false;
		}
		else if (cmd == "l")
		{
			system("cls");
			Game game;
			game.b = game.load();
			game.run();
		}
		else if (cmd == "h")
		{

		}
		else
		{
			system("cls");
			displayMainMenu();
			cout<< BOLDYELLOW<< "\t\tInvalid Command ! Try again..."<<endl<<RESET;
		}
	}
}