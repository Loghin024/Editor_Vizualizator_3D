#include <iostream>
#include <SFML\Graphics.hpp>
#include "menu.hpp"
#include <direct.h>
#include <filesystem>
#include "menu/texts.hpp"
#include "menu/button.hpp"
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"
#include "utils/mouse.hpp"
#include <filesystem>

int language = 1, line = 0, nivel = 0, nivel2, nrProiecte = 0, scrool = 0;
int curentWindow = 0;
char sir[100], proiect[100];
bool q = 0;
char stergere[200];
bool maximLength;
int pozMx, pozMy;

void littleDraw(sf::RenderWindow& window, int x, int y, int z, int h, bool edit)
{
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	window.setVerticalSyncEnabled(true);
	//Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	//creaza un cub 
	Cub cub(Vector(x, y, z), h);
	
	//Cub cub1(Vector(100, 100, 100), 30);


	// creaza camera
	
	Camera camera(Vector(0, -100, -230), -30, 0, 0, 1200, 800);

	while (window.isOpen() && !edit)
	{
		
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					window.close();
				if (event.type == sf::Event::TextEntered)
					if(event.text.unicode == 97)
					edit = 1;
			}

			//rotire camera
			camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window));

			// misca camera
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
				camera.move(Camera::DIRECTION::FRONT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
				camera.move(Camera::DIRECTION::BACK);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
				camera.move(Camera::DIRECTION::RIGHT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
				camera.move(Camera::DIRECTION::LEFT);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
				camera.move(Camera::DIRECTION::UP);
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
				camera.move(Camera::DIRECTION::DOWN);

			//afisare
			window.clear();
			cub.render_solid(window, 1200, 800, camera);
			//cub1.render_solid(window, 1200, 800, camera);
			//cub2.render_solid(window, 1200, 800, camera);
			//platou.render_solid(window, 1200, 800, camera);
			//cub1.render_solid(window, 1200, 800, camera);
			//cub.rotate(Vector(50,0,0), Vector(0,1,0), 1, true);
			//cub1.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);
			//cub2.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);

			window.display();
		
	}
	
	//window.clear();
		cub.render_solid(window, 1200, 800, camera);
	//window.display();
	

}

