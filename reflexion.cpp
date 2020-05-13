#include <iostream>
#include <string>
#include "Game.h"

void header()
{
	system("color A");

	cout << R"( _       __     __                             ______          
| |     / ___  / _________  ____ ___  ___     /_  ______     _ 
| | /| / / _ \/ / ___/ __ \/ __ `__ \/ _ \     / / / __ \   (_)
| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/    / / / /_/ /  _   
|__/|__/\___/_/\___/\____/_/ /_/ /_/\___/    /_/  \____/  (_)  
                                                               )" << endl;
	cout << '\t' << R"(    ____                            _____             __   _    __              _               
)";
	cout << '\t' << R"(   / __ \   ___     ____ _         / ___/   ____     / /  (_)  / /_   ____ _   (_)  _____   ___ 
)";
	cout << '\t' << R"(  / /_/ /  / _ \   / __ `/         \__ \   / __ \   / /  / /  / __/  / __ `/  / /  / ___/  / _ \
)";
	cout << '\t' << R"( / ____/  /  __/  / /_/ /         ___/ /  / /_/ /  / /  / /  / /_   / /_/ /  / /  / /     /  __/
)";
	cout << '\t' << R"(/_/       \___/   \__, /         /____/   \____/  /_/  /_/   \__/   \__,_/  /_/  /_/      \___/ 
)";
	cout << '\t' << R"(                 /____/                                                                         
)";
}
void displayMainMenu()
{
	cout << "\n\n";
	cout << "\t\t\t\t\tContinue Game:(c)\n" << endl;
	cout << "\t\t\t\t\tNew Game:(n)\n" << endl;
	cout << "\t\t\t\t\tLoad Game:(l)\n" << endl;
	cout << "\t\t\t\t\tHow to Play:(h)\n" << endl;
	cout << "\t\t\t\t\tExit Game(e)\n" << endl;
}
void help()
{
	cout << "\n\n Peg Solitaire is one of the most recognizable and popular board games of all time. With easy-to-learn rules and seemingly simple goals" << endl;
	cout << "\nThe object of the game is to remove all of the pegs from the board by jumping over them with any of the other pegs.The peg can move vertically or horizontally over another one." << endl;
	cout << "\nTo move a peg you need to specify the coordinate of the piece you want to move  + \'to\' + destination coordinate " << endl;
	cout << "\n To win the game ,only one peg should stay on the board. " << endl;
	cout << "\n If two or more pegs are on the board with no possible movements , the game is over and you lost ." << endl;
}
int main()
{
	extern bool EXIT;
	header();
	displayMainMenu();
	string cmd;
	bool B = true;
	while (B) {
		cout << "\t\tPress a Key: ";
		getline(std::cin, cmd);
		if (cmd == "n")
		{
			system("cls");
			Game game;
			game.run();
			if (EXIT == true)
			{
				system("cls");
				main();
			}
			B = false;
		}
		else if (cmd == "e")
			exit(0);
		else if (cmd == "c")
		{
			system("cls");
			Game game;
			game.b = game.Autoload();
			game.setScore(game.b.getScore());
			game.run();
			if (EXIT == true)
			{
				main();
			}
			B = false;
		}
		else if (cmd == "l")
		{
			system("cls");
			Game game;
			game.b = game.load();
			game.setScore(game.b.getScore());
			game.run();
			if (EXIT == true)
			{
				system("cls");
				main();
			}
			B = false;
		}
		else if (cmd == "h")
		{
			system("cls");
			help();
			cin.get();
		}
		else
		{
			system("cls");
			header();
			displayMainMenu();
			cout << BOLDYELLOW << "\t\tInvalid Command ! Try again..." << endl /*<< RESET*/;
		}
	}
}