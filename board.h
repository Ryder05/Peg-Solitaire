#pragma once
#include <set>
#include <string>
#include "Piece.h"
class board
{
private:
	int P[7][7]; //matrice des case
	piece* T[7][7] ;//matrice des peice
	friend class Game;
public:
	board(std::string filepath);
	board();
	int getScore();
	void board_display();
	set<std::pair<int, int>	> valid_movs(int_pair s);
	bool move(int_pair s, int_pair f);
};