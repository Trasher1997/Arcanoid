#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#define Max_main_menu 4

using namespace sf;
using namespace std;

class MainMenu
{
public:
	MainMenu(float width, float height);
	void draw(RenderWindow& window);
	void moveUp();
	void moveDown();

	int MenuPress()
	{
		return MenuSelected;
	}

private:
	int MenuSelected;
	Font font;
	Text mainMenu[Max_main_menu];
};