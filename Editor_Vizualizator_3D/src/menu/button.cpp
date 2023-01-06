#include "button.hpp"
#include <SFML\Graphics.hpp>
#include <vector>
#include <iostream>

button::button(int x, int y, std::string textButton, int length, int height, int characterSize)
{
	using namespace sf;
	rectangle.setSize(Vector2f(length, height));
	rectangle.setPosition(x, y);

	if (!font.loadFromFile("Fonts/RobotoCondensed-Regular.ttf"));
	text.setFont(font);
	text.setString(textButton);
	text.setPosition(x + 10, y - 5);
	text.setCharacterSize(characterSize);

}

button::button(int x, int y, std::string textButton, int length, int height, int characterSize, int outlineT, int outLineColorR, int outLineColorG, int outLineColorB, int outLineColorA)
{
	using namespace sf;
	rectangle.setSize(Vector2f(length, height));
	rectangle.setPosition(x, y);

	if (!font.loadFromFile("Fonts/RobotoCondensed-Regular.ttf"));
	text.setFont(font);
	text.setString(textButton);
	text.setPosition(x + 10, y);
	text.setCharacterSize(characterSize);
	rectangle.setOutlineThickness(outlineT);
	rectangle.setOutlineColor(sf::Color(outLineColorR, outLineColorG, outLineColorB, outLineColorA));

}

button::button(sf::RenderWindow& window, int x, int y,int length, int height, std::string textButton, std::string coordonatesX, std::string coordonatesY, std::string coordonatesZ, int textSize, int coordonatesSize, int outlineT, int outLineColorR, int outLineColorG, int outLineColorB, int outLineColorA)
{
	using namespace sf;
	rectangle.setSize(Vector2f(length, height));
	rectangle.setPosition(x, y);
	rectangle.setOutlineThickness(outlineT);
	rectangle.setOutlineColor(sf::Color(outLineColorR, outLineColorG, outLineColorB, outLineColorA));
	if (!font.loadFromFile("Fonts/RobotoCondensed-Regular.ttf"));
	text.setFont(font);

	//text.getFillColor()
	text.setString(textButton);
	text.setPosition(x + 10, y);
	text.setCharacterSize(textSize);
	window.draw(text);

	text.setCharacterSize(coordonatesSize);
	text.setString(coordonatesX);
	text.setPosition(x + 5, y + 50);
	window.draw(text);

	text.setString(coordonatesY);
	text.setPosition(x + 25, y + 50);
	window.draw(text);

	text.setString(coordonatesZ);
	text.setPosition(x + 45, y + 50);
	window.draw(text);


}

void button::changeText(std::string theText)
{
	text.setString(theText);
}

void button::coordonatesText(sf::RenderWindow& window, int x, int y,int coordonatesSize, std::string coordonatesX, std::string coordonatesY, std::string coordonatesZ)
{
	text.setCharacterSize(coordonatesSize);
	text.setString(coordonatesX);
	text.setPosition(x + 5, y + 50);
	window.draw(text);

	text.setString(coordonatesY);
	text.setPosition(x + 5 + 72, y + 50);
	window.draw(text);

	text.setString(coordonatesZ);
	text.setPosition(x + 5 + 72 * 2, y + 50);
	window.draw(text);
}

void button::coordonatesValues(sf::RenderWindow& window, int x, int y, std::string coordonatesX, std::string coordonatesY, std::string coordonatesZ)
{
	
	text.setCharacterSize(25);
	text.setString(coordonatesX);
	text.setPosition(x + 22, y + 50);
	window.draw(text);

	text.setString(coordonatesY);
	text.setPosition(x + 22 + 72, y + 50);
	window.draw(text);

	text.setString(coordonatesZ);
	text.setPosition(x + 22 + 72 * 2, y + 50);
	window.draw(text);
}

void button::divideCoordonates(sf::RenderWindow& window, int x, int y)
{
	sf::RectangleShape line(sf::Vector2f(2, 65));

	line.setPosition(x + 70, 710);
	window.draw(line);

	line.setPosition(x + 140, 710);
	window.draw(line);

}

