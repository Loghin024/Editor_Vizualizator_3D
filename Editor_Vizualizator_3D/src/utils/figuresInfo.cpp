#include "figuresInfo.hpp"
#include "../menu/texts.hpp"
#include <SFML/Graphics.hpp>
#include "../menu/button.hpp"
#include "../geometry/geometrie.hpp"
#include "../geometry/solid3d.hpp"
#include <iostream>
//#include "parameters.hpp"
//#include "mouse.hpp"
//#include "..\\utils\mouse.hpp"

void figuresInfo::figures(sf::RenderWindow& window, int height, int width, int PozMx, int PozMy, int language)
{
	using namespace sf;
	char figure[100];
	Vector2u size = window.getSize();
	int line = 0;
	//Camera camera(Vector(0, -100, -230), -30, 0, 0, 1900, 900);

	button figures(0, 15, "", 195, 56, 20, 2, 81, 81, 81, 255);
	figures.setButtonColor(81, 81, 81, 255);

	RectangleShape dividerForFigures(Vector2f(200, size.y));
	dividerForFigures.setFillColor(Color(81, 81, 81, 255));
	window.draw(dividerForFigures);

	sf::Font font;
	if (!font.loadFromFile("Fonts/Oswald-Medium.ttf"));
	//figures.changeFont(font);

	FILE* PosibleFiguresFromFile;
	if (PosibleFiguresFromFile = fopen("src\\programtexts\\posibleFigures.txt", "r"));
	{
		for (int j = 1; j <= 7; j++)
		{
			char sir[100]{};

			figures.setTextFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");

			for (int i = 1; i <= 3; i++)
			{
				fgets(figure, 100, PosibleFiguresFromFile);
				if (i == language)
					strncpy(sir, figure, strlen(figure) - 1);
			}
			line++;
			figures.changeText(sir);
			figures.changePosition(0, 15 + 60 * line);

			if ((PozMx > 0 && PozMx < 195) && (PozMy > 60 * line + 15 && PozMy < 60 * line + 60))
				figures.setButtonColor(41, 45, 48, 255);
			else
				figures.setButtonColor(81, 81, 81, 255);

			//if (line == 6 || line == 7) {
			//	figures.setTextSize(20);
			//	//figures.textUpDown(window, sir);
			//}
			//else figures.setTextSize(25);

			if (line == 1) 	figures.putIcon(window, "", sir);
			figures.centerTextInMidddle();
			/*if(line != 6 && line != 7)*/
			figures.draw(window);
			figures.putIcon(window, "", sir);

		}
		std::fclose(PosibleFiguresFromFile);
	}

	texts goToMainMenu("Meniu Principal", 20, window.getSize().y - 30, 0, 0, 20);

	if (PozMy > window.getSize().y - 30 && PozMx < 180 && PozMy > window.getSize().y - 30 && PozMx > 20)
	{
		goToMainMenu.changeColor(203, 55, 23, 255);
	}
	else
		goToMainMenu.changeColor(255, 255, 255, 255);
	goToMainMenu.draw(window);
}

void figuresInfo::componentsNames(sf::RenderWindow& window, int WINDOW_WIDTH, int WINDOW_HEIGHT, std::string Name, int pozMx, int pozMy, bool changeUp, bool changeDown, int& x, int& y, int language, Camera camera, int& compScroll)
{
	int copieScroll = compScroll;
	int compNr = 0;
	using namespace sf;
	using namespace std;
	int line = 0;
	int numberOfComponents = 0;
	char buff[100]{}, saveSir[100]{};
	int maximComponents = 0;
	int maximComponents2 = 0;

	int select = 0;
	Vector2u size = window.getSize();
	RectangleShape spaceForComponents(Vector2f(size.x, size.y));
	//Vector2f sizeSpace = spaceForComponents.getSize();
	spaceForComponents.setPosition(size.x - 350, 0);
	//cout << size.x - (size.x / 7) << endl;
	spaceForComponents.setFillColor(Color(81, 81, 81, 255));
	window.draw(spaceForComponents);

	RectangleShape Line(Vector2f(350, 2));
	Line.setFillColor(Color(204, 224, 228, 255));

	std::string pathForProject = "src\\userProjects\\";//; + Name; //+ "nameOfFigures";;
	pathForProject += Name + "\\name.txt";
	FILE* componentsFromFile;
	FILE* componentsFromFile2;

	texts text(20, 51, 51, 51, 255, "");
	button components(0, 0, "", 350, 40, 25);
	components.setButtonColor(81, 81, 81, 255);
	components.setTextColor(234, 235, 229, 255);
	components.setTextFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");

	if (!(componentsFromFile = fopen(pathForProject.c_str(), "a+")));
	while (!feof(componentsFromFile))
	{
		std::fgets(buff, 100, componentsFromFile);
		numberOfComponents++;
	}
	std::fclose(componentsFromFile);

	if (numberOfComponents < 11) copieScroll = 0;
	else
	{
		if (copieScroll > (numberOfComponents - 12)) { copieScroll = numberOfComponents - 12; std::cout << "as= " << (numberOfComponents - 11) << std::endl; }
	}

	//if (scrollBar > numberOfComponents - 14) scrollBar = (numberOfComponents - 14);

	//std::cout << "poz cl x: " << x << std::endl;
	//std::cout << "poz cl y: " << y << std::endl;
	//std::cout << "scro= " << copieScroll << std::endl;

	if (!(componentsFromFile2 = fopen(pathForProject.c_str(), "a+")));
	else
	{
		if (std::fgets(buff, 100, componentsFromFile2) == 0);

		while (!feof(componentsFromFile2))
		{
			//std::cout << copieScroll << std::endl;
			if (copieScroll <= 0)
			{
				if (maximComponents2 < 11)
				{
					char sir[100]{};
					std::strncpy(sir, buff, strlen(buff) - 1);
					//	componentsDrawStatic(window, Name, sir);

						//std::cout << sir << std::endl;
					components.changeText(sir);
					components.changePosition(window.getSize().x - 350, 50 + 40 * line + 5 + 2);
					if (pozMx > WINDOW_WIDTH - 350 && pozMy > 50 + 40 * (line)+5 + 2 && pozMy < 50 + 40 * (line)+5 + 2 + 40)
					{
						std::strcpy(saveSir, sir);
						components.setButtonColor(49, 51, 49, 255);
						figureInfoPosition(window, WINDOW_WIDTH, WINDOW_HEIGHT, "Pozitii:", Name, sir, changeUp, changeDown, x, y, camera, compScroll, compNr, language);
						figureInfoSize(window, WINDOW_WIDTH, WINDOW_HEIGHT, "Marimi:", Name, sir, language, changeUp, changeDown, x, y, camera, compScroll, compNr);
						figureInfoType(window, "Tip:", Name, sir, language, compNr);
					}
					else
						components.setButtonColor(81, 81, 81, 255);

					components.draw(window);
					Line.setPosition(size.x - 350, 50 + 40 * (line + 1) + 5);
					window.draw(Line);

					if (pozMx > 1390 && pozMy > 50 + 40 * line + 5 + 2 && pozMy < 50 + 40 * line + 5 + 2 + 30)
					{
						int positionX = components.getPositionX();
						int positionY = components.getPositionY();
						deleteComponent(window, WINDOW_WIDTH, WINDOW_HEIGHT, sir, Name, x, y, positionX, positionY, camera);
						//fseek(componentsFromFile2, SEEK_SET, 0);
					}

					line++;
					maximComponents2++;
					compNr++;

				}
			}
			else copieScroll--;
			std::fgets(buff, 100, componentsFromFile2);

		}
	}
	std::fclose(componentsFromFile2);
	scrollBar(window, numberOfComponents, 0, compScroll);

	//scrollBar(window, numberOfComponents, 0, compScroll);
}

