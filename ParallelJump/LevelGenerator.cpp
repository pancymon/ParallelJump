#include"LevelGenerator.h"
#include"WorldManager.h"

LevelGenerator::LevelGenerator() {}

void LevelGenerator::Update(Time elapsed)
{

}

std::vector<Vector2f> LevelGenerator::Generate(float currenttop)
{
	std::vector<Vector2f> answer;
	std::vector<Vector2f> answer1;
	std::vector<Vector2f> answer2;
	//for (int i = 1; i < 5; i++)
	//	answer.push_back(Vector2f(10 * (rand() % 50 - 25), currenttop - 100*i));
	//answer.push_back(Vector2f(100* (rand() % 5 - 2), currenttop - 50));
	//answer.push_back(Vector2f(100 * (rand() % 5 - 2), currenttop - 100));
	//answer.push_back(Vector2f(100 * (rand() % 5 - 2), currenttop - 150));
	//answer.push_back(Vector2f(100 * (rand() % 5 - 2), currenttop - 200));

	srand(time(0));

	int interval = 75;

	for (int i = 1; i < 5; i++)
	{
		Vector2f vec1(10 * (rand() % 50 - 25), currenttop - interval * i);
		Vector2f vec2(10 * (rand() % 50 - 25), currenttop - interval * i);
		answer1.push_back(vec1);
		answer2.push_back(vec2);
		int same = rand() % 2;
		if (same==0)
		{
			answer1.push_back(vec2);
		}
		else
		{
			answer2.push_back(vec1);
		}
		//WorldManager::Instance()->m_Games[0]->AddObject(new Object(answer1[i-1]));
		//WorldManager::Instance()->m_Games[1]->AddObject(new Object(answer2[i-1]));
	}
	for (int i = 0; i < answer1.size(); i++)
	{

		WorldManager::Instance()->m_Games[0]->AddObject(new Object(answer1[i]));
	}
	for (int i = 0; i < answer2.size(); i++)
	{

		WorldManager::Instance()->m_Games[1]->AddObject(new Object(answer2[i]));
	}
	return answer;
}