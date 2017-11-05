#ifndef _COMPUTERPLAYER_H
#define _COMPUTERPLAYER_H

#include<iostream>
#include "humanplayer.h"

using namespace std;

class ComputerPlayer :public Player
{
private:
	int computerpoint;
	char computerplayersign;
public:
	ComputerPlayer();
	~ComputerPlayer();
	int get_computerpoint();
	char computerplayerchoosesign(char sign);//receive humanplayer's sign to decide which sign the computerplayer uses
	int computerplayerchoosepawn(Table &t, HumanPlayer &humanplayer, ComputerPlayer &computerplayer);//computer add pawn, this is the most important algorithm
	int computerpoint_increase(int number);// make the value computerpoint plus 1
	char get_computerplayersign();
};
#endif  