#pragma once
#pragma warning (disable : 4996)
#include "board.h"
#include <iostream>
#include <string>
#include<tuple>
#include<stack>
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define RESET   "\033[0m"
typedef std::pair<int, int> int_pair;
class board;
class Game
{
    int Score=0;
	stack<std::tuple<int_pair, int_pair>> Play;
	friend class board;
public:
	board b;
	//Game(board b);
	std::tuple<int_pair, int_pair> Extract(string str);
	void run();
    void Undo();
    void save();
	board load();
	void help();
	bool GameOver();
};

