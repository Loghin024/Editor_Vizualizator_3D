#include <SFML/Graphics.hpp>
#include "componentsDates.hpp"
#include "../menu/texts.hpp"
#include "../menu/button.hpp"
#include "../geometry/geometrie.hpp"
#include "../geometry/solid3d.hpp"
#include "foldersAndTexts.hpp"

void componentsDates::cubAndSfera(sf::RenderWindow& window, char output3[10][100], std::string playerText, char indexAndCoordonates[200][100], int coordonates,int minus, int index, int language)
{
	using namespace sf;

	char output[10][100]{};
	FILE* out = fopen("src\\programtexts/textsForCreateScreenCub.txt", "r");
	for (int j = 0; j <= 6; j++)
		for (int i = 1; i <= 3; i++)
		{
			char sir[100];
			fgets(sir, 100, out);
			if (language == i)
				strcpy(output[j], sir);
		}
	fclose(out);

	Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));
	texts detail(output[3], 10, 50, 0, 0, 30, 0, 0, 0, 255);
	detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	FloatRect nameText = detail.getLocalBoundsAuto();
	Text playerText2(playerText, font, 30);
	//playerText2.setFillColor(Color(26, 30, 28, 255));
	FloatRect width = detail.getLocalBoundsAuto();
	playerText2.setPosition(600, 70);

	if (coordonates > 0)
	{
		detail.changeTheText(output[1]);
		std::cout << output[1] << std::endl;
		detail.changePosition(45, 120);
		detail.draw(window);
		width = detail.getLocalBoundsAuto();

		//playerText2.setPosition(10 + 16 * strlen(output3[1]) + 100 * (coordonates - 1) + 25 + minus, 100);

		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		for (int i = 1; i <= coordonates;i++)
		{

			if (i == 1)
			{
				detail.PositionSizeString("x:", 45 + textWidth.width + 10, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 40, 120);
			}
			detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
			detail.draw(window);
		
			if (i == 2) 
			{ 
				detail.PositionSizeString("y:", 45 + textWidth.width + 150, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 180, 120);
			} 
			detail.draw(window);

			if (i == 3) 
			{ 
				detail.PositionSizeString("z:", 45 + textWidth.width + 290, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 320, 120);
			} 
			detail.draw(window);
		}
		if (coordonates == 4)
		{
			//std::cout << output3[2] << " ";
			if(index == 2)
				detail.PositionSizeString(output[2], 45, 170, 30);
			else if (index == 4)
			{
				detail.PositionSizeString(output[4], 45, 170, 30);
			}

			detail.draw(window);
			FloatRect width = detail.getLocalBoundsAuto();
			playerText2.setPosition(width.width + 45 + 10, 170);
			playerText2.setString(playerText);
			window.draw(playerText2);
		}
	}

	for (int i = 0; i < 4;i++)
	{
		detail.changeTheText(output[1]);
		detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
		detail.changeColor(255, 255, 255, 255);
		sf::FloatRect textWidth = detail.getLocalBoundsAuto();

		if
			(i == 0) detail.PositionSizeString(indexAndCoordonates[i], 600, 70, 30);
		else
			detail.PositionSizeString(indexAndCoordonates[i], 45 + textWidth.width + 40 + (i-1)*140, 120, 30);
		detail.draw(window);
	}
	
	window.draw(playerText2);
}

