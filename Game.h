#pragma once
#include "board.h"
#pragma warning (disable : 4996)
#include <iostream>
#include <string>
#include<tuple>
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define RESET   "\033[0m"
typedef std::pair<int, int> int_pair;
class board;
class Game
{
	static int Score;
	board b;
public:
	std::tuple<int_pair, int_pair> Extract(string str);
	void run();
	void save();
	void load();
	void help();
	bool GameOver();
};

