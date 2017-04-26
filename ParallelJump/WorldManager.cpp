#include <stddef.h>  // defines NULL
#include"WorldManager.h"


WorldManager* WorldManager::m_pInstance = 0;

WorldManager::WorldManager()
{
	clock.restart();
	m_GameState = GameState::Normal;
	m_Generator = new LevelGenerator();
}

WorldManager* WorldManager::Instance()
{
	if (!m_pInstance)
		m_pInstance = new WorldManager();
	return m_pInstance;

}

void WorldManager::Update(Time elapsed)
{
	//if (m_GameState == GameState::GameOver)
	//{
	//	//wait for restart
	//	
	//}
	for (int i = 0; i < m_Games.size(); i++)
	{
		m_Games[i]->Update(elapsed);
	}
}
void WorldManager::AddGame(GameManager* game)
{
	m_Games.push_back(game);
}

void WorldManager::Draw(RenderWindow* window)
{
	//if (m_GameState == GameState::GameOver)
	//{
	//	window->clear(Color(135, 206, 235));
	//}

	for (int i = 0; i < m_Games.size(); i++)
		m_Games[i]->Draw(window);
}