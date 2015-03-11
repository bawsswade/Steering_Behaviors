#include "SteeringBehavior.h"

void SteeingBehavior::getForce(vec2 p1Pos)
{
	float force;
	force = normalize((owner.position - p1Pos)) * owner.maxVelocity;

}