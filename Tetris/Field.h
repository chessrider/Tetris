#pragma once
#include "Figure.h"
const int HEIGTH = 20;
const int WIDTH = 10;


class Field
{
	int field[HEIGTH][WIDTH];

public:
	Field()
	{

		for (int j = 0; j < HEIGTH; j++)
		{
			for (int k = 0; k < WIDTH; k++)
			{
				field[j][k] = 0;
			}
		}
	}
	int fieldYX(int y, int x)
	{
		return field[y][x];
	}
	int fieldYX(int y, int x, int v)
	{
		field[y][x] = v;
		return y;
	}
};
