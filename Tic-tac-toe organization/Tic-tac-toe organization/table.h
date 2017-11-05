#ifndef _TABLE_H
#define _TABLE_H

#include<iostream>
#include "humanplayer.h"

using namespace std;

class Table
{
private:
	int win, turn;
	int human_choose_again;
	//this value judges that if humanplayer add a pawn in a place which already have signs of humanplayer or computerplayer
public:
	Table();
	~Table();
	char table[3][3];
	void table_initialize();//initialize the table,make each pawn of the table to be '*'
	void table_refresh();//print some basic information and the table
	int check_win(Table &t, char symbol);//check who wins
	int get_turn();
	void set_turn(int number);
	int get_win();
	void  set_win(int number);
	int get_human_choose_again();
	void set_human_choose_again(int number);
};
#endif  