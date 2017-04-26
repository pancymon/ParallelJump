#ifndef LEVELGENERATOR
#define LEVELGENERATOR

#include<vector>
#include<SFML/Graphics.hpp>
using namespace sf;

class LevelGenerator
{
public:
	LevelGenerator();

	void Update(Time elapsed);

	std::vector<Vector2f> Generate(float currenttop);

};

#endif