#ifndef _TANK_H_
#define _TANK_H_

#include "SteeringBehavior.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

class Tank
{
public:
	Tank(){};
	//mat3 position;
	vec2 position;

	virtual void Update();
	~Tank();
};


class AITank : Tank
{
public:
	vec2 velocity;		//	current velocity
	float maxVelocity;
	

	void Update();
};

#endif