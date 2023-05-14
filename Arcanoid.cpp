#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Menu.h"
#include "MenuColor.h"
#include "Options.h"
#include "Ball.h"
#include "Paddle.h"
#include "Block.h"
#include "Global_Change.h"


template <class obj1, class obj2> bool intersects(obj1& A, obj2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool colisiontest(Paddle& paddle, Ball& ball)
{
	if (!intersects(paddle, ball)) return false;
	ball.moveUp();

	if (ball.getPosition().x < paddle.getPosition().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosition().x > paddle.getPosition().x)
	{
		ball.moveRight();
	}
}

bool colisiontest(Block& block, Ball& ball)
{
	if (!intersects(block, ball)) return false;
	block.destroyblock();

	float checkLeft { ball.right() - block.left() };
	float checkRight { block.right() - ball.left() };
	float checkTop { ball.bottom() - block.top() };
	float checkBottom{ block.bottom() - ball.top() };

	bool ballHitFromLeft(abs(checkLeft) < abs(checkRight));
	bool ballHitFromTop(abs(checkTop) < abs(checkBottom));

	float mincheckX{ ballHitFromLeft ? checkLeft : checkRight };
	float mincheckY{ ballHitFromTop ? checkTop : checkBottom };

	if (abs(mincheckX) < abs(mincheckY))
	{
		ballHitFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else
	{
		ballHitFromTop ? ball.moveUp() : ball.moveDown();
	}
}

void main()
{
	RenderWindow MENU(VideoMode(960, 720), "Arcanoid", Style::Default);
	MainMenu mainMenu(MENU.getSize().x, MENU.getSize().y);

	while (MENU.isOpen())
	{
		Event event;
		while (MENU.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				MENU.close();
			}
			if (event.type == Event::KeyReleased)
			{
				if (event.key.code == Keyboard::Up)
				{
					mainMenu.moveUp();
				}
				if (event.key.code == Keyboard::Down)
				{
					mainMenu.moveDown();
				}
				if (event.key.code == Keyboard::Return)
				{
					int x = mainMenu.MenuPress();

					//Start gry
					if (x == 0)
					{
						MENU.close();
						Ball Ball(960 / 2, 720 / 2);
						Paddle Paddle(960 / 2, 650);
						RenderWindow Play{ VideoMode{960, 720}, "Arcanoid" };
						Play.setFramerateLimit(60);
						unsigned blockX{ 9 }, blockY{ 4 }, blockWidth{ 80 }, blockHeight{ 30 };

						vector<Block> block;
						for (int i = 0; i < blockY; i++)
						{
							for (int j = 0; j < blockX; j++)
							{
								block.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
							}
						}

						while (true)
						{
							Event eventa;
							Play.clear(Color::Blue);
							Play.pollEvent(eventa);

							if (eventa.type == Event::Closed)
							{
								Play.close();
								main();
							}	

							Ball.updatePos();
							Paddle.updatePos();
							colisiontest(Paddle, Ball);

							for (auto& block : block) if (colisiontest(block, Ball)) break;

							auto iterator = remove_if(begin(block), end(block), [](Block& block) { return block.isExist(); });
							block.erase(iterator, end(block));
							
							Play.draw(Ball);
							Play.draw(Paddle);

							for (auto& block : block)
								Play.draw(block);

							Play.display();
						}
					}
					//Opcje
					if (x == 1)
					{

						MENU.close();
						RenderWindow Opcje(VideoMode(960, 720), "Opcje", Style::Default);
						OptionsMenu optionsMenu(Opcje.getSize().x, Opcje.getSize().y);
						while (Opcje.isOpen())
						{
							Event eventb;
							while (Opcje.pollEvent(eventb))
							{
								if (eventb.type == Event::Closed)
								{
									Opcje.close();
									main();
								}
								if (eventb.type == Event::KeyReleased)
								{
									if (eventb.key.code == Keyboard::Up)
									{
										optionsMenu.moveUp();
									}
									if (eventb.key.code == Keyboard::Down)
									{
										optionsMenu.moveDown();
									}
									if (eventb.key.code == Keyboard::Return)
									{
										int y = optionsMenu.optionPress();

										//Zmiana koloru napisów
										if (y == 0)
										{
											Opcje.close();
											RenderWindow Color_Change(VideoMode(960, 720), "Zmiana koloru menu");
											MenuColor colorMenu(Color_Change.getSize().x, Color_Change.getSize().y);
											while (Color_Change.isOpen())
											{
												Event event1;
												while (Color_Change.pollEvent(event1))
												{
													if (event1.type == Event::Closed)
													{
														Color_Change.close();
														main();
													}
													if (event1.type == Event::KeyReleased)
													{
														if (event1.key.code == Keyboard::Up)
														{
															colorMenu.moveUp();
														}
														if (event1.key.code == Keyboard::Down)
														{
															colorMenu.moveDown();
														}
														if (event1.key.code == Keyboard::Return)
														{
															int tinge = colorMenu.menuColorPress();
															if (tinge == 0)
															{
																colorSet(tinge);
															}
															if (tinge == 1)
															{
																colorSet(tinge);
															}
															if (tinge == 2)
															{
																colorSet(tinge);
															}
															if (tinge == 3)
															{
																Color_Change.close();
																main();
															}

														}
													}
												}
												Color_Change.clear();
												colorMenu.draw(Color_Change);
												Color_Change.display();
											}
										}
										if (y == 1)
										{
											Opcje.close();
											RenderWindow opcja2(VideoMode(960, 720), "Opcja2");
											while (opcja2.isOpen())
											{
												Event event2;
												opcja2.pollEvent(event2);
												if (event2.type == Event::Closed)
												{
													opcja2.close();
													main();
												}
												opcja2.display();
											}
										}
										if (y == 2)
										{
											Opcje.close();
											RenderWindow opcja3(VideoMode(960, 720), "Opcja3");
											while (opcja3.isOpen())
											{
												Event event3;
												opcja3.pollEvent(event3);
												if (event3.type == Event::Closed)
												{
													opcja3.close();
													main();
												}
												opcja3.display();
											}
										}
										if (y == 3)
										{
											Opcje.close();
											main();
										}
									}
								}
								Opcje.clear();
								optionsMenu.draw(Opcje);
								Opcje.display();
							}
						}
					}

					// O mnie
					if (x == 2)
					{
						MENU.close();
						RenderWindow About(VideoMode(960, 720), "OMnie");
						while (About.isOpen())
						{
							Event eventc;
							while (About.pollEvent(eventc))
							{
								if (eventc.type == Event::Closed)
								{
									About.close();
									main();
								}
								About.display();
							}
						}
					}
					//Wyjscie
					if (x == 3)
					{
						MENU.close();
						break;
					}
				}
			}
			MENU.clear();
			mainMenu.draw(MENU);
			MENU.display();
		}

	}
}