void figuresInfo::justComponentsNmaes(sf::RenderWindow& window, std::string Name, int& compScroll, int compNr, int language)
{
	int copieScroll = compScroll;
	using namespace sf;
	using namespace std;
	int line = 0;
	int numberOfComponents = 0;
	char buff[100]{}, saveSir[100]{};
	int maximComponents = 0;
	int maximComponents2 = 0;

	int select = 0;
	Vector2u size = window.getSize();
	RectangleShape spaceForComponents(Vector2f(size.x, size.y));
	//Vector2f sizeSpace = spaceForComponents.getSize();
	spaceForComponents.setPosition(size.x - 350, 0);
	//cout << size.x - (size.x / 7) << endl;
	spaceForComponents.setFillColor(Color(81, 81, 81, 255));
	window.draw(spaceForComponents);

	RectangleShape Line(Vector2f(350, 2));
	Line.setFillColor(Color(204, 224, 228, 255));

	std::string pathForProject = "src\\userProjects\\";//; + Name; //+ "nameOfFigures";;
	pathForProject += Name + "\\name.txt";
	FILE* componentsFromFile;
	FILE* componentsFromFile2;

	texts text(20, 51, 51, 51, 255, "");
	button components(0, 0, "", 350, 40, 25);
	components.setButtonColor(81, 81, 81, 255);
	components.setTextColor(234, 235, 229, 255);
	components.setTextFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");

	if (!(componentsFromFile = fopen(pathForProject.c_str(), "a+")));
	while (!feof(componentsFromFile))
	{
		std::fgets(buff, 100, componentsFromFile);
		numberOfComponents++;
	}
	std::fclose(componentsFromFile);

	if (numberOfComponents < 11) copieScroll = 0;
	else
	{
		if (copieScroll > (numberOfComponents - 12)) { copieScroll = numberOfComponents - 12; std::cout << "as= " << (numberOfComponents - 11) << std::endl; }
	}

	//if (scrollBar > numberOfComponents - 14) scrollBar = (numberOfComponents - 14);

	//std::cout << "poz cl x: " << x << std::endl;
	//std::cout << "poz cl y: " << y << std::endl;
	//std::cout << "scro= " << copieScroll << std::endl;

	if (!(componentsFromFile2 = fopen(pathForProject.c_str(), "a+")));
	else
	{
		if (std::fgets(buff, 100, componentsFromFile2) == 0);

		while (!feof(componentsFromFile2))
		{
			//std::cout << copieScroll << std::endl;
			if (copieScroll <= 0)
			{
				if (maximComponents2 < 11)
				{
					char sir[100]{};
					std::strncpy(sir, buff, strlen(buff) - 1);
					//	componentsDrawStatic(window, Name, sir);

						//std::cout << sir << std::endl;
					components.changeText(sir);
					components.changePosition(window.getSize().x - 350, 50 + 40 * line + 5 + 2);

					if (!compNr)
						components.setButtonColor(49, 51, 49, 255);
					else
						components.setButtonColor(81, 81, 81, 255);

					components.draw(window);
					Line.setPosition(size.x - 350, 50 + 40 * (line + 1) + 5);
					window.draw(Line);

					line++;
					maximComponents2++;
					compNr--;
				}
			}
			else copieScroll--;
			std::fgets(buff, 100, componentsFromFile2);

		}
	}
	std::fclose(componentsFromFile2);
	scrollBar(window, numberOfComponents, 0, compScroll);

}

void figuresInfo::scrollBar(sf::RenderWindow& window, int numberOfComponents, int howMuch, int& scrollBar)
{
	using namespace sf;
	numberOfComponents--;
	//std::cout << "scroll= " << scrollBar<<std::endl;
	//std::cout << "nr= " << numberOfComponents << std::endl;

	RectangleShape scroll(Vector2f(0, 0));
	scroll.setPosition(window.getSize().x - 15, 57);
	if (numberOfComponents <= 11)
	{
		scroll.setSize(Vector2f(15, 40 * (numberOfComponents)));
		scrollBar = 0;
	}
	else
	{
		scroll.setSize(Vector2f(15, 40 * 11));
		int resize = scroll.getSize().y - ((numberOfComponents - 11) * 10);
		scroll.setSize(Vector2f(15, resize));
		if (scrollBar > numberOfComponents - 11) scrollBar = (numberOfComponents - 11);
		//std::cout << "r " << numberOfComponents << " " << scrollBar << " q ";
		//if (!(scrollBar == numberOfComponents - 14))
		scroll.setPosition(window.getSize().x - 15, 57 + 10 * scrollBar);

	}

	window.draw(scroll);
}

