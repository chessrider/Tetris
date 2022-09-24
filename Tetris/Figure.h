#pragma once
#include "Field.h"
#include <conio.h>
#include <windows.h>

const int heigth = 20;
using namespace std;
using namespace sf;


class Block {
	int x;
	int y;
public:
	Block() = default;
	void setX(int x)
	{
		this->x = x;
	}
	void setY(int y)
	{
		this->y = y;
	}
	int getX() const
	{
		return x;
	}
	int getY() const
	{
		return y;
	}


};

class Figure {
protected:
	vector <Block> figure;
	int color;
	int degree = 0;
public:
	Figure()
	{
		figure.resize(4);

	}
	int getColor()const
	{
		return color;
	}
	virtual void rotate(Field &f, Figure *block) = 0;
	void setXi(int i, int x)
	{
		figure[i].setX(x);
	}
	void setYi(int i, int y)
	{
		figure[i].setY(y);
	}
	int getXi(int i)
	{
		return figure[i].getX();
	}
	int getYi(int i)
	{
		return figure[i].getY();
	}

	~Figure() = default;
};

class figure1 :public Figure
{
public:
	figure1()
	{
		int x = rand() % 7;
		color = 1;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x + 1);	figure[1].setY(1);
		figure[2].setX(x + 2);	figure[2].setY(1);
		figure[3].setX(x + 3);	figure[3].setY(1);

	}
	void rotate(Field &f, Figure *block)override
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);
		switch (degree)
		{
		case 0:
			if (f.fieldYX(figure[0].getY() - 1, figure[0].getX() + 1) == 0 &&
				f.fieldYX(figure[2].getY() + 1, figure[2].getX() - 1) == 0 &&
				f.fieldYX(figure[3].getY() + 2, figure[3].getX() - 2) == 0 && figure[0].getY() < HEIGTH - 2)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1); figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() - 1); figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() - 2); figure[3].setY(figure[3].getY() + 2);
				degree = 1;
			}
			f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
			f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
			f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
			f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
			break;

		case 1:
			if (f.fieldYX(figure[0].getY() + 1, figure[0].getX() - 1) == 0 &&
				f.fieldYX(figure[2].getY() - 1, figure[2].getX() + 1) == 0 &&
				f.fieldYX(figure[3].getY() - 2, figure[3].getX() + 2) == 0 && figure[0].getX() < WIDTH - 2 && figure[0].getX() > 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 1); figure[0].setY(figure[0].getY() + 1);
				figure[2].setX(figure[2].getX() + 1); figure[2].setY(figure[2].getY() - 1);
				figure[3].setX(figure[3].getX() + 2); figure[3].setY(figure[3].getY() - 2);
				degree = 0;
			}
			f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
			f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
			f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
			f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
			break;
		}
	}
};

class figure2 :public Figure
{
public:
	figure2()
	{
		int x = rand() % 8;
		color = 2;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x + 1);	figure[1].setY(1);
		figure[2].setX(x + 1);	figure[2].setY(2);
		figure[3].setX(x + 2);	figure[3].setY(2);

	}
	void rotate(Field &f, Figure *block)override
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);
		switch (degree)
		{
		case 0:
			if (f.fieldYX(figure[0].getY() + 1, figure[0].getX()) == 0 &&
				f.fieldYX(figure[1].getY() - 1, figure[1].getX()) == 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1); figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() - 1); figure[2].setY(figure[2].getY() - 1);
				figure[3].setX(figure[3].getX() - 2); figure[3].setY(figure[3].getY());
				degree = 1;
			}

			break;

		case 1:
			if (f.fieldYX(figure[0].getY() + 1, figure[0].getX() - 1) == 0 &&
				f.fieldYX(figure[2].getY() + 1, figure[2].getX() + 1) == 0 &&
				f.fieldYX(figure[3].getY(), figure[3].getX() + 2) == 0 && figure[0].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 1); figure[0].setY(figure[0].getY() + 1);
				figure[2].setX(figure[2].getX() + 1); figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() + 2); figure[3].setY(figure[3].getY());
				degree = 0;
			}
			break;
		}
		f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
		f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
		f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
		f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
	}
};

