#include "AIE.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main( int argc, char* argv[] )
{	
	//initialize screen settings
	Initialise(720, 720, false, "stuff");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));

	unsigned int s1 = CreateSprite("./images/ai.png", 20.0f, 30.0f, true);
	MoveSprite(s1, 720/2, 720 /2);

    //***********************Game Loop************************
	do
	{
		ClearScreen();

		float fDeltaT = GetDeltaTime();

		DrawSprite(s1);
	

	} while(FrameworkUpdate() == false);
	//*******************************************************
		

    Shutdown();

    return 0;
}