void figuresInfo::figureInfoType(sf::RenderWindow& window, std::string type, std::string name, std::string componentname, int language, int compNr)
{
	int index = 0;
	using namespace sf;
	Vector2u size = window.getSize();
	texts Type(15, 51, 51, 51, 255, type);
	//Type.changePosition(window.getSize().x - 340, 500);
	Type.PositionSizeString(type, window.getSize().x - 340, 510, 25);
	Type.changeColor(255, 255, 255, 255);
	Type.setFont("res/Fonts/Montserrat/static/Montserrat-Light.ttf");
	Type.draw(window);
	FloatRect textwidht = Type.getLocalBoundsAuto();

	std::string pathforproject = "src\\userprojects\\";
	pathforproject += name;
	pathforproject += "\\";
	pathforproject += componentname;
	pathforproject += ".txt";

	FILE* figuresfromfile = fopen(pathforproject.c_str(), "r");
	char buff[100];

	//std::cout <<"eroare= " << pathforproject << std::endl;
	if (!feof(figuresfromfile))
	{
		std::fgets(buff, 100, figuresfromfile);
		std::fgets(buff, 100, figuresfromfile);
		fgets(buff, 100, figuresfromfile);
		char gettext[100]{};
		strncpy(gettext, buff, strlen(buff) - 1);
		for (int i = 0; i < strlen(gettext); i++)
		{
			if (gettext[i] >= '0' && gettext[i] <= '9')
				index = index * 10 + int(gettext[i] - 48);

		}
	}
	fclose(figuresfromfile);


	button figuretype(window.getSize().x - 230, 515, "", 220, 24, 24);

	FILE* typetext;
	if (typetext = fopen("src\\programtexts\\posiblefigures.txt", "r"));

	//if (index == 6 || index == 7)
	//	figuretype.setTextSize(15);
	//else
	figuretype.setTextSize(24);

	char Typename[100]{};
	while (!feof(typetext) && index)
	{
		memset(Typename, 0, sizeof(Typename));
		for (int i = 1; i <= 3; i++)
		{
			fgets(buff, 100, typetext);
			if (i == language)
				strncpy(Typename, buff, strlen(buff) - 1);
			//std::cout << "nume fig =" << Typename << std::endl;

		}
		index--;
	}
	std::fclose(typetext);

	figuretype.changeText(Typename);
	figuretype.setTextColor(51, 51, 51, 255);
	figuretype.setButtonColor(132, 125, 120, 255);

	figuretype.draw(window);
}

void figuresInfo::figureInfoPosition(sf::RenderWindow& window, int WINDOW_WIDTH, int WINDOW_HEIGHT, std::string position, std::string Name, std::string componentName, bool& changeUp, bool& changeDown, int& pozMx, int& pozMy, Camera camera, int compScroll, int compNr, int language)
{
	//if (changeUp > 0) std::cout<<"dadasdasdasdasd";
	using namespace sf;
	std::string xCoordonate = "x: ", yCoordonate = "y: ", zCoordonate = "z: ";
	char X[20]{}, Y[20]{}, Z[20]{};
	int x = 0, y = 0, z = 0;
	//Vector2u size = window.getSize();
	//std::cout << changeUp << " " << changeDown << std::endl;

	char Position[100]{};
	FILE* programUtilities11 = fopen("src\\programtexts/positionText.txt", "r");
	for (int i = 1; i <= 3; i++)
	{
		char buff[100];
		fgets(buff, 100, programUtilities11);
		if (i == language)
			strncpy(Position, buff, strlen(buff) - 1);
	}
	fclose(programUtilities11);
	texts type(15, 51, 51, 51, 255, Position);
	type.PositionSizeString(Position, window.getSize().x - 340, 540, 25);
	type.changeColor(255, 255, 255, 255);
	type.setFont("res/Fonts/Montserrat/static/Montserrat-Light.ttf");
	type.draw(window);

	FloatRect l = type.getLocalBoundsAuto();
	char size[200], index[30]{};
	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";
	//window.getSize().x - 230, 515, "", 220, 24, 24
	button forX(window.getSize().x - 230, 548, "", 220, 24, 24);
	button forY(window.getSize().x - 230, 578, "", 220, 24, 24);
	button forZ(window.getSize().x - 230, 608, "", 220, 24, 24);

	FILE* compALL;
	if (compALL = fopen(pathForProject.c_str(), "r"));
	char buff[100];
	if (!feof(compALL))
	{
		fgets(buff, 100, compALL);
		fgets(size, 200, compALL);
		fgets(index, 10, compALL);

		char getText[100]{};
		strncpy(getText, buff, strlen(buff) - 1);
		int c = 0;
		//std::cout << getText << std::endl;
		for (int i = 0; i < strlen(getText); i++)
		{
			if (getText[i] == ' ') c++;
			else
			{
				if (getText[i] >= '0' && getText[i] <= '9')
				{
					if (c == 0)
						x = x * 10 + int(getText[i] - 48);
					else if (c == 1)
						y = y * 10 + int(getText[i] - 48);
					else if (c == 2)
						z = z * 10 + int(getText[i] - 48);
				}
			}
		}
		c = 0;
		for (int i = 0; i < strlen(getText); i++)
		{
			if (getText[i] == ' ') c++;
			else
			{
				//std::cout << getText[i] << " " << c << std::endl;
				if (c == 0)
					if (getText[i] == '-') x = x * -1;
				if (c == 1)
					if (getText[i] == '-') y = y * -1;
				if (c == 2)
					if (getText[i] == '-') z = z * -1;
			}
		}
	}
	std::fclose(compALL);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 548 && pozMy < 548 + 24)
	{
		forX.setButtonColor(244, 207, 137, 255);
		if (changeDown) { x--; }
		if (changeUp) {
			x++;
		}
	}
	else
		forX.setButtonColor(132, 125, 120, 255);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 578 && pozMy < 578 + 24)
	{
		forY.setButtonColor(244, 207, 137, 255);
		if (changeDown)
		{
			y--;
		}
		if (changeUp)
		{
			y++;
		}
	}
	else
		forY.setButtonColor(132, 125, 120, 255);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 608 && pozMy < 608 + 24)
	{
		forZ.setButtonColor(244, 207, 137, 255);
		if (changeDown)
		{
			z--;
		}
		if (changeUp)
		{
			z++;
		}
	}
	else
		forZ.setButtonColor(132, 125, 120, 255);

	_itoa(x, X, 10); xCoordonate += X;
	_itoa(y, Y, 10); yCoordonate += Y;
	_itoa(z, Z, 10); zCoordonate += Z;
	forX.changeText(xCoordonate);
	forX.setTextColor(51, 51, 51, 255);

	forX.draw(window);

	forY.changeText(yCoordonate);
	forY.setTextColor(51, 51, 51, 255);
	forY.draw(window);

	forZ.changeText(zCoordonate);
	forZ.setTextColor(51, 51, 51, 255);

	forZ.draw(window);

	FILE* newCordonates;
	newCordonates = fopen(pathForProject.c_str(), "w");
	fprintf(newCordonates, "%s", X);
	fprintf(newCordonates, "%s", " ");
	fprintf(newCordonates, "%s", Y);
	fprintf(newCordonates, "%s", " ");
	fprintf(newCordonates, "%s", Z);
	fprintf(newCordonates, "%s", " \n");
	fprintf(newCordonates, "%s", size);
	fprintf(newCordonates, "%s", index);
	fclose(newCordonates);
	if (changeDown || changeUp)
		change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);

}

