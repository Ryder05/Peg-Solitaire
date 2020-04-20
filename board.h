#pragma once
#include <set>

#include "Piece.h"
class board
{
private:
	int P[7][7];
	piece* T[7][7];
public:
	bool valid(int x, int y);
	board();
	void board_display();
	set<	std::pair<int, int>	> valid_movs(int_pair s);
	bool move(int_pair s, int_pair f);
	bool GameOver();
};