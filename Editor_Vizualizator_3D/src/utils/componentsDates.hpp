#pragma once

#include <SFML/Graphics.hpp>

class componentsDates
{
public:
	void cubAndSfera(sf::RenderWindow& window, char output3[10][100], std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int index, int language);

	void Line(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int index, int language);

	void conAndCilinder(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int index, int language);

	void prismaPatratica(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int language, int index);

	void piramide(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int language, int index);

	void sfera(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int language);

	void createTxtForComponent(std::string saveNameOfProject, std::string& project, std::string playerInput);
	
	void addCoordonates(std::string saveNameOfProject, std::string& project, std::string playerInput, int coordonates);

	void addIndex(std::string saveNameOfProject, std::string& project, int index);

};