void figuresInfo::figureInfoSize(sf::RenderWindow& window, int WINDOW_WIDTH, int WINDOW_HEIGHT, std::string _size, std::string Name, std::string componentName, int language, bool changeUp, bool changeDown, int pozMx, int pozMy, Camera camera, int compScroll, int compNr)
{
	int index = 0;
	using namespace sf;
	using namespace std;
	std::string hSize = "H: ", lenSize = "l: ", wSize = "w: ";
	char output[10][100];
	FILE* Texts = fopen("src\\programtexts/textsForSizes.txt", "r");

	for (int j = 0; j < 6; j++)
		for (int i = 1; i <= 3; i++)
		{
			char temporary[100];
			std::fgets(temporary, 100, Texts);
			if (i == language)
				std::strcpy(output[j], temporary);
		}
	std::fclose(Texts);

	texts size(15, 51, 51, 51, 255, output[0]);
	size.PositionSizeString(output[0], window.getSize().x - 340, 630, 25);
	size.changeColor(255, 255, 255, 255);
	size.setFont("res/Fonts/Montserrat/static/Montserrat-Light.ttf");
	size.draw(window);

	FloatRect textWidht = size.getLocalBoundsAuto();

	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";

	FILE* sizeDates = fopen(pathForProject.c_str(), "r");
	char position[100], sizes[101], Index[10];
	//window.getSize().x - 230, 515, "", 220, 24, 24
	button forH(window.getSize().x - 230, 640, "", 220, 24, 24);
	button forlen(window.getSize().x - 230, 670, "", 220, 24, 24);
	button forW(window.getSize().x - 230, 700, "", 220, 24, 24);

	if (!feof(sizeDates))
	{
		std::fgets(position, 100, sizeDates);
		std::fgets(sizes, 101, sizeDates);
		std::fgets(Index, 10, sizeDates);

	}
	char getIndex[100]{};
	std::strncpy(getIndex, Index, strlen(Index) - 1);
	//std::cout << "getIndex= " << getIndex << std::endl;
	for (int i = 0; i < strlen(getIndex); i++)
	{
		if (getIndex[i] >= '0' && getIndex[i] <= '9')
			index = index * 10 + int(getIndex[i] - 48);
	}
	//index /= 10;

	int h = 0, l = 0, L = 0;
	int c = 0;
	for (int i = 0; i < strlen(sizes); i++)
	{
		if (sizes[i] == ' ') c++;
		else
		{
			if (sizes[i] != '-')
			{
				if (c == 0)
					h = h * 10 + int(sizes[i] - 48);
				else if (c == 1)
					l = l * 10 + int(sizes[i] - 48);
				else if (c == 2)
					L = L * 10 + int(sizes[i] - 48);
			}
		}
	}
	c = 0;
	for (int i = 0; i < strlen(sizes); i++)
	{
		if (sizes[i] == ' ') c++;
		else
		{
			//std::cout << getText[i] << " " << c << std::endl;
			if (c == 0)
				if (sizes[i] == '-') h = h * -1;
			if (c == 1)
				if (sizes[i] == '-') l = l * -1;
			if (c == 2)
				if (sizes[i] == '-') L = L * -1;
		}
	}
	std::fclose(sizeDates);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 640 && pozMy < 640 + 24)
	{
		forH.setButtonColor(244, 207, 137, 255);
		if (changeDown) {
			h--; change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);
			int a = 0;
		}
		if (changeUp) {
			h++;change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);
		}
	}
	else
		forH.setButtonColor(132, 125, 120, 255);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 670 && pozMy < 670 + 24)
	{
		forlen.setButtonColor(244, 207, 137, 255);
		if (changeDown) {
			l--;change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);
		}
		if (changeUp) {
			l++; change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);
		}
	}
	else
		forlen.setButtonColor(132, 125, 120, 255);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 700 && pozMy < 700 + 24)
	{
		forW.setButtonColor(244, 207, 137, 255);
		if (changeDown) {
			L--; change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);
		}
		if (changeUp) {
			L++;change(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, Name, componentName, language, pozMx, pozMy, compScroll, compNr);
		}
	}
	else
		forW.setButtonColor(132, 125, 120, 255);

	char H[10]{}, len[10]{}, W[10]{};
	_itoa(h, H, 10); hSize += H;
	_itoa(l, len, 10); lenSize += len;
	_itoa(L, W, 10); wSize += W;

	//std::cout << h << " " << l << " " << L << " " << index<<std::endl;
	forH.changeText(hSize);
	forH.setTextColor(51, 51, 51, 255);

	forlen.changeText(lenSize);
	forlen.setTextColor(51, 51, 51, 255);

	forW.changeText(wSize);//
	forW.setTextColor(51, 51, 51, 255);
	//std::cout << "index = " << index << std::endl;

	if (index == 2)
	{
		forH.draw(window);
	}
	else if (index == 3 || index == 7)
	{
		forH.draw(window);
		forlen.draw(window);
		forW.draw(window);
	}
	else if (index == 5 || index == 8)
	{
		forH.draw(window);
		std::string raza = "r: ";
		raza += len;
		forlen.changeText(raza);
		forlen.draw(window);
	}
	else if (index == 6)
	{
		forH.draw(window);
		forlen.draw(window);
	}
	else if (index == 4)
	{
		std::string diametru = "d: ";
		diametru += H;
		forH.changeText(diametru);
		forH.draw(window);
	}

	FILE* newSize = fopen(pathForProject.c_str(), "r+");
	std::fprintf(newSize, "%s", position);
	std::fprintf(newSize, "%s", H);
	std::fprintf(newSize, "%s", " ");
	std::fprintf(newSize, "%s", len);
	std::fprintf(newSize, "%s", " ");
	std::fprintf(newSize, "%s", W);
	std::fprintf(newSize, "%s", " \n");
	std::fprintf(newSize, "%s", Index);
	std::fclose(newSize);

}

