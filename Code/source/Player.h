#pragma once
#include "Decl.h"

/*declares Player function and Variables*/
class Player
{
	 // Position
	int m_w, m_h; // Dimensions

	float m_speed;
	unsigned m_sprite;
	
	GameState *e_gs;

	float m_fDelay, m_fTimer; // Firing controls
	float m_fSpeed;

	int m_w2; // half width
	int m_pad; // For boundary collision.

	
	

	char m_up, m_down, m_left, m_right, m_fire , m_ind;

public:

	int m_boundary_left;
	int m_boundary_right;
	float m_x, m_y;

	Player(GameState *a_gs, unsigned a_sprite,
		   int a_w, int a_h,
		   float a_speed, float a_fDelay, char a_u, char a_d, char a_l, char a_r, char a_f, float a_b_l, float a_b_r);
	
	
	void Update(float a_dt);
	
	void Scoring();
	
	void Draw();

	
	void Fire();
};