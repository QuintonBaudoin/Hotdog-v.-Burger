#include "Player.h"
#include "GameState.h"


/*When called creats player*/
Player::Player(GameState *a_gs, unsigned a_sprite,
	int a_w, int a_h, float a_speed, float a_fDelay, char a_u, char a_d, char a_l, char a_r, char a_f, float a_b_l, float a_b_r)
{	
	
	
	m_boundary_left = a_b_l;
	m_boundary_right = a_b_r;

	e_gs				= a_gs;
	m_x					= m_boundary_left + (m_boundary_right - m_boundary_left)/2 ;
	m_y					= gv_pScreenBot;

	

	m_w					= a_w;
	m_h					= a_h;
	m_speed				= a_speed;
	m_fSpeed			= 400;
	m_fDelay			= a_fDelay;
	m_sprite			= a_sprite;
	m_fTimer			= 1;
	m_up				= a_u;
	m_down				= a_d;
	m_left				= a_l;
	m_right				= a_r;
	m_fire				= a_f;
	
	


	m_w2 = m_w / 2;

	if (e_gs) m_pad = e_gs->GetPadding();
	else m_pad = 0;
}											

/*Spawns bullets based on m_fTimer and delay*/

void Player::Fire()
{
	if (m_fTimer > m_fDelay)
	{
		m_fTimer = 0;
		e_gs->SpawnBullet(m_x, m_y, m_fSpeed);
	}
} 

/*Updates player*/
void Player::Update(float a_dt)
{
	m_fTimer += a_dt;

	if (IsKeyDown(m_left))		m_x -= m_speed * a_dt;	
	if (IsKeyDown(m_right))		m_x += m_speed * a_dt;
	if (IsKeyDown(m_up))		m_y += m_speed * a_dt;
	if (IsKeyDown(m_down))		m_y -= m_speed * a_dt;
	if (IsKeyDown(m_fire))		Fire();
	
	if (m_x < m_boundary_left	+5) m_x = m_boundary_left	+5;
	if (m_x > m_boundary_right	-5) m_x = m_boundary_right	-5;

	if (m_y		> 		gv_pScreenTop)	m_y = gv_pScreenTop;
	if (m_y		<		gv_pScreenBot) m_y = gv_pScreenBot;
}
/*Draws player*/
void Player::Draw()
{
	MoveSprite(m_sprite,m_x, m_y);
	DrawSprite(m_sprite);
}