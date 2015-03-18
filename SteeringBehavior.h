#ifndef _SB_H_
#define _SB_H

#include "Tank.h"
#include <time.h>

class SteeringBehavior
{
public:
	SteeringBehavior(){};

	//AITank owner;	//	behavior's AI
	virtual vec2 getForce(AITank* target, AITank* owner){ return{ 0, 0 }; };
};

class Seek : public SteeringBehavior
{
public: 
	Seek(){};

	vec2 getForce(AITank* target, AITank* owner);
};

class Flee : public SteeringBehavior
{
public:
	Flee(){};

	vec2 getForce(AITank* target, AITank* owner);
};

class Wander : public SteeringBehavior
{
public:
	Wander(){};
	/*const int CIRCLE_DIST = 2;
	const int CIRCLE_RAD = 100;
	int wanderAngle = 90;
	int wanderChange = 30;*/

	const int CIRCLE_DIST = 5;
	const int CIRCLE_RADIUS = 50;
	vec2 circleTarget = { CIRCLE_RADIUS, 0 };	//	desired target to follow
	const int jitter = 50;					//	vector off of circle target
	
	vec2 getForce(AITank* target, AITank* owner);
};

#endif