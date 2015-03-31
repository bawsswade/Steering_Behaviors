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
		tank->id = i;
		tank->position = { 360 + 1, 360 + 1 };
		tank->id = CreateSprite("./images/circle.png", 20.0f, 20.0f, true);
		tankList.push_back(tank);
	}
}

void Flocking::Update(float deltaT)
{
	std::vector<AITank*>::iterator it;
	it = this->tankList.begin();
	while (it != tankList.end())
	{
		this->GetAllignment();		//	works 
		//this->GetCohesion();		//	works
		this->GetSeperation();		//	think it works

		if ((*it)->position.x > 720 || (*it)->position.x < 0)
			//(*it)->position.x = 360;
			(*it)->velocity.x *= -1;
		if ((*it)->position.y > 720 || (*it)->position.y < 0)
			//(*it)->position.y = 360;
			(*it)->velocity.y *= -1;

		(*it)->Update(deltaT);
		it++;
	}
}

void Flocking::Draw()
{
	std::vector<AITank*>::iterator it;
	it = this->tankList.begin();
	while (it != tankList.end())
	{
		MoveSprite((*it)->id, (*it)->position.x, (*it)->position.y);
		DrawSprite((*it)->id);
		//cout << (*it)->position.x << ", " << (*it)->position.y << endl;
		it++;
	}
}

vec2 Flocking::GetAllignment()
{
	std::vector<AITank*>::iterator it;
	it = this->tankList.begin();
	vec2 temp;
	while (it != tankList.end())
	{
		if ((*it)->allignNeighbCount < 1)
		{
			it++;
			continue;
		}
		temp.x = (*it)->allignTotalVel.x / (*it)->allignNeighbCount;
		temp.y =(*it)->allignTotalVel.y / (*it)->allignNeighbCount;
		vec2 targetVel = temp + (*it)->velocity;
		targetVel.x /= 2;
		targetVel.y /= 2;
		vec2 force = normalize(targetVel);
		force.x *= (*it)->maxVelocity.x;
		force.y *= (*it)->maxVelocity.y;
		vec2 steering = force - (*it)->velocity;

		vec2 weight = { 2, 2 };			// doesnt really wortk well
		steering.x /= weight.x;
		steering.y /= weight.y;

		//	making sure ai doesnt go over max velocity
		if (steering[0] > (*it)->MAX_FORCE[0])
			steering[0] = (*it)->MAX_FORCE[0];
		if (steering[1] > (*it)->MAX_FORCE[1])
			steering[1] = (*it)->MAX_FORCE[1];
		if (steering[0] < (*it)->nMAX_FORCE[0])
			steering[0] = (*it)->nMAX_FORCE[0];
		if (steering[1] < (*it)->nMAX_FORCE[1])
			steering[1] = (*it)->nMAX_FORCE[1];

		(*it)->velocity += steering;

		it++;
	}
	return { 0, 0 };
}

vec2 Flocking::GetCohesion()
{
	std::vector<AITank*>::iterator it;
	it = this->tankList.begin();
	vec2 temp;
	while (it != tankList.end())
	{
		if ((*it)->cohesNeighbCount < 1)
		{
			it++;
			continue;
		}
		temp.x = (*it)->cohesTotalPos.x / (*it)->cohesNeighbCount;
		temp.y = (*it)->cohesTotalPos.y / (*it)->cohesNeighbCount;

		//********************************//
		//	temporary fix: when blah is (0,0), shit gets fucked up
		//********************************//
		vec2 blah = temp - (*it)->position;
		vec2 blah2 = { 0, 0 };
		if (blah == blah2)
			blah = { 1, 1 };
		//********************************//

		vec2 targetVelocity = glm::normalize(blah);
		targetVelocity *= (*it)->maxVelocity;
		vec2 steering = targetVelocity - (*it)->velocity;

		vec2 weight = { 100000, 100000 };
		steering.x /= weight.x;
		steering.y /= weight.y;

		//	making sure ai doesnt go over max velocity
		if (steering[0] > (*it)->MAX_FORCE[0])
			steering[0] = (*it)->MAX_FORCE[0];
		if (steering[1] > (*it)->MAX_FORCE[1])
			steering[1] = (*it)->MAX_FORCE[1];
		if (steering[0] < (*it)->nMAX_FORCE[0])
			steering[0] = (*it)->nMAX_FORCE[0];
		if (steering[1] < (*it)->nMAX_FORCE[1])
			steering[1] = (*it)->nMAX_FORCE[1];

		(*it)->velocity += steering;
		it++;
	}
	return { 0, 0 };
}

