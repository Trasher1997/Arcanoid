#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

void colorSet(int& x)
{
	if (x == 0)
	{
		cout << "x = " << x << endl;
		Color::Red;
	}
	if (x == 1)
	{
		cout << "x = " << x << endl;
		Color::Blue;
	}
	if (x == 2)
	{
		cout << "x = " << x << endl;
		Color::Green;
	}
	if (x == 3)
	{
		Color::White;
	}
}