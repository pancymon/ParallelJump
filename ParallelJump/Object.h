#ifndef OBJECT_H
#define OBJECT_H
#include<SFML/Graphics.hpp>
#include<iostream>

using namespace std;
using namespace sf;

class Object : public Drawable, public Transformable
{
public:

	Object();
	Object(Vector2f position);
	void setTexture(Texture texture);

	void loadTextureFromFile(string fileName, IntRect rect);
	void loadTextureFromFile(string fileName);

	virtual void draw(RenderTarget& target, RenderStates states) const;
	virtual void Update(Time elapsed);
	virtual void Start();
	void setPosition(Vector2f position);


	virtual float getTop();
	virtual float getBottom();
	virtual float getLeft();
	virtual float getRight();
	virtual void OnObjectEnter(Object* other);

	VertexArray m_vertices;
	Sprite m_sprite;
	Texture m_texture;
};

#endif