vec2 Flocking::GetSeperation()
{
	std::vector<AITank*>::iterator it;
	it = this->tankList.begin();
	vec2 temp;
	while (it != tankList.end())
	{
		if ((*it)->sepNeighbCount < 1)
		{
			it++;
			continue;
		}
		temp.x = (*it)->sepTotalPos.x / (*it)->sepNeighbCount;
		temp.y = (*it)->sepTotalPos.y / (*it)->sepNeighbCount;

		//********************************//
		//	temporary fix: when blah is (0,0), shit gets fucked up
		//********************************//
		vec2 blah = (*it)->position - temp;
		vec2 blah2 = { 0, 0 };
		if (blah == blah2)
			blah = { 1, 1 };
		//********************************//

		vec2 targetVelocity = glm::normalize(blah);
		targetVelocity *= (*it)->maxVelocity;
		vec2 steering = targetVelocity - (*it)->velocity;

		//	making sure ai doesnt go over max velocity
		if (steering[0] > (*it)->MAX_FORCE[0])
			steering[0] = (*it)->MAX_FORCE[0];
		if (steering[1] > (*it)->MAX_FORCE[1])
			steering[1] = (*it)->MAX_FORCE[1];
		if (steering[0] < (*it)->nMAX_FORCE[0])
			steering[0] = (*it)->nMAX_FORCE[0];
		if (steering[1] < (*it)->nMAX_FORCE[1])
			steering[1] = (*it)->nMAX_FORCE[1];

		(*it)->velocity += steering;
		it++;
	}
	return { 0, 0 };
}

void Flocking::GetNeighbors()
{
	std::vector<AITank*>::iterator it;
	it = this->tankList.begin();
	vec2 numAVel, numPos, numSPos;
	int aCount, cCount, sCount;
	//	loop through all tanks
	while (it != tankList.end())
	{
		std::vector<AITank*>::iterator i;
		i = this->tankList.begin();

		numAVel = { 0, 0 };
		numPos = { 0, 0 };
		numSPos = { 0, 0 };
		aCount = 0;
		cCount = 0;
		sCount = 0;

		//	check against all other tanks
		while (i != tankList.end())
		{
			if (it != i)
			{
				//	if in allignment radius, add to total velocity numVel
				if ((sqrt((*it)->position.x * (*it)->position.x + (*i)->position.y * (*i)->position.y)) < (*it)->allignRadius)
				{
					//	add to toatal velocity vec
					numAVel.x += (*i)->velocity.x;
					numAVel.y += (*i)->velocity.y;
					//	increase allignment neighbor count
					aCount++;
				}
				//	if in cohesion radius, add to total position numPos
				if ((sqrt((*it)->position.x * (*it)->position.x + (*i)->position.y * (*i)->position.y)) < (*it)->cohesRadius)
				{
					//	add to total position vec
					numPos.x += (*i)->position.x;
					numPos.y += (*i)->position.y;
					//	increase cohesion neighbor count
					cCount++;
				}
				//	if in seperation radius, add to count++
				if ((sqrt((*it)->position.x * (*it)->position.x + (*i)->position.y * (*i)->position.y)) < (*it)->sepRadius)
				{
					//add to total velocity vec
					numSPos.x += (*i)->position.x;
					numSPos.y += (*i)->position.y;
					//	increase seperation neighbor count
					sCount++;
				}
			}
			i++;
		}
		(*it)->allignTotalVel = numAVel;
		(*it)->cohesTotalPos = numPos;
		(*it)->sepTotalPos = numSPos;
		(*it)->allignNeighbCount = aCount;
		(*it)->cohesNeighbCount = cCount;
		(*it)->sepNeighbCount = sCount;
		it++;
	}
}



