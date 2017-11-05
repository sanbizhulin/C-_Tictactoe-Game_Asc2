#ifndef _PLAYER_H
#define _PLAYER_H

#include<iostream>
#include<string.h>

using namespace std;

class Player
{
private:
	char *name;
	char *side;
public:
	Player();
	~Player();
	Player(char *inputname);//receive name
	void printnameof(void);//output name
	char* outputside(char* sidename);
};
#endif