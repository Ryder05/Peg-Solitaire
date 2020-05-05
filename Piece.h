#pragma once
#include <utility>
using namespace std;
typedef std::pair<int, int> int_pair;
class piece
{
private:
	int_pair cord;
	friend class board;
	friend class Game;

public:
	piece(int_pair c);
	piece();
};



