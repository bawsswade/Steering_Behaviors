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
	////	calc circle center
	//vec2 circleCenter;	//	same direction as objects direction
	//owner.position;
	//circleCenter = owner.velocity;
	//normalize(circleCenter);
	////	scale
	//circleCenter.x *= CIRCLE_DIST;
	//circleCenter.y *= CIRCLE_DIST;

	////	calc displacement force
	//vec2 displacement = { 0, -1 };	//	radius of circle
	//displacement.x *= CIRCLE_RAD;
	//displacement.y *= CIRCLE_RAD;

	////	randonly change the vector direction by changing angle
	//int len = displacement.length();
	//displacement.x = cos(wanderAngle) * len;
	//displacement.y = sin(wanderAngle) * len;

	////	change wander angle for next frame
	//srand(time(NULL));
	//wanderAngle = rand() % wanderChange;

	////	calc wander force
	//return (circleCenter + displacement);


	//	set circle distance
	vec2 wanderRad = normalize(owner->velocity);
	wanderRad *= CIRCLE_DIST;

	////	make circle with radius 
	//vec2 circPos = owner->position + wanderRad;
	////	set starting vector
	//circleTarget -= circPos;

	//	add rand vector to starting vector (jitter)
	vec2 jitterVec;
	//srand(time(NULL));
	int num = rand() % jitter;
	//num -= (jitter / 2);
	jitterVec.x = num;
	srand(time(NULL));
	num = rand() % jitter;
	//num -= (jitter / 2);
	jitterVec.y = num;

	//circleTarget = normalize(circleTarget);
	circleTarget += jitterVec; 
	//	normalize added vector
	
	circleTarget = normalize(circleTarget);
	circleTarget *= CIRCLE_RADIUS;

	//vec2 r = normalize(circleTarget);
	//	make starting vector = new vector
	owner->velocity =normalize( circleTarget + wanderRad);
	//normalize(owner->velocity);

	return{ 0, 0 };
}