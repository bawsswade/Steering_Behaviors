//#include "AIE.h"
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
	const int numAIs = 10;

	//	behavior pointers to different behaviors
	AITank p1;
	AITank *arr_tank[numAIs];
	for (int i = 0; i < numAIs; i++)
	{
		arr_tank[i] = new AITank;
		arr_tank[i]->id = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
		arr_tank[i]->position = { 720 / (i +1), 720 / (i +1)};
		/*arr_tank[i]->x = 720 / (i+1);
		arr_tank[i]->y = 720 / (i+1);*/
	}

	AITank p2;
	SteeringBehavior* p_seek = new Seek;	//	behavior pointer to seek
	SteeringBehavior* p_flee = new Flee;
	SteeringBehavior* p_wander = new Wander;
	vec2 move;

	p1.id = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
	p1.position = { 720 / 2, 720 / 2 };
	/*p1.x = 720 / 2;
	p1.y = 720 / 2;*/

	p2.id = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
	p2.position = { 720 / 4, 720/4 };
	/*p2.x = 720 / 4;
	p2.y = 720 / 4;*/

	float velocity = 500;
	bool SorF = 1;
    //***********************Game Loop************************
	do
	{
		ClearScreen();

		float fDeltaT = GetDeltaTime();

		DrawSprite(p1.id);
		DrawSprite(p2.id);

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
		if (IsKeyDown(GLFW_KEY_LEFT))
		{
			SorF = true;
		}
		if (IsKeyDown(GLFW_KEY_RIGHT))
		{
			SorF = false;
		}

		//	seek behavior
		for (int i = 0; i < numAIs; i++)
		{
			//DrawSprite(arr_tank[i]->id);

			if (SorF)
				move = p_wander->getForce(&p1 ,arr_tank[i]);
				//move = p_seek->getForce(&p1, arr_tank[i]);
			else if (!SorF)
				move = p_flee->getForce(&p1, arr_tank[i]);

			//	update p2 with seek movement
			arr_tank[i]->Update(deltaTime, move);

			//	move shit
			MoveSprite(arr_tank[i]->id, arr_tank[i]->position.x, arr_tank[i]->position.y);
		}

		p_wander->getForce(&p1, &p2);
		//p_seek->getForce(&p1, &p2);
		p2.Update(deltaTime, move);
		MoveSprite(p2.id, p2.position.x, p2.position.y);
		MoveSprite(p1.id, p1.position.x, p1.position.y);

		//cout << p2.position[0] << ", " << p2.position[1] << endl;

	} while(FrameworkUpdate() == false);
	//*******************************************************
		

    Shutdown();

    return 0;
}
