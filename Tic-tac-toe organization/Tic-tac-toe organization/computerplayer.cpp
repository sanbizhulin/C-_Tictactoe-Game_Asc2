#include "player.h"
#include "table.h"
#include "computerplayer.h"
#include "humanplayer.h"

ComputerPlayer::ComputerPlayer()
{
	computerpoint = 0;
}

ComputerPlayer::~ComputerPlayer()
{
//empty
}

char ComputerPlayer::get_computerplayersign()
{
	return computerplayersign;
}

int ComputerPlayer::get_computerpoint()
{
	return computerpoint;
}

int ComputerPlayer::computerpoint_increase(int number)
{
	computerpoint = number;
	computerpoint++;
	return computerpoint;
}

char ComputerPlayer::computerplayerchoosesign(char sign)//receive the sign of humanplayer to judge that the computerplayer adopt another sign
{
	if (sign == 'X')
	{
		cout << "The comouterplayer uses:O" << endl;
		computerplayersign = 'O';
	}
	if (sign == 'O')
	{
		cout << "The comouterplayer uses:X" << endl;
		computerplayersign = 'X';
	}

	return computerplayersign;
}

int  ComputerPlayer::computerplayerchoosepawn(Table &t, HumanPlayer &humanplayer, ComputerPlayer &computerplayer)//computerplayer choose where to add its sign,this function is the most important function
{

	int comi = 0, comj = 0, enough = 0;//comi and comj are the values receive the actually pawn where computerplayer will add its sign into
	//Firstly,check where the humanplayer add his sign in
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 2; j++)
		{
			if (t.table[i][j] == '*')
			{

				t.table[i][j] = computerplayer.computerplayersign;
				if (t.check_win(t, computerplayer.computerplayersign) == 1)
				{
					t.set_win(0);
					comi = i;
					comj = j;
					enough = 1;//enough==1 means that no need to check other conditions
				}

				t.table[i][j] = '*';
			}
		}
	}
	if (enough == 0)
	{
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (t.table[i][j] == '*')
				{

					t.table[i][j] = humanplayer.get_humanplayersign();
				
					if (t.check_win(t, humanplayer.get_humanplayersign())== 1)
					{
						t.set_win(0);
						comi = i;
						comj = j;
						enough = 1;

					}
					t.table[i][j] = '*';
				}
			}
		}
	}

	if (enough == 0)
	{
		for (int i = 0; i <= 2; i++)
		{
			for (int j = 0; j <= 2; j++)
			{
				if (t.table[i][j] == '*')
				{
					comi = i;
					comj = j;
					enough = 1;
				}
			}
		}
	}
	enough = 0;


	t.table[comi][comj] = computerplayer.computerplayersign;

	return 1;
}