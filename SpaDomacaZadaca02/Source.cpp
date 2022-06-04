#include <SFML/Graphics.hpp>
#include "gameOfLife.h"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Hello, SFML world!");
	window.setFramerateLimit(0.5);

	int rows = 10;
	int columns = 10;

	vector<vector<int>> grid = gameOfLife::generateGrid(rows, columns);

	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (clock.getElapsedTime().asSeconds() < 2)
		{
			continue;
		}

		window.clear();
		gameOfLife::drawGrid(window, grid, rows, columns);
		gameOfLife::updateGrid(grid, rows, columns);
		cout << endl;
		window.display();
		clock.restart();
	}

	return 0;
}