class figure3 :public Figure
{
public:
	figure3()
	{
		int x = rand() % 8 + 1;
		color = 3;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x + 1);	figure[1].setY(1);
		figure[2].setX(x - 1);	figure[2].setY(2);
		figure[3].setX(x);		figure[3].setY(2);

	}
	void rotate(Field &f, Figure *block)override
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);
		switch (degree)
		{
		case 0:
			if (f.fieldYX(figure[0].getY() - 1, figure[0].getX() - 1) == 0 &&
				f.fieldYX(figure[0].getY(), figure[1].getX() - 1) == 0)
			{
				sleep(seconds(0.2));
				figure[1].setX(figure[1].getX() - 1); figure[1].setY(figure[1].getY() + 1);
				figure[2].setX(figure[2].getX());     figure[2].setY(figure[2].getY() - 2);
				figure[3].setX(figure[3].getX() - 1); figure[3].setY(figure[3].getY() - 1);
				degree = 1;
			}

			break;

		case 1:
			if (f.fieldYX(figure[1].getY() - 1, figure[1].getX() + 1) == 0 &&
				f.fieldYX(figure[2].getY() + 2, figure[2].getX()) == 0 &&
				f.fieldYX(figure[3].getY() + 1, figure[3].getX() + 1) == 0 && figure[0].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[1].setX(figure[1].getX() + 1); figure[1].setY(figure[1].getY() - 1);
				figure[2].setX(figure[2].getX());	  figure[2].setY(figure[2].getY() + 2);
				figure[3].setX(figure[3].getX() + 1); figure[3].setY(figure[3].getY() + 1);
				degree = 0;
			}
			break;
		}
		f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
		f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
		f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
		f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
	}
};

class figure4 :public Figure
{
public:
	figure4()
	{
		int x = rand() % 8;
		color = 4;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x + 1);	figure[1].setY(1);
		figure[2].setX(x + 2);	figure[2].setY(1);
		figure[3].setX(x + 1);	figure[3].setY(2);

	}
	void rotate(Field &f, Figure *block)override
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);
		switch (degree)
		{
		case 0:
			if (f.fieldYX(figure[1].getY() - 1, figure[1].getX()) == 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1);	figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() - 1);   figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() - 1);	figure[3].setY(figure[3].getY() - 1);
				degree = 1;
			}
			break;
		case 1:
			if (f.fieldYX(figure[1].getY(), figure[1].getX() + 1) == 0 && figure[0].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1);	figure[0].setY(figure[0].getY() + 1);
				figure[2].setX(figure[2].getX() - 1);	figure[2].setY(figure[2].getY() - 1);
				figure[3].setX(figure[3].getX() + 1);	figure[3].setY(figure[3].getY() - 1);
				degree = 2;
			}
			break;
		case 2:
			if (f.fieldYX(figure[1].getY() + 1, figure[1].getX()) == 0 && figure[0].getY() < HEIGTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 1);	figure[0].setY(figure[0].getY() + 1);
				figure[2].setX(figure[2].getX() + 1);	figure[2].setY(figure[2].getY() - 1);
				figure[3].setX(figure[3].getX() + 1);	figure[3].setY(figure[3].getY() + 1);
				degree = 3;
			}
			break;
		case 3:
			if (f.fieldYX(figure[1].getY(), figure[1].getX() - 1) == 0 && figure[0].getX() > 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 1);	figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() + 1);	figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() - 1);	figure[3].setY(figure[3].getY() + 1);
				degree = 0;
			}
			break;
		}

		f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
		f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
		f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
		f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
	}
};

class figure5 :public Figure
{
public:
	figure5()
	{
		int x = rand() % 9;
		color = 5;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x + 1);	figure[1].setY(1);
		figure[2].setX(x);		figure[2].setY(2);
		figure[3].setX(x + 1);	figure[3].setY(2);

	}
	void rotate(Field &f, Figure *block)override
	{ }
};

class figure6 :public Figure
{
public:
	figure6()
	{
		int x = rand() % 9;
		color = 6;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x);		figure[1].setY(2);
		figure[2].setX(x);		figure[2].setY(3);
		figure[3].setX(x + 1);	figure[3].setY(3);

	}
	void rotate(Field &f, Figure *block)override
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);
		switch (degree)
		{
		case 0:
			if (f.fieldYX(figure[0].getY() + 1, figure[0].getX() + 2) == 0 &&
				f.fieldYX(figure[1].getY(), figure[1].getX() + 1) == 0 && figure[3].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 2);	figure[0].setY(figure[0].getY() + 1);
				figure[1].setX(figure[1].getX() + 1);	figure[1].setY(figure[1].getY());
				figure[2].setX(figure[2].getX());		figure[2].setY(figure[2].getY() - 1);
				figure[3].setX(figure[3].getX() - 1);	figure[3].setY(figure[3].getY());
				degree = 1;
			}
			break;
		case 1:
			if (f.fieldYX(figure[1].getY() + 1, figure[1].getX()) == 0 &&
				f.fieldYX(figure[1].getY() - 1, figure[1].getX()) == 0 &&
				f.fieldYX(figure[2].getY() - 1, figure[2].getX()) == 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 1);		figure[0].setY(figure[0].getY() + 1);
				figure[2].setX(figure[2].getX() + 1);	figure[2].setY(figure[2].getY() - 1);
				figure[3].setX(figure[3].getX());	    figure[3].setY(figure[3].getY() - 2);
				degree = 2;
			}
			break;
		case 2:
			if (f.fieldYX(figure[1].getY(), figure[1].getX() - 1) == 0 &&
				f.fieldYX(figure[1].getY(), figure[1].getX() + 1) == 0 &&
				f.fieldYX(figure[2].getY(), figure[2].getX() + 1) == 0 &&
				figure[0].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 1);	figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() + 1);	figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() + 2);	figure[3].setY(figure[3].getY());
				degree = 3;
			}
			break;
		case 3:
			if (f.fieldYX(figure[1].getY() - 1, figure[1].getX()) == 0 &&
				f.fieldYX(figure[1].getY() + 1, figure[1].getX()) == 0 &&
				f.fieldYX(figure[2].getY() + 1, figure[2].getX()) == 0 &&
				figure[0].getY() < HEIGTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1);	figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() - 1);	figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX());	    figure[3].setY(figure[3].getY() + 2);
				degree = 0;
			}
			break;
		}

		f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
		f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
		f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
		f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
	}
};

