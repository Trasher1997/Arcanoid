#include "Paddle.h"

Paddle::Paddle(float X, float Y)
{
	paddleShape.setFillColor(Color::Yellow);
	paddleShape.setPosition(X, Y);
	paddleShape.setSize({ paddleWidth, paddleHeight });
	paddleShape.setOrigin(paddleWidth / 2, paddleHeight / 2);
}

void Paddle::draw(RenderTarget& targetpaddle, RenderStates statespaddle) const
{
	targetpaddle.draw(paddleShape, statespaddle);
}

void Paddle::updatePos()
{
	paddleShape.move(speed);

	if (Keyboard::isKeyPressed(Keyboard::Key::Left) && left() > 0)
	{
		speed.x = -paddleSpeed;
	}
	else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && right() < 960)
	{
		speed.x = paddleSpeed;
	}
	else
	{
		speed.x = 0;
	}
}

float Paddle::top()
{
	return paddleShape.getPosition().y - paddleShape.getSize().y / 2;
}
float Paddle::bottom()
{
	return paddleShape.getPosition().y + paddleShape.getSize().y / 2;
}
float Paddle::left()
{
	return paddleShape.getPosition().x - paddleShape.getSize().x / 2;
}
float Paddle::right()
{
	return paddleShape.getPosition().x + paddleShape.getSize().x / 2;
}

Vector2f Paddle::getPosition()
{
	return paddleShape.getPosition();
}