void componentsDates::Line(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int index, int language)
{
	using namespace sf;
	char output[10][100]{};
	FILE* text = fopen("src\\programtexts/Line.txt", "r");
	for(int i = 0; i<=1; i++)
	{
		char sir[100];
		for (int j = 1; j <= 3; j++)
		{
			fgets(sir, 100, text);
			if (j == language)
				strncpy(output[i], sir, strlen(sir) - 1);
		}
	}

	sf::Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));
	texts text1(output[0], 45, 120, 0, 0, 30, 0, 0, 0, 255);
	text1.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	sf::FloatRect nameText = text1.getLocalBoundsAuto();
	Text playerText2(playerText, font, 30);
	//playerText2.setFillColor(Color(26, 30, 28, 255));
	FloatRect width = text1.getLocalBoundsAuto();
	playerText2.setPosition(600, 70);

	if (coordonates > 0)
	{
		text1.draw(window);

		texts text2(output[1], 45, 170, 0, 0, 30, 0, 0, 0, 255);
		text2.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
		FloatRect width2 = text2.getLocalBoundsAuto();

		if (coordonates >= 4)
			text2.draw(window);

		if (coordonates <= 3 && coordonates >= 1)
		{
			playerText2.setPosition(45 + width.width + 40 + (140 * (coordonates - 1)), 120);
			window.draw(playerText2);
		}

		if (coordonates >= 4)
		{
			playerText2.setPosition(45 + width2.width + 40 + (140 * (coordonates - 4)), 170);
			window.draw(playerText2);
		}

		texts detail(output[3], 10, 50, 0, 0, 30, 0, 0, 0, 255);
		for (int i = 1; i <= coordonates;i++)
		{

			if (i == 1)
			{
				detail.PositionSizeString("x:", 45 + width.width + 10, 120, 30);
				playerText2.setPosition(45 + width.width + 40, 120);
			}
			detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
			detail.draw(window);

			if (i == 2)
			{
				detail.PositionSizeString("y:", 45 + width.width + 150, 120, 30);
				playerText2.setPosition(45 + width.width + 180, 120);
			}
			detail.draw(window);

			if (i == 3)
			{
				detail.PositionSizeString("z:", 45 + width.width + 290, 120, 30);
				playerText2.setPosition(45 + width.width + 320, 120);
			}
			detail.draw(window);
			if (i == 4)
			{
				detail.PositionSizeString("x:", 45 + width2.width + 10, 170, 30);
				playerText2.setPosition(45 + width.width + 40, 120);
			}
			detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
			detail.draw(window);

			if (i == 5)
			{
				detail.PositionSizeString("y:", 45 + width2.width + 150, 170, 30);
				playerText2.setPosition(45 + width.width + 180, 120);
			}
			detail.draw(window);

			if (i == 6)
			{
				detail.PositionSizeString("z:", 45 + width2.width + 290, 170, 30);
				playerText2.setPosition(45 + width.width + 320, 120);
			}
			detail.draw(window);
		}

		fclose(text);
		for (int i = 0; i < coordonates;i++)
		{
			detail.changeTheText(output[0]);
			detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
			detail.changeColor(255, 255, 255, 255);
			sf::FloatRect textWidth = detail.getLocalBoundsAuto();

			if
				(i == 0) detail.PositionSizeString(indexAndCoordonates[i], 600, 70, 30);
			else if (i >= 1 && i < 4)
				detail.PositionSizeString(indexAndCoordonates[i], 45 + width.width + 40 + (i - 1) * 140, 120, 30);
			else
			{
				detail.changeTheText(output[1]);
				sf::FloatRect textWidth = detail.getLocalBoundsAuto();
				detail.PositionSizeString(indexAndCoordonates[i], 45 + width2.width + 40 + (i - 4) * 140, 170, 30);

			}
			detail.draw(window);
		}
	}
	if(coordonates == 0)
	window.draw(playerText2);
}


