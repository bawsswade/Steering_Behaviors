#ifndef _SB_H_
#define _SB_H

#include "Tank.h"
#include <time.h>
#include <iostream>
#include <vector>
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

class Flocking : public SteeringBehavior
{
public:
	Flocking(){};
	Flocking(int num);

	std::vector<AITank*> tankList;

	vec2 getForce(AITank* target, AITank* owner);
	void GetNeighborCount(AITank* leader, AITank *p_TankList[]);
};

class Allignment : public Flocking
{
public:
	Allignment(){};

	vec2 flockVelocity;
	int neighbors;
	float allignRadius = 100.0f;

	vec2 getForce(AITank* target, AITank* owner);
	void GetNeighborCount(AITank* leader, AITank *p_TankList[]);
};

class Cohesion : public Flocking
{
public:
	Cohesion(){};

	vec2 flockPos;
	int neighbors;
	float cohRadius = 400.0f;

	vec2 getForce(AITank* target, AITank* owner);
	void GetNeighborCount(AITank* leader, AITank *p_TankList[]);
};

#endif