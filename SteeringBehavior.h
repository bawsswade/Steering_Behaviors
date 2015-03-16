#ifndef _SB_H_
#define _SB_H

#include "Tank.h"

class SteeringBehavior
{
public:
	SteeringBehavior(){};
	//AITank owner;	//	behavior's AI
	virtual vec2 getForce(AITank target, AITank owner){ return{ 0, 0 }; };
};

class Seek : public SteeringBehavior
{
public: 
	Seek(){};
	//AITank target;

	vec2 getForce(AITank target, AITank owner);
};

#endif