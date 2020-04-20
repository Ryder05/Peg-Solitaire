#include "Piece.h"

piece::piece(int_pair c)
{
	cord=c;
}

piece::piece()
{
	cord=std::make_pair(-1,-1);
}
