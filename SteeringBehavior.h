#ifndef _SB_H_
#define _SB_H

#include "Tank.h"
#include <time.h>
#include <iostream>
using namespace std;

class SteeringBehavior
{
public:
	SteeringBehavior(){};

	virtual vec2 getForce(AITank* target, AITank* owner){ return{ 0, 0 }; };
	void Reset(AITank *owner){};

	virtual void GetNeighborCount(AITank* owner, AITank *p_TankList[]){};
};

class Seek : public SteeringBehavior
{
public: 
	Seek(){};

	vec2 getForce(AITank* target, AITank* owner);
};

class Pursue : public SteeringBehavior
{
public:
	Pursue(){};

	vec2 getForce(AITank* target, AITank* owner);
};

class Flee : public SteeringBehavior
{
public:
	Flee(){};

	vec2 getForce(AITank* target, AITank* owner);
};

class Evade : public SteeringBehavior
{
public:
	Evade(){};

	vec2 getForce(AITank* target, AITank* owner);
};

class Wander : public SteeringBehavior
{
public:
	Wander(){};
	
	vec2 getForce(AITank* target, AITank* owner);

	void Reset(AITank *owner);
};

class Allignment : public SteeringBehavior
{
public:
	Allignment(){};

	vec2 flockVelocity;
	int neighbors;

	vec2 getForce(AITank* target, AITank* owner);
	void GetNeighborCount(AITank* leader, AITank *p_TankList[]);
};


#endif