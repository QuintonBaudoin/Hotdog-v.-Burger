#include "Bullet.h"
#include "GameState.h"
#include "Player.h"


/*Creates Bullets properties*/
Bullet::Bullet(GameState *a_gs, unsigned a_sprite,
	float a_x, float a_y, int a_w, int a_h,
	float a_speed)
{
	e_gs = a_gs;
	m_speed = a_speed;
	m_x = a_x;
	m_y = a_y;
	m_w = a_w;
	m_h = a_h;
	m_sprite = a_sprite;
}
/* Bullets update*/
void Bullet::Update(float a_dt)
{
	m_y += m_speed * a_dt;
	//
	if (m_y > g_h)
	{
		if (m_x > gv_gScreenMid)
			m_x -= gv_gScreenLeft;
		else m_x += gv_gScreenLeft;
		m_speed *= -1;
		m_y = g_h;
	}



}




/*Draws bullet*/

void Bullet::Draw()
{
	MoveSprite(m_sprite, m_x, m_y);
	DrawSprite(m_sprite);
}

/* Checks to see if its active*/

bool Bullet::IsActive()
{
	return m_y > 0;
}
 

/*  Checks to see if there is a collision between a bullet and a player.    It checks to see how close the bullet is to the player and if it gets close to the player it is consisdered a colide*/

bool Bullet::Collides(const Player *p)
{
	return (p->m_x - m_x) * (p->m_x - m_x) + (p->m_y - m_y) * (p->m_y - m_y) < 100 && m_speed < 0;
}