void componentsDates::conAndCilinder(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int index, int language)
{
	using namespace sf;
	char output[10][100]{};
	FILE* out = fopen("src\\programtexts/textsForCreateScreenCon.txt", "r");
	for (int j = 0; j <= 6; j++)
		for (int i = 1; i <= 3; i++)
		{
			char sir[100];
			fgets(sir, 100, out);
			if (language == i)
				strcpy(output[j], sir);
		}
	fclose(out);
	Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));
	texts detail(output[3], 10, 50, 0, 0, 30, 0, 0, 0, 255);
	//FloatRect nameText = detail.getLocalBoundsAuto();
	//Text playerText2(playerText, font, 30);
	//playerText2.setFillColor(Color(26, 30, 28, 255));
	//FloatRect width = detail.getLocalBoundsAuto();
	//playerText2.setPosition(width.width + 50, 50);

	FloatRect nameText = detail.getLocalBoundsAuto();
	Text playerText2(playerText, font, 30);
	//playerText2.setFillColor(Color(26, 30, 28, 255));
	FloatRect width = detail.getLocalBoundsAuto();
	playerText2.setPosition(600, 70);

	if (coordonates > 0)
	{
		detail.changeTheText(output[1]);
		std::cout << output[1] << std::endl;
		detail.changePosition(45, 120);
		detail.draw(window);
		width = detail.getLocalBoundsAuto();

		//playerText2.setPosition(10 + 16 * strlen(output3[1]) + 100 * (coordonates - 1) + 25 + minus, 100);

		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		for (int i = 1; i <= coordonates;i++)
		{
			if (i == 1)
			{
				detail.PositionSizeString("x:", 45 + textWidth.width + 10, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 40, 120);
			}
			detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
			detail.draw(window);

			if (i == 2)
			{
				detail.PositionSizeString("y:", 45 + textWidth.width + 150, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 180, 120);
			}
			detail.draw(window);

			if (i == 3)
			{
				detail.PositionSizeString("z:", 45 + textWidth.width + 290, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 320, 120);
			}
			detail.draw(window);
		}
		if (coordonates == 4)
		{
			//std::cout << output3[2] << " ";
			
			detail.PositionSizeString(output[2], 45, 170, 30);
			sf::FloatRect textWidth = detail.getLocalBoundsAuto();
			detail.draw(window);
			playerText2.setPosition(textWidth.width + 45 + 10, 170);
			playerText2.setString(playerText);
			window.draw(playerText2);
		}

		if (coordonates == 5)
		{
			//std::cout << output3[2] << " ";
			detail.PositionSizeString(output[4], 45, 220, 30);
			sf::FloatRect textWidth = detail.getLocalBoundsAuto();
			detail.draw(window);
			playerText2.setPosition(textWidth.width + 45 + 10, 220);
			playerText2.setString(playerText);
			window.draw(playerText2);

		}
	}
	for (int i = 0; i < coordonates;i++)
	{
		detail.changeTheText(output[1]);
		detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
		detail.changeColor(255, 255, 255, 255);
		sf::FloatRect textWidth = detail.getLocalBoundsAuto();

		if(i == 0) detail.PositionSizeString(indexAndCoordonates[i], 600, 70, 30);
		else if(i >=1 && i <=3)
			detail.PositionSizeString(indexAndCoordonates[i], 45 + textWidth.width + 40 + (i - 1) * 140, 120, 30);
		else if (i == 4)
		{
			detail.PositionSizeString(output[2], 45, 170, 30);
			sf::FloatRect textWidth = detail.getLocalBoundsAuto();
			detail.changeColor(0, 0, 0, 255);
			detail.draw(window);

			detail.PositionSizeString(indexAndCoordonates[i], 45 + textWidth.width + 40 + (i - 1) * 140, 170, 30);
			detail.changePosition(textWidth.width + 55, 170);
			detail.changeColor(255, 255, 255, 255);
			detail.draw(window);
		}
		detail.draw(window);
	}

	window.draw(playerText2);
}

