#ifndef _GAME_H
#define _GAME_H

#include <iostream>
#include "table.h"
#include "pawn.h"
#include "computerplayer.h"

using namespace std;

class Game
{
private:
	int round;
	bool human_win;
public:
	Game();
	~Game();
	int display(Table &t, HumanPlayer &humanplayer, ComputerPlayer &computerplayer);//display the basic information
	int run();
	void fiverounds(Table &t, HumanPlayer &humanplayer, ComputerPlayer &computerplayer, Pawn &pawn);
	void last_winner(HumanPlayer &humanplayer, ComputerPlayer &computerplayer);//judge who is the last winner
	void change_turn(Table &t);
	void set_human_win(bool value);
	bool get_human_win();
	int get_round();
	void set_round(int number);
	void round_increase(int number);//make the value round plus 1
};
#endif