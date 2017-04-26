#include"Hero.h"



Hero::Hero()
{

	Start();
}



void Hero::Jump()
{
	jumpSound.play();
	m_speed.y = -800;
	m_state = Airborne;
	m_sprite.setTexture(m_Jump);
}

void Hero::UpdateTransform(Time elapsed)
{
	if(m_state==Airborne)
	{

		m_speed.y += m_acceleration *(float)elapsed.asMilliseconds();
		if (m_speed.y > maxFallSpeed)
			m_speed.y = maxFallSpeed;
	}
	//m_sprite.move(m_speed);
	m_sprite.move((float)elapsed.asSeconds()*m_speed);

}

void Hero::UpdateState()
{
	if (m_contact == NULL)
		return;

	if (getLeft() > m_contact->getRight() || getRight() < m_contact->getLeft())
	{
		m_state = Airborne;
		m_sprite.setTexture(m_Jump);
		m_contact = NULL;
	}
}

void Hero::Update(Time elapsed)
 {

	 //m_sprite.move(Vector2f(1,0));
	 current += elapsed.asSeconds();
	 if (current > interval&&jump&&start)
	 {
		 jump = false;
		 current = 0;
		 Jump();
	 }
	 ProcessInput(elapsed);
	 UpdateTransform(elapsed);
	 UpdateState();
}

void Hero::Start()
{
	m_Stand.loadFromFile("Texture/character.png");
	m_Jump.loadFromFile("Texture/characterjump.png");
	jumpSoundBuffer.loadFromFile("SFX/jump.wav");
	jumpSound.setBuffer(jumpSoundBuffer);
	loadTextureFromFile("Texture/characterjump.png");//, IntRect(0, 0, 48, 48));
	m_sprite.move(Vector2f(40, -100));
	m_state = Airborne;
	m_sprite.setTexture(m_Jump);

	interval = 0.17;
	current = 0;
	jump = false;
	m_contact = NULL;
	maxFallSpeed = 400;
	m_acceleration = 1;
	start = false;
}

void Hero::ProcessInput(Time elapsed)
{
	//m_speed = Vector2f(0, 0);
	m_speed.x = 0;
	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		m_speed.x = -300;
	}
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		m_speed.x = 300;
	}
	if (Keyboard::isKeyPressed(Keyboard::Space))
	{
		if (m_state == Landed)
		{
			start = true;
			Jump();
		}
	}
	//if (Keyboard::isKeyPressed(Keyboard::Up))
	//{
	//	m_speed.y--;
	//}
	//if (Keyboard::isKeyPressed(Keyboard::Down))
	//{
	//	m_speed.y++;
	//}
	//m_sprite.move(m_speed * 500.0f * elapsed.asSeconds());
}



void Hero::OnObjectEnter(Object* other)
{
	m_contact = other;
	m_state = Landed;
	m_sprite.setTexture(m_Stand, true);
	m_speed = Vector2f(m_speed.x, 0);
	float y = other->getTop();
	y -= m_texture.getSize().y;
	m_sprite.setPosition(Vector2f(m_sprite.getPosition().x, y));
	current = 0;
	jump = true;
	//Jump();

}