void figuresInfo::figureInfoSize2(sf::RenderWindow& window, std::string _size, std::string Name, std::string componentName, int language, bool changeUp, bool changeDown, int pozMx, int pozMy, int compScroll)
{
	int index = 0;
	using namespace sf;
	using namespace std;
	std::string hSize = "H: ", lenSize = "l: ", wSize = "w: ";
	char output[10][100];
	FILE* Texts = fopen("src\\programtexts/textsForSizes.txt", "r");

	for (int j = 0; j < 6; j++)
		for (int i = 1; i <= 3; i++)
		{
			char temporary[100];
			std::fgets(temporary, 100, Texts);
			if (i == language)
				std::strcpy(output[j], temporary);
		}
	std::fclose(Texts);

	texts size(15, 51, 51, 51, 255, output[0]);
	size.PositionSizeString(output[0], window.getSize().x - 340, 630, 25);
	size.changeColor(255, 255, 255, 255);
	size.setFont("res/Fonts/Montserrat/static/Montserrat-Light.ttf");
	size.draw(window);

	FloatRect textWidht = size.getLocalBoundsAuto();

	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";

	FILE* sizeDates = fopen(pathForProject.c_str(), "r");
	char position[100], sizes[101], Index[10];
	//window.getSize().x - 230, 515, "", 220, 24, 24
	button forH(window.getSize().x - 230, 640, "", 220, 24, 24);
	button forlen(window.getSize().x - 230, 670, "", 220, 24, 24);
	button forW(window.getSize().x - 230, 700, "", 220, 24, 24);

	if (!feof(sizeDates))
	{
		std::fgets(position, 100, sizeDates);
		std::fgets(sizes, 101, sizeDates);
		std::fgets(Index, 10, sizeDates);

	}
	char getIndex[100]{};
	std::strncpy(getIndex, Index, strlen(Index) - 1);
	//std::cout << "getIndex= " << getIndex << std::endl;
	for (int i = 0; i < strlen(getIndex); i++)
	{
		if (getIndex[i] >= '0' && getIndex[i] <= '9')
			index = index * 10 + int(getIndex[i] - 48);
	}
	//index /= 10;

	int h = 0, l = 0, L = 0;
	int c = 0;
	for (int i = 0; i < strlen(sizes); i++)
	{
		if (sizes[i] == ' ') c++;
		else
		{
			if (sizes[i] != '-')
			{
				if (c == 0)
					h = h * 10 + int(sizes[i] - 48);
				else if (c == 1)
					l = l * 10 + int(sizes[i] - 48);
				else if (c == 2)
					L = L * 10 + int(sizes[i] - 48);
			}
		}
	}
	c = 0;
	for (int i = 0; i < strlen(sizes); i++)
	{
		if (sizes[i] == ' ') c++;
		else
		{
			//std::cout << getText[i] << " " << c << std::endl;
			if (c == 0)
				if (sizes[i] == '-') h = h * -1;
			if (c == 1)
				if (sizes[i] == '-') l = l * -1;
			if (c == 2)
				if (sizes[i] == '-') L = L * -1;
		}
	}
	std::fclose(sizeDates);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 640 && pozMy < 640 + 24)
	{
		forH.setButtonColor(244, 207, 137, 255);
	}
	else
		forH.setButtonColor(132, 125, 120, 255);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 670 && pozMy < 670 + 24)
	{
		forlen.setButtonColor(244, 207, 137, 255);

	}
	else
		forlen.setButtonColor(132, 125, 120, 255);

	if (pozMx > window.getSize().x - 230 && pozMx < window.getSize().x - 230 + 220 && pozMy > 700 && pozMy < 700 + 24)
	{
		forW.setButtonColor(244, 207, 137, 255);

	}
	else
		forW.setButtonColor(132, 125, 120, 255);

	char H[10]{}, len[10]{}, W[10]{};
	_itoa(h, H, 10); hSize += H;
	_itoa(l, len, 10); lenSize += len;
	_itoa(L, W, 10); wSize += W;

	//std::cout << h << " " << l << " " << L << " " << index<<std::endl;
	forH.changeText(hSize);
	forH.setTextColor(51, 51, 51, 255);

	forlen.changeText(lenSize);
	forlen.setTextColor(51, 51, 51, 255);

	forW.changeText(wSize);//
	forW.setTextColor(51, 51, 51, 255);
	//std::cout << "index = " << index << std::endl;

	if (index == 2)
	{
		forH.draw(window);
	}
	else if (index == 3 || index == 7)
	{
		forH.draw(window);
		forlen.draw(window);
		forW.draw(window);
	}
	else if (index == 5 || index == 8)
	{
		forH.draw(window);
		std::string raza = "r: ";
		raza += len;
		forlen.changeText(raza);
		forlen.draw(window);
	}
	else if (index == 6)
	{
		forH.draw(window);
		forlen.draw(window);
	}
	else if (index == 4)
	{
		std::string diametru = "d: ";
		diametru += H;
		forH.changeText(diametru);
		forH.draw(window);
	}

	FILE* newSize = fopen(pathForProject.c_str(), "r+");
	std::fprintf(newSize, "%s", position);
	std::fprintf(newSize, "%s", H);
	std::fprintf(newSize, "%s", " ");
	std::fprintf(newSize, "%s", len);
	std::fprintf(newSize, "%s", " ");
	std::fprintf(newSize, "%s", W);
	std::fprintf(newSize, "%s", " \n");
	std::fprintf(newSize, "%s", Index);
	std::fclose(newSize);
}

