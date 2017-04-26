#include"WorldManager.h"
#include"Camera.h"

RenderWindow* GameWindow;

//Camera camera1;
//Camera camera2;

void SetUp()
{
	GameManager* gm1 = new GameManager();
	gm1->AddHero(new Hero());
	gm1->AddCamera(new Camera(gm1->m_Heros[0]));

	gm1->m_Cameras[0]->m_view.setViewport(FloatRect(0, 0, 0.5, 1));
	//camera2.m_view.setViewport(FloatRect(0.5, 0, 0.5, 0.5));
	gm1->AddObject(new Object());
	//gm1->AddObject(new Object(Vector2f(100,-100)));
	//gm1->AddObject(new Object(Vector2f(-100, -200)));
	//gm1->AddObject(new Object(Vector2f(100, -300)));
	//gm1->AddObject(new Object(Vector2f(-100, -400)));
	WorldManager::Instance()->AddGame(gm1);
	GameManager* gm2 = new GameManager();
	gm2->AddHero(new Hero());
	gm2->AddCamera(new Camera(gm2->m_Heros[0]));

	gm2->m_Cameras[0]->m_view.setViewport(FloatRect(0.5, 0, 0.5, 1));
	gm2->AddObject(new Object());
	//gm2->AddObject(new Object(Vector2f(-100, -100)));
	//gm2->AddObject(new Object(Vector2f(100, -200)));
	//gm2->AddObject(new Object(Vector2f(-100, -300)));
	//gm2->AddObject(new Object(Vector2f(100, -400)));
	WorldManager::Instance()->AddGame(gm2);
}

void Update(Time elapsed)
{

	WorldManager::Instance()->Update(elapsed);

	//Object object;

	//object.loadTextureFromFile("Texture/platform.png");

	GameWindow->clear(Color(135, 206, 235));
	//GameWindow->setView(camera2.m_view);
	//GameWindow->draw(object);
	//GameWindow->setView(camera1.m_view);
	//GameWindow->draw(object);


	WorldManager::Instance()->Draw(GameWindow);
	GameWindow->display();
}

int main()
{

	//camera1.m_view.setViewport(FloatRect(0, 0, 0.5, 0.5));
	//camera2.m_view.setViewport(FloatRect(0.5, 0, 0.5, 0.5));

	sf::RenderWindow window(sf::VideoMode(1000, 500), "Parallel Jump!");

	

	GameWindow = &window;
	SetUp();
	Clock clock;
	float sum = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

		}



		//sf::Time elapsed = clock.restart().asMicroseconds;
		sum += clock.restart().asMicroseconds();
		if (sum >= 16000)
		{
			Time elapsed = microseconds(sum);
			Update(elapsed);
			sum = 0;
		}

	}

	return 0;
}