#include "Game.h"
#include <iostream>
//Game::Game(board b):b(){}
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
    	if(str=="undo")
			Undo();
		else if(str=="exit")
			exit(0);
		else
		{
			std::tuple<int_pair, int_pair> tup = Extract(str);
			if (b.move(std::get<0>(tup), std::get<1>(tup)))
			{
				Play.push(tup);
				Score++;
			}
		}
        system("cls");
        b.board_display();
    	cout<<"Score: "<<Score<<endl;
    	save();
    }
}
void Game::Undo()
{
	if(Play.empty()==true)
	{
		cout<<"Invalid Command"<<endl;
		return;
	}
	auto x=Play.top();
	auto f=get<0>(x);
	auto s=get<1>(x);
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
	b.T[f.first - 1][f.second - 1] = new piece(std::make_pair(f.first - 1,f.second - 1));
	Play.pop();
	Score--;
}
void Game::save()
{
//	cout<<"Enter your Game name "<<endl;
//	getline(cin,lg);
	FILE* pFile = fopen(R"(C:\Users\Osama\\Documents\PegSolg.txt)", "w");
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
board Game::load()
{
	return board(R"(C:\Users\Osama\Documents\PegSolg.txt)");
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
