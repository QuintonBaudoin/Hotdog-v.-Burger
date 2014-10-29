#include <string>
#include <cmath>
#include <time.h>
#include <assert.h>
#if !defined(OSX)
	#include <crtdbg.h>
#endif
#include <iostream>
#include <list>
#include <string>


#include "Decl.h"
#include "GameState.h"
#include "Assets.h"
#include "Player.h"
#include "ScoreBuffer.h"

/*	
				Hotdog V. Burger
				14/10/2014
				Quinton Baudoin

			|------	 |^\	/^|	 |
			|		 |  \  /  |	 |
			|----	 |	 \/	  |	 |
			|		 |		  |	 |
			|		 |		  |	 |
			|ree	 |y		  |	 |______ife
		
*/






int g_State = eMenu;
int g_Last = eMenu;
int main(int argc, char* argv[])
{
	// Initialises screen and colors background
	Initialise(g_w, g_h, false, "HotDog v Burger");
	SetBackgroundColour(SColour(0x00, 0x00, 0x00, 0xFF));
	
	ScoreBuffer::load();

	Assets *assets = new Assets;

	assets->LoadSprite("./images/burgervan.png",				80, 80, ePlayer);
	assets->LoadSprite("./images/PickleBullets.png",			40, 40, eShot);
	

	assets->LoadSprite("./images/hotdogtruck.png",				80, 80, eHotDog);

	GameState *myGame = new GameState(20, assets);

	bool is_e_key_down = false;
	bool is_q_key_down = false;	do
	{
		ClearScreen();
		float dt = GetDeltaTime();

		switch (g_State)
		{

		case eMenu:

			
			if (!IsKeyDown('Q') && is_q_key_down){ g_State = ePlay; g_Last = g_State; }
			is_q_key_down = IsKeyDown('Q');
			
			if (!IsKeyDown('E') && is_e_key_down) g_State = eRecords;			
			is_e_key_down = IsKeyDown('E');

			if (IsKeyDown('P')) g_State = eClose;
			

			DrawString("Press  Q to start.", gv_gScreenLeft + 150, g_w / 2 - 10);
			DrawString("Press  E to see records.", gv_gScreenLeft + 130, g_w / 2 -35);
			DrawString("Press  P close the  game.", gv_gScreenLeft - 80 , g_w / 2 - 60);
			

			

			break;



		case eRecords:
			ScoreBuffer::draw(0,g_h);

			if (IsKeyDown('P')) g_State = eClose;
			

			if (!IsKeyDown('E') && is_e_key_down) g_State = g_Last;
			is_e_key_down = IsKeyDown('E');
							
			
		break;

		case ePlay:

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\/\/
			DrawLine(gv_gScreenMid, 0, gv_gScreenMid, g_h, SColour(0x00, 0xFC, 0x00, 0xFF));  //\/\/	
			DrawLine(gv_gScreenLeft, 0, gv_gScreenLeft, g_h, SColour(0x00, 0xFC, 0x00, 0xFF)); //\/\/
			DrawLine(gv_gScreenRight, 0, gv_gScreenRight, g_h, SColour(0x00, 0xFC, 0x00, 0xFF));//\/\/   
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////\/\/
			if (!IsKeyDown('E') && is_e_key_down) g_State = eRecords;
			is_e_key_down = IsKeyDown('E');
			if (IsKeyDown('P')) g_State = eClose;




			if (!IsKeyDown('Q') && is_q_key_down){ g_State = eMenu; g_Last = g_State; }
			is_q_key_down = IsKeyDown('Q');
			/*if (g_h < 1001)
				g_h++;

			if (g_h < 500)
				g_h--;*/



			myGame->Update(dt);
			myGame->Draw();

			

			break;
		}
	} while (FrameworkUpdate()== false && g_State != eClose); //  == true


	



		delete myGame;
		//delete assets;

		ScoreBuffer::save();
	
	Shutdown();
	return 0;
}
