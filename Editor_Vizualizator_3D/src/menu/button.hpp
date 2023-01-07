#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

class button {
public:
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::Font font;
	sf::Sprite sprite;
	sf::Texture icon;

	button(int x, int y, std::string textButton, int length, int height, int characterSize);

	button(int x, int y, std::string textButton, int length, int height, int characterSize, int outlineT, int outLineColorR, int outLineColorG, int outLineColorB, int outLineColorA);

	button(sf::RenderWindow& window, int x, int y, int length, int height, std::string textButton, std::string coordonatesX, std::string coordonatesY, std::string coordonatesZ, int textSize, int coordonatesSize, int outlineT, int outLineColorR, int outLineColorG, int outLineColorB, int outLineColorA);
	
	void changeText(std::string theText);
	
	void coordonatesText(sf::RenderWindow& window, int x, int y, int coordonatesSize, std::string coordonatesX, std::string coordonatesY, std::string coordonatesZ);
	
	void coordonatesValues(sf::RenderWindow& window, int x, int y, std::string coordonatesX, std::string coordonatesY, std::string coordonatesZ);

	void divideCoordonates(sf::RenderWindow& window, int x, int y);

	void divideSigns(sf::RenderWindow& window, int x, int y, int r, int g, int b, int a);

	void setTextColor(int r, int g, int b, int a);

	void changeLengthAndHeight(int length, int height);

	void setButtonColor(int r, int g, int b, int a);

	void setOutlineThicknesAndColor(float t, int r, int g, int b, int a);

	void setTextSize(int x);
	
	void setTextFont(std::string pathToFont);

	void setOutLineThicknes(float t);

	void changePosition(int x, int y);

	void changeTextPosition(int x, int y);

	void setTextOrigin(int x, int y);

	void centerTextInMidddle();

	void putIcon(sf::RenderWindow& window, std::string path, std::string name);

	void textUpDown(sf::RenderWindow& window, std::string sir);

	void changeFont(sf::Font font);

	int getX();
	
	int getY();

	int getLocalBoundsX();

	int getLocalBoundsY();

	int getPositionX();

	int getPositionY();

	void draw(sf::RenderWindow& window);

	void draw(sf::RenderWindow& window, bool d);

};