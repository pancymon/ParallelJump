#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include<vector>
#include<list>
#include"Object.h"
#include"Hero.h"
#include"LevelGenerator.h"

using namespace std;

class Camera;

class GameManager {
public:
	//static GameManager* Instance();

	void Update(Time elapsed);
	void PhysicsUpdate(Time elapsed);

	void Draw(RenderWindow* window);

	void AddObject(Object* object);
	void AddHero(Hero* hero);
	void AddCamera(Camera* camera);

	vector<Hero*> m_Heros;

	vector<Camera*> m_Cameras;
	list<Object*> m_Objects;

	LevelGenerator* m_Generator;

	float currentTop;
	float currentBot;
	Clock clock;

	SoundBuffer failSoundBuffer;
	Sound failSound;

	//singleton
	GameManager();
	//GameManager(GameManager const&) {};
	//GameManager& operator=(GameManager const&) {};
	//static GameManager* m_pInstance;

};

#endif