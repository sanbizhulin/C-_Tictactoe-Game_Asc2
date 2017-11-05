#include"player.h"
#include"humanplayer.h"
#include "table.h"

HumanPlayer::~HumanPlayer()
{
  //empty
}

int HumanPlayer::humanpoint_increase(int number)
{
	humanpoint = number;
	humanpoint++;
	return humanpoint;
}

int HumanPlayer::get_humanpoint()
{
	return humanpoint;
}

void HumanPlayer::set_human_row()
{
	cin >> row;
}

void HumanPlayer::set_human_col()
{
	cin >> col;
}

int HumanPlayer::get_human_row()
{
	return row;
}

int HumanPlayer::get_human_col()
{
	return col;
}

void HumanPlayer::set_humanplayersign()
{
	cin >> humanplayersign;
	if (humanplayersign != 'X'&&humanplayersign != 'O')//controls that the humanplayersign must be 'X' or 'O'
	{
		cout << "Please input 'X'or 'O'"<<endl;
		set_humanplayersign();
	}

}

char HumanPlayer::get_humanplayersign()
{
	return humanplayersign;
}

char HumanPlayer::humanplayerchoosesign(char sign)
{
	humanplayersign = sign;
	return humanplayersign;
}

int HumanPlayer::humanplayerchoosepawn(int row, int col, char array[3][3], char sign)//make the humanplayer to add his sign into the pawn which he choose
{

	array[row][col] = sign;
	return 1;
}