#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class gameOfLife
{
public:
	static vector<vector<int>> generateGrid(int rows, int colums);
	static void drawGrid(sf::RenderWindow& win, vector<vector<int>>& grid, int columns, int rows);
	static void updateGrid(vector<vector<int>>& grid, int columns, int rows);


};