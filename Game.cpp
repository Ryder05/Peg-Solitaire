#include "Game.h"
#include <iostream>
#include <vector>

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
    b.board_display();
    std::string str;
    while (!GameOver())
    {
        cout << BOLDYELLOW << "\t\t\t Player Command: " << RESET;
        getline(std::cin, str);
        std::tuple<int_pair, int_pair> tup = Extract(str);
        b.move(std::get<0>(tup), std::get<1>(tup));
        system("cls");
        b.board_display();
    	save();
    }
}
void Game::save()
{
	FILE* pFile = fopen("C:\\Users\\Osama\\Documents\\PegSolg.txt", "w");
	std::cout << "Saving Data Game...";
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if ((j == 0) && (i != 0))
				fprintf(pFile, " \n");
			fprintf(pFile, "%2d", b.P[i][j]);
		}
	}
	fclose(pFile);
}
void Game::load()
{
	b=board(R"(C:\Users\Osama\Documents\PegSolg.txt)");
}

//void Game::load()
//{
//	FILE* pFile = fopen(R"(C:\Users\Osama\Documents\PegSolg.txt)", "r");
//	if (pFile == nullptr)
//	{
//		cout << "File can't be loaded ERROR";
//		return;
//	}
//	std::cout << "Loading  Data..." << std::endl;
//	string str;
//	string raw;
//	vector<short> v;
//	while (true) {
//		str += static_cast<char>(fgetc(pFile));
//		str += static_cast<char>(fgetc(pFile));
//		if (str == "-1")
//		{
//			v.push_back(-1);
//			str = "";
//		}
//		else if (str == " 1")
//		{
//			v.push_back(1);
//			str = "";
//		}
//		else if (str == " 0")
//		{
//			v.push_back(0);
//			str = "";
//		}
//		else if (str == " \n")
//			str = "";
//		else
//			break;
//	}
//	fclose(pFile);
//	int Pp[7][7];
//	for (int i = 0; i < 7; i++)
//	{
//		for (int j = 0; j < 7; j++)
//		{
//			Pp[i][j] = v[i * 7 + j];
//			cout << Pp[i][j] << " ";
//		}
//	}
//}
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
