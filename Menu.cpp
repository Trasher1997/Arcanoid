#include "Menu.h"
#include <iostream>


MainMenu::MainMenu(float width, float heighht)
{
	if (!font.loadFromFile("Fonts/Gardu.ttf"))
	{
		cout << "Brak czcionki" << endl;
	}


	//start
	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(Color::White);
	mainMenu[0].setString("Start Gry");
	mainMenu[0].setCharacterSize(70);
	mainMenu[0].setPosition(300, 200);

	//opcje
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(Color::White);
	mainMenu[1].setString("Opcje");
	mainMenu[1].setCharacterSize(70);
	mainMenu[1].setPosition(300, 300);

	//O mnie
	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(Color::White);
	mainMenu[2].setString("O mnie");
	mainMenu[2].setCharacterSize(70);
	mainMenu[2].setPosition(300, 400);

	//Exit
	mainMenu[3].setFont(font);
	mainMenu[3].setFillColor(Color::White);
	mainMenu[3].setString("Wyjscie");
	mainMenu[3].setCharacterSize(70);
	mainMenu[3].setPosition(300, 500);

	MenuSelected = 0;
	mainMenu[MenuSelected].setFillColor(Color::Blue);
	//cout << "x= " << MenuSelected << endl;
}

//funkcja rysujaca moje menu
void MainMenu::draw(RenderWindow& window)
{
	for (int i = 0; i < Max_main_menu; i++)
	{
		window.draw(mainMenu[i]);
	}
}

//ruch do góry
void MainMenu::moveUp()
{
	if (MenuSelected - 1 >= 0)
	{
		mainMenu[MenuSelected].setFillColor(Color::White);
		MenuSelected--;
		mainMenu[MenuSelected].setFillColor(Color::Blue);
		//cout << "x= " << MenuSelected << endl;
	}
}

//ruch w dol
void MainMenu::moveDown()
{
	if (MenuSelected + 1 < Max_main_menu)
	{
		mainMenu[MenuSelected].setFillColor(Color::White);
		MenuSelected++;
		mainMenu[MenuSelected].setFillColor(Color::Blue);
		//cout << "x= " << MenuSelected << endl;
	}
}

