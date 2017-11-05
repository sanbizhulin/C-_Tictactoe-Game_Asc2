#include"table.h"
#include "player.h"
#include "humanplayer.h"
#include "computerplayer.h"
#include "game.h"
#include "pawn.h"
#include "table.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

Game::Game()
{
	//empty
}

Game::~Game()
{
   //empty
}

void Game::set_human_win(bool value)
{
	human_win = value;
}

bool Game::get_human_win()
{
	return human_win;

}

void Game::set_round(int number)
{
	round = number;
}

int Game::get_round()
{
	return round;
}

void Game::round_increase(int number)
{
	round = number;
	round++;
}

int Game::display(Table &t, HumanPlayer &humanplayer, ComputerPlayer &computerplayer)//display some basic information and the new table after changing
{
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Round:" << get_round() << "    " << endl;
	cout << "The humanplayer's name:";
	humanplayer.printnameof();
	cout << "The humanplayer score:   " << humanplayer.get_humanpoint()<< "              " << endl;
	cout << "The computerplayer score:" << computerplayer.get_computerpoint() << "        " << endl;
	cout << "The humanplayer uses" << humanplayer.get_humanplayersign() << "              " << endl;
	cout << "The computerplayer uses" << computerplayer.get_computerplayersign()<< "     " << endl;
	cout << "-------------------------------------------------------------------" << endl;

	t.table_refresh();
	return 0;
}

void Game::fiverounds(Table &t, HumanPlayer &humanplayer, ComputerPlayer &computerplayer, Pawn &pawn)//this function controls the game of five rounds
{

	while (get_round() <= 4)
	{
		system("cls");
		pawn.set_emptypawn(9);
		t.set_win(0);
		t.table_initialize();//When a new round starts,the whole table must be initialized with '*'
		display(t, humanplayer, computerplayer);

		if (get_human_win() == false) //if humanplayer lose in last time round
		{
			t.set_turn(1);//the next round the humanplayer will add his sign firstly
		}
		if (get_human_win() == true)//if computerplayer lose in last time round 
		{
			t.set_turn(0);
		}//the next round the computerplayer will add its sign firstly

		cout << "There is a new round" << endl;

		while (t.get_win()==0)
		{

			if ( t.get_turn()==1)//humanplayer add his sign in a pawn
			{
				t.set_human_choose_again(0);
				//t.human_choose_again = 0 means that humanplayer needn't to choose a pawn once more at the same step
				cout << "Row:";
				humanplayer.set_human_row();
				cout << "Col:";
				humanplayer.set_human_col();
				if (t.table[humanplayer.get_human_row()][humanplayer.get_human_col()] == '*')
				{
					humanplayer.humanplayerchoosepawn(humanplayer.get_human_row(), humanplayer.get_human_col(), t.table, humanplayer.get_humanplayersign());
					pawn.emptypawn_decrease(pawn.get_emptypawn());
				}
				else
				{
					t.set_human_choose_again(1);
					//t.human_choose_again = 1 means that the humanplayer need to choose another pawn to add his sign
					cout << "The pawn which you choose already has a sign, please choose another pawn(press  any key to continue)" << endl;
					char stop = '?';
					cin >> stop;
				}
				system("cls");
				display(t, humanplayer, computerplayer);

				if (t.check_win(t, humanplayer.get_humanplayersign()) == 1)//check that if the humanplayer have already wins
				{
					humanplayer.humanpoint_increase(humanplayer.get_humanpoint());
					round_increase(get_round());
					set_human_win(true);
					cout << "The winner is the humanplayer" << endl;
					cout << "press any key to start a new round" << endl;
					char start = '?';
					cin >> start;
					break;
				}
			}



			if (t.get_turn()==0)//computerplayer add its sign in a pawn
			{
				system("cls");
				computerplayer.computerplayerchoosepawn(t, humanplayer, computerplayer);
				pawn.emptypawn_decrease(pawn.get_emptypawn());
				display(t, humanplayer, computerplayer);
				if (t.check_win(t, computerplayer.get_computerplayersign()) == 1)//check that if the computerplayer have already wins
				{
					computerplayer.computerpoint_increase(computerplayer.get_computerpoint());
					round_increase(get_round());
					set_human_win(false);
					cout << "The winner is the computerplayer" << endl;
					cout << "press any key to start a new round" << endl;
					char start = '?';
					cin >> start;
					break;
				}
			}


			//the following part check if this round is a draw
			if (pawn.get_emptypawn() == 0 && t.check_win(t, humanplayer.get_humanplayersign())== 0 && t.check_win(t, computerplayer.get_computerplayersign()) == 0)
			{
				cout << "draw" << endl;
				round_increase(get_round());
				t.set_win(1);//regard it as someone wins although actually no one wins
				cout << "press any key to start a new round" << endl;
				char stop = '?';
				cin >> stop;
			}


			change_turn(t);//change the turn between humanplayer and computerplayer
		}
	}
}

void Game::change_turn(Table &t)//change turn between humanplayer and computerplayer in the same round
{
	if (t.get_human_choose_again()== 0)
	{
		if (t.get_turn()==1)
		{
			t.set_turn(0);
		}
		else
		{
			t.set_turn(1);
		}
	}
	if (t.get_human_choose_again()== 1)//if the humanplayer need to add his sign once more, set the turn to be 1
	{
		t.set_turn(1);
	}

}

void Game::last_winner(HumanPlayer &humanplayer, ComputerPlayer &computerplayer)//judge points of humanplayer and computerplayer to know who is the last winner
{
	
	if (humanplayer.get_humanpoint()>computerplayer.get_computerpoint())
	{
		system("cls");
		cout << "The ultima winner is";
		humanplayer.printnameof();
		cout << endl<<"Press any key to finish this game ";
		char pause='?';
		cin >> pause;
	}

	else if (humanplayer.get_humanpoint()<computerplayer.get_computerpoint())
	{
		system("cls");
		cout << "The ultima winner is computerplayer" << endl;
		cout << "Press any key to finish this game ";
		char pause = '?';
		cin >> pause;
	}
	else
	{
		system("cls");
		cout << "Draw" << endl;
		cout << "Press any key to finish this game ";
		char pause = '?';
		cin >> pause;

	}

}

int Game::run()//define objects and initialize some values
{
	system("color 5E");//number means the background color,capital letter means foreground color 7ÊÇ»ÒÉ«
	Table t;
	Pawn  pawn;
	ComputerPlayer computerplayer;
	HumanPlayer humanplayer("ZHOU Yi");//make the "humanplayer" to be the name of humanplayer
	cout << humanplayer.outputside("Side:Humanplayer") << endl;//print the side of humanplayer
	cout << "The humanplayer's name is :";
	humanplayer.printnameof();//print the name of humanplayer
	cout << "The humanplayer uses(X/O):";
	humanplayer.set_humanplayersign();
	cout << computerplayer.outputside("Side:Computerplayer") << endl;
	computerplayer.computerplayerchoosesign(humanplayer.get_humanplayersign());

	t.table_initialize();//The first time to initialize the table[3][3] but not print it
	set_round(0);
	set_human_win(false);
	fiverounds(t, humanplayer, computerplayer, pawn);//starts the game of five rounds
	last_winner(humanplayer, computerplayer);

	return 0;
}



