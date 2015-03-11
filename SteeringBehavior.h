#ifndef _SB_H_
#define _SB_H

#include "Tank.h"

class SteeingBehavior
{
public:
	AITank owner;	//	behavior's AI

	virtual vec2 getForce(vec2 targetPos);
};

class Seek : SteeingBehavior
{
public: 
	//AITank target;

	vec2 getForce(vec2 targetPos){ vec2 test; return test;};
};

#endif