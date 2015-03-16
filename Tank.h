#ifndef _TANK_H_
#define _TANK_H_

#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>

using namespace glm;

class Tank
{
public:
	Tank(){};
	//mat3 position;
	unsigned int id;
	vec2 position;
	vec2 velocity = { 10.0f, 10.0f };		//	current velocity
	vec2 maxVelocity = { 500.0f, 500.0f };
	float x, y;

	virtual void Update(float deltaTime, vec2 move){};
	~Tank(){};
};


class AITank : public Tank
{
public:
	
	//SteeringBehavior *behavior;	//	each ai tank has its own seek
	
	void Update(float deltaTime, vec2 move);
};

#endif