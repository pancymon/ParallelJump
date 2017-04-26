#ifndef WORLDMANAGER_H
#define WORLDMANAGER_H
#include"GameManager.h"

enum GameState
{
	Normal,
	Fail,
	GameOver
};

class WorldManager
{
public:


	static WorldManager* Instance();

	void Update(Time elapsed);
	void AddGame(GameManager* game);
	void Draw(RenderWindow* window);
	vector<GameManager*> m_Games;

	GameState m_GameState;
	LevelGenerator* m_Generator;
	float currentTop;

	//void PhysicsUpdate(Time elapsed);

	//void Draw(RenderWindow* window);


	//void AddHero(Hero* hero);
	//void AddCamera(Camera* camera);

	//vector<Hero*> m_Heros;
	//vector<Object*> m_Objects;
	//vector<Camera*> m_Cameras;

private:
	Clock clock;

	//singleton
	WorldManager();
	WorldManager(WorldManager const&) {};
	WorldManager& operator=(WorldManager const&) {};
	static WorldManager* m_pInstance;
};

#endif