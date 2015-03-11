#include "SteeringBehavior.h"

vec2 SteeingBehavior::getForce(vec2 targetPos)
{
	owner.position = { owner.x, owner.y };
	vec2 force;
	vec2 targetVelocity = glm::normalize((targetPos - owner.position));
	return force = targetVelocity * owner.maxVelocity;
}