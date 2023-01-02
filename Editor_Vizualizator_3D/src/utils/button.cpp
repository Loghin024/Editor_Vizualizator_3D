#include "buton.hpp"
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

button::button(int x, int y, char textButton[100], int length, int height)
{
	using namespace sf;
	RectangleShape rectangle(Vector2f(length, height));
	rectangle.setPosition(x, y);

	sf::Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));
	Text text;
	text.setString(textButton);
	text.setPosition(x + 5, y);
	
}

button::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(text);
}