#include <stddef.h>  // defines NULL
#include <cmath>	//defines abs
#include"GameManager.h"
#include"Camera.h"
#include"WorldManager.h"

//GameManager* GameManager::m_pInstance = 0;
//
//GameManager* GameManager::Instance()
//{
//	if (!m_pInstance)
//		m_pInstance = new GameManager();
//	return m_pInstance;
//
//}


GameManager::GameManager()
{
	clock.restart();
	currentTop = 0;
	currentBot = 100;
	m_Generator = WorldManager::Instance()->m_Generator;
	failSoundBuffer.loadFromFile("SFX/fail.wav");
	failSound.setBuffer(failSoundBuffer);
}

void GameManager::AddObject(Object* object)
{
	m_Objects.push_back(object);
}

void GameManager::AddHero(Hero* hero)
{
	m_Heros.push_back(hero);
}

void GameManager::AddCamera(Camera* camera)
{
	m_Cameras.push_back(camera);
}

void GameManager::Draw(RenderWindow* window)
{
	window->setView(m_Cameras[0]->m_view);

	for (int i = 0; i < m_Heros.size(); i++)
		window->draw(*m_Heros[i]);
	for (list<Object*>::iterator iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		window->draw(*(*iter));
	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(290, currentTop)),
		sf::Vertex(sf::Vector2f(290, currentBot))
	};

	window->draw(line, 2, sf::Lines);
}

void GameManager::Update(Time elapsed)
{
	PhysicsUpdate(elapsed);
	for (int i = 0; i < m_Heros.size(); i++)
		m_Heros[i]->Update(elapsed);


		m_Cameras[0]->Update(elapsed);
		float viewHeight = m_Cameras[0]->m_view.getSize().y;
		float viewCenter = m_Cameras[0]->m_view.getCenter().y;

		float viewTop = viewCenter - viewHeight / 2;
		float viewBot = viewCenter + viewHeight / 2;
		currentBot = viewBot;
		if (m_Heros[0]->getBottom()>viewBot)
		{
			//cout <<"game over"<< endl;
			//WorldManager::Instance()->m_GameState++;
			if (WorldManager::Instance()->m_GameState == GameState::Normal)
			{
				WorldManager::Instance()->m_GameState = GameState::Fail;
				failSound.play();
			}
			else if (WorldManager::Instance()->m_GameState == GameState::Fail)
				WorldManager::Instance()->m_GameState = GameState::GameOver;
		}
		if (viewTop < WorldManager::Instance()->currentTop)//currentTop)
		{
			vector<Vector2f> answer = m_Generator->Generate(WorldManager::Instance()->currentTop);
			//for (int i = 0; i < answer.size(); i++)
			//{
			//	AddObject(new Object(answer[i]));
			//}
		}

		for (list<Object*>::iterator iter = m_Objects.begin(); iter != m_Objects.end();)
		{
			float top = (*iter)->getTop();
			if (top > currentBot)
			{
				//cout << "delete" << endl;
				iter = m_Objects.erase(iter);
			}
			else
			{
				if ((*iter)->getTop() < currentTop)
				{
					currentTop = (*iter)->getTop();
					if (currentTop < WorldManager::Instance()->currentTop)
					{
						WorldManager::Instance()->currentTop = currentTop;
					}
				}
				(*iter)->Update(elapsed);
				iter++;
			}
		}

}

void GameManager::PhysicsUpdate(Time elapsed)
{
	for (int i = 0; i < m_Heros.size(); i++)
	{
		if (m_Heros[i]->m_speed.y <= 0)
			continue;
		for (list<Object*>::iterator iter = m_Objects.begin(); iter != m_Objects.end(); iter++)
		{
			//if (m_Heros[i]->getBottom() > m_Objects[j]->getBottom())
			//	continue;
			//if (m_Heros[i]->getBottom() < m_Objects[j]->getTop())
			//	continue;
			if (abs(m_Heros[i]->getBottom() - (*iter)->getTop()) > 10)
				continue;
			if (m_Heros[i]->getLeft() >= (*iter)->getRight())
				continue;
			if (m_Heros[i]->getRight() <= (*iter)->getLeft())
				continue;
 			m_Heros[i]->OnObjectEnter((*iter));
			(*iter)->OnObjectEnter(m_Heros[i]);
			//m_Heros[i]->m_contact = m_Objects[j];
		}
	}
}