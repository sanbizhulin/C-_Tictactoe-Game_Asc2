#include"pawn.h"
#include "table.h"

Pawn::Pawn()
{
	//empty
}

Pawn::~Pawn()
{
	//empty
}

int Pawn::set_emptypawn(int emptypawn_number)
{
	emptypawn = emptypawn_number;
	return emptypawn;
}

int Pawn::get_emptypawn()
{
	return emptypawn;
}

void Pawn::emptypawn_decrease(int emptypawn_number)
{
	emptypawn = emptypawn_number - 1;
}