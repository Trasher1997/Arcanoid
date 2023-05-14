#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Block : public sf::Drawable
{
public:
	Block(float X, float Y, float Width, float Height);

	void blockUpdate();
	Vector2f getPosition();

	float top();
	float bottom();
	float left();
	float right();

	bool isExist();
	void destroyblock();
	Vector2f getSize();

private:
	void draw(RenderTarget& targerblock, RenderStates statesblock) const override;
	RectangleShape blockShape;
	bool destroyed{ false };
};