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
#include "utils/figuresInfo.hpp"
#include "utils/componentsDates.hpp"

int language = 1, line = 0, nivel = 0, nivel2, nrProiecte = 0, scrool = 0;
int curentWindow = 0;
char sir[100], proiect[100];
bool q = 0;
char stergere[200];
bool maximLength;
int pozMx, pozMy;
int pozX, pozY, cPozX, cPozY;

void littleDraw(sf::RenderWindow& window, int x, int y, int z, int h, bool edit)

{
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	window.setVerticalSyncEnabled(true);
	//Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	//creaza un cub 
	Prism cub(Vector(x, y, z), h, h, h);
	
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
			camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), edit);

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
	for(int j = 0; j<5; j++)
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(createScreen[j], a);
	}

	//Principal screen
	for (int j = 0; j < 4; j++)
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(principalScreen[j], a);
	}
	
	//viewer screen
	for (int j = 0; j < 5; j++)
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(viewerScreen[j], a);
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
			//std::cout << pathTxt << " ";
			remove(pathTxt.c_str());
			fgets(temp, 100, DELETE);
		}
	}
	std::fclose(DELETE);

	remove(path.c_str());
	
}

void principalScreen(sf::RenderWindow& window, char output[10][100], int selectL)
{
	using namespace sf;
	Texture texture;
	texture.loadFromFile("images/PrincipalBackground.jpg");
	Sprite sprite(texture);
	window.clear();
	window.draw(sprite);
	Vector2u size = window.getSize();

	//titlu
	texts titlu(output[0], size.x / 2.0f, 100, 0, 0, 60, 14, 24, 65, 255);
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
	button bar(0, 0, "", 1600, 40, 0);;
	bar.setButtonColor(11, 126, 168, 255);
	bar.draw(window);

	// textul de dupa are vor fi afisate proiectele mele
	texts titlu(output2[0], 20, 36, 0, 0, 60, 0, 0, 0, 255);
	titlu.draw(window);

	// linia ce separa bara de navigare de restul programului
	bar.changeLengthAndHeight(1600, 0);
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

	std::fclose(f2);

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
	std::fclose(f4);
	window.display();
}

void detailsAboutProject(sf::RenderWindow& window, char output3[10][100], int nrFigure, int coordonates, int nextInput, char indexAndCoordonates[200][10], int down, std::string playerText, int index)
{
	//std::cout << playerText << std::endl;
	//std::cout << index << " ";
	using namespace sf;
	Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));

	texts detail(output3[3], 10, 50, 0, 0, 40, 0, 0, 0, 255);
	Texture texture;
	//INCARCAREA BACKGROUNDULUI
	texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
	Sprite sprite(texture);
	window.clear();

	window.draw(sprite);
	//numele figurii
	detail.draw(window);

	//minus pt engleza
	int minus;
	if (language == 2) minus = 10;
	else minus = 0;

	componentsDates figura;
	if (index == 1);
	else if (index == 2) figura.cubAndSfera(window, output3, playerText, indexAndCoordonates, coordonates, minus, index, language);
	else if (index == 3) figura.prismaPatratica(window, playerText, indexAndCoordonates, coordonates, minus, language);
	else if (index == 4) figura.cubAndSfera(window, output3, playerText, indexAndCoordonates, coordonates, minus, index, language);
	else if (index == 5) figura.conAndCilinder(window, playerText, indexAndCoordonates, coordonates, minus, index, language);
	else if (index == 8) figura.conAndCilinder(window, playerText, indexAndCoordonates, coordonates, minus, index, language);
	else if (index == 6 || index == 7) figura.piramide(window, playerText, indexAndCoordonates, coordonates, minus, language, index);



	//figura.cub(window, output3, playerText, indexAndCoordonates, coordonates, minus);
		
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

	std::fclose(theNameTexts);

	int back = 40 + 10 * strlen(sir);

	texts goBack(sir, 20, 2, 0, 0, 30);
	if (pozMx < back && pozMy < 40)	goBack.changeColor(203, 55, 23, 255);
	else goBack.changeColor(234, 235, 229, 255);
	goBack.draw(window);

	window.display();
}

void viewAndEdit(sf::RenderWindow& window, int xMoved, int yMoved, int language, int scrool, int sideScrool, int sidePress, int PozMx, int PozMy, std::string Name, bool& figureChosed, bool changeUp, bool changeDown, int cpozx, int cpozy)
{
	sf::Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));

	sf::Event event{};
	using namespace sf;
	window.clear(Color(51, 51, 51, 255));
	
	int line = 0;
	char screen[10][100];
	char figure[100];
	Vector2u size = window.getSize();

	figuresInfo a;
	//std::cout << xMoved << " " << yMoved << std::endl;
	a.figures(window, size.x, size.y, xMoved, yMoved);
	a.componentsNames(window, Name, PozMx, PozMy, changeUp, changeDown, cPozX, cPozY);

	//a.figureInfoType(window, "tip:");
	//a.figureInfoPosition(window, "position:", 1, 1, 1);
	//a.figureInfoSize(window, "size:", 0, 0, 0);

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
	//for (int i = 1; i <= 3; i++)
	//{
	//	char temporary[100];
	//	fgets(temporary, 100, f);
	//	if (i == language) strcpy(screen[2], temporary);
	//}

	std::fclose(f);
	texts text(screen[0], 10, 10, 0, 0, 30, 234, 235, 229, 255);
	text.draw(window);
	text.PositionSizeString(screen[1], 1380 + 10, 10, 30);
	text.draw(window);
	window.display();
}

