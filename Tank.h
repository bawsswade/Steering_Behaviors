#ifndef _TANK_H_
#define _TANK_H_

#include "AIE.h"
#include <glm\glm.hpp>
#include <math.h>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

class Tank
{
public:
	Tank(){};
	//mat3 position;
	unsigned int id;
	vec2 position;
	vec2 velocity = { 0.0f, 1.0f };		//	current velocity
	vec2 maxVelocity = { 500.0f, 500.0f };
	const vec2 MAX_FORCE = { .3, .3 };
	const vec2 nMAX_FORCE = { -.3, -.3 };
	//float x, y;
	float speed = 500;

	virtual void Update(float deltaTime, vec2 move){};
	~Tank(){};
};


class AITank : public Tank
{
public:
	
	//SteeringBehavior *behavior;	//	each ai tank has its own seek
	
	void Update(float deltaTime, vec2 move);
};

#endif