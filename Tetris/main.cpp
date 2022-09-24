#include <SFML/Graphics.hpp>

#include "Figure.h"
#include "Field.h"
#include "Game_.h"


using namespace sf;
using namespace std;



int main()
{
	srand(time(0));
	Game game;
	game.play();
}