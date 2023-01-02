#include "figuresInfo.hpp"
#include "../menu/texts.hpp"
#include <SFML/Graphics.hpp>
#include <set>

void figuresInfo::cub(sf::RenderWindow& window, char output3[10][100], std::string playerText, char indexAndCoordonates[200][10], int coordonates, int minus)
{
	using namespace sf;
	using namespace std;

	Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));
	texts detail(output3[3], 10, 50, 0, 0, 40, 0, 0, 0, 255);
	Text playerText2(playerText, font, 40);

	if (coordonates > 0)
	{
		detail.changeTheText(output3[1]);
		std::cout << output3[1] << std::endl;
		detail.changePosition(10, 100);
		detail.draw(window);
		//playerText2.setPosition(10 + 16 * strlen(output3[1]) + 100 * (coordonates - 1) + 25 + minus, 100);

		for (int i = 1; i <= coordonates;i++)
		{
			if (i == 1) { detail.PositionSizeString("x:", 10 + 16 * strlen(output3[1]) + 100 * (i - 1) + minus, 100, 40); } detail.draw(window);
			if (i == 2) { detail.PositionSizeString("y:", 10 + 16 * strlen(output3[1]) + 100 * (i - 1) + minus, 100, 40); } detail.draw(window);
			if (i == 3) { detail.PositionSizeString("z:", 10 + 16 * strlen(output3[1]) + 100 * (i - 1) + minus, 100, 40); } detail.draw(window);

			for (int i = 1; i < coordonates;i++)
			{
				detail.PositionSizeString(indexAndCoordonates[i], 10 + 16 * strlen(output3[1]) + 100 * (i - 1) + 25 - minus, 100, 40);
				detail.draw(window);
			}
		}
		if (coordonates == 4)
		{
			//std::cout << output3[2] << " ";
			detail.PositionSizeString(output3[2], 10, 150, 40);
			detail.draw(window);
			playerText2.setPosition(10 + 16 * strlen(output3[2]) + minus - 18, 150);
			playerText2.setString(playerText);
			window.draw(playerText2);
		}
	}
	window.draw(playerText2);
}
