#include "GameState.h"
#include "Player.h"
#include "Assets.h"
#include "Bullet.h"

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "ScoreBuffer.h"
using namespace std;;

int GameState::GetPadding() { return m_padding; }

/*

	Manages how the game runs.

*/






/*
		Starts game by creating 2 players and bullet array
*/

GameState::GameState(int a_padding, Assets *a_assets)
{
	score_1 = 0;
	score_2 = 0;
	win_1 = 0;
	win_2 = 0;

	m_padding = a_padding;
	e_assets  = a_assets;

	m_player = new Player(this, e_assets->Get(ePlayer), 80, 80, 150, .25f, 'I', 'K', 'J', 'L', ';', gv_gScreenMid, gv_gScreenRight);

	m_hotdog = new Player(this, e_assets->Get(eHotDog), 80, 80, 150, .25f, 'W', 'S', 'A', 'D', 'F', gv_gScreenLeft, gv_gScreenMid);

	for (int i = 0; i < g_maxBullets; ++i)
		m_bullets[i] = nullptr;
}


/*
	Updates game

*/



void GameState::Update(float a_dt)
{

	/*If players exists it uses the Update Player functions*/
	if (m_player || m_hotdog)
	{
		m_player->Update(a_dt);
		m_hotdog->Update(a_dt);
	}


	/* Manages bullets */
	for (int i = 0; i < g_maxBullets; ++i)

		/*If bullets exist updates them using Bullet update functions*/
		if (m_bullets[i])
		{
			m_bullets[i]->Update(a_dt);

			/*
			Checks for collisions. If one exists adds score to player that was not hit. If score hits 10 resets scores and adds a win to files
			*/

			if (m_bullets[i]->Collides(m_player))
			{	

				delete m_bullets[i];
				if (score_1 < 10)score_1++;
				else {
					
					ScoreData t = { score_2, "Hotdog Won!" };
					ScoreBuffer::addScore(t);
					score_1 = 0; score_2 = 0; win_1++;
				}
				m_bullets[i] = nullptr;
				
			}
			else if (m_bullets[i]->Collides(m_hotdog))
			{


				
				if (score_2 < 10)score_2++;
				else {
					
					ScoreData t = { score_1, "Burger Won!" };
					ScoreBuffer::addScore(t);
					score_1 = 0; score_2 = 0; win_2++;
				}
				delete m_bullets[i];
				m_bullets[i] = nullptr;
			}
		}


	/* calls for Draws functions for the sprites and draws the scores at the bottom of the screan*/
}
void GameState::Draw()
{	//Scorings
	{
		char output[16] = "Score: ";	
		char c_score[8];				
		itoa(score_1, c_score, 10);     
		strcat_s(output, 16, c_score);	
		DrawString(output, 50, 50);		
	}
	{
		char output[16] = "Score: ";	
		char c_score[8];				
		itoa(score_2, c_score, 10);     
		strcat_s(output, 16, c_score);	
		DrawString(output, 840, 50);		
	}
	// Winnings
	{
			char output[16] = "Wins ";	
			char c_score[8];				
			itoa(win_1, c_score, 10);   
			strcat_s(output, 16, c_score);	
			DrawString(output, 50, 100);	 
	}

	{
			char output[16] = "Wins ";		
			char c_score[8];				
			itoa(win_2, c_score, 10);		
			strcat_s(output, 16, c_score);		
			DrawString(output, 840, 100);		
	}


	/*Draws players if they exist*/
	if (m_player || m_hotdog){ m_player->Draw();  m_hotdog->Draw(); }

	for (int i = 0; i < g_maxBullets; ++i)

		/*Draws Bullets if they exist*/
	if (m_bullets[i])
	{
		m_bullets[i]->Draw();
	}
}

void GameState::SpawnBullet(int a_x, int a_y, float a_speed)
{
	// This is the hard part.


	// Loop through each bullet pointer:
		// IF a pointer is NULL:
			// Create a new Bullet

		// If the point isn't NULL:
			// check to see if it is Active (see bullet.h)
				// if it is, delete the bullet
				// And then create a new bullet

	for (int i = 0; i < g_maxBullets; ++i)
		if (!m_bullets[i] || !m_bullets[i]->IsActive()) //Checks to see if bullets are active. Meaning exist and sets to true if it is and false if it isnt
		{
		if (m_bullets[i] && !m_bullets[i]->IsActive()) // If the bullet is not active and deletes it to make room for a new one.
		{
			delete m_bullets[i];
		}

		/*Creates the bullet(s)*/
		m_bullets[i] = new Bullet(this, e_assets->Get(eShot), a_x, a_y, 10, 14, a_speed);
		return;
		}
}

GameState::~GameState()
{
	delete m_player;
}