#include "gameOfLife.h"
#include <iostream>

//Make grid with random values
vector<vector<int>> gameOfLife::generateGrid(int rows, int columns)
{
	vector<vector<int>> grid;

	srand((unsigned)std::time(NULL));

	for (int i = 0; i < rows; i++)
	{
		vector<int> v;
		grid.push_back(v);
		for (int j = 0; j < columns; j++)
		{
			float randNum = (float)rand() / RAND_MAX;

			if (randNum > 0.25)
			{
				grid[i].push_back(0);
				cout << 0;
			}
			else
			{
				grid[i].push_back(1);
				cout << 1;
			}
		}
		cout << endl;
	}

	cout << endl;
	return grid;
}

//Draw grid with sfml
void gameOfLife::drawGrid(sf::RenderWindow& win, vector<vector<int>> &grid, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			sf::RectangleShape rect(sf::Vector2f(25, 25));
			rect.setPosition(0+(25 + 5)*j,0+(25 + 5)*i);

			if (grid[i][j] == 1)
			{
				rect.setFillColor(sf::Color(255, 255, 255));
			}
			else
			{
				rect.setFillColor(sf::Color(50, 50, 50));
			}

			win.draw(rect);
		}
	}
}

//Wait 2 seconds and update grid
void gameOfLife::updateGrid(vector<vector<int>>& grid, int rows, int columns)
{
	vector<vector<int>> newGrid = grid;

	//For every cell
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int totalAliveNeighbours = 0;

			if (i != 0)
			{
				if (grid[i - 1][j] == 1) { totalAliveNeighbours += 1; }
				if (j != 0)
				{
					if (grid[i - 1][j - 1] == 1) { totalAliveNeighbours += 1; }
				}
				if (j != columns - 1)
				{
					if (grid[i - 1][j + 1] == 1) { totalAliveNeighbours += 1; }
				}
			}

			if (i != rows - 1)
			{
				if (grid[i + 1][j] == 1) { totalAliveNeighbours += 1; }
				if (j != 0)
				{
					if (grid[i + 1][j - 1] == 1) { totalAliveNeighbours += 1; }
				}
				if (j != columns - 1)
				{
					if (grid[i + 1][j + 1] == 1) { totalAliveNeighbours += 1; }
				}
			}

			if (j != 0)
			{
				if (grid[i][j - 1] == 1) { totalAliveNeighbours += 1; }
			}
			if (j != columns - 1)
			{
				if (grid[i][j + 1] == 1) { totalAliveNeighbours += 1; }
			}

			cout << totalAliveNeighbours << " ";
			//Updating logic
			if (grid[i][j] == 1) //ALIVE
			{
				if (totalAliveNeighbours < 2 || totalAliveNeighbours > 3)
				{
					newGrid[i][j] = 0;
				}
				else
				{
					newGrid[i][j] = 1;
				}

			}
			else if (grid[i][j] == 0) //DEAD
			{
				if (totalAliveNeighbours == 3)
				{
					newGrid[i][j] = 1;
				}
				else
				{
					newGrid[i][j] = 0;
				}
			}
		}

		cout << endl;

	}

	grid = newGrid;
}