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
	Tank()
	{
		this->velocity = { 0.1f, 1.0f };
	};
	//mat3 position;
	unsigned int id;
	vec2 position;
	vec2 velocity = { 1.0f, 0.0f };		//	current velocity
	vec2 maxVelocity = { 100.0f, 100.0f };
	const vec2 MAX_FORCE = { .2, .2 };
	const vec2 nMAX_FORCE = { -.2, -.2 };
	float speed = 50;

	//	for wander
	const int CIRCLE_DIST = 10;
	const int CIRCLE_RADIUS = 100;
	vec2 circleTarget = { CIRCLE_RADIUS, 0 };	//	desired target to follow
	const int jitter = 100;					//	vector off of circle target

	//	for flocking
	//float flockRadius = 100.0f;
	bool inAllignCircle = false;
	bool inCohCircle = false;
	//int neighborhood;

	virtual void Update(float deltaTime, vec2 move){};
	~Tank(){};
};


class AITank : public Tank
{
public:
	AITank()
	{
		this->velocity = { 0.1f, 1.0f };
	};
	//SteeringBehavior *behavior;	//	each ai tank has its own seek
	
	void Update(float deltaTime, vec2 move);
};

#endif