#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Ball : public sf::Drawable
{
public:
	Ball(float X, float Y);
	void updatePos();
	Vector2f getPosition();

	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();

	float top();
	float bottom();
	float left();
	float right();

private:
	CircleShape ballShape;
	const float ballRadius{ 12 };
	const float ballSpeed{ 3 };
	Vector2f direction{ ballSpeed, ballSpeed };
	void draw(RenderTarget& targetball, RenderStates stateball) const override;
};