void interfata(sf::RenderWindow& window)
{
	using namespace sf;
	componentsDates addAndCreate;
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
	// fontul
	sf::Font font;
	if(!font.loadFromFile("Fonts/calibri.ttf"));

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
	//astea au fost pentru detaliile unui proiect nou

	getOutText(output, output2, output3);

	int back = 40 + 10 * strlen(output2[1]);
	std::string saveNameOfProject;
	bool rightClickPressed = 0, figureChosed = 0;

	while (window.isOpen())
	{
		sf::Event event;
		view = 0;
		bool changeUp = 0, changeDown = 0;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
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
								window.close();
							}
							else if (event.mouseButton.y > 70 && event.mouseButton.y < 95) {
								if (language == 1) language = 3;
								else if (language == 2) language = 1;
								else if (language == 3) language = 2;
								window.close();
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
						//std::cout << stergere<< " ";
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
						fclose(f3);
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
				std::cout << index << " ";
				char creareFiserTextChar[256]{};
				if (event.type == sf::Event::TextEntered)
				{
					if (index == 2 || index == 4)
					{
						if (event.text.unicode == 13)
						{
							if (coordonates == 0)
								addAndCreate.createTxtForComponent(saveNameOfProject, project, playerInput);
							else
								addAndCreate.addCoordonates(saveNameOfProject, project, playerInput, coordonates);
								
							strcpy(indexAndCoordonates[coordonates], playerInput.c_str());

							coordonates++;
							if (coordonates == 5)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
								memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
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
					else if (index == 3)
					{
						if (event.text.unicode == 13)
						{
							if (coordonates == 0)
								addAndCreate.createTxtForComponent(saveNameOfProject, project, playerInput);
							else
								addAndCreate.addCoordonates(saveNameOfProject, project, playerInput, coordonates);

							strcpy(indexAndCoordonates[coordonates], playerInput.c_str());

							coordonates++;
							if (coordonates == 7)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
								memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
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
					else if (index == 5 || index == 8)
					{
						if (event.text.unicode == 13)
						{
							if (coordonates == 0)
								addAndCreate.createTxtForComponent(saveNameOfProject, project, playerInput);
							else
								addAndCreate.addCoordonates(saveNameOfProject, project, playerInput, coordonates);

							strcpy(indexAndCoordonates[coordonates], playerInput.c_str());

							coordonates++;
							if (coordonates == 6)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
								memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
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
					else if (index == 6 || index == 7)
					{
						if (event.text.unicode == 13)
						{
							if (coordonates == 0)
								addAndCreate.createTxtForComponent(saveNameOfProject, project, playerInput);
							else
								addAndCreate.addCoordonates(saveNameOfProject, project, playerInput, coordonates);

							strcpy(indexAndCoordonates[coordonates], playerInput.c_str());

							coordonates++;
							if (coordonates == 6 && index == 6)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
								memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
								curentWindow = 3;
								coordonates = 0;
							}
							if (coordonates == 7)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
								memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
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
					/*if (event.type == sf::Event::TextEntered)
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

					}*/
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Right)
						{
							Vector2u size = window.getSize();

							if (event.mouseButton.x > 0 && event.mouseButton.x < size.x / 7)
							{
								//70 120 150
								for (int i = 0; i < 9; i++)
								{
									if (event.mouseButton.y > 50 + i * 50 && event.mouseButton.y < 50 + i * 50 + 50)
									{
										curentWindow = 2; index = i;
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
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							if (event.mouseButton.y < 500)
							{
								pozX = event.mouseButton.x;
								pozY = event.mouseButton.y;
							}
							else
							{
								cPozX = event.mouseButton.x;
								cPozY = event.mouseButton.y;
							}
						}
					}
					if (event.type == sf::Event::KeyPressed)
					{
						if (event.text.unicode == 73) changeUp = 1;
						if (event.text.unicode == 74) changeDown = 1;

					}
				}
			}
		}
		//afisare
		//std::cout << figureChosed << " ";
		if (curentWindow == 0) principalScreen(window, output, selectL);
		else if (curentWindow == 1) myProjectsWindow(window, output2, back, view, saveNameOfProject, slide);
		else if (curentWindow == 2)	detailsAboutProject(window, output3, nrFigure, coordonates, nextInput, indexAndCoordonates, down, playerInput, index);
		else if (curentWindow == 3)
		{
			if (slide == 0) giveNameForProject(window, language, playerInput, pozMx, pozMy);
			else
				viewAndEdit(window, pozMx, pozMy, language, down, right, sidePress, pozX, pozY, saveNameOfProject, figureChosed, changeUp, changeDown, cPozX, cPozY);

		}
	}
}