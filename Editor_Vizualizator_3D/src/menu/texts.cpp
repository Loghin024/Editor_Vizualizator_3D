#include "texts.hpp"
#include <SFML\Graphics.hpp>
#include <iostream>

texts::texts(std::string theText,int x, int y, int originX, int originY, int characterSize, int r, int g, int b, int a)
{
	if (!font.loadFromFile("Fonts/calibri.ttf"));
	text.setFont(font);
	text.setString(theText);
	text.setPosition(x, y);
	text.setOrigin(originX, originY);
	text.setFillColor(sf::Color(r, g, b, a));
	text.setCharacterSize(characterSize);
}

texts::texts(std::string theText, int x, int y, int originX, int originY, int characterSize)
{
	if (!font.loadFromFile("Fonts/calibri.ttf"));
	text.setFont(font);
	text.setString(theText);
	text.setPosition(x, y);
	text.setOrigin(originX, originY);
	text.setCharacterSize(characterSize);
}

texts::texts(int size, int r, int g, int b, int a, std::string theText)
{
	if (!font.loadFromFile("Fonts/calibri.ttf"));
	text.setFont(font);
	text.setString(theText);
	text.setFillColor(sf::Color(r, g, b, a));
}

void texts::changePosition(int x, int y)
{
	text.setPosition(x, y);
}

void texts::changeOrigin(int originX, int originY)
{
	text.setOrigin(originX, originY);
}

void texts::changeColor(int r, int g, int b, int a)
{
	text.setFillColor(sf::Color(r, g, b, a));
}

void texts::changeTheText(std::string theText)
{
	text.setString(theText);
}

void texts::getLocalBounds(int &x, int &y)
{
	sf::FloatRect textRect = text.getLocalBounds();
	x = textRect.width / 2;
	y = textRect.height / 2;
}

sf::FloatRect texts::getLocalBoundsAuto()
{
	sf::FloatRect textRect = text.getLocalBounds();
	return textRect;
}

void texts::PositionSizeString(std::string theText, int x, int y, int size)
{
	text.setCharacterSize(size);
	text.setString(theText);
	text.setPosition(x, y);
}

int texts::getX()
{
	return text.getPosition().x;
}

void texts::draw(sf::RenderWindow& window)
{
	window.draw(text);
}
