#include"Object.h"

Object::Object()
{
	Start();
	//
}

Object::Object(Vector2f position)
{
	Start();
	setPosition(position);
}

void Object::setTexture(Texture texture)
{
	m_sprite.setTexture(texture);
	m_texture = texture;
}

void Object::loadTextureFromFile(string fileName, IntRect rect)
{
	m_texture.loadFromFile(fileName, rect);
	m_sprite.setTexture(m_texture, true);
}

void Object::loadTextureFromFile(string fileName)
{
	m_texture.loadFromFile(fileName);
	m_sprite.setTexture(m_texture, true);
}

void Object::draw(RenderTarget& target, RenderStates states) const
{
	// apply the transform
	//states.transform *= getTransform();

	// our particles don't use a texture
	states.texture = NULL;

	// draw the vertex array
	//Texture texture;
	//texture.loadFromFile("Texture/platform.png");
	//m_sprite.setTexture(texture);
	target.draw(m_sprite, states);
}

void Object::Update(Time elapsed)
{}

void Object::Start()
{
	loadTextureFromFile("Texture/platform.png");
}

void Object::setPosition(Vector2f position)
{
	m_sprite.setPosition(position);
}

void Object::OnObjectEnter(Object* other)
{}

float Object::getBottom()
{
	float answer = 0;
	answer = m_sprite.getPosition().y;
	answer += m_texture.getSize().y;
	return answer;
}

float Object::getTop()
{
	float answer = 0;
	answer = m_sprite.getPosition().y;
	return answer;
}

float Object::getLeft()
{
	float answer = 0;
	answer = m_sprite.getPosition().x;
	return answer;
}

float Object::getRight()
{
	float answer = 0;
	answer = m_sprite.getPosition().x;
	answer += m_texture.getSize().x;
	return answer;
}