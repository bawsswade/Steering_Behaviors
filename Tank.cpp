#include "Tank.h"
#include <iostream>
#include "glm/gtx/string_cast.hpp"

using std::cout;

void AITank::Update(float vel)
{
	//this->position += (dirMove * vel);

	//std::cout << glm::to_string(dirMove) << "\n";

	this->position.x += (this->velocity.x * vel * speed);
	this->position.y += (this->velocity.y * vel * speed);

	//	trying to rotate as it moves: keeps adding on to curr deg. how to reset?
	/*float deg = atan(this->x, this->y)*(180.0f / 3.1415);
	RotateSprite(this->id, deg);*/
}