#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define  Max_options_menu 4

using namespace sf;
using namespace std;

class OptionsMenu
{
public:
	OptionsMenu(float width, float height);
	void draw(RenderWindow& options);
	void moveUp();
	void moveDown();

	int optionPress()
	{
		return optionSelected;
	}

private:
	int optionSelected;
	Font font;
	Text optionsMenu[Max_options_menu];
};