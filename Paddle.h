#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Paddle :public sf::Drawable
{
public:
	Paddle(float X, float Y);
	void updatePos();
	Vector2f getPosition();

	void moveLeft();
	void moveRight();

	float top();
	float bottom();
	float left();
	float right();

private:
	RectangleShape paddleShape;
	const float paddleHeight{ 20 };
	const float paddleWidth{ 60 };
	const float paddleSpeed{ 5 };
	Vector2f speed{ paddleSpeed, 0 };
	void draw(RenderTarget& targetpaddle, RenderStates statespaddle) const override;
};