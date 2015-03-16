#include "AIE.h"
#include <iostream>
#include <string>
#include <fstream>
#include "SteeringBehavior.h"
#include "Tank.h"

using namespace std;

int main( int argc, char* argv[] )
{	
	//initialize screen settings
	Initialise(720, 720, false, "stuff");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	float deltaTime = GetDeltaTime();

	//	behavior pointers to different behaviors
	AITank p1;
	AITank p2;
	SteeringBehavior* p_seek = new Seek;	//	behavior pointer to seek
	vec2 move;
	
	//enemySteer.getForce(p1.position);

	p1.id = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
	p1.position = { 720 / 2, 720 / 2 };
	p1.x = 720 / 2;
	p1.y = 720 / 2;

	p2.id = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
	p2.position = { 720 / 4, 720 / 4 };
	p2.x = 720 / 4;
	p2.y = 720 / 4;

	float velocity = 100;

    //***********************Game Loop************************
	do
	{
		ClearScreen();

		float fDeltaT = GetDeltaTime();

		DrawSprite(p1.id);
		DrawSprite(p2.id);
		if (IsKeyDown('A'))
		{
			p1.x -= fDeltaT * velocity;
		}
		if (IsKeyDown('W'))
		{
			p1.y += fDeltaT * velocity;
		}
		if (IsKeyDown('D'))
		{
			p1.x += fDeltaT * velocity;
		}
		if (IsKeyDown('S'))
		{
			p1.y -= fDeltaT * velocity;
		}
	
		move = p_seek->getForce(p1, p2);
		//p_seek->getForce(p1, p2) * deltaTime;
		//vec2 *p_move = &move;
		p2.Update(deltaTime, move);
		MoveSprite(p2.id, p2.x, p2.y);
		//MoveSprite(p2.id, p_move);
		//MoveSprite()
		//MoveSprite(p2.id, p2.x, p2.y);
		MoveSprite(p1.id, p1.x, p1.y);

		cout << p2.position[0] << ", " << p2.position[1] << endl;

	} while(FrameworkUpdate() == false);
	//*******************************************************
		

    Shutdown();

    return 0;
}
