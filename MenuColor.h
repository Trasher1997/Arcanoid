#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#define  Max_color_menu 4

using namespace sf;
using namespace std;

class MenuColor
{
public:
	MenuColor(float width, float height);
	void draw(RenderWindow& menuColor);
	void moveUp();
	void moveDown();

	int menuColorPress()
	{
		return menuColorSelected;
	}

private:
	int menuColorSelected;
	Font font;
	Text colorMenu[Max_color_menu];
};