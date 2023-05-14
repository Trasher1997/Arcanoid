#include "Ball.h"

Ball::Ball(float X, float Y)
{
	ballShape.setPosition(X, Y);
	ballShape.setRadius(ballRadius);
	ballShape.setFillColor(Color::Yellow);
	ballShape.setOrigin(ballRadius, ballRadius);
}

void Ball::draw(RenderTarget& targetball, RenderStates stateball) const
{
	targetball.draw(ballShape, stateball);
}

void Ball::updatePos()
{
	ballShape.move(direction);

	if (top() < 0)
	{
		direction.y = ballSpeed;
	}
	else if (bottom() > 720)
	{
		direction.y = -ballSpeed;
	}
	if (left() < 0)
	{
		direction.x = ballSpeed;
	}
	else if (right() > 960)
	{
		direction.x = -ballSpeed;
	}
}

float Ball::top()
{
	return ballShape.getPosition().y - ballShape.getRadius();
}
float Ball::bottom()
{
	return ballShape.getPosition().y + ballShape.getRadius();
}
float Ball::left()
{
	return ballShape.getPosition().x - ballShape.getRadius();
}
float Ball::right()
{
	return ballShape.getPosition().x + ballShape.getRadius();
}

Vector2f Ball::getPosition()
{
	return ballShape.getPosition();
}

void Ball::moveUp()
{
	direction.y = -ballSpeed;
}

void Ball::moveDown()
{
	direction.y = ballSpeed;
}

void Ball::moveLeft()
{
	direction.x = -ballSpeed;
}

void Ball::moveRight()
{
	direction.x = ballSpeed;
}