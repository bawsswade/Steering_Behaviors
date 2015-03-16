#include "Tank.h"

void AITank::Update(float vel, vec2 move)
{
	this->position += (move * vel);
	//this->position *= vel;
	this->x += (move[0] * vel * 5);
	//this->x *= vel;
	this->y += (move[1]* vel * 5);
	//this->y *= vel;
}