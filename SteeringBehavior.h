#ifndef _SB_H_
#define _SB_H

#include "Tank.h"

static class SteeingBehavior
{
public:
	AITank owner;

	virtual void getForce(vec2 p1) = 0;
};

class Seek : SteeingBehavior
{
public:
	AITank target;

	void getForce();
};

#endif