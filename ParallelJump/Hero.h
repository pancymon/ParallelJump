#ifndef HERO_H
#define HERO_H
#include"Object.h"
#include <SFML/Audio.hpp>

enum HeroState
{
	None,
	Landed,
	Airborne,
	Error
};

class Hero : public Object
{
public:
	Hero();
	void Jump();
	void UpdateTransform(Time elapsed);
	void UpdateState();

	virtual void Update(Time elapsed);
	virtual void Start();
	virtual void OnObjectEnter(Object* other);

	Vector2f m_position;
	Vector2f m_speed;
	float m_acceleration;
    Object* m_contact;
	Texture m_Stand;
	Texture m_Jump;
	SoundBuffer jumpSoundBuffer;
	Sound jumpSound;

private:
	float maxFallSpeed = 0.2;
	void ProcessInput(Time elapsed);
	HeroState m_state;

	float interval;
	float current;
	bool jump;
	bool start;

};

#endif
