#include "Game.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <direct.h>
#include <shlobj.h>
#define RED     "\033[31m"			  /* Red */
#define YELLOW  "\033[33m"            /* Bold Yellow */
void end()
{
	cout << RED << R"(         .            )        )
                  (  (|              .
              )   )\/ ( ( (
      *  (   ((  /     ))\))  (  )    )
    (     \   )\(          |  ))( )  (|
    >)     ))/   |          )/  \((  ) \
    (     (      .        -.     V )/   )(    (
     \   /     .   \            .       \))   ))
       )(      (  | |   )            .    (  /
      )(    ,'))     \ /          \( `.    )
      (\>  ,'/__      ))            __`.  /
     ( \   | /  ___   ( \/     ___   \ | ( (
      \.)  |/  /   \__      __/   \   \|  ))
     .  \. |>  \      | __ |      /   <|  /
          )/    \____/ :..: \____/     \ <
   )   \ (|__  .      / ;: \          __| )  (
  ((    )\)  ~--_     --  --      _--~    /  ))
   \    (    |  ||               ||  |   (  /
         \.  |  ||_             _||  |  /
           > :  |  ~V+-I_I_I-+V~  |  : (.
          (  \:  T\   _     _   /T  : ./
           \  :    T^T T-+-T T^T    ;<
            \..`_       -+-       _'  )
  )            . `--=.._____..=--'. ./                                                               
  ____    _    __  __ _____    _____     _______ ____  
 / ___|  / \  |  \/  | ____|  / _ \ \   / | ____|  _ \ 
| |  _  / _ \ | |\/| |  _|   | | | \ \ / /|  _| | |_) |
| |_| |/ ___ \| |  | | |___  | |_| |\ V / | |___|  _ < 
 \____/_/   \_|_|  |_|_____|  \___/  \_/  |_____|_| \_\
                                                       
 
)" << RESET;
	std::cin.get();

}
void won()
{
	cout << YELLOW << R"(                      . . . .
                      ,`,`,`,`,                   __   _____  _   _      
. . . .               `\`\`\`\;                   \ \ / / _ \| | | |     
`\`\`\`\`,            ~|;!;!;\!                    \ V | | | | | | |     
 ~\;\;\;\|\          (--,!!!~`!       .             | || |_| | |_| |     
(--,\\\===~\         (--,|||~`!     ./              |_| \___/ \___/      
 (--,\\\===~\         `,-,~,=,:. _,//                   
  (--,\\\==~`\        ~-=~-.---|\;/J,                   
   (--,\\\((```==.    ~'`~/       a |                   
     (-,.\\('('(`\\.  ~'=~|     \_.  \                    __        _____  _   _ 
        (,--(,(,(,'\\. ~'=|       \\_;>                   \ \      / / _ \| \ | |
          (,-( ,(,(,;\\ ~=/        \                       \ \ /\ / | | | |  \| |
          (,-/ (.(.(,;\\,/          )                       \ V  V /| |_| | |\  |
           (,--/,;,;,;,\\         ./------.                  \_/\_/  \___/|_| \_|
             (==,-;-'`;'         /_,----`. \                   
     ,.--_,__.-'                    `--.  ` \                   
    (='~-_,--/        ,       ,!,___--. \  \_)                   
   (-/~(     |         \   ,_-         | ) /_|                   
   (~/((\    )\._,      |-'         _,/ /                                      
    \\))))  /   ./~.    |           \_\;                   
 ,__/////  /   /    )  /                   
  '===~'   |  |    (, <.
           / /       \. \
         _/ /          \_\
        /_!/            >_\
)" << RESET;
	std::cin.get();
}
bool EXIT = false;

LPSTR desktop_directory() {
	static char path[10];
	if (SHGetSpecialFolderPathA(HWND_DESKTOP, path, CSIDL_PROFILE, FALSE)) return path;
	else return NULL;
}
std::tuple<int_pair, int_pair> Game::Extract(string str)
{
	std::string x = str.substr(0, 2);
	std::string y = str.substr(6, 2);
	char x1 = x[0];
	char x2 = x[1];
	char y1 = y[0];
	char y2 = y[1];
	int_pair ip1 = std::make_pair((int)x1 - '0', (int)(x2 - 96));
	int_pair ip2 = std::make_pair((int)y1 - '0', (int)(y2 - 96));
	return std::make_tuple(ip1, ip2);
}
void Game::run()
{
	cout << RESET;
	EXIT = false;
	b.board_display();
	std::string str;
	bool HELP = false;
	while (!GameOver())
	{
		if (!HELP)
		{
			cout << RED << "\t\t\t\tScore: " << Score << RESET << "\n\n";
			cout << '\n' << "\033[32m" << "To make a move ,you have to write the position a peg 'to' the position you want to make the move to ." << endl;
			cout << '\n' << "\033[32m" << "For example : 4f to 4d ." << endl;
			cout << '\n' << "\033[32m" << "Writing 'undo' will return you to the previous move." << endl;
			cout << '\n' << "\033[32m" << "Writing 'save' will save the game ." << endl;
			cout << '\n' << "\033[32m" << "Writing 'help' will show you the possible moves of every peg." << endl;
			cout << '\n' << "\033[32m" << "Writing 'exit' will return you to the main menu." << endl;
			cout << '\n' << endl;
			cout << BOLDYELLOW << "\t\t\t Player Command: " << RESET;
			
			getline(std::cin, str);
		}
		else
		{
			system("cls");
			b.board_display();
			cout << "\tScore: " << Score << endl;
			
			Help();
			HELP = false;
			cout << '\n' << BOLDYELLOW << "\t\t\t Player Command: " << RESET;
			
			getline(std::cin, str);

			
		}
		if (str == "undo" || str == "Undo")
			Undo();
		else if (str == "Help" || str == "help" || str == "hlp")
		{
			HELP = true;
		}
		else if (str == "GameOver")
		{
			system("cls");
			end();
		}
		else if (str == "GameWon")
		{
			system("cls");
			won();
		}
		else if (str == "exit" || str == "EXIT")
		{
			system("cls");
			EXIT = true;
			Autosave();
			return;
		}
		else if (str == "save" || str == "Save" || str == "SAVE")
			save();
		else
		{
			try
			{
				std::tuple<int_pair, int_pair> tup = Extract(str);
				if (b.move(std::get<0>(tup), std::get<1>(tup)))
				{
					Play.push(tup);
					Score++;
				}
			}
			catch (const std::out_of_range& oor) {
				std::cerr << "Out of Range error: " << oor.what() << '\n';
			}
		}
		if (HELP == false)
		{
			system("cls");
			b.board_display();
		}
	}
	if (Score == 37)
		won();
	else
		end();
}
void Game::Undo()
{
	if (Play.empty() == true)
	{
		cout << "Invalid Command" << endl;
		return;
	}
	auto x = Play.top();
	auto f = get<0>(x);
	auto s = get<1>(x);
	int dirx = 0;
	int diry = 0;
	int tmpx;
	int tmpy;
	if (f.first - 1 < s.first - 1)
		tmpx = -1;
	else if (f.first - 1 > s.first - 1)
		tmpx = 1;
	else
		tmpx = 0;


	if (f.second - 1 < s.second - 1)
		tmpy = 1;
	else if (f.second - 1 > s.second - 1)
		tmpy = -1;
	else
		tmpy = 0;
	int tmp = tmpx * 10 + tmpy;
	switch (tmp)
	{
	case 1:
	{
		dirx = 0;
		diry = -1;
		break;
	}
	case -1:
	{
		dirx = 0;
		diry = 1;
		break;
	}
	case -10:
	{
		diry = 0;
		dirx = -1;
		break;
	}
	case 10:
	{
		diry = 0;
		dirx = 1;
		break;
	}
	}
	b.P[s.first - 1 + dirx][s.second + diry - 1] = 1;
	b.P[s.first - 1][s.second - 1] = 0;
	b.P[f.first - 1][f.second - 1] = 1;

	b.T[s.first - 1][s.second - 1] = nullptr;
	b.T[s.first - 1 + dirx][s.second + diry - 1] = new piece(std::make_pair(s.first - 1 + dirx, s.second + diry - 1));
	b.T[f.first - 1][f.second - 1] = new piece(std::make_pair(f.first - 1, f.second - 1));
	Play.pop();
	Score--;
}
void Game::save()
{
	string filePath;
	ofstream pFile;
	cout << "\t\tEnter your Game name: ";
	getline(cin, filePath);
	string str1 = string(desktop_directory()) + "\\Documents\\Ensi_Solitaire";
	const char* c = str1.c_str();
	_mkdir(c);
	filePath = str1 + "\\" + filePath + ".txt";
	pFile.open(filePath);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if ((j == 0) && (i != 0))
				pFile << " \n";
			pFile << setw(2) << b.P[i][j];
		}
	}
	pFile.close();
	std::cout << "Saving Data Game...";
}
void Game::Autosave()
{
	string filePath;
	ofstream pFile;
	string str1 = string(desktop_directory()) + "\\Documents\\Ensi_Solitaire";
	const char* c = str1.c_str();
	_mkdir(c);
	pFile.open(str1 + "\\autoSave.txt");
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if ((j == 0) && (i != 0))
				pFile << " \n";
			pFile << setw(2) << b.P[i][j];
		}
	}
	pFile.close();
}
board Game::load()
{
	FILE* file;
	string filePath;
	cout << "\n\n\n\t\t\tEnter your Game name to load the game :";
	getline(cin, filePath);
	string str1 = string(desktop_directory()) + "\\Documents\\Ensi_Solitaire\\";
	filePath = str1 + filePath + ".txt";
	system("cls");
	return board(filePath);
}
board Game::Autoload()
{
	string str1 = string(desktop_directory()) + "\\Documents\\Ensi_Solitaire";
	return board(str1 + "\\autoSave.txt");

}
bool Game::GameOver()
{
	set<pair<int, int>> sp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (b.P[i][j] == 1)
			{
				auto vm = b.valid_movs(std::make_pair(i + 1, j + 1));
				for (auto x : vm)
				{
					sp.insert(x);
				}
			}
		}
	}
	return sp.empty();
}
void Game::Help()
{
	set<pair<int, int>> sp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (b.P[i][j] == 1)
			{
				auto vm = b.valid_movs(std::make_pair(i + 1, j + 1));
				for (auto x : vm)
				{
					std::cout << "\t\t\t\t" << YELLOW << '(' << i + 1 << ',' << char(j + 65) << ')' << "==========>" <<
						'(' << x.first << ',' << char(x.second + 64) << ')' << RESET << std::endl;
				}
			}
		}
	}
	cout << RESET;
}