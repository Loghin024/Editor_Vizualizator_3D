#pragma once

#include <SFML/Graphics.hpp>
#include "..\\geometry\camera.hpp"
class figuresInfo
{
public:
	void cub(sf::RenderWindow& window, char output3[10][100], std::string playerText, char indexAndCoordonates[200][10], int coordonates, int minus);

	void componentsDrawStatic(sf::RenderWindow& window, std::string Name, std::string componentName);

	void componentsDrawMoving(sf::RenderWindow& window, std::string Name, std::string componentName);

	void figures(sf::RenderWindow& window, int height, int width, int pozMx, int pozMy, int language);

	void componentsNames(sf::RenderWindow& window, std::string Name, int pozMx, int pozMy, bool changeUp, bool changeDown, int& x, int& y, int language, Camera camera, int& compScroll);

	void scrollBar(sf::RenderWindow& window, int numberOfComponents, int howMuch, int& scroll);

	void figureInfoType(sf::RenderWindow& window, std::string type, std::string Name, std::string componentName, int language);
	
	void figureInfoPosition(sf::RenderWindow& window, std::string position, std::string Nmae, std::string componentName, bool& changeUp, bool& changeDown, int& pozMx, int& pozMy, Camera camera);

	void figureInfoSize(sf::RenderWindow& window, std::string size, std::string Name, std::string componentName, int language, bool changeUp, bool changeDown, int pozMx, int pozMy, Camera camera);

	void change(sf::RenderWindow& window, Camera camera, std::string saveNameOfProject);

	void deleteComponent(sf::RenderWindow& window, std::string compName, std::string projName, int& pozMx, int& pozMy, int x, int y, Camera camera);

};