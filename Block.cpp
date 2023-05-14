#include "Block.h"

Block::Block(float X, float Y, float Width, float Height)
{
	blockShape.setPosition(X, Y);
	blockShape.setFillColor(Color::Yellow);
	blockShape.setSize({ Width, Height });
	blockShape.setOrigin(Width / 2, Height / 2);
}

void Block::draw(RenderTarget& tergetblock, RenderStates statesblock) const
{
	tergetblock.draw(blockShape, statesblock);
}

float Block::top()
{
	return blockShape.getPosition().y - blockShape.getSize().y / 2;
}

float Block::bottom()
{
	return blockShape.getPosition().y + blockShape.getSize().y / 2;
}

float Block::left()
{
	return blockShape.getPosition().x - blockShape.getSize().x / 2;
}

float Block::right()
{
	return blockShape.getPosition().x + blockShape.getSize().x / 2;
}

Vector2f Block::getPosition()
{
	return blockShape.getPosition();
}

bool Block::isExist()
{
	return this->destroyed;
}

void Block::destroyblock()
{
	this->destroyed = true;
}

Vector2f Block::getSize()
{
	return blockShape.getSize();
}

void Block::blockUpdate() {}