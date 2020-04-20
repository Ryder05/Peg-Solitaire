#include <iostream>
#include <string>
#include<tuple>
#include "board.h"
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define RESET   "\033[0m"
std::tuple<int_pair, int_pair> Extract(string str)
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
int main()
{
	typedef std::pair<int, int> int_pair;
	board b;
	b.board_display()	;
	std::string str;
 	while(!b.GameOver())
 	{
 		cout<<BOLDYELLOW<<"\t\t\t Player Commmand: "<<RESET;
 		getline(std::cin, str);
 		std::tuple<int_pair, int_pair> tup = Extract(str);
 		b.move(std::get<0>(tup), std::get<1>(tup));
		system("cls");
 		b.board_display();
 	}
}

