#ifndef _HUMANPLAYER_H
#define _HUMANPLAYER_H

#include<iostream>
#include "table.h"
#include "player.h"

using namespace std;

class HumanPlayer :public Player
{
private:
	char humanplayersign;
	int row, col;
	int humanpoint;
public:
	HumanPlayer(char *inputname) :Player(inputname)
	{
		humanpoint = 0;
	}
	~HumanPlayer();
	char get_humanplayersign();
	void set_humanplayersign();
	char humanplayerchoosesign(char sign);//decide which sign the humanplayer uses
	int humanplayerchoosepawn(int row, int col, char array[3][3], char sign);// control the humanplayer to add a pawn in a special place
	int get_human_row();
	int get_human_col();
	void set_human_row();
	void set_human_col();
	int get_humanpoint();
	int humanpoint_increase(int number);//make the value humanpoint plus 1
};
#endif