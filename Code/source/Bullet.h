#pragma once
#include "Decl.h"

/* Declares Bullet functions and vars*/

class Player;

class Bullet
{
		
	int m_w, m_h;		

	float m_speed;
	unsigned m_sprite;

	GameState *e_gs;	

public:

	Bullet(GameState *a_gs, unsigned a_sprite,
		float a_x, float a_y, int a_w, int a_h,
		float a_speed);
	float m_x, m_y;	
	void Update(float a_dt);
	void Draw();
	bool IsActive();	// Whether or not this bullet needs to be deleted

	bool Collides(const Player *p);
};