void button::divideSigns(sf::RenderWindow& window, int x, int y, int r, int g, int b, int a)
{
	sf::RectangleShape line(sf::Vector2f(2, 37));

	line.setPosition(x + 32, 738);
	window.draw(line);

	line.setPosition(x + 32 + 65, 738);
	window.draw(line);

	line.setPosition(x + 32 + 130, 738);
	window.draw(line);

	sf::Text minus("-", font,30);
	sf::Text plus("+", font, 30);

	minus.setPosition( x + 15, 735);
	window.draw(minus);
	minus.setPosition(x + 15 + 65, 735);
	window.draw(minus);
	minus.setPosition(x + 15 + 130, 735);
	window.draw(minus);

	plus.setPosition(x + 32 + 15, 735);
	window.draw(plus);
	plus.setPosition(x + 32 + 15 + 65, 735);
	window.draw(plus);
	plus.setPosition(x + 32 + 15 + 130, 735);
	window.draw(plus);
}

void button::setTextColor(int r, int g, int b, int a)
{
	text.setFillColor(sf::Color(r, g, b, a));
}

void button::changeLengthAndHeight(int length, int height)
{
	rectangle.setSize(sf::Vector2f(length, height));
}

void button::setButtonColor(int r, int g, int b, int a)
{
	rectangle.setFillColor(sf::Color(r, g, b, a));
}

void button::setOutlineThicknesAndColor(float t, int r, int g, int b, int a)
{
	rectangle.setOutlineThickness(t);
	rectangle.setOutlineColor(sf::Color(r, g, b, a));
}

void button::setOutLineThicknes(float t)
{
	rectangle.setOutlineThickness(t);
}

void button::setTextSize(int x)
{
	text.setCharacterSize(x);
}

void button::changePosition(int x, int y)
{
	rectangle.setPosition(x, y);
	changeTextPosition(x + 10, y);
}

void button::centerTextInMidddle()
{
	sf::FloatRect f = sprite.getLocalBounds();
	text.setPosition(f.width + 15,
					rectangle.getPosition().y + rectangle.getSize().y / 2 - text.getLocalBounds().height / 2 - 5);
}

void button::textUpDown(sf::RenderWindow& window, std::string sir)
{
	std::string first = "";
	std::string second = "";
	bool t = 0;
	for (int i = 0; i < sir.size(); i++)
	{
		if (sir[i] == ' ') t = 1;
		if((sir[i] >= 'a' && sir[i] <= 'z') || (sir[i] >= 'A' && sir[i] <= 'Z'))
		if (t == 0)
		{
			first += sir[i];
		}
		else
		{
			second += sir[i];
		}
	}
	sf::FloatRect f = sprite.getLocalBounds();

	window.draw(rectangle);

	//std::cout  << first << " " << second << std::endl;
	text.setString(first.c_str());
	text.setPosition(f.width + 15,
		rectangle.getPosition().y - 5);
	window.draw(text);
	text.setString(second.c_str());
	text.setPosition(f.width + 15,
		rectangle.getPosition().y + rectangle.getSize().y / 2 - text.getLocalBounds().height / 2 + 5);
	window.draw(text);
}

void button::putIcon(sf::RenderWindow& window, std::string path, std::string name)
{
	path = "icons\\";
	path += name;
	if (name == "Con")
		path += "e";
	path += ".png";

	icon.loadFromFile(path.c_str());
	sprite.setTexture(icon);
	float x = 0, y = 0;
	x = rectangle.getPosition().x;
	y = rectangle.getPosition().y;
	//rectangle.getPosition()
	//std::cout << x << " " << y << std::endl;
	sprite.setPosition(x + 10, y);
	window.draw(sprite);
}

void button::changeFont(sf::Font font)
{
	text.setFont(font);
}

void button::changeTextPosition(int x, int y)
{
	text.setPosition(x, y);
}

int button::getX()
{
	return rectangle.getPosition().x;
}

int button::getY()
{
	return rectangle.getPosition().y;
}

int button::getLocalBoundsX()
{
	return text.getLocalBounds().width;
}

int button::getLocalBoundsY()
{
	return text.getLocalBounds().height;
}

int button::getPositionX()
{
	return rectangle.getPosition().x;
}

int button::getPositionY()
{
	return rectangle.getPosition().y;
}

void button::setTextOrigin(int x, int y)
{
	text.setOrigin(x, y);
}

void button::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);
	window.draw(text);
}

void button::draw(sf::RenderWindow& window, bool d)
{
	if (d)
	{
		window.draw(rectangle);
		window.draw(text);
	}
}


