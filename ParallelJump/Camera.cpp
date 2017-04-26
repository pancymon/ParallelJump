#include"Camera.h"
#include"WorldManager.h"

Camera::Camera():m_view(FloatRect(-500, -200, 500, 500))
{
	pass = false;
}

Camera::Camera(Hero* hero) : m_view(FloatRect(-500, -200, 500, 500))
{
	m_hero = hero;
	m_view.setCenter(m_hero->m_sprite.getPosition());
}


void Camera::Update(Time elapsed)
{
	float hero_Y = m_hero->m_sprite.getPosition().y;
	float m_Y = m_view.getCenter().y;
	if (WorldManager::Instance()->m_GameState==GameState::Fail)
	{
		if (m_Y > hero_Y)
			pass = true;
		if(!pass)
			m_view.move(0, m_hero->m_speed.y * elapsed.asSeconds() * 2);
		else
			m_view.move(0, m_hero->m_speed.y * elapsed.asSeconds() * 0.5);
	}
	else if (hero_Y < m_Y)
		m_view.setCenter(m_view.getCenter().x, hero_Y);//GameManager::Instance()->m_Heros[0]->m_sprite.getPosition());
	//else if(WorldManager::Instance()->m_GameOver)
	//{
	//	m_view.move(0, m_hero->m_speed.y);
	//}
}