void getOutText(char principalScreen[100][100], char viewerScreen[100][100], char createScreen[100][100])
{
	FILE* f1 = fopen("src\\programtexts/textsForPrincipalScreen.txt", "r");
	FILE* creari = fopen("src\\programtexts/textsForViewerScreen.txt", "r");
	FILE* detalii = fopen("src\\programtexts/textsForCreateScreen.txt", "r");

	//textul din ferestra de creeari a unui proiect mou
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(createScreen[0], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(createScreen[1], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(createScreen[2], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(createScreen[3], a);
	}

	//Principal screen
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(principalScreen[0], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(principalScreen[1], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(principalScreen[2], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(principalScreen[3], a);
	}

	//viewer screen
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(viewerScreen[0], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(viewerScreen[1], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(viewerScreen[2], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(viewerScreen[3], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(viewerScreen[4], a);
	}

	fclose(f1);
	fclose(creari);
	fclose(detalii);

}

void deleteDirectory(std::string path)
{
	path.pop_back();
	path.pop_back();
	path.pop_back();
	path.pop_back();
	std::string copyPath;
	copyPath = path;
	copyPath += "\\";
	path += "\\name.txt";
	std::cout << path;

	FILE* DELETE = fopen(path.c_str(), "r");
	char temp[100]{};//temp -> temporary
	if (!feof(DELETE))
	{
		fgets(temp, 100, DELETE);
		while (!feof(DELETE))
		{
			std::string pathTxt = copyPath;
			char sir[100]{};
			strncpy(sir, temp, strlen(temp) - 1);
			pathTxt += sir;
			pathTxt += ".txt";
			std::cout << pathTxt << " ";
			remove(pathTxt.c_str());
			fgets(temp, 100, DELETE);
		}
	}
	fclose(DELETE);

	remove(path.c_str());
	
}

void principalScreen(sf::RenderWindow& window, char output[10][100], int selectL)
{
	using namespace sf;
	Texture texture;
	texture.loadFromFile("images/PrincipalBackground2.jpg");
	Sprite sprite(texture);
	window.clear();
	window.draw(sprite);
	Vector2u size = window.getSize();

	//titlu
	texts titlu(output[0], 1200 / 2.0f, 100, 0, 0, 60, 14, 24, 65, 255);
	int width, height;
	titlu.getLocalBounds(width, height);
	titlu.changeOrigin(width, height);
	titlu.draw(window);

	button limba(1150, 20, output[1], 40, 25, 20);
	if (pozMx > 1150 && pozMx < 1200 && pozMy > 20 && pozMy < 45)	limba.setOutlineThicknesAndColor(1.5, 203, 55, 23, 255);
	else limba.setOutlineThicknesAndColor(1.5, 0, 0, 0, 255);

	// butonul pentru a schimba limba
	limba.setButtonColor(43, 113, 149, 255);
	limba.setTextColor(6, 7, 7, 255);
	limba.draw(window);

	if (selectL == 1)
	{

		limba.changePosition(1150, 48);
		if (language == 1)
			limba.changeText("EG");
		else if (language == 2)
			limba.changeText("RU");
		else if (language == 3)
			limba.changeText("RO");

		limba.changeTextPosition(1200 - 42, 46);
		limba.draw(window);

		limba.changePosition(1150, 76);
		if (language == 1)
			limba.changeText("RU");
		else if (language == 2)
			limba.changeText("RO");
		else if (language == 3)
			limba.changeText("EG");
		limba.changeTextPosition(1200 - 42, 74);

		limba.draw(window);
	}

	button myProjects(60, 200, output[2], 300, 60, 45);
	// patratul ce va contine butonul spre pagina cu proiectele mele
	if (pozMx > 60 && pozMx < 360 && pozMy > 200 && pozMy < 260) {
		myProjects.setOutlineThicknesAndColor(5.0, 203, 55, 23, 255);
		myProjects.setTextColor(203, 55, 23, 255);
	}
	else {
		myProjects.setOutlineThicknesAndColor(3, 0, 0, 0, 255);
		myProjects.setTextColor(0, 0, 0, 255);
	}
	myProjects.setButtonColor(60, 154, 188, 255);
	myProjects.draw(window);

	button createProject(60, 300, output[3], 300, 60, 45);
	if (pozMx > 60 && pozMx < 360 && pozMy > 300 && pozMy < 360)
	{
		createProject.setOutlineThicknesAndColor(5.0, 203, 55, 23, 255);
		createProject.setTextColor(203, 55, 23, 255);
	}
	else
	{
		createProject.setOutlineThicknesAndColor(3, 0, 0, 0, 255);
		createProject.setTextColor(0, 0, 0, 255);
	}
	createProject.setButtonColor(60, 154, 188, 255);
	createProject.draw(window);
	window.display();

}

void myProjectsWindow(sf::RenderWindow& window, char output2[10][100], int back, bool view, std::string& saveNameOfProject, int& slide)
{
	using namespace sf;
	Texture texture;
	texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
	Sprite sprite(texture);
	nrProiecte = 0;

	FILE* f2 = fopen("src\\userProjects/userNameOfProjects.txt", "r");

	// in clear alegem si culoarea backgroundului
	window.clear(Color(37, 150, 190));
	window.draw(sprite);

	// un patrat de culoare diferita ce va fi pozotionat in partea de sus a ferestrei
	// ce va fi practic, bara noastra de navigare
	button bar(0, 0, "", 1200, 40, 0);;
	bar.setButtonColor(11, 126, 168, 255);
	bar.draw(window);

	// textul de dupa are vor fi afisate proiectele mele
	texts titlu(output2[0], 20, 36, 0, 0, 60, 0, 0, 0, 255);
	titlu.draw(window);

	// linia ce separa bara de navigare de restul programului
	bar.changeLengthAndHeight(1200, 0);
	bar.changePosition(0, 40);
	bar.setOutlineThicknesAndColor(1, 0, 0, 0, 255);
	bar.draw(window);

	// linia ce separa cele doua butoane din bara de navigare
	button divide(back, 6, "", 2, 30, 0);
	divide.setButtonColor(0, 0, 0, 255);
	divide.draw(window);

	texts goBack(output2[1], 20, 2, 0, 0, 30);
	if (pozMx < back && pozMy < 40)	goBack.changeColor(203, 55, 23, 255);
	else goBack.changeColor(0, 0, 0, 255);
	goBack.draw(window);

	texts newProject(output2[2], divide.getX() + 20, 2, 0, 0, 30);
	// textul celui de al doilea buton din bara de navigare, de creare a unui proiect nou
	if (pozMx > back && pozMy < 40) newProject.changeColor(203, 55, 23, 255);
	else newProject.changeColor(0, 0, 0, 255);
	newProject.draw(window);

	fclose(f2);

	FILE* f4 = fopen("src\\userProjects/userNameOfProjects.txt", "r");

	line = 0;
	// afisarea proiectelor pe care le avem salvate pana acum
	if (pozMx > 500 - 10 * strlen(output2[3]) && pozMx < 500 + 2 * 10 * strlen(output2[3]) && pozMy > 116)	nivel = (pozMy - 116) / 50;
	if (pozMx > 500 + 2 * 10 * strlen(output2[3]) && pozMx < 500 + 2 * 10 * strlen(output2[1]) + 5 * strlen(output2[4]) + 15 * strlen(output2[4]) && pozMy > 116)	nivel2 = (pozMy - 116) / 50;

	char proiecte[100];
	fgets(proiecte, 100, f4);
	int copieScrool = scrool;
	while (!feof(f4))
	{
		nrProiecte++;
		if (copieScrool > 0) copieScrool--;
		else
		{
			texts out(proiecte, 10, 120 + 50 * line, 0, 0, 30, 0, 0, 0, 255);
			out.draw(window);
			/*text.setString(proiecte);
			text.setPosition(10, 120 + 50 * line);
			window1.draw(text);*/

			if (!nivel) out.changeColor(203, 55, 23, 255);
			else out.changeColor(0, 0, 0, 255);

			out.PositionSizeString(output2[3], 500, 130 + 50 * line, 25);
			out.draw(window);

			if (!nivel2) out.changeColor(203, 55, 23, 255);
			else out.changeColor(0, 0, 0, 255);
			int lungimeSirRemove = strlen(output2[1]);

			out.PositionSizeString(output2[4], 500 + 2 * 10 * lungimeSirRemove + 5 * strlen(output2[4]), 130 + 50 * line, 25);
			out.draw(window);

			if (!nivel2 && view == 1)
			{
				curentWindow = 3;
				char temp[100]{};
				strncpy(temp, proiecte, strlen(proiecte) - 1);
				saveNameOfProject = temp;
				slide = 1;
			}
			if (!nivel)	divide.setButtonColor(203, 55, 23, 255);

			divide.changePosition(500 - 10 * lungimeSirRemove, 130 + 50 * line);
			divide.draw(window);

			if (!nivel2) divide.setButtonColor(203, 55, 23, 255);
			divide.changePosition(500 + 2 * 10 * lungimeSirRemove, 130 + 50 * line);
			divide.draw(window);

			if (!nivel)	divide.setButtonColor(0, 0, 0, 255);
			divide.changePosition(500 + 2 * 10 * lungimeSirRemove + 5 * strlen(output2[4]) + 15 * strlen(output2[4]), 130 + 50 * line);
			divide.draw(window);

			divide.setButtonColor(0, 0, 0, 255);

			bar.changePosition(1, 145 + 50 * line + 20);
			bar.draw(window);
			nivel--;
			nivel2--;
			line++;
			copieScrool--;
		}
		fgets(proiecte, 100, f4);
	}
	fclose(f4);
	window.display();
}

void detailsAboutProject(sf::RenderWindow& window, char output3[10][100], int nrFigure, int coordonates, int nextInput, char indexAndCoordonates[200][10], int down, std::string playerText, int index)
{
	//std::cout << playerText << std::endl;
	//5std::cout << index << " ";
	using namespace sf;
	Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));

	texts detail(output3[3], 10, 50, 0, 0, 40, 0, 0, 0, 255);

	Text playerText2(playerText, font, 40);
	playerText2.setFillColor(Color::Black);
	Texture texture;
	//INCARCAREA BACKGROUNDULUI
	texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
	Sprite sprite(texture);
	window.clear();

	window.draw(sprite);
	detail.draw(window);
	int minus;
	if (language == 2) minus = 10;
	else minus = 0;

	playerText2.setPosition(10 + 16 * strlen(output3[3]) + minus, 50);
	detail.draw(window);
	if (coordonates == 0)
	{
		window.draw(playerText2);
	}

	if (coordonates > 0)
	{
		detail.PositionSizeString(indexAndCoordonates[0], 10 + 16 * strlen(output3[3]) + minus, 50, 40);
		detail.draw(window);
		detail.changeTheText(output3[1]);
		detail.changePosition(10, 100);
		detail.draw(window);
		playerText2.setPosition(10 + 16 * strlen(output3[1]) + 100 * (coordonates - 1) + 25 + minus, 100);

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

	texts goBack(output3[0], 20, 1, 0, 0, 30);
	button line(40 + 10 * strlen(output3[0]), 8, "", 2, 30, 0);
	if (pozMx < 111 && pozMy < 40)
	{
		goBack.changeColor(203, 55, 23, 255);
		line.setButtonColor(203, 55, 23, 255);
	}
	else
	{
		goBack.changeColor(0, 0, 0, 255);
		line.setButtonColor(0, 0, 0, 255);
	}

	goBack.draw(window);

	line.draw(window);
	line.changePosition(10, 40);
	line.changeLengthAndHeight(30 + 10 * strlen(output3[0]), 2);
	line.draw(window);

	window.display();
}

void giveNameForProject(sf::RenderWindow& window, int language, std::string name, int PozMx, int PozMy)
{
	window.clear();
	char sir[100];
	FILE* theNameTexts = fopen("src\\programtexts/giveNameForProject.txt", "r");

	for (int i = 1; i <= 3; i++)
	{
		char buff[100];
		fgets(buff, 100, theNameTexts);
		if (i == language)
			strcpy(sir, buff);
	}

	texts text(sir, 20, 50, 0, 0, 50, 234, 235, 229, 255);
	text.draw(window);
	texts theNmae(name, strlen(sir) * 20 + 15, 54, 0, 0, 50, 234, 235, 229, 255);
	theNmae.draw(window);

	for (int i = 1; i <= 3; i++)
	{
		char buff[100];
		fgets(buff, 100, theNameTexts);
		if (i == language)
			strcpy(sir, buff);
	}

	fclose(theNameTexts);

	int back = 40 + 10 * strlen(sir);

	texts goBack(sir, 20, 2, 0, 0, 30);
	if (pozMx < back && pozMy < 40)	goBack.changeColor(203, 55, 23, 255);
	else goBack.changeColor(234, 235, 229, 255);
	goBack.draw(window);

	window.display();
}

void viewAndEdit(sf::RenderWindow& window, int getxRightClick, int getyRightClick, int language, int scrool, int sideScrool, int sidePress, int PozMx, int PozMy, std::string Name, bool& figureChosed)
{
	//ppstd::cout << Name << std::endl;
	//std::cout << sideScrool << " " << sidePress << std::endl;
	sf::Event event{};
	using namespace sf;
	window.clear();
	sf::RectangleShape divider(sf::Vector2f(2, 800));
	divider.setFillColor(sf::Color(85, 186, 213, 255));
	divider.setPosition(sf::Vector2f(220, 0));
	window.draw(divider);
	divider.setSize(sf::Vector2f(1200, 2));
	divider.setPosition(0, 630);
	window.draw(divider);
	int line = 0;
	char screen[10][100];
	char figure[100];
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

	fclose(f);
	texts text(screen[0], 20, 10, 0, 0, 30, 234, 235, 229, 255);
	text.draw(window);

	button figures(10, 70, "", 200, 50, 40, 2, 85, 186, 213, 255);
	figures.setButtonColor(0, 0, 0, 255);
	figures.changeTextPosition(figures.getX() + 200 / 2 - figures.getLocalBoundsX() / 2, figures.getY() + 50 / 2 - figures.getLocalBoundsY() / 2 - 13);

	FILE* PosibleFiguresFromFile = fopen("src\\programtexts/posibleFigures.txt", "r");

	while (!feof(PosibleFiguresFromFile))
	{
		fgets(figure, 100, PosibleFiguresFromFile);
		if (scrool > 0) scrool--;
		else
		{
			if (line < 7)
			{
				char sir[100]{};
				strncpy(sir, figure, strlen(figure) - 1);
				//std::cout << PozMx << " " << PozMy << std::endl;
				figures.changeText(sir);
				figures.changePosition(10, 70 + 80 * line);
				figures.changeTextPosition(figures.getX() + 200 / 2 - figures.getLocalBoundsX() / 2, figures.getY() + 50 / 2 - figures.getLocalBoundsY() / 2 - 13);

				if ((PozMx > 10 && PozMx < 210) && (PozMy > 70 + 80 * line && PozMy < 70 + 80 * line + 50))
					figures.setOutlineThicknesAndColor(1, 198, 49, 20, 255);
				else
					figures.setOutlineThicknesAndColor(1, 85, 186, 213, 255);

				figures.draw(window);

				line++;
			}
		}
	}

	text.PositionSizeString(screen[1], 20, 650, 50);
	text.draw(window);
	text.PositionSizeString(screen[2], 20, 700, 50);
	text.draw(window);
	fclose(PosibleFiguresFromFile);

	std::string pathForProject = "src\\userProjects\\";//; + Name; //+ "nameOfFigures";;
	pathForProject += Name + "\\name.txt";
	FILE* figuresFromFile;// = fopen(pathForProject.c_str(), "r");
	char buff[100];
	/*if(!feof(figuresFromFile))
	fgets(buff, 100, figuresFromFile);*/

	button edit(250, 650, "", 220, 125, 30, 2, 85, 186, 213, 255);
	edit.setButtonColor(0, 0, 0, 255);
	////edit.draw(window);
	int split = 0, nr = 0;
	//std::cout << PozMx << " " << PozMy << std::endl;
	if (!(figuresFromFile = fopen(pathForProject.c_str(), "r")));
	else
	{
		fgets(buff, 100, figuresFromFile);

		while (!feof(figuresFromFile))
		{
			if (sideScrool > 0)
			{
				sideScrool--;
				sidePress--;
			}
			else
			{
				sidePress--;
				split++;
				char sir[100]{};
				strncpy(sir, buff, strlen(buff) - 1);
				std::string pathForFigure = "src\\userProjects\\" + Name + "\\" + sir + ".txt";
				FILE* datesFromFigures = fopen(pathForFigure.c_str(), "r");
				char getText[100]{};
				if(!feof(datesFromFigures))
				fgets(getText, 100, datesFromFigures);
				//std::cout << getText << std::endl;
				fclose(datesFromFigures);
				int x = 0, y = 0, z = 0, h = 0;
				int c = 0;
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
							else if (c == 3) h = h * 10 + int(getText[i] - 48);
						}
					}
				}
				c = 0;
				for (int i = 0; i < strlen(getText); i++)
				{
					if (getText[i] == ' ') c++;
					else
					{
						std::cout << getText[i] << " " << c << std::endl;
						if (c == 0)
							if (getText[i] == '-') x = x * -1;
						if (c == 1)
							if (getText[i] == '-') y = y * -1;
						if (c == 2)
							if (getText[i] == '-') z = z * -1;
					}
				}

				if (sidePress == 0 && figureChosed == 1)
				{
					edit.setOutlineThicknesAndColor(2, 213, 66, 30, 255);
					while (window.pollEvent(event))
						if (event.type == sf::Event::MouseButtonPressed)
						{
							if (event.mouseButton.button == sf::Mouse::Left)
							{
								if (event.mouseButton.y > 738)
								{
									if (event.mouseButton.x > 235 * split + 32 && event.mouseButton.x < 235 * split + 70) x += 5;
									else if (event.mouseButton.x > 235 * split + 65 + 32 && event.mouseButton.x < 235 * split + 140) y += 5;
									else if (event.mouseButton.x > 235 * split + 130 + 32 && event.mouseButton.x < 235 * split + 225) z += 5;
									else if (event.mouseButton.x > 235 * split && event.mouseButton.x < 235 * split + 32) x -= 5;
									else if (event.mouseButton.x > 235 * split + 70 && event.mouseButton.x < 235 * split + 65 + 32) y -= 5;
									else if (event.mouseButton.x > 235 * split + 140 && event.mouseButton.x < 235 * split + 130 + 32) z -= 5;

								}
								else
									figureChosed = 0;
							}
						}
				}
				else
					edit.setOutlineThicknesAndColor(2, 85, 186, 213, 255);

				edit.changePosition(235 * split, 650);
				edit.changeText(sir);
				edit.draw(window);
				edit.coordonatesText(window, 235 * split, 650, 25, "x:", "y:", "z:");

				bool enter = 1;
				if (event.type == sf::Event::TextEntered)
				{
					std::cout << event.text.unicode << " ";
					if (event.text.unicode == 112)
						enter = 0;
				}
				littleDraw(window, x, y, z, h, enter);
				char coordonates[4][4];
				_itoa(x, coordonates[0], 10);
				_itoa(y, coordonates[1], 10);
				_itoa(z, coordonates[2], 10);
				_itoa(h, coordonates[3], 10);

				edit.coordonatesValues(window, 235 * split, 650, coordonates[0], coordonates[1], coordonates[2]);
				edit.divideCoordonates(window, 235 * split, 650);
				edit.divideSigns(window, 235 * split, 650, 247, 242, 239, 255);

				FILE* newDates = fopen(pathForFigure.c_str(), "w");
				for (int i = 0; i <= 3; i++)
				{
					fprintf(newDates, "%s", coordonates[i]);
					fprintf(newDates, "%s", " ");
				}
				fclose(newDates);

			}
			fgets(buff, 100, figuresFromFile);
		}
		fclose(figuresFromFile);
	}
	window.display();
}

void interfata()
{
	using namespace sf;
	char indexAndCoordonates[200][10]{};
	// selectL --> selectarea limbei 
	int selectL = 0;
	// nextInput --> pentru pagina creare, apasand enter trecem la textul urmator si incremantam nextInput pentru a ajuta la salvarea textului
	int nextInput = 0;
	char output[10][100]{};
	char output2[10][100]{};
	char output3[10][100]{};
	int nrFigure = -1, coordonates = 0;
	bool view = 0;
	int down = 0, slide = 0, index = 0, right = 0, sidePress = -1;
	int getxRightClick = -1, getyRightClick = -1;

	sf::RenderWindow window1(sf::VideoMode(1200, 800), "Editor/Vizualizator 3D");

	// fontul
	sf::Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));

	//pentru detaliile unui proiect nou
	std::string playerInput{};
	std::string proiect{};
	std::string project{};


	//textul ce va aparea in fereastra cu detaliile proiectului
	Text details("", font, 40);
	details.setFillColor(Color::Black);

	texts detail(output3[0], 40, 0, 0, 0, 0);

	// textul pe care l scrie utilizatorul cand da nume proiectului
	Text playerText("", font, 40);
	playerText.setFillColor(Color::Black);
	playerText.setPosition(detail.getX() + 16 * strlen(output3[0]), 20);

	Text playerText2("", font, 40);
	playerText2.setFillColor(Color::Black);
	playerText2.setPosition(detail.getX() + 16 * strlen(output3[0]), 100);
	//asteau au fost pentru detaliile unui proiect nou

	getOutText(output, output2, output3);

	int back = 40 + 10 * strlen(output2[1]);
	std::string saveNameOfProject;
	bool rightClickPressed = 0, figureChosed = 0;

	while (window1.isOpen())
	{
		sf::Event event;
		view = 0;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window1.close();
				q = 1;
			}
			if (event.type == Event::MouseMoved)
			{
				pozMx = event.mouseMove.x;
				pozMy = event.mouseMove.y;
			}
			if (curentWindow == 0)
			{
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						//cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
						if (event.mouseButton.x > 1150 && event.mouseButton.x < 1200)
						{
							//daca apasam pe limba vor aparea limbile disponibile
							if (event.mouseButton.y > 20 && event.mouseButton.y < 45)
								selectL = 1;

							//aici vom calcula ce limba a ales utilizatorul
							if (event.mouseButton.y > 45 && event.mouseButton.y < 70) {
								if (language == 1) language = 2;
								else if (language == 2) language = 3;
								else if (language == 3) language = 1;
								window1.close();
							}
							else if (event.mouseButton.y > 70 && event.mouseButton.y < 95) {
								if (language == 1) language = 3;
								else if (language == 2) language = 1;
								else if (language == 3) language = 2;
								window1.close();
							}
						}
						if (event.mouseButton.x > 60 && event.mouseButton.x < 360 && event.mouseButton.y > 200 && event.mouseButton.y < 260)	curentWindow = 1;
						if (event.mouseButton.x > 60 && event.mouseButton.x < 360 && event.mouseButton.y > 300 && event.mouseButton.y < 360)	curentWindow = 3;
					}
				}
				//if (event.type == sf::Event::TextEntered)
				//	std::cout << event.text.unicode << " ";
			}
			else if (curentWindow == 1)
			{
				if (event.type == Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						if (event.mouseButton.y < 40 && event.mouseButton.x < back)
						{
							//daca apasam butonul back ne intoarcem pe pagina anterioara
							curentWindow = 0;
						}

						if (event.mouseButton.y < 40 && event.mouseButton.x > back + 1)
						{
							//daca apasam pe butonul de proiect nou ne ducem pe urmatoarea pagina
							curentWindow = 3;
						}
						if (event.mouseButton.x > 500 + 2 * 10 * strlen(output2[3]) && event.mouseButton.x < 500 + 2 * 10 * strlen(output2[1]) + 5 * strlen(output2[4]) + 15 * strlen(output2[4]) && event.mouseButton.y > 116) view = 1;
					}
					// aici se realizeaza stergerea proiectului dorit
					if (event.mouseButton.x > 500 - 10 * strlen(output2[3]) && event.mouseButton.x < 500 + 2 * 10 * strlen(output2[3]) && event.mouseButton.y > 116)
					{
						nrProiecte--;
						char proiect[100];
						FILE* f2 = fopen("src\\userProjects/userNameOfProjects.txt", "r");

						nivel = (event.mouseButton.y - 116) / 50;
						fseek(f2, 0, SEEK_SET);

						FILE* f3 = fopen("src\\userProjects\\temporary.txt", "w+");

						fgets(proiect, 100, f2);
						nivel--;

						while (!feof(f2))
						{
							if (nivel != -1)
							{
								fprintf(f3, "%s", proiect);
							}
							else
							{
								strcpy(stergere, "src\\userProjects\\");
								strncat(stergere, proiect, strlen(proiect) - 1);
								strcat(stergere, ".txt");
								deleteDirectory(stergere);
							}
							fgets(proiect, 100, f2);
							nivel--;
						}
						remove(stergere);
						stergere[strlen(stergere) - 1] = NULL;
						stergere[strlen(stergere) - 1] = NULL;
						stergere[strlen(stergere) - 1] = NULL;
						stergere[strlen(stergere) - 1] = NULL;
						std::cout << stergere<< " ";
						_rmdir(stergere);
						//std::cout << stergere << std::endl;

						//filesystem::	
						

						fclose(f2);
						FILE* g = fopen("src\\userProjects/userNameOfProjects.txt", "w");
						fseek(f3, 0, SEEK_SET);

						fgets(proiect, 100, f3);
						while (!feof(f3))
						{
							fprintf(g, "%s", proiect);
							fgets(proiect, 100, f3);

						}
						fclose(g);
						//s a terminat stergerea
					}
					if (pozMx > 500 + 2 * 10 * strlen(output2[3]) && pozMx < 500 + 2 * 10 * strlen(output2[1]) + 5 * strlen(output2[4]) + 15 * strlen(output2[4]) && pozMy > 116) view = 1;

				}

				if (event.type == sf::Event::TextEntered)
				{
					if (scrool <= nrProiecte - 13)
						if (event.text.unicode == 108) scrool++;

					if (event.text.unicode == 111) scrool--;

					if (scrool < 0) scrool = 0;

				}
			}
			else if (curentWindow == 2)
			{
				char creareFiserTextChar[256]{};
				if (event.type == sf::Event::TextEntered)
				{
					if (nextInput == 0)
					{
						if (event.text.unicode == 13)
						{
							if (coordonates == 0)
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
							else
							{
								char projectFolder[100];

								strcpy(projectFolder, "src\\userProjects\\");
								strcat(projectFolder, saveNameOfProject.c_str());
								strcat(projectFolder, "\\");
								char sir[100];
								strcpy(sir, project.c_str());
								strcat(projectFolder, sir);
								strcat(projectFolder, ".txt");
								std::cout << projectFolder<< " ";
								
							/*	if (coordonate[0] == '-')
								{
									std::cout << "cas";
									fprintf(numeProiect2, "%s", "fhgfgh");
								}*/
								FILE* add = fopen(projectFolder, "a");
								//fprintf(add, "%s", playerInput.c_str());
								//if(playerInput[0] == '-')
								//fprintf(add, "%s", "-");

								fprintf(add, "%s", playerInput.c_str());
								fprintf(add, "%s", " ");

								fclose(add);
							}
							strcpy(indexAndCoordonates[coordonates], playerInput.c_str());

							coordonates++;
							if (coordonates == 5)
							{
								curentWindow = 3;
								coordonates = 0;
								//window1.close();
							}
							playerInput.clear();
							playerText2.setString("");

						}
						else if (coordonates > 0) {
							if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 8 || event.text.unicode == 45)
							{
								if (playerInput.length() < 3)
								{
									if (event.text.unicode == 8)
									{
										//aici daca apasam stergere din tastatura se sterge ultima litera
										if (playerInput.length() > 0)
										{
											playerInput.pop_back();
											playerText2.setString(playerInput);
										}
									}
									else
									{
										//aici modificam textul la fiecare litara apasata
										playerInput += event.text.unicode;
										playerText2.setString(playerInput);
									}
								}
								else
								{
									if (event.text.unicode == 8)
									{
										//aici daca apasam stergere din tastatura se sterge ultima litera
										playerInput.pop_back();
										playerText2.setString(playerInput);
									}
								}
							}
						}
						else if (coordonates == 0)
						{
							if (event.text.unicode == 8)
							{
								if (playerInput.length() > 0)
								{
									playerInput.pop_back();
									playerText2.setString(playerInput);
								}
							}
							else
							{
								playerInput += event.text.unicode;
								playerText2.setString(playerInput);

							}
						}
					}
				}
				if (event.type == Event::MouseButtonPressed)
				{
					//std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						if (event.mouseButton.x < 111 && event.mouseButton.y < 40)
						{
							curentWindow = 3;
							playerInput.clear();
							playerText.setString("");
							nextInput = 0;
							playerText2.setString("");
						}
						if (event.mouseButton.x > 600 && event.mouseButton.y < 100)
						{
							std::string crearefisierTextSring = "userProjects\\" + saveNameOfProject + ".txt";
							strcpy(creareFiserTextChar, crearefisierTextSring.c_str());
							nextInput = 1;
							playerText2.setString("");
							//draw(creareFiserTextChar);
						}
					}
				}
			}
			else if (curentWindow == 3)
			{
				if (slide == 0)
				{
					if (event.type == sf::Event::TextEntered)
					{
						if (event.text.unicode == 13)
						{
							char creareFiserTextChar[256];

							FILE* numeProiect = fopen("src\\userProjects/userNameOfProjects.txt", "a");

							proiect = playerInput;
							fprintf(numeProiect, "%s", proiect.c_str());
							fprintf(numeProiect, "%s", "\n");
							fclose(numeProiect);

							std::string creareFisierText;
							creareFisierText = "src\\userProjects\\" + proiect + ".txt";
							int n = creareFisierText.length();
							strcpy(creareFiserTextChar, creareFisierText.c_str());
							FILE* creare = fopen(creareFiserTextChar, "w");
							fclose(creare);
							slide++;
							saveNameOfProject = playerInput;
							std::string projectFolder = "src\\userProjects\\" + saveNameOfProject;
							strcpy(creareFiserTextChar, projectFolder.c_str());
							if (_mkdir(creareFiserTextChar));
							strcat(creareFiserTextChar, "\\");
							/*	strcat(creareFiserTextChar, "nameOfFigures");
								strcat(creareFiserTextChar, ".txt");
								FILE* creareFisier = fopen(creareFiserTextChar, "w");
								fclose(creareFisier);*/

							playerInput.clear();
						}
						else if (playerInput.length() < 25)
						{
							if (event.text.unicode != 8) {
								//aici modificam textul la fiecare litara apasata
								playerInput += event.text.unicode;
								playerText.setString(playerInput);
							}
						}
						else if (event.text.unicode == 8)
						{
							if (playerInput.length() > 0) {
								playerInput.pop_back();
								playerText.setString(playerInput);
							}
						}
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Right)
						{
							if (event.mouseButton.y < 40 && event.mouseButton.x < back) curentWindow = 0;

						}
					}
				}
				else
				{
					if (event.type == sf::Event::TextEntered)
					{
						//std::cout << event.text.unicode << " ";
						if (event.text.unicode == 27)
						{
							playerInput.clear();
							curentWindow = 0;
							slide = 0;
						}
						if (event.text.unicode == 115)
							down++;
						else if (event.text.unicode == 119)
							down--;
						else if (event.text.unicode == 97)
							right++;
						else if (event.text.unicode == 100)
							right--;

						if (down < 0) down = 0;
						if (right < 0) right = 0;

					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Right)
						{
							if (event.mouseButton.x > 10 && event.mouseButton.x < 210)
							{
								//70 120 150
								for (int i = 0; i < 7; i++)
								{
									if (event.mouseButton.y > 70 + i * 80 && event.mouseButton.y < 70 + i * 80 + 50)
									{
										curentWindow = 2; index = i + down + 1;
									}
								}
							}


							if (event.mouseButton.y > 650 && event.mouseButton.y < 775)
							{
								figureChosed = 1;
								for (int i = 0; i <= 3; i++)
								{
									if (event.mouseButton.x > 235 + 250 * i && event.mouseButton.x < 235 + 225 + 250 * i)
										sidePress = i + 1 + right;
								}
							}
							else figureChosed = 0;



							if (sidePress > 0)
							{
								getxRightClick = event.mouseButton.x;
								getyRightClick = event.mouseButton.y;
							}
						}
					}
				}
			}
		}
		//afisare
		//std::cout << figureChosed << " ";
		if (curentWindow == 0) principalScreen(window1, output, selectL);
		else if (curentWindow == 1) myProjectsWindow(window1, output2, back, view, saveNameOfProject, slide);
		else if (curentWindow == 2)	detailsAboutProject(window1, output3, nrFigure, coordonates, nextInput, indexAndCoordonates, down, playerInput, index);
		else if (curentWindow == 3)
		{
			if (slide == 0) giveNameForProject(window1, language, playerInput, pozMx, pozMy);
			else
				viewAndEdit(window1, getxRightClick, getyRightClick, language, down, right, sidePress, pozMx, pozMy, saveNameOfProject, figureChosed);

		}
	}
}