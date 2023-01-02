#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class texts
{
public:
	sf::Text text;
	sf::Font font;

	texts(std::string theText, int x, int y, int originX, int originY, int characterSize, int r, int g, int b, int a);

	texts(std::string theText, int x, int y, int originX, int originY, int characterSize);

	texts(int size, int r, int g, int b, int a, std::string theText);

	void draw(sf::RenderWindow& window);

	void changePosition(int x, int y);

	void changeOrigin(int originX, int originY);

	void changeTheText(std::string theText);

	void changeColor(int r, int g, int b, int a);

	void getLocalBounds(int& x, int& y);

	int getX();

	void PositionSizeString(std::string theText, int x, int y, int size);
};