void componentsDates::prismaPatratica(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int language, int index)
{
	using namespace sf;
	char output[10][100]{};
	FILE* getText = fopen("src\\programtexts/textsForCreateScreenPrisma.txt", "r");
	for (int j = 0; j <= 6; j++)
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, getText);
		if (i == language)
			strcpy(output[j], a);
	}
	using namespace sf;
	fclose(getText);
	Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));
	texts detail(output[0], 45, 70, 0, 0, 30, 0, 0, 0, 255);
	FloatRect nameText = detail.getLocalBoundsAuto();
	Text playerText2(playerText, font, 30);
	playerText2.setFillColor(Color(255, 255, 255, 255));
	FloatRect width = detail.getLocalBoundsAuto();
	playerText2.setPosition(600, 70);
	if (coordonates > 0)
	{
		detail.changeTheText(output[1]);
		detail.changePosition(45, 120);
		detail.draw(window);
		width = detail.getLocalBoundsAuto();

		//playerText2.setPosition(10 + 16 * strlen(output3[1]) + 100 * (coordonates - 1) + 25 + minus, 100);

		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		for (int i = 1; i <= coordonates;i++)
		{
			if (i == 1)
			{
				detail.PositionSizeString("x:", 45 + textWidth.width + 10, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 40, 120);
			}
			detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
			detail.draw(window);

			if (i == 2)
			{
				detail.PositionSizeString("y:", 45 + textWidth.width + 150, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 180, 120);
			}
			detail.draw(window);

			if (i == 3)
			{
				detail.PositionSizeString("z:", 45 + textWidth.width + 290, 120, 30);
				playerText2.setPosition(45 + textWidth.width + 320, 120);
			}
			detail.draw(window);
		}
	}
	if (coordonates == 4)
	{
		//std::cout << output3[2] << " ";
		detail.PositionSizeString(output[2], 45, 170, 30);
		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		detail.draw(window);
		playerText2.setPosition(600, 170);
		playerText2.setString(playerText);
		window.draw(playerText2);
	}
	if (coordonates == 5)
	{
		if (index == 3)
			detail.PositionSizeString(output[3], 45, 220, 30);
		else
			detail.PositionSizeString(output[5], 45, 220, 30);
		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		detail.draw(window);
		playerText2.setPosition(600, 220);
		playerText2.setString(playerText);
		window.draw(playerText2);
	}
	if (coordonates == 6)
	{
		if(index == 3)
			detail.PositionSizeString(output[4], 45, 270, 30);
		else
			detail.PositionSizeString(output[6], 45, 270, 30);

		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		detail.draw(window);
		playerText2.setPosition(600, 270);
		playerText2.setString(playerText);
		window.draw(playerText2);
	}

	for (int i = 0; i < coordonates;i++)
	{
		detail.changeColor(255, 255, 255, 255);
		detail.changeTheText(output[1]);
		sf::FloatRect textWidth = detail.getLocalBoundsAuto();
		if (i == 0) detail.PositionSizeString(indexAndCoordonates[i], 600, 70, 30);
		else if (i <= 3)
		{
			detail.PositionSizeString(indexAndCoordonates[i], 45 + textWidth.width + 40 + (i - 1) * 140, 120, 30);

		}
		else
		{
			detail.PositionSizeString(indexAndCoordonates[i], 600, 70 + 50*(i-2), 30);
			detail.draw(window);

			if (i >= 4)
			{
				detail.PositionSizeString(output[2], 45, 170, 30);
				detail.changeColor(0, 0, 0, 255);
				detail.draw(window);
			}

			if (i >= 5)
			{
				if(index == 3)
					detail.PositionSizeString(output[3], 45, 220, 30);
				else
					detail.PositionSizeString(output[5], 45, 220, 30);
				detail.changeColor(0, 0, 0, 255);
				detail.draw(window);
			}
		}
		detail.draw(window);
	}

	window.draw(playerText2);
}

void componentsDates::piramide(sf::RenderWindow& window, std::string playerText, char indexAndCoordonates[200][100], int coordonates, int minus, int language, int index)
{
	using namespace sf;
	char output[10][100]{};
	FILE* getText = fopen("src\\programtexts/textsForCreateScreenPiramide.txt", "r");
	for (int j = 0; j <= 4; j++)
		for (int i = 1; i <= 3; i++)
		{
			char a[100];
			fgets(a, 99, getText);
			if (i == language)
				strcpy(output[j], a);
		}
	using namespace sf;
	fclose(getText);
	Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));
	texts detail(output[0], 10, 50, 0, 0, 30, 0, 0, 0, 255);
	FloatRect nameText = detail.getLocalBoundsAuto();
	Text playerText2(playerText, font, 40);
	playerText2.setFillColor(Color(26, 30, 28, 255));
	FloatRect width = detail.getLocalBoundsAuto();
	playerText2.setPosition(width.width + 50, 50);

	if (coordonates > 0)
	{
		detail.changeTheText(output[1]);
		std::cout << output[1] << std::endl;
		detail.changePosition(10, 100);
		detail.draw(window);
		width = detail.getLocalBoundsAuto();

		//playerText2.setPosition(10 + 16 * strlen(output3[1]) + 100 * (coordonates - 1) + 25 + minus, 100);

		for (int i = 1; i <= coordonates;i++)
		{
			if (i == 1)
			{
				detail.PositionSizeString("x:", 10 + 16 * strlen(output[1]) + 100 * (i - 1) + minus, 100, 40);
				playerText2.setPosition(width.width + 50, 100);
			}
			detail.draw(window);

			if (i == 2)
			{
				detail.PositionSizeString("y:", 10 + 16 * strlen(output[1]) + 100 * (i - 1) + minus, 100, 40);
				playerText2.setPosition(width.width + 150, 100);
			}
			detail.draw(window);

			if (i == 3)
			{
				detail.PositionSizeString("z:", 10 + 16 * strlen(output[1]) + 100 * (i - 1) + minus, 100, 40);
				playerText2.setPosition(width.width + 250, 100);
			}
			detail.draw(window);

		}

	}
	for (int i = 0; i < 4;i++)
	{
		if
			(i == 0) detail.PositionSizeString(indexAndCoordonates[i], nameText.width + 50, 50, 40);
		else
			detail.PositionSizeString(indexAndCoordonates[i], 10 + 16 * strlen(output[1]) + 100 * (i - 1) + 25 - minus, 100, 40);
		detail.draw(window);
	}
	if (coordonates == 4)
	{
		//std::cout << output3[2] << " ";
		detail.PositionSizeString(output[2], 10, 150, 40);
		detail.draw(window);
		FloatRect width = detail.getLocalBoundsAuto();
		playerText2.setPosition(width.width + 15, 150);
		playerText2.setString(playerText);
		window.draw(playerText2);
	}
	if (coordonates == 5)
	{
		//std::cout << output3[2] << " ";
		detail.PositionSizeString(output[3], 10, 150, 40);
		detail.draw(window);
		FloatRect width = detail.getLocalBoundsAuto();
		playerText2.setPosition(width.width + 15, 150);		
		playerText2.setString(playerText);
		window.draw(playerText2);
	}
	if (coordonates == 6)
	{
		//std::cout << output3[2] << " ";
		detail.PositionSizeString(output[4], 10, 150, 40);
		detail.draw(window);
		FloatRect width = detail.getLocalBoundsAuto();
		playerText2.setPosition(width.width + 15, 150);
		playerText2.setString(playerText);
		window.draw(playerText2);
	}

	window.draw(playerText2);
}

