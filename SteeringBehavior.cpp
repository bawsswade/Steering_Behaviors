#include "SteeringBehavior.h"

vec2 Seek::getForce(AITank* target, AITank* owner)
{
	//	get direction to target and normalize
	vec2 targetVelocity = glm::normalize((target->position - owner->position));
	targetVelocity *= owner->maxVelocity;	//	resize to match velocity

	//	where to point so not immediately to target
	vec2 steering = targetVelocity - owner->velocity;

	//	making sure ai doesnt go over max velocity
	if (steering[0] > owner->MAX_FORCE[0])
		steering[0] = owner->MAX_FORCE[0];
	if (steering[1] > owner->MAX_FORCE[1])
		steering[1] = owner->MAX_FORCE[1];
	if (steering[0] < owner->nMAX_FORCE[0])
		steering[0] = owner->nMAX_FORCE[0];
	if (steering[1] < owner->nMAX_FORCE[1])
		steering[1] = owner->nMAX_FORCE[1];

	owner->velocity += steering;

	if (owner->velocity.x > owner->maxVelocity.x)
		owner->velocity.x = owner->maxVelocity.x;
	if (owner->velocity.y > owner->maxVelocity.y)
		owner->velocity.y = owner->maxVelocity.y;


	return steering;
}

vec2 Flee::getForce(AITank* target, AITank* owner)
{
	vec2 targetVelocity = glm::normalize((owner->position - target->position));
	targetVelocity *= owner->maxVelocity;

	vec2 steering = targetVelocity - owner->velocity;

	//	making sure ai doesnt go over max velocity
	if (steering[0] > owner->MAX_FORCE[0])
		steering[0] = owner->MAX_FORCE[0];
	if (steering[1] > owner->MAX_FORCE[1])
		steering[1] = owner->MAX_FORCE[1];
	if (steering[0] < owner->nMAX_FORCE[0])
		steering[0] = owner->nMAX_FORCE[0];
	if (steering[1] < owner->nMAX_FORCE[1])
		steering[1] = owner->nMAX_FORCE[1];

	owner->velocity += steering;

	if (owner->velocity.x > owner->maxVelocity.x)
		owner->velocity.x = owner->maxVelocity.x;
	if (owner->velocity.y > owner->maxVelocity.y)
		owner->velocity.y = owner->maxVelocity.y;


	return steering;
}

vec2 Wander::getForce(AITank* p, AITank* owner)
{
	//	set circle distance
	vec2 wanderRad = normalize(owner->velocity);
	wanderRad *= CIRCLE_DIST;

	//	calc random jitter vec
	vec2 jitterVec;
	int num = rand() % jitter;
	num -= (jitter / 2);
	jitterVec.x = num;
	num = rand() % jitter;
	num -= (jitter / 2);
	jitterVec.y = num;

	//	add jitter to circlevec
	//circleTarget += jitterVec; 
	//	add jitter to normalized vector
	circleTarget = normalize(circleTarget) + jitterVec;
	assert((float)circleTarget.x);
	//	scale to radius
	//circleTarget *= CIRCLE_RADIUS;

	//	seek circleTarget
	vec2 targetVelocity = circleTarget * owner->maxVelocity;
	vec2 steering = targetVelocity - owner->velocity;
	//	making sure ai doesnt go over max velocity
	if (steering[0] > owner->MAX_FORCE[0])
		steering[0] = owner->MAX_FORCE[0];
	if (steering[1] > owner->MAX_FORCE[1])
		steering[1] = owner->MAX_FORCE[1];
	if (steering[0] < owner->nMAX_FORCE[0])
		steering[0] = owner->nMAX_FORCE[0];
	if (steering[1] < owner->nMAX_FORCE[1])
		steering[1] = owner->nMAX_FORCE[1];
	owner->velocity += steering;
	//cout << this->circleTarget.x << ", " << this->circleTarget.y << endl;
	if (owner->velocity.x > owner->maxVelocity.x)
		owner->velocity.x = owner->maxVelocity.x;
	if (owner->velocity.y > owner->maxVelocity.y)
		owner->velocity.y = owner->maxVelocity.y;

	//vec2 targetPos = normalize(circleTarget + wanderRad);
	//	make starting vector = new vector
	//owner->velocity = targetPos;

	//cout << circleTarget.x << ", " << circleTarget.y << endl;

	return{ 0, 0 };
}

void Wander::Reset(AITank *owner)
{
	owner->position = { 720 / 2, 720 / 2 };
	owner->velocity = { 1, 0 };
	//this->circleTarget = { CIRCLE_RADIUS, 0 };
}