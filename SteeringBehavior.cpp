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

vec2 Pursue::getForce(AITank* target, AITank* owner)
{
	//	get direction to target and normalize
	vec2 targetVelocity = glm::normalize((target->position + target->velocity - owner->position));
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

vec2 Evade::getForce(AITank* target, AITank* owner)
{
	vec2 targetVelocity = glm::normalize((owner->position - target->position + target->velocity));
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
	vec2 red = owner->circleTarget;		// circle target has to be scaled to radius size first

	//	calc random jitter vec from (0,0)
	vec2 jitterVec;
	int num = rand() % owner->jitter;	//	jitter = 10   for now
	num -= (owner->jitter / 2);		//	num = -5 to 5
	jitterVec.x = num;
	num = rand() % owner->jitter;
	num -= (owner->jitter / 2);
	jitterVec.y = num;

	red = red + jitterVec;		//	add 
	red = normalize(red);		//	normalize
	red.x *= owner->CIRCLE_RADIUS;		//	scale to circle radius
	red.y *= owner->CIRCLE_RADIUS;
	owner->circleTarget = red;

	//	create wander radius
	vec2 green = normalize(owner->velocity);	
	green.x *= owner->CIRCLE_RADIUS;
	green.y *= owner->CIRCLE_RADIUS;

	vec2 target = owner->position + red + green;	//	seek position

	//	seek to target
	vec2 targetVelocity = glm::normalize((target - owner->position));
	targetVelocity *= owner->maxVelocity;	//	resize to match velocity

	vec2 steering = targetVelocity - owner->velocity;	//	where to point so not immediately to target

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


	return { 0, 0 };
}

void Wander::Reset(AITank *owner)
{
	owner->position = { 720 / 2, 720 / 2 };
	owner->velocity = { 1, 0 };
	owner->circleTarget = { owner->CIRCLE_RADIUS, 0 };
}






/*************************FLOCKING***************************************/

Flocking::Flocking(int num)
{
	for (int i = 0; i < num; i++)
	{
		AITank* tank = new AITank;
		std::vector<AITank*>::iterator it;
		it = this->tankList.begin();
		it = this->tankList.insert(it, tank);
		it++;
	}
}


vec2 Allignment::getForce(AITank* leader, AITank* owner)
{
	/*vec2 v;
	v.x /= this->neighbors;
	v.y /= this->neighbors;*/

	if (owner->inAllignCircle)
	{
		if (this->flockVelocity.x == 0 || this->flockVelocity.y == 0)
		{
			return{ 0, 0 };
		}

		this->flockVelocity.x /= this->neighbors;
		this->flockVelocity.y /= this->neighbors;
		this->flockVelocity = normalize(this->flockVelocity);

		//	************* leader's velocity isn't correct: change in main **************
		vec2 steering = leader->velocity - this->flockVelocity;

		owner->velocity += steering;
		//owner->velocity = normalize(owner->velocity);

		if (owner->velocity.x > owner->maxVelocity.x)
			owner->velocity.x = owner->maxVelocity.x;
		if (owner->velocity.y > owner->maxVelocity.y)
			owner->velocity.y = owner->maxVelocity.y;
	}
	return{ 0, 0 };
}

void Allignment::GetNeighborCount(AITank* leader, AITank* p_TankList[])
{
	this->flockVelocity = { 0, 0 };
	int neighborCount = 0;
	int i = 0;
	while (i < 10)
	{
		vec2 distanceVec;
		distanceVec = leader->position - p_TankList[i]->position;	
		distanceVec.x = abs(distanceVec.x);
		distanceVec.y = abs(distanceVec.y);

		float distance;
		//	find distance from leader: pythag theorem
		distance = sqrt((distanceVec.x * distanceVec.x) + (distanceVec.y * distanceVec.y));

		if (distance < this->allignRadius)		//	if in radius
		{
			//	add ai's velocity to total velocity
			this->flockVelocity += p_TankList[i]->velocity;
			p_TankList[i]->inAllignCircle = true;

			//	increment num of agents in radius
			neighborCount++;
		}
		else
			p_TankList[i]->inAllignCircle = false;
		i++;
	}
	this->neighbors = neighborCount;
}

vec2 Cohesion::getForce(AITank* leader, AITank* owner)
{
	if (owner->inCohCircle)
	{
		if (this->flockPos.x == 0 || this->flockPos.y == 0)
		{
			return{ 0, 0 };
		}

		this->flockPos.x /= this->neighbors;
		this->flockPos.y /= this->neighbors;
		//this->flockPos = normalize(this->flockPos);

		if (this->neighbors > 2)
		{
			//	************* leader's velocity isn't correct: change in main **************
			vec2 targetVelocity = normalize(this->flockPos - owner->position);
			targetVelocity *= owner->maxVelocity;	//	resize to match velocity

			//	where to point so not immediately to target
			vec2 steering = targetVelocity - owner->velocity;

			owner->velocity += steering;
			//owner->velocity = normalize(owner->velocity);

			if (owner->velocity.x > owner->maxVelocity.x)
				owner->velocity.x = owner->maxVelocity.x;
			if (owner->velocity.y > owner->maxVelocity.y)
				owner->velocity.y = owner->maxVelocity.y;
		}
	}
	
	return{ 0, 0 };
}

void Cohesion::GetNeighborCount(AITank* leader, AITank* p_TankList[])
{
	this->flockPos = { 0, 0 };
	int neighborCount = 0;
	int i = 0;
	while (i < 2)
	{
		vec2 distanceVec;
		distanceVec = leader->position - p_TankList[i]->position;
		distanceVec.x = abs(distanceVec.x);
		distanceVec.y = abs(distanceVec.y);

		float distance;
		//	find distance from leader: pythag theorem
		distance = sqrt((distanceVec.x * distanceVec.x) + (distanceVec.y * distanceVec.y));

		if (distance < this->cohRadius)		//	if in radius
		{
			//	add ai's velocity to total velocity
			this->flockPos += p_TankList[i]->position;
			p_TankList[i]->inCohCircle = true;

			//	increment num of agents in radius
			neighborCount++;
		}
		else
			p_TankList[i]->inCohCircle = false;
		i++;
	}
	this->neighbors = neighborCount;
}