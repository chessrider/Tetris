#pragma once
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <Queue>
#include "Figure.h"
#include "Field.h"
#include "Game_.h"


using namespace sf;
using namespace std;

class Game {
	Field f;
	Figure *block;
	queue <Figure*> qfigure;

public:
	Game()
	{
		int tmp;
		tmp = rand() % 7 + 1;
		switch (tmp)
		{
		case 1:
			block = new figure1;
			break;
		case 2:
			block = new figure2;
			break;
		case 3:
			block = new figure3;
			break;
		case 4:
			block = new figure4;
			break;
		case 5:
			block = new figure5;
			break;
		case 6:
			block = new figure6;
			break;
		case 7:
			block = new figure7;
			break;
		}
		qfigure.push(block);
		block = nullptr;
	}
	~Game()
	{
		delete block;
	}
	Figure* makeFigure()
	{
		int tmp;
		tmp = rand() % 7 + 1;
		switch (tmp)
		{
		case 1:
			block = new figure1;
			break;
		case 2:
			block = new figure2;
			break;
		case 3:
			block = new figure3;
			break;
		case 4:
			block = new figure4;
			break;
		case 5:
			block = new figure5;
			break;
		case 6:
			block = new figure6;
			break;
		case 7:
			block = new figure7;
			break;
		}
		qfigure.push(block);
		block = qfigure.front();
		qfigure.pop();
		return block;
	}
	void falling(int &i)
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);

		if (f.fieldYX(block->getYi(0) + 1, block->getXi(0)) == 0 &&
			f.fieldYX(block->getYi(1) + 1, block->getXi(1)) == 0 &&
			f.fieldYX(block->getYi(2) + 1, block->getXi(2)) == 0 &&
			f.fieldYX(block->getYi(3) + 1, block->getXi(3)) == 0)
		{
			block->setYi(0, block->getYi(0) + 1);
			block->setYi(1, block->getYi(1) + 1);
			block->setYi(2, block->getYi(2) + 1);
			block->setYi(3, block->getYi(3) + 1);

		}
		else {
			i = -1;
		}
		f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
		f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
		f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
		f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());

	}
	void shiftL()
	{
		if (block->getXi(0) > 0 && block->getXi(1) > 0 && block->getXi(2) > 0 && block->getXi(3) > 0)
		{

			f.fieldYX(block->getYi(0), block->getXi(0), 0);
			f.fieldYX(block->getYi(1), block->getXi(1), 0);
			f.fieldYX(block->getYi(2), block->getXi(2), 0);
			f.fieldYX(block->getYi(3), block->getXi(3), 0);

			if (f.fieldYX(block->getYi(0), block->getXi(0) - 1) == 0 &&
				f.fieldYX(block->getYi(1), block->getXi(1) - 1) == 0 &&
				f.fieldYX(block->getYi(2), block->getXi(2) - 1) == 0 &&
				f.fieldYX(block->getYi(3), block->getXi(3) - 1) == 0)
			{
				block->setXi(0, block->getXi(0) - 1);
				block->setXi(1, block->getXi(1) - 1);
				block->setXi(2, block->getXi(2) - 1);
				block->setXi(3, block->getXi(3) - 1);
				sleep(seconds(0.2));
			}
			f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
			f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
			f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
			f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
		}
	}
	void shiftR()
	{
		if (block->getXi(0) < 9 && block->getXi(1) < 9 && block->getXi(2) < 9 && block->getXi(3) < 9)
		{
			f.fieldYX(block->getYi(0), block->getXi(0), 0);
			f.fieldYX(block->getYi(1), block->getXi(1), 0);
			f.fieldYX(block->getYi(2), block->getXi(2), 0);
			f.fieldYX(block->getYi(3), block->getXi(3), 0);

			if ((f.fieldYX(block->getYi(0), block->getXi(0) + 1) == 0) &&
				(f.fieldYX(block->getYi(1), block->getXi(1) + 1) == 0) &&
				(f.fieldYX(block->getYi(2), block->getXi(2) + 1) == 0) &&
				(f.fieldYX(block->getYi(3), block->getXi(3) + 1) == 0))
			{
				block->setXi(0, block->getXi(0) + 1);
				block->setXi(1, block->getXi(1) + 1);
				block->setXi(2, block->getXi(2) + 1);
				block->setXi(3, block->getXi(3) + 1);
				sleep(seconds(0.2));
			}
			f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
			f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
			f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
			f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());


		}
	}
	void deleteLine(int &Line, int &level)
	{
		bool l = 0;
		for (int g = 1; g < HEIGTH; g++)
		{
			for (int k = 0; k < WIDTH; k++)
			{
				if (f.fieldYX(g, k) != 0)
				{
					l = 1;
				}
				else {
					l = 0;
					break;
				}
			}
			if (l == 1)//если строка заполнена
			{
				for (int i1 = g; i1 > 0; i1--)//g -номер строки
				{
					for (int k = 0; k < WIDTH; k++)
					{
						f.fieldYX(i1, k, f.fieldYX(i1 - 1, k));
					}
				}
				sleep(seconds(0.4));
				Line++;//количество удаленных строк
			}
		}
		if (Line > 70)
		{
			level = 6;
		}
		else if (Line > 50)
		{
			level = 5;
		}
		else if (Line > 30)
		{
			level = 4;
		}
		else if (Line > 20)
		{
			level = 3;
		}
		else if (Line > 10)
		{
			level = 2;
		}
		else if (Line > 5)
		{
			level = 1;
		}
	}
	void play()
	{
		RenderWindow window(VideoMode(heigth*HEIGTH, heigth*HEIGTH), "Tetris", Style::Close);
		RectangleShape cubick(Vector2f(heigth, heigth));
		cubick.setOutlineThickness(-1);
		cubick.setOutlineColor(Color::Black);
		RectangleShape qcubick(Vector2f(heigth, heigth));
		qcubick.setOutlineThickness(-1);
		qcubick.setOutlineColor(Color::White);

		window.setVerticalSyncEnabled(true);
		/*Image background;
		background.loadFromFile("Game Over.png");*/
		Texture texture;
		texture.loadFromFile("Game Over.png");
		// Create a sprite
		Sprite game;
		game.setTexture(texture);
		game.setPosition(50, 0);
		Sprite background;
		Texture backpaper;
		backpaper.loadFromFile("Background.jpg");
		background.setTexture(backpaper);
		background.setPosition(0, 0);
		int level = 0;
		Text levels;
		Text lines;
		Text next;
		Text guide;
		Font font;
		font.loadFromFile("17933.otf");
		guide.setFont(font);
		RectangleShape line(Vector2f(3, 400));
		line.setFillColor(Color::Black);
		line.setOutlineThickness(-1);
		line.setOutlineColor(Color::White);


		int t = 0;
		bool isGameOver = 0;
		int s = 0;//для регулировки скорости
		int countLines = 0;//количество удаленных линий
		double speed = 0.0;
		//i увеличивается каждые 10 итераций цикла
		//if(j==9) ->i++-> j=0
		for (int i = 0, j = 0; window.isOpen(); j++)// j - для плавного передвижения вправо-влево
		{

			if (isGameOver == 0) {
				s = 1;
				switch (level)//в зависимости от уровня сложности скорость падения фигур увеличивается
				{
				case 0:
					speed = 0.0;
					break;
				case 1:
					speed = 0.019;
					break;
				case 2:
					speed = 0.03;
					break;
				case 3:
					speed = 0.04;
					break;
				case 4:
					speed = 0.05;
					break;
				case 5:
					speed = 0.08;
					break;
				case 6:
					speed = 0.089;
					break;
				}
				sleep(seconds(0.09 - speed));
				window.clear();
				window.draw(background);
				if (i == 0 && j == 0)//каждые 10 итераций главного цикла фигура опускается вниз
				{
					if (f.fieldYX(1, 0) != 0 || f.fieldYX(1, 1) != 0 || f.fieldYX(1, 2) != 0 || f.fieldYX(1, 3) != 0 ||
						f.fieldYX(1, 4) != 0 || f.fieldYX(1, 5) != 0 || f.fieldYX(1, 6) != 0 || f.fieldYX(1, 7) != 0 ||
						f.fieldYX(1, 8) != 0 || f.fieldYX(1, 9) != 0) {
						isGameOver = 1;
						sleep(seconds(3));
					}
					deleteLine(countLines, level);
					makeFigure();
					t = 0;
					if (f.fieldYX(block->getYi(0), block->getXi(0)) != 0 ||
						f.fieldYX(block->getYi(1), block->getXi(1)) != 0 ||
						f.fieldYX(block->getYi(2), block->getXi(2)) != 0 ||
						f.fieldYX(block->getYi(3), block->getXi(3)) != 0) {
						isGameOver = 1;
						sleep(seconds(3));
					}
					sleep(seconds(0.09 - speed));
				}
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed) {
						window.close();
					}
					if (event.type == Event::KeyPressed) {
						if (event.key.code == Keyboard::Left) {

							shiftL();
							break;
						}
						if (event.key.code == Keyboard::Right) {
							shiftR();
							break;
						}
						if (event.key.code == Keyboard::Up)
						{
							block->rotate(f, block);
							break;
						}
						if (event.key.code == Keyboard::Down)
						{
							j = 9;
							s = 2;
							break;
						}
						if (event.key.code == Keyboard::R) {
							level = 0;
							i = 0;
							j = 0;
							t = 0;
							isGameOver = 0;
							s = 0;
							countLines = 0;
							speed = 0.0;
							for (int j = 0; j < HEIGTH; j++)
							{
								for (int k = 0; k < WIDTH; k++)
								{
									f.fieldYX(j, k, 0);
								}
							}
							makeFigure();
							break;
						}
						if (event.key.code == Keyboard::Enter)
						{
							window.close();
						}
						if (event.key.code == Keyboard::P)
						{
							for (int g = 0;g==0;)
							{
								
								while (window.pollEvent(event))
								{
									if (event.type == Event::Closed) {
										window.close();
									}
									if (event.type == Event::KeyPressed) {
										if (event.key.code == Keyboard::P)
										{
											g = 1;
										}
										if (event.key.code == Keyboard::Enter)
										{
											window.close();
										}
									}
								}
							}
						}

					}
				}
				int posx = 0, posy = 0;
				//выбор цвета и вывод в консоль
				for (int l = 0; l < HEIGTH; l++)
				{
					for (int k = 0; k < WIDTH; k++)
					{
						switch (f.fieldYX(l, k))
						{
						case 1:
							cubick.setFillColor(Color::Red);
							break;
						case 2:
							cubick.setFillColor(Color::Green);
							break;
						case 3:
							cubick.setFillColor(Color(0, 172, 230));
							break;
						case 4:
							cubick.setFillColor(Color::Yellow);
							break;
						case 5:
							cubick.setFillColor(Color(70, 1, 72));
							break;
						case 6:
							cubick.setFillColor(Color(0, 0, 153));
							break;
						case 7:
							cubick.setFillColor(Color(230, 138, 0));
							break;
						}
						if (f.fieldYX(l, k) != 0)
						{
							cubick.setPosition(posx, posy);
							window.draw(cubick);
						}
						posx += 20;
					}
					posx = 0;
					posy += 20;
				}
				if (j == 9)
				{
					j = -1;
					//"окрашивание" поля
					f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
					f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
					f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
					f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
					//выбор цвета и вывод
					int posx = 0, posy = 0;
					for (int row = 0; row < HEIGTH; row++)
					{
						for (int col = 0; col < WIDTH; col++)
						{
							switch (f.fieldYX(row, col))
							{
							case 1:
								cubick.setFillColor(Color::Red);
								break;
							case 2:
								cubick.setFillColor(Color::Green);
								break;
							case 3:
								cubick.setFillColor(Color(0, 172, 230));
								break;
							case 4:
								cubick.setFillColor(Color::Yellow);
								break;
							case 5:
								cubick.setFillColor(Color(70, 1, 72));
								break;
							case 6:
								cubick.setFillColor(Color(0, 0, 153));
								break;
							case 7:
								cubick.setFillColor(Color(230, 138, 0));
								break;
							}
							if (f.fieldYX(row, col) != 0)
							{
								cubick.setPosition(posx, posy);
								window.draw(cubick);
							}
							posx += 20;
						}
						posx = 0;
						posy += 20;
					}
					//остановка фигуры
					falling(i);
					if (block->getYi(0) == 19 || block->getYi(1) == 19 || block->getYi(2) == 19 || block->getYi(3) == 19)//если блок достиг дна
					{
						i = -1;
						if (t == 0)
						{
							j = 7;//для возможности двигать фигуру когда она достигла дна(2 лишних прохода цикла до 9)
						}
						t++;
						f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
						f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
						f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
						f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
					}
					i++;
					sleep(seconds((0.08 / s)));
				}
				int x = 250;
				for (int k = 0; k < 4; k++)
				{
					switch (qfigure.front()->getColor())
					{
					case 1:
						qcubick.setFillColor(Color::Red);
						break;
					case 2:
						qcubick.setFillColor(Color::Green);
						break;
					case 3:
						qcubick.setFillColor(Color(0, 172, 230));
						x = 270;
						break;
					case 4:
						qcubick.setFillColor(Color::Yellow);
						break;
					case 5:
						qcubick.setFillColor(Color(70, 1, 72));
						break;
					case 6:
						qcubick.setFillColor(Color(0, 0, 153));
						break;
					case 7:
						qcubick.setFillColor(Color(230, 138, 0));
						x = 270;
						break;
					}
					qcubick.setPosition(x + 20 * (qfigure.front()->getXi(k) - qfigure.front()->getXi(0)), 60 + 20 * (qfigure.front()->getYi(k) - qfigure.front()->getYi(0)));
					window.draw(qcubick);
				}
				line.setPosition(200, 0);
				window.draw(line);

				next.setFont(font);
				next.setFillColor(Color::White);
				next.setCharacterSize(20);
				next.setString("Next:");
				next.setPosition(240, 20);
				window.draw(next);
				levels.setFont(font);
				levels.setFillColor(Color::White);
				levels.setCharacterSize(20);
				levels.setString("Level:");
				levels.setPosition(240, 140);
				window.draw(levels);
				levels.setString(to_string(level));
				levels.setPosition(320, 140);
				window.draw(levels);

				lines.setString("Lines:");
				lines.setFont(font);
				lines.setCharacterSize(20);
				lines.setPosition(240, 180);
				window.draw(lines);
				lines.setString(to_string(countLines));
				lines.setPosition(320, 180);
				window.draw(lines);
				guide.setCharacterSize(15);
				guide.setString("Up ~ rotate");
				guide.setPosition(240, 230);
				window.draw(guide);
				guide.setString("< ~ move left");
				guide.setPosition(240, 260);
				window.draw(guide);
				guide.setString("> ~ move rigth");
				guide.setPosition(240, 290);
				window.draw(guide);
				guide.setString("Enter ~ finish");
				guide.setPosition(240, 320);

				window.draw(guide);
				guide.setString("P ~ pause");
				guide.setPosition(240, 350);
				window.draw(guide);
				window.display();
			}
			if (isGameOver != 0) {
				window.clear();

				window.draw(game);
				window.display();
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed) {
						window.close();
					}
					if (event.type == Event::KeyPressed)
					{
						if (event.key.code == Keyboard::R) {
							level = 0;
							i = 0;
							j = 0;
							t = 0;
							isGameOver = 0;
							s = 0;
							countLines = 0;
							speed = 0.0;
							for (int j = 0; j < HEIGTH; j++)
							{
								for (int k = 0; k < WIDTH; k++)
								{
									f.fieldYX(j, k, 0);
								}
							}
							makeFigure();
						}
						if (event.key.code == Keyboard::Enter)
						{
							window.close();
						}
					}
				}
			}

		}

	}
};
