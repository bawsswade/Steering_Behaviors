//#include "AIE.h"
#include <iostream>
#include <string>
#include <fstream>
#include "SteeringBehavior.h"
#include "Tank.h"

using namespace std;

const int SCREEN_WIDTH = 720;
const int SCREEN_HEIGHT = 720;

int main( int argc, char* argv[] )
{	
	//initialize screen settings
	Initialise(SCREEN_WIDTH, SCREEN_HEIGHT, false, "stuff");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	float deltaTime = GetDeltaTime();
	//const int numAIs = 1000;

	//	behavior pointers to different behaviors
	AITank p1;
	/*AITank *arr_tank[numAIs];
	for (int i = 0; i < numAIs; i++)
	{
		arr_tank[i] = new AITank;
		arr_tank[i]->id = CreateSprite("./images/circle.png", 20.0f, 20.0f, true);
		arr_tank[i]->position = { 720 / 2 , 720 / 2 };
	}*/

	AITank p2;
	SteeringBehavior* p_seek = new Seek;	//	behavior pointer to seek
	SteeringBehavior* p_flee = new Flee;
	SteeringBehavior* p_wander = new Wander;
	SteeringBehavior* p_pursue = new Pursue;
	SteeringBehavior* p_evade = new Evade;
	SteeringBehavior* p_flock = new Flocking;
	Flocking f(100);
	/*Flocking* p_allign = new Allignment; 
	Flocking* p_cohesion = new Cohesion;*/

	p1.id = CreateSprite("./images/circle.png", 20.0f, 20.0f, true);
	p1.position = { SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2 };
	/*p1.x = 720 / 2;
	p1.y = 720 / 2;*/

	p2.id = CreateSprite("./images/circle.png", 20.0f, 20.0f, true);
	p2.position = { SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4 };
	/*p2.x = 720 / 4;
	p2.y = 720 / 4;*/

	float velocity = 500;
	bool SorF = 1;
	srand(time(NULL));
    //***********************Game Loop************************
	do
	{
		ClearScreen();

		float fDeltaT = GetDeltaTime();

		DrawSprite(p1.id);
		//DrawSprite(p2.id);
		f.Draw();

		if (IsKeyDown('A'))
		{
			p1.position.x -= fDeltaT * velocity;
		}
		if (IsKeyDown('W'))
		{
			p1.position.y += fDeltaT * velocity;
		}
		if (IsKeyDown('D'))
		{
			p1.position.x += fDeltaT * velocity;
		}
		if (IsKeyDown('S'))
		{
			p1.position.y -= fDeltaT * velocity;
		}
		/*p1.velocity.x = p1.position.x - 359.0f;
		p1.velocity.y = p1.position.y - 359.0f;
		p1.velocity = normalize(p1.velocity);*/
		if (IsKeyDown(GLFW_KEY_LEFT))
		{
			SorF = true;
		}
		if (IsKeyDown(GLFW_KEY_RIGHT))
		{
			SorF = false;
		}

		////	behavior
		//for (int i = 0; i < numAIs; i++)
		//{
		//	DrawSprite(arr_tank[i]->id);
		//	p_wander->getForce(&p1, arr_tank[i]);
		//	if (arr_tank[i]->position.x > 720.0f || arr_tank[i]->position.x <= 0.0f ||
		//		arr_tank[i]->position.y > 720.0f || arr_tank[i]->position.y <= 0.0f)
		//	{
		//		arr_tank[i]->velocity.x *= -1;
		//		arr_tank[i]->velocity.y *= -1;
		//	}
		//	arr_tank[i]->Update(deltaTime, move);
		//	//	move shit
		//	MoveSprite(arr_tank[i]->id, arr_tank[i]->position.x, arr_tank[i]->position.y);
		//	//cout << arr_tank[i]->velocity.x << ", " << arr_tank[i]->velocity.y << endl;
		//}

		//p_wander->getForce(&p1, &p2);
		p_seek->getForce(&p1, &p2);
		if (p2.position.x > 720.0f || p2.position.x <= 0 || p2.position.y > 720.0f || p2.position.y <= 0)
		{
			p2.position = { 720 / 2, 720 / 2 };
			p2.velocity = { 1, 0 };
		}

		p2.Update(deltaTime);
		MoveSprite(p2.id, p2.position.x, p2.position.y);
		MoveSprite(p1.id, p1.position.x, p1.position.y);

	} while(FrameworkUpdate() == false);
	//*******************************************************
		

    Shutdown();

    return 0;
}
