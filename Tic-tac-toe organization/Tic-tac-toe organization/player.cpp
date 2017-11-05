#include"player.h"
#include <string.h>

Player::Player()
{
	//empty
}

Player::~Player()
{
 //empty
}

Player::Player(char *inputname)//receive player's name and give it to the value name
{
	name = new char[strlen(inputname) + 1];
	strcpy(name, inputname);
}

void Player::printnameof()
{
	cout << name << endl;
}

char* Player::outputside(char *sidename)//print which side the player is in
{
	side = new char[strlen(sidename) + 1];
	strcpy(side, sidename);
	return side;
}