//
//vec2 Allignment::getForce(AITank* leader, AITank* owner)
//{
//	/*vec2 v;
//	v.x /= this->neighbors;
//	v.y /= this->neighbors;*/
//
//	if (owner->inAllignCircle)
//	{
//		if (this->flockVelocity.x == 0 || this->flockVelocity.y == 0)
//		{
//			return{ 0, 0 };
//		}
//
//		this->flockVelocity.x /= this->neighbors;
//		this->flockVelocity.y /= this->neighbors;
//		this->flockVelocity = normalize(this->flockVelocity);
//
//		//	************* leader's velocity isn't correct: change in main **************
//		vec2 steering = leader->velocity - this->flockVelocity;
//
//		owner->velocity += steering;
//		//owner->velocity = normalize(owner->velocity);
//
//		if (owner->velocity.x > owner->maxVelocity.x)
//			owner->velocity.x = owner->maxVelocity.x;
//		if (owner->velocity.y > owner->maxVelocity.y)
//			owner->velocity.y = owner->maxVelocity.y;
//	}
//	return{ 0, 0 };
//}
//
//void Allignment::GetNeighborCount(AITank* leader, AITank* p_TankList[])
//{
//	this->flockVelocity = { 0, 0 };
//	int neighborCount = 0;
//	int i = 0;
//	while (i < 10)
//	{
//		vec2 distanceVec;
//		distanceVec = leader->position - p_TankList[i]->position;	
//		distanceVec.x = abs(distanceVec.x);
//		distanceVec.y = abs(distanceVec.y);
//
//		float distance;
//		//	find distance from leader: pythag theorem
//		distance = sqrt((distanceVec.x * distanceVec.x) + (distanceVec.y * distanceVec.y));
//
//		if (distance < this->allignRadius)		//	if in radius
//		{
//			//	add ai's velocity to total velocity
//			this->flockVelocity += p_TankList[i]->velocity;
//			p_TankList[i]->inAllignCircle = true;
//
//			//	increment num of agents in radius
//			neighborCount++;
//		}
//		else
//			p_TankList[i]->inAllignCircle = false;
//		i++;
//	}
//	this->neighbors = neighborCount;
//}
//
//vec2 Cohesion::getForce(AITank* leader, AITank* owner)
//{
//	if (owner->inCohCircle)
//	{
//		if (this->flockPos.x == 0 || this->flockPos.y == 0)
//		{
//			return{ 0, 0 };
//		}
//
//		this->flockPos.x /= this->neighbors;
//		this->flockPos.y /= this->neighbors;
//		//this->flockPos = normalize(this->flockPos);
//
//		if (this->neighbors > 2)
//		{
//			//	************* leader's velocity isn't correct: change in main **************
//			vec2 targetVelocity = normalize(this->flockPos - owner->position);
//			targetVelocity *= owner->maxVelocity;	//	resize to match velocity
//
//			//	where to point so not immediately to target
//			vec2 steering = targetVelocity - owner->velocity;
//
//			owner->velocity += steering;
//			//owner->velocity = normalize(owner->velocity);
//
//			if (owner->velocity.x > owner->maxVelocity.x)
//				owner->velocity.x = owner->maxVelocity.x;
//			if (owner->velocity.y > owner->maxVelocity.y)
//				owner->velocity.y = owner->maxVelocity.y;
//		}
//	}
//	
//	return{ 0, 0 };
//}
//
//void Cohesion::GetNeighborCount(AITank* leader, AITank* p_TankList[])
//{
//	this->flockPos = { 0, 0 };
//	int neighborCount = 0;
//	int i = 0;
//	while (i < 2)
//	{
//		vec2 distanceVec;
//		distanceVec = leader->position - p_TankList[i]->position;
//		distanceVec.x = abs(distanceVec.x);
//		distanceVec.y = abs(distanceVec.y);
//
//		float distance;
//		//	find distance from leader: pythag theorem
//		distance = sqrt((distanceVec.x * distanceVec.x) + (distanceVec.y * distanceVec.y));
//
//		if (distance < this->cohRadius)		//	if in radius
//		{
//			//	add ai's velocity to total velocity
//			this->flockPos += p_TankList[i]->position;
//			p_TankList[i]->inCohCircle = true;
//
//			//	increment num of agents in radius
//			neighborCount++;
//		}
//		else
//			p_TankList[i]->inCohCircle = false;
//		i++;
//	}
//	this->neighbors = neighborCount;
//}