void componentsDates::createTxtForComponent(std::string saveNameOfProject, std::string& project, std::string playerInput)
{
	char projectFolder[100];
	strcpy(projectFolder, "src\\userProjects\\");
	strcat(projectFolder, saveNameOfProject.c_str());
	strcat(projectFolder, "\\name.txt");
	FILE* numeProiect = fopen(projectFolder, "a");
	project = playerInput;
	fprintf(numeProiect, "%s", project.c_str());
	fprintf(numeProiect, "%s", "\n");
	fclose(numeProiect);

	strcpy(projectFolder, "src\\userProjects\\");
	strcat(projectFolder, saveNameOfProject.c_str());
	strcat(projectFolder, "\\");
	char sir[100];
	strcpy(sir, project.c_str());
	strcat(projectFolder, sir);
	strcat(projectFolder, ".txt");
	FILE* numeProiect2 = fopen(projectFolder, "w");
	fclose(numeProiect2);
}

void componentsDates::addCoordonates(std::string saveNameOfProject, std::string& project, std::string playerInput, int coordonates)
{
	char projectFolder[100];

	strcpy(projectFolder, "src\\userProjects\\");
	strcat(projectFolder, saveNameOfProject.c_str());
	strcat(projectFolder, "\\");
	char sir[100];
	strcpy(sir, project.c_str());
	strcat(projectFolder, sir);
	strcat(projectFolder, ".txt");

	FILE* add = fopen(projectFolder, "a");
	//FILE* add2 = fopen(projectFolder, "r+");
	fprintf(add, "%s", playerInput.c_str());
	fprintf(add, "%s", " ");
	
	if(coordonates == 3)
		fprintf(add, "%s", "\n");

	fclose(add);
}

void componentsDates::addIndex(std::string saveNameOfProject, std::string& project, int index)
{
	char projectFolder[100];

	strcpy(projectFolder, "src\\userProjects\\");
	strcat(projectFolder, saveNameOfProject.c_str());
	strcat(projectFolder, "\\");
	char sir[100];
	strcpy(sir, project.c_str());
	strcat(projectFolder, sir);
	strcat(projectFolder, ".txt");

	FILE* add = fopen(projectFolder, "a");
	fprintf(add, "%s", "\n");

	//FILE* add2 = fopen(projectFolder, "r+");
	fprintf(add, "%d", index);
	fprintf(add, "%s", " ");


	fclose(add);
}