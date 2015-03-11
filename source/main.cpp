#include "AIE.h"
#include <iostream>
#include <string>
#include <fstream>
#include "SteeringBehavior.h"

using namespace std;


int main( int argc, char* argv[] )
{	
	//initialize screen settings
	Initialise(720, 720, false, "stuff");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	Tank p1;
	Seek enemySteer;

	enemySteer.getForce(p1.position);

	p1.id = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
	p1.position = { 720 / 2, 720 / 2 };
	p1.x = 720 / 2;
	p1.y = 720 / 2;

	vec2 *p_p1 = &(p1.position);

	//	trying to move sprite with vector FIX
	//MoveSprite(p1.id, p_p1);

	float velocity = 100;

    //***********************Game Loop************************
	do
	{
		ClearScreen();

		float fDeltaT = GetDeltaTime();

		DrawSprite(p1.id);
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
	
		MoveSprite(p1.id, p1.x, p1.y);
	} while(FrameworkUpdate() == false);
	//*******************************************************
		

    Shutdown();

    return 0;
}
