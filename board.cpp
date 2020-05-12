#include "board.h"
#include <fstream>
#include <windows.h>
#include <shlobj.h>
#include <iostream>
#include <set>
#include <ostream>
#include <vector>
#pragma warning (disable : 4996)

board::board(std::string filepath): P{0}, T{nullptr}
{
	std::fstream pFile(filepath);
	/*if (pFile == nullptr)
	{
		cout << "File can't be loaded ERROR";
		return;
	}*/
	string str;
	std::cout << "Loading  Data from game..." << std::endl;
	vector<short> v;
	int score=0;
	char c;
	while (!pFile.eof()) {
		pFile.get(c);
		str+= static_cast<char>(c);
		pFile.get(c);
		str+=c;
		if (str == "-1")
		{
			v.push_back(-1);
			str = "";
		}
		else if (str == " 1")
		{
			v.push_back(1);
			str = "";
		}
		else if (str == " 0")
		{
			v.push_back(0);
			str = "";
			score++;
		}
		else if (str == " \n")
			str = "";
		else
			break;
	}
	score--;
	//fclose(pFile);
	pFile.close();
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			P[i][j] = v[i * 7 + j];
			if ((P[i][j] == 1))
			{
				T[i][j] = new piece(std::make_pair(i + 1, j + 1));
			}
			else
				T[i][j] = nullptr;
		}
	}
}

board::board() : P{
		{-1, -1, 1, 1, 1, -1, -1,},
		{-1, 1, 1, 1, 1, 1, -1,},
		{1, 1, 1, 1, 1, 1, 1,},
		{1, 1, 1, 0, 1, 1, 1,},
		{1, 1, 1, 1, 1, 1, 1,},
		{-1, 1, 1, 1, 1, 1, -1,},
		{-1, -1, 1, 1, 1, -1, -1,} }
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if ((P[i][j] == 1))
			{
				T[i][j] = new piece(std::make_pair(i + 1, j + 1));
			}
			else
				T[i][j]=nullptr;
		}
	}
}

int board::getScore()
{
	int n=0;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{

			if(P[i][j]==0)
				n++;
		}
	}
	n--;
	return n;
}
void board::board_display()
{
	cout << endl << endl;
	std::cout << "\t\t   | A  B  C  D  E  F  G  |" << std::endl;
	std::cout << "\t\t   |-----------------------" ;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if(j==0) 
				cout<<endl << " \t\t"<<i+1<<"  |";
			if ((P[i][j] == 1))
			{
				wcout<<L"\033[1;34m"<<" X "<< "\033[0m" ;
			}
			else if(P[i][j]==0)
				cout<<"\033[1;35m" << " * "<< "\033[0m";
			else
				cout << "   ";
		}
	}
	cout<<endl<<endl;

}

bool board::move(int_pair s, int_pair f)
{
	int dirx=0;
	int diry=0;
	int tmpx;
	int tmpy;
	if(f.first-1 < s.first-1)
		tmpx=-1;
	else if(f.first - 1 > s.first - 1)
		tmpx=1;
	else
		tmpx=0;
	
	
	if (f.second - 1 < s.second - 1)
		tmpy = 1;
	else if (f.second - 1 > s.second - 1)
		tmpy = -1;
	else
		tmpy = 0;
	int tmp=tmpx*10+tmpy;
	switch (tmp)
	{
	case 1:
		{
			dirx = 0;
			diry=-1;
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
			dirx=-1;
			break;
		}
		case 10:
		{
			diry = 0;
			dirx = 1;
			break;
		}		
	}
	piece* p=T[s.first-1][s.second-1];
	std::set<std::pair<int, int>> sp=valid_movs(s);
	if (sp.find(f) != sp.end())
	{
		P[s.first -1 +dirx][s.second +diry-1]=0;
		P[s.first-1][s.second-1]=0;
		P[f.first-1][f.second-1]=1;
		T[f.first-1][f.second-1]= T[s.first - 1][s.second - 1];
		T[f.first - 1][f.second - 1]->cord=f;
		T[s.first - 1][s.second - 1]=nullptr;
		return true;
	}
	return false;
}

std::set<std::pair<int, int>> board::valid_movs(int_pair s)
{
	std::set<	std::pair<int, int>	> sp;
	int x=s.first-1;
	int y=s.second-1;
	if((P[x+1][y]==1)&& (P[x+2][y] ==0 )&&(x+2)<7)
		sp.insert(std::make_pair(x+2+1,y+1));
	if ((P[x - 1][y] == 1) && (P[x - 2][y ] == 0)&&(x-1)>0)
		sp.insert(std::make_pair(x-2+1 , y+1));
	if ((P[x][y - 1] == 1) && (P[x][y - 2] == 0)&&y-1>0)
		sp.insert(std::make_pair(x +1, y - 2+1));
	if ((P[x][y + 1] == 1) && (P[x][y + 2] == 0)&&y+2<7)
		sp.insert(std::make_pair(x +1, y + 2+1));
	return sp;
}
