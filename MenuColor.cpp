#include "MenuColor.h"
#include <iostream>

int color = 4;

MenuColor::MenuColor(float width, float height)
{
	if (!font.loadFromFile("Fonts/Gardu.ttf"))
	{
		cout << "Brak czcionki" << endl;
	}

	//kolor czerwony
	colorMenu[0].setFont(font);
	colorMenu[0].setCharacterSize(70);
	colorMenu[0].setFillColor(Color::White);
	colorMenu[0].setString("Czerwony");
	colorMenu[0].setPosition(300, 200);

	//kolor niebieski
	colorMenu[1].setFont(font);
	colorMenu[1].setCharacterSize(70);
	colorMenu[1].setFillColor(Color::White);
	colorMenu[1].setString("Niebieski");
	colorMenu[1].setPosition(300, 300);

	//kolor zielony
	colorMenu[2].setFont(font);
	colorMenu[2].setCharacterSize(70);
	colorMenu[2].setFillColor(Color::White);
	colorMenu[2].setString("Zielony");
	colorMenu[2].setPosition(300, 400);

	//kolor ¿ó³ty
	colorMenu[3].setFont(font);
	colorMenu[3].setCharacterSize(70);
	colorMenu[3].setFillColor(Color::White);
	colorMenu[3].setString("Cofnij");
	colorMenu[3].setPosition(300, 500);

	menuColorSelected = 0;
	colorMenu[menuColorSelected].setFillColor(Color::Blue);
	//cout << "z = " << menuColorSelected << endl;
}

void MenuColor::draw(RenderWindow& menuColor)
{
	for (int i = 0; i < Max_color_menu; i++)
	{
		menuColor.draw(colorMenu[i]);
	}
}

//ruch w góre
void MenuColor::moveUp()
{
	if (menuColorSelected - 1 >= 0)
	{
		colorMenu[menuColorSelected].setFillColor(Color::White);
		menuColorSelected--;
		colorMenu[menuColorSelected].setFillColor(Color::Blue);
		//cout << "z = " << menuColorSelected << endl;
	}

}

//ruch w dó³
void MenuColor::moveDown()
{
	if (menuColorSelected + 1 < Max_color_menu)
	{
		colorMenu[menuColorSelected].setFillColor(Color::White);
		menuColorSelected++;
		colorMenu[menuColorSelected].setFillColor(Color::Blue);
		//cout << "z = " << menuColorSelected << endl;
	}
}

/*void MenuColor::colorSet()
{
	menuColorSelected = menuColorSelected + 1;
	if (menuColorSelected = 1)
	{
		cout << "kolor czerwony" << endl;
	}
	if (menuColorSelected = 2)
	{
		cout << "Kolor niebieski" << endl;
	}
	if (menuColorSelected = 3)
	{
		cout << "Kolor zielony" << endl;
	}
}*/
