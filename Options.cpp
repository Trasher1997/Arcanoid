#include "Options.h"
#include <iostream>

OptionsMenu::OptionsMenu(float width, float height)
{
	if (!font.loadFromFile("Fonts/Gardu.ttf"))
	{
		cout << "Brak czcionki" << endl; // gdzy nie wczyta czcionki 
	}

	//opcja1
	optionsMenu[0].setFont(font);
	optionsMenu[0].setCharacterSize(70);
	optionsMenu[0].setFillColor(Color::White);
	optionsMenu[0].setString("Kolor Menu");
	optionsMenu[0].setPosition(300, 200);

	//opcja2
	optionsMenu[1].setFont(font);
	optionsMenu[1].setCharacterSize(70);
	optionsMenu[1].setFillColor(Color::White);
	optionsMenu[1].setString("Opcja2");
	optionsMenu[1].setPosition(300, 300);

	//opcja3
	optionsMenu[2].setFont(font);
	optionsMenu[2].setCharacterSize(70);
	optionsMenu[2].setFillColor(Color::White);
	optionsMenu[2].setString("Opcja3");
	optionsMenu[2].setPosition(300, 400);

	//opcja4
	optionsMenu[3].setFont(font);
	optionsMenu[3].setCharacterSize(70);
	optionsMenu[3].setFillColor(Color::White);
	optionsMenu[3].setString("Cofnij");
	optionsMenu[3].setPosition(300, 500);

	optionSelected = 0;
	optionsMenu[optionSelected].setFillColor(Color::Blue);
	//cout << "y= " << optionSelected << endl;
}

void OptionsMenu::draw(RenderWindow& options)
{
	for (int i = 0; i < Max_options_menu; i++)
	{
		options.draw(optionsMenu[i]);
	}
}

//ruch d góre
void OptionsMenu::moveUp()
{
	if (optionSelected - 1 >= 0)
	{
		optionsMenu[optionSelected].setFillColor(Color::White);
		optionSelected--;
		optionsMenu[optionSelected].setFillColor(Color::Blue);
		//cout << "y= " << optionSelected << endl;
	}
}

//ruch w dol
void OptionsMenu::moveDown()
{
	if (optionSelected + 1 < Max_options_menu)
	{
		optionsMenu[optionSelected].setFillColor(Color::White);
		optionSelected++;
		optionsMenu[optionSelected].setFillColor(Color::Blue);
		//cout << "y= " << optionSelected << endl;
	}
}