void figuresInfo::change(sf::RenderWindow& window, int WINDOW_WIDTH, int WINDOW_HEIGHT, Camera camera, std::string saveNameOfProject, std::string componentName, int language, int pozMx, int pozMy, int compScroll, int compNr)
{
	window.clear();
	int nothing = 0;
	int ale = 0;
	int nr = 0;
	char everything[100][100];
	std::string path = "src\\userProjects\\";
	path += saveNameOfProject;
	path += "\\";
	path += "name.txt";

	FILE* compNames2 = fopen(path.c_str(), "r+");
	while (!feof(compNames2))
	{
		char buff[100];
		fgets(buff, 100, compNames2);
		nothing++;
	}
	fclose(compNames2);
	//std::cout << "number of copmps= " << nothing << std::endl;

	if (nothing == 1)
	{
		window.clear();
	}
	else
	{
		FILE* compNames = fopen(path.c_str(), "r+");
		//std::cout << path << std::endl;
		//if(!feof)
		char buff[100];
		fgets(buff, 100, compNames);
		while (!feof(compNames))
		{
			//std::cout << "nifint";
			int index = 0;
			char comp[100]{};
			strncpy(comp, buff, strlen(buff) - 1);
			std::string pathForDates = "src\\userProjects\\";
			pathForDates += saveNameOfProject;
			pathForDates += "\\";
			pathForDates += comp;
			pathForDates += ".txt";
			//std::cout << pathForDates << std::endl;
			FILE* compDates = fopen(pathForDates.c_str(), "r+");
			if (!feof(compDates))
			{
				char position[100], sizes[101], Index[10];
				std::fgets(position, 100, compDates);
				std::fgets(sizes, 101, compDates);
				std::fgets(Index, 10, compDates);

				char getIndex[100];
				strncpy(getIndex, Index, strlen(Index) - 1);
				for (int i = 0; i < strlen(getIndex); i++)
				{
					if (getIndex[i] >= '0' && getIndex[i] <= '9')
						index = index * 10 + int(getIndex[i] - 48);
				}
				index /= 10;

				int h = 0, l = 0, L = 0;
				int x = 0, y = 0, z = 0;
				//scoatem size - urile din fisier
				int c = 0;
				for (int i = 0; i < strlen(sizes); i++)
				{
					if (sizes[i] == ' ') c++;
					else
					{
						if (sizes[i] >= '0' && sizes[i] <= '9')
						{
							if (c == 0)
								h = h * 10 + int(sizes[i] - 48);
							else if (c == 1)
								l = l * 10 + int(sizes[i] - 48);
							else if (c == 2)
								L = L * 10 + int(sizes[i] - 48);
						}
					}
				}
				c = 0;
				for (int i = 0; i < strlen(sizes); i++)
				{
					if (sizes[i] == ' ') c++;
					else
					{
						//std::cout << getText[i] << " " << c << std::endl;
						if (c == 0)
							if (sizes[i] == '-') h = h * -1;
						if (c == 1)
							if (sizes[i] == '-') l = l * -1;
						if (c == 2)
							if (sizes[i] == '-') L = L * -1;
					}
				}

				//scoatem pozitiile din fisier
				c = 0;
				char getText[100];
				strncpy(getText, position, strlen(position) - 1);

				for (int i = 0; i < strlen(getText); i++)
				{
					if (getText[i] == ' ') c++;
					else
					{
						if (getText[i] >= '0' && getText[i] <= '9')
						{
							if (c == 0)
								x = x * 10 + int(getText[i] - 48);
							else if (c == 1)
								y = y * 10 + int(getText[i] - 48);
							else if (c == 2)
								z = z * 10 + int(getText[i] - 48);
						}
					}
				}
				c = 0;
				for (int i = 0; i < strlen(getText); i++)
				{
					if (getText[i] == ' ') c++;
					else
					{
						//std::cout << getText[i] << " " << c << std::endl;
						if (c == 0)
							if (getText[i] == '-') x = x * -1;
						if (c == 1)
							if (getText[i] == '-') y = y * -1;
						if (c == 2)
							if (getText[i] == '-') z = z * -1;
					}
				}
				fclose(compDates);
				//std::cout << x << " " << y << " " << z << std::endl;
				//std::cout << index << std::endl;
				//std::cout << h << " " << l << " " << L << std::endl;
				char X[100]{};
				_itoa(x, X, 10);
				strcpy(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(y, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(z, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(h, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(l, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(L, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(index, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				nr++;

			}

			fgets(buff, 100, compNames);

		}
		fclose(compNames);

		for (int i = 0; i < nr; i++)
		{
			int x = 0, y = 0, z = 0, index = 0, h = 0, l = 0, L = 0;
			int c = 0;
			for (int j = 0; j < strlen(everything[i]); j++)
			{
				if (everything[i][j] == ' ') c++;
				else if (everything[i][j] >= '0' && everything[i][j] <= '9')
				{
					if (c == 0)
						x = x * 10 + int(everything[i][j] - 48);
					else if (c == 1)
						y = y * 10 + int(everything[i][j] - 48);
					else if (c == 2)
						z = z * 10 + int(everything[i][j] - 48);
					else if (c == 3)
						h = h * 10 + int(everything[i][j] - 48);
					else if (c == 4)
						l = l * 10 + int(everything[i][j] - 48);
					else if (c == 5)
						L = L * 10 + int(everything[i][j] - 48);
					else if (c == 6)
						index = index * 10 + int(everything[i][j] - 48);
				}
			}

			c = 0;
			for (int j = 0; j < strlen(everything[i]); j++)
			{
				if (everything[i][j] == ' ') c++;
				else
				{
					if (c == 0)
						if (everything[i][j] == '-') x = x * -1;
					if (c == 1)
						if (everything[i][j] == '-') y = y * -1;
					if (c == 2)
						if (everything[i][j] == '-') z = z * -1;
				}
			}
			//std::cout << nr << " " << x << " " << y << " " << z;
			//std::cout << " " << index << " ";
			//std::cout << h << " " << l << " " << L << std::endl;
			std::cout << "aici" << std::endl;
			std::cout << everything[i] << std::endl;
			std::cout << "x =" << x << std::endl;
			std::cout << "y =" << y << std::endl;
			std::cout << "z =" << z << std::endl;
			std::cout << "h =" << h << std::endl;
			std::cout << "l =" << l << std::endl;
			std::cout << "L =" << L << std::endl;
			std::cout << std::endl;
			if (index == 2)
			{
				Cub cub(Vector(x, y, z), h);
				cub.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 3)
			{
				Prism prisma(Vector(x, y, z), h, l, L);
				prisma.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 4)
			{
				Sphere3d sphere(Vector(x, y, z), h, 100, 40);
				sphere.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 5)
			{
				Cylinder3d cylinder(Vector(x, y, z), h, l, 100);
				cylinder.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 6)
			{
				Pyramid3d pyramid(Vector(x, y, z), h, l, L);
				pyramid.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 7)
			{
				Con3d con(Vector(x, y, z), h, l, 100);
				con.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
		}
		//std::cout << everything[i] << std::endl;
		//sf::Vector2u size = window.getSize();
		//sf::RectangleShape spaceForComponents(sf::Vector2f(size.x, size.y));
		////Vector2f sizeSpace = spaceForComponents.getSize();
		//spaceForComponents.setPosition(size.x - 220, 0);
		////cout << size.x - (size.x / 7) << endl;
		//spaceForComponents.setFillColor(sf::Color(81, 81, 81, 255));
		//window.draw(spaceForComponents);
		//memset(everything, 0, sizeof(everything));
		justComponentsNmaes(window, saveNameOfProject, compScroll, compNr, language);
		bool a = 0, b = 0;
		figureInfoType(window, "Tip:", saveNameOfProject, componentName, language, compNr);
		figureInfoPosition(window, WINDOW_WIDTH, WINDOW_HEIGHT, "Pozitii:", saveNameOfProject, componentName, a, b, pozMx, pozMy, camera, compScroll, compNr, language);
		figureInfoSize2(window, "Marime:", saveNameOfProject, componentName, language, a, b, pozMx, pozMy, compScroll);
		//componentsNames(window, saveNameOfProject, 0, 0, 0, 0, x, y, 1, camera, 0);
		figures(window, 1920, 1080, 0, 0, language);

		char screen[10][20];
		FILE* f = fopen("src\\programtexts/viewAndEdit.txt", "r");
		for (int i = 1; i <= 3; i++)
		{
			char temporary[100];
			fgets(temporary, 100, f);
			if (i == language) strcpy(screen[0], temporary);
		}
		for (int i = 1; i <= 3; i++)
		{
			char temporary[100];
			fgets(temporary, 100, f);
			if (i == language) strcpy(screen[1], temporary);
		}
		for (int i = 1; i <= 3; i++)
		{
			char temporary[100];
			fgets(temporary, 100, f);
			if (i == language) strcpy(screen[2], temporary);
		}

		std::fclose(f);
		texts text(screen[0], 10, 10, 0, 0, 30, 234, 235, 229, 255);
		text.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
		text.draw(window);
		text.PositionSizeString(screen[1], window.getSize().x - 350 + 10, 10, 30);
		text.draw(window);
		text.PositionSizeString(screen[2], 215, 20, 20);
		text.draw(window);
		window.display();

	}
}

void figuresInfo::simpleChange(sf::RenderWindow& window, int WINDOW_WIDTH, int WINDOW_HEIGHT, Camera camera, std::string saveNameOfProject)
{
	window.clear();
	int nothing = 0;
	int ale = 0;
	int nr = 0;
	char everything[100][100];
	while (saveNameOfProject[saveNameOfProject.size() - 1] == ' ')
	{
		saveNameOfProject.pop_back();
	}
	std::string path = "src\\userProjects\\";
	path += saveNameOfProject;
	path += "\\";
	path += "name.txt";
	FILE* compNames2 = fopen(path.c_str(), "r+");
	while (!feof(compNames2))
	{
		char buff[100];
		fgets(buff, 100, compNames2);
		nothing++;
	}
	fclose(compNames2);
	//std::cout << "number of copmps= " << nothing << std::endl;

	if (nothing == 1)
	{
		window.clear();
	}
	else
	{
		FILE* compNames = fopen(path.c_str(), "r+");

		//std::cout << path << std::endl;
		//if(!feof)
		char buff[100];
		fgets(buff, 100, compNames);
		while (!feof(compNames))
		{
			//std::cout << "nifint";
			int index = 0;
			char comp[100]{};
			strncpy(comp, buff, strlen(buff) - 1);
			std::string pathForDates = "src\\userProjects\\";
			pathForDates += saveNameOfProject;
			pathForDates += "\\";
			pathForDates += comp;
			pathForDates += ".txt";
			//std::cout << pathForDates << std::endl;
			FILE* compDates = fopen(pathForDates.c_str(), "r+");
			if (!feof(compDates))
			{
				char position[100], sizes[101], Index[10];
				std::fgets(position, 100, compDates);
				std::fgets(sizes, 101, compDates);
				std::fgets(Index, 10, compDates);

				char getIndex[100];
				strncpy(getIndex, Index, strlen(Index) - 1);
				for (int i = 0; i < strlen(getIndex); i++)
				{
					if (getIndex[i] >= '0' && getIndex[i] <= '9')
						index = index * 10 + int(getIndex[i] - 48);
				}
				index /= 10;

				int h = 0, l = 0, L = 0;
				int x = 0, y = 0, z = 0;
				//scoatem size - urile din fisier
				int c = 0;
				for (int i = 0; i < strlen(sizes); i++)
				{
					if (sizes[i] == ' ') c++;
					else
					{
						if (sizes[i] != '-')
						{
							if (c == 0)
								h = h * 10 + int(sizes[i] - 48);
							else if (c == 1)
								l = l * 10 + int(sizes[i] - 48);
							else if (c == 2)
								L = L * 10 + int(sizes[i] - 48);
						}
					}
				}
				c = 0;
				for (int i = 0; i < strlen(sizes); i++)
				{
					if (sizes[i] == ' ') c++;
					else
					{
						//std::cout << getText[i] << " " << c << std::endl;
						if (c == 0)
							if (sizes[i] == '-') h = h * -1;
						if (c == 1)
							if (sizes[i] == '-') l = l * -1;
						if (c == 2)
							if (sizes[i] == '-') L = L * -1;
					}
				}

				c = 0;
				char getText[100];
				strncpy(getText, position, strlen(position) - 1);

				for (int i = 0; i < strlen(getText); i++)
				{
					if (getText[i] == ' ') c++;
					else
					{
						if (getText[i] != '-')
						{
							if (c == 0)
								x = x * 10 + int(getText[i] - 48);
							else if (c == 1)
								y = y * 10 + int(getText[i] - 48);
							else if (c == 2)
								z = z * 10 + int(getText[i] - 48);
						}
					}
				}
				c = 0;
				for (int i = 0; i < strlen(getText); i++)
				{
					if (getText[i] == ' ') c++;
					else
					{
						if (c == 0)
							if (getText[i] == '-') x = x * -1;
						if (c == 1)
							if (getText[i] == '-') y = y * -1;
						if (c == 2)
							if (getText[i] == '-') z = z * -1;
					}
				}
				fclose(compDates);

				char X[100]{};
				_itoa(x, X, 10);
				strcpy(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(y, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(z, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(h, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(l, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(L, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				memset(X, 0, sizeof(X));
				_itoa(index, X, 10);
				strcat(everything[nr], X);
				strcat(everything[nr], " ");
				nr++;

			}

			fgets(buff, 100, compNames);

		}
		fclose(compNames);

		for (int i = 0; i < nr; i++)
		{
			int x = 0, y = 0, z = 0, index = 0, h = 0, l = 0, L = 0;
			int c = 0;
			for (int j = 0; j < strlen(everything[i]); j++)
			{
				if (everything[i][j] == ' ') c++;
				else if (everything[i][j] >= '0' && everything[i][j] <= '9')
					if (c == 0)
						x = x * 10 + int(everything[i][j] - 48);
					else if (c == 1)
						y = y * 10 + int(everything[i][j] - 48);
					else if (c == 2)
						z = z * 10 + int(everything[i][j] - 48);
					else if (c == 3)
						h = h * 10 + int(everything[i][j] - 48);
					else if (c == 4)
						l = l * 10 + int(everything[i][j] - 48);
					else if (c == 5)
						L = L * 10 + int(everything[i][j] - 48);
					else if (c == 6)
						index = index * 10 + int(everything[i][j] - 48);
			}
			c = 0;
			for (int j = 0; j < strlen(everything[i]); j++)
			{
				if (everything[i][j] == ' ') c++;
				else
					if (c == 0)
						if (everything[i][j] == '-') x = x * -1;
				if (c == 1)
					if (everything[i][j] == '-') y = y * -1;
				if (c == 2)
					if (everything[i][j] == '-') z = z * -1;
			}
			/*std::cout << "x =" << x << std::endl;
			std::cout << "y =" << y << std::endl;
			std::cout << "z =" << z << std::endl;
			std::cout << "h =" << h << std::endl;
			std::cout << "l =" << l << std::endl;
			std::cout << "L =" << L << std::endl;
			std::cout<<std::endl;*/
			if (index == 2)
			{
				Cub cub(Vector(x, y, z), h);
				cub.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 3)
			{
				Prism prisma(Vector(x, y, z), h, l, L);
				prisma.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 4)
			{
				Sphere3d sphere(Vector(x, y, z), h, 100, 40);
				sphere.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 5)
			{
				Cylinder3d cylinder(Vector(x, y, z), h, l, 100);
				cylinder.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 6)
			{
				Pyramid3d pyramid(Vector(x, y, z), h, l, L);
				pyramid.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
			else if (index == 7)
			{
				Con3d con(Vector(x, y, z), h, l, 100);
				con.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			}
		}
	}
	figures(window, 0, 0, 0, 0, 1);
	sf::Vector2u size = window.getSize();
	sf::RectangleShape spaceForComponents(sf::Vector2f(size.x, size.y));
	//Vector2f sizeSpace = spaceForComponents.getSize();
	spaceForComponents.setPosition(size.x - 220, 0);
	//cout << size.x - (size.x / 7) << endl;
	spaceForComponents.setFillColor(sf::Color(81, 81, 81, 255));
	window.draw(spaceForComponents);
	window.display();

}

void figuresInfo::deleteComponent(sf::RenderWindow& window, int WINDOW_WIDTH, int WINDOW_HEIGHT, std::string compName, std::string projname, int& pozMx, int& pozMy, int x, int y, Camera camera)
{
	bool find = 0;
	//std::cout << "compNmae: " << projname << std::endl;
	sf::Font font;
	if (!font.loadFromFile("Fonts/RobotoCondensed-Regular.ttf"));
	sf::Text text("X", font, 24);
	text.setPosition(window.getSize().x - 40, y + 3);

	sf::RectangleShape divider(sf::Vector2f(2, 30));
	divider.setPosition(window.getSize().x - 50, y + 4);
	window.draw(text);
	window.draw(divider);

	if (pozMx >= window.getSize().x - 50 && pozMx <= window.getSize().x - 10 && pozMy >= y && pozMy <= y + 40)
	{
		std::string path = "src\\userProjects\\";
		path += projname;
		path += "\\";
		path += "name.txt";
		std::string removeF = "src\\userProjects\\";
		removeF += projname;
		removeF += "\\";
		std::string buff;
		FILE* temp = fopen("src\\userProjects\\tempo.txt", "w");
		FILE* deleteComp = fopen(path.c_str(), "r+");

		if (!feof(deleteComp))
		{
			char sir[100];
			fgets(sir, 100, deleteComp);

			while (!feof(deleteComp))
			{
				char nou[100]{};
				strncpy(nou, sir, strlen(sir) - 1);
				if (compName.compare(nou) == 0) {
					//std::cout << "am gasit" << std::endl;
					buff = nou;
				}
				else
				{
					find = 1;
					fprintf(temp, "%s", sir);
				}
				fgets(sir, 100, deleteComp);

			}
		}
		fclose(deleteComp);
		fclose(temp);
		removeF += buff;
		removeF += ".txt";
		//std::cout << "remove: " << removeF << std::endl;

		remove(removeF.c_str());
		FILE* afterDelete = fopen(path.c_str(), "w");
		FILE* temp2 = fopen("src\\userProjects\\tempo.txt", "r+");

		if (find == 1)
		{
			char sir[100];
			fgets(sir, 100, temp2);
			while (!feof(temp2))
			{
				//std::cout << "sir: " << sir;
				fprintf(afterDelete, "%s", sir);
				fgets(sir, 100, temp2);

			}
		}
		fclose(temp2);
		fclose(afterDelete);
		simpleChange(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, projname);
		//change(window, camera, projname,compName, 1, pozMx, pozMy);
		pozMx = 0; pozMy = 0;

	}

	//pozMx = 0; pozMy = 0;



}

