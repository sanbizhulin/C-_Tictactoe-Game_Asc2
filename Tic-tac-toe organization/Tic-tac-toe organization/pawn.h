#ifndef _PAWN_H
#define _PAWN_H

#include<iostream>
#include "table.h"

using namespace std;

class Pawn
{
private:
	int emptypawn;
public:
	Pawn();
	~Pawn();
	int get_emptypawn();//know how many empty pawns are there in the table
	int set_emptypawn(int emptypawn_number);
	void emptypawn_decrease(int emptypawn_number); //make the value emptypawn decrease 1
};
#endif