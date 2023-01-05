#pragma once

#include <SFML/Graphics.hpp>

class figuresInfo
{
public:
	void cub(sf::RenderWindow& window, char output3[10][100], std::string playerText, char indexAndCoordonates[200][10], int coordonates, int minus);

	void componentsDrawStatic(sf::RenderWindow& window, std::string Name, std::string componentName);

	void componentsDrawMoving(sf::RenderWindow& window, std::string Name, std::string componentName);


	void figures(sf::RenderWindow& window, int height, int width, int pozMx, int pozMy, int language);

	void componentsNames(sf::RenderWindow& window, std::string Name, int pozMx, int pozMy, bool changeUp, bool changeDown, int x, int y);

	void figureInfoType(sf::RenderWindow& window, std::string type, std::string Name, std::string componentName);
	
	void figureInfoPosition(sf::RenderWindow& window, std::string position, std::string Nmae, std::string componentName, bool changeUp, bool changeDown, int pozMx, int pozMy);

	void figureInfoSize(sf::RenderWindow& window, std::string size, std::string Name, std::string componentName, int language, bool changeUp, bool changeDown, int pozMx, int pozMy);

};