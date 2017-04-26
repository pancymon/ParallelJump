#ifndef CAMERA_H
#define CAMERA_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include"Hero.h"

using namespace std;
using namespace sf;

//class GameManager;

class Camera
{
public:
	Camera();
	Camera(Hero* hero);
	void Update(Time elapsed);
	Hero* m_hero;
	View m_view;
	bool pass;
	
};

#endif
