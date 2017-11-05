#include"table.h"
#include "humanplayer.h"
#include "player.h"

Table::Table()
{
   set_turn(1);
}

Table::~Table()
{
  //empty
}

int Table::get_human_choose_again()
{
	return human_choose_again;
}

void Table::set_human_choose_again(int number)
{
	human_choose_again = number;
}

int Table::get_win()
{
	return win;
}

void  Table::set_win(int number)
{
	win = number;
}

int Table::get_turn()
{
	return turn;
}

void Table::set_turn(int number)
{
	turn = number;

}

void Table::table_initialize()//This function only for initialize the table[3][3]
{
	int i, j;
	for (i = 0; i <= 2; i++)
	for (j = 0; j <= 2; j++)
	{
		table[i][j] = '*';
	}
}
void Table::table_refresh()//print again the table with new sign of players
{
	int i, j;
	for (i = 0; i <= 2; i++)
	for (j = 0; j <= 2; j++)
	{

		cout << table[i][j] << " ";
		if (j == 2)
			cout << endl;
	}
}

int Table::check_win(Table &t, char symbol)//This fuction not only can check if humanplayer wins, but also it can check if computerplayer wins,depending on what sign this function recieves
{
	for (int i = 0; i <= 2; i++)//check row
	{
		if (t.table[i][0] == symbol&&t.table[i][1] == symbol&&t.table[i][2] == symbol)
		{
			win = 1;
			break;
		}
	}

	if (win == 0)
	{
		for (int j = 0; j <= 2; j++)//check col
		{
			if (t.table[0][j] == symbol&&t.table[1][j] == symbol&&t.table[2][j] == symbol)
			{
				win = 1;
				break;
			}
		}
	}

	if (win == 0)
	{
		if (t.table[0][0] == symbol&&t.table[1][1] == symbol&&t.table[2][2] == symbol)//check diagonal
		{
			win = 1;
		}
	}
	if (win == 0)
	{
		if (t.table[0][2] == symbol&&t.table[1][1] == symbol&&t.table[2][0] == symbol)//check other diagonal
		{
			win = 1;
		}
	}

	return win;
}