class figure7 :public Figure
{
public:
	figure7()
	{
		int x = rand() % 9 + 1;
		color = 7;
		figure[0].setX(x);		figure[0].setY(1);
		figure[1].setX(x);		figure[1].setY(2);
		figure[2].setX(x);		figure[2].setY(3);
		figure[3].setX(x - 1);	figure[3].setY(3);

	}
	void rotate(Field &f, Figure *block)override
	{
		f.fieldYX(block->getYi(0), block->getXi(0), 0);
		f.fieldYX(block->getYi(1), block->getXi(1), 0);
		f.fieldYX(block->getYi(2), block->getXi(2), 0);
		f.fieldYX(block->getYi(3), block->getXi(3), 0);
		switch (degree)
		{
		case 0:
			if (f.fieldYX(figure[0].getY() + 2, figure[0].getX() + 1) == 0 &&
				f.fieldYX(figure[3].getY() - 1, figure[3].getX()) == 0 && figure[0].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1);	figure[0].setY(figure[0].getY() + 2);
				figure[1].setX(figure[1].getX());		figure[1].setY(figure[1].getY() + 1);
				figure[2].setX(figure[2].getX() - 1);		figure[2].setY(figure[2].getY());
				figure[3].setX(figure[3].getX());		figure[3].setY(figure[3].getY() - 1);
				degree = 1;
			}
			break;
		case 1:
			if (f.fieldYX(figure[3].getY() - 1, figure[3].getX() + 1) == 0 &&
				f.fieldYX(figure[3].getY() - 1, figure[3].getX()) == 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() - 2);	figure[0].setY(figure[0].getY());
				figure[1].setX(figure[1].getX() - 1);	figure[1].setY(figure[1].getY() - 1);
				figure[2].setX(figure[2].getX());		figure[2].setY(figure[2].getY() - 2);
				figure[3].setX(figure[3].getX() + 1);	    figure[3].setY(figure[3].getY() - 1);
				degree = 2;
			}
			break;
		case 2:
			if (f.fieldYX(figure[0].getY(), figure[0].getX() + 2) == 0 &&
				f.fieldYX(figure[1].getY(), figure[1].getX() + 1) == 0 &&
				f.fieldYX(figure[1].getY(), figure[1].getX() + 2) == 0 &&
				figure[3].getX() < WIDTH - 1)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX());	figure[0].setY(figure[0].getY() - 1);
				figure[1].setX(figure[1].getX() + 1);	figure[1].setY(figure[1].getY());
				figure[2].setX(figure[2].getX() + 2);	figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() + 1);	figure[3].setY(figure[3].getY() + 2);
				degree = 3;
			}
			break;
		case 3:
			if (f.fieldYX(figure[1].getY() - 1, figure[1].getX()) == 0 &&
				f.fieldYX(figure[1].getY() + 1, figure[1].getX()) == 0 &&
				f.fieldYX(figure[0].getY() + 1, figure[0].getX()) == 0)
			{
				sleep(seconds(0.2));
				figure[0].setX(figure[0].getX() + 1);	figure[0].setY(figure[0].getY() - 1);
				figure[2].setX(figure[2].getX() - 1);	figure[2].setY(figure[2].getY() + 1);
				figure[3].setX(figure[3].getX() - 2);	    figure[3].setY(figure[3].getY());
				degree = 0;
			}
			break;
		}

		f.fieldYX(block->getYi(0), block->getXi(0), block->getColor());
		f.fieldYX(block->getYi(1), block->getXi(1), block->getColor());
		f.fieldYX(block->getYi(2), block->getXi(2), block->getColor());
		f.fieldYX(block->getYi(3), block->getXi(3), block->getColor());
	}
};




