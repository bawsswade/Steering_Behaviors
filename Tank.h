#ifndef _TANK_H_
#define _TANK_H_

//#include "SteeringBehavior.h"
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

class Tank
{
public:
	Tank(){};
	//mat3 position;
	unsigned int id;
	vec2 position;
	float x, y;

	virtual void Update(){};
	~Tank(){};
};


class AITank : public Tank
{
public:
	vec2 velocity;		//	current velocity
	float maxVelocity;
	
	void Update(){};
};

#endif