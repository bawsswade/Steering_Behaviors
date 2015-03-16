#include "SteeringBehavior.h"

vec2 Seek::getForce(AITank target, AITank owner)
{
	owner.position = { owner.x, owner.y };
	target.position = { target.x, target.y };
	vec2 targetVelocity = glm::normalize((target.position - owner.position)) * owner.maxVelocity;
	vec2 steering = targetVelocity - owner.velocity;

	//	making sure ai doesnt go over max velocity
	if (steering[0] > owner.maxVelocity[0])
		steering[0] = owner.maxVelocity[0];
	if (steering[1] > owner.maxVelocity[1])
		steering[1] = owner.maxVelocity[1];

	return steering;
	//return (force - owner.position);
}
