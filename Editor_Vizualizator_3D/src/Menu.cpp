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
//#include "../src/utils/mouse.hpp"
#include "utils/parameters.hpp"
#include <vector>
#include <map>

int language = 1, line = 0, nivel = 0, nivel2, nrProiecte = 0, scrool = 0;
int curentWindow = 0;
char sir[100], proiect[100];
bool q = 0;
char stergere[200];
bool maximLength, moving;
int pozMx, pozMy;
int pozX, pozY, cPozX, cPozY;

int nrCubes;
std::map<std::string, Cub>cubes;

void littleDraw(sf::RenderWindow& window, int x, int y, int z, int h, bool edit)

{
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	window.setVerticalSyncEnabled(true);
	//Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	//creaza un cub 
	Prism cub(Vector(x, y, z), h, h, h);
	Prism cub1(Vector(10, 20 , 30), 12, 23, h);

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
		cub.render_solid(window, 1200, 800, camera);		cub1.render_solid(window, 1200, 800, camera);

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
	for (int j = 0; j < 5; j++)
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
	//std::cout << path;
	
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
	texture.loadFromFile("res/images/PrincipalBackground.jpg");
	Sprite sprite(texture);
	sprite.setTextureRect(sf::IntRect(0,0,WINDOW_WIDTH, WINDOW_HEIGHT));
	window.clear();
	window.draw(sprite);
	Vector2u size = window.getSize();

	//titlu
	texts titlu(output[0], size.x / 2.0f, 150, 0, 0, 100, 14, 24, 65, 255);
	int width, height;
	titlu.setFont("res/Fonts/Montserrat/static/Montserrat-Bold.ttf");
	titlu.getLocalBounds(width, height);
	titlu.changeOrigin(width, height);
	titlu.draw(window);

	button limba(WINDOW_WIDTH - 80, 30, output[1], 50, 30, 20);
	limba.setTextFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	limba.changeTextPosition(limba.getPositionX() + 10, limba.getPositionY() + 2);
	if (pozMx > WINDOW_WIDTH - 80 && pozMx < WINDOW_WIDTH - 30 && pozMy > 30 && pozMy < 60)	limba.setOutlineThicknesAndColor(1.5, 203, 55, 23, 255);
	else limba.setOutlineThicknesAndColor(1.5, 0, 0, 0, 255);

	// butonul pentru a schimba limba
	limba.setButtonColor(43, 113, 149, 255);
	limba.setTextColor(6, 7, 7, 255);
	limba.draw(window);

	if (selectL == 1)
	{

		limba.changePosition(WINDOW_WIDTH - 80, 60);
		if (language == 1)
			limba.changeText("EG");
		else if (language == 2)
			limba.changeText("RU");
		else if (language == 3)
			limba.changeText("RO");

		limba.changeTextPosition(limba.getPositionX() + 10, limba.getPositionY() + 2);
		limba.draw(window);

		limba.changePosition(WINDOW_WIDTH - 80, 90);
		if (language == 1)
			limba.changeText("RU");
		else if (language == 2)
			limba.changeText("RO");
		else if (language == 3)
			limba.changeText("EG");
		limba.changeTextPosition(limba.getPositionX() + 10, limba.getPositionY() + 2);

		limba.draw(window);
	}

	button myProjects(WINDOW_WIDTH - 650, 350, output[2], 500, 70, 50);
	myProjects.changeTextPosition(myProjects.getPositionX() + 100, myProjects.getPositionY());
	// patratul ce va contine butonul spre pagina cu proiectele mele
	if (pozMx > WINDOW_WIDTH - 650 && pozMx < WINDOW_WIDTH - 150 && pozMy > 350 && pozMy < 420) {
		myProjects.setOutlineThicknesAndColor(4.0, 203, 55, 23, 255);
		myProjects.setTextColor(203, 55, 23, 255);
	}
	else {
		myProjects.setOutlineThicknesAndColor(3, 0, 0, 0, 255);
		myProjects.setTextColor(0, 0, 0, 255);
	}
	myProjects.setButtonColor(60, 154, 188, 255);
	myProjects.draw(window);

	button createProject(WINDOW_WIDTH - 650, 440, output[3], 500, 70, 50);
	createProject.changeTextPosition(createProject.getPositionX() + 115, createProject.getPositionY());
	if (pozMx > WINDOW_WIDTH - 650 && pozMx < WINDOW_WIDTH - 150 && pozMy > 440 && pozMy < 510)
	{
		createProject.setOutlineThicknesAndColor(4.0, 203, 55, 23, 255);
		createProject.setTextColor(203, 55, 23, 255);
	}
	else
	{
		createProject.setOutlineThicknesAndColor(3, 0, 0, 0, 255);
		createProject.setTextColor(0, 0, 0, 255);
	}
	createProject.setButtonColor(60, 154, 188, 255);
	createProject.draw(window);


	//buton iesire
	button exitApp(WINDOW_WIDTH - 650, 530, output[4], 500, 70, 50);
	exitApp.changeTextPosition(exitApp.getPositionX() + 200, exitApp.getPositionY());

	if (pozMx > WINDOW_WIDTH - 650 && pozMx < WINDOW_WIDTH - 150 && pozMy > 530 && pozMy < 600) {
		exitApp.setOutlineThicknesAndColor(4.0, 203, 55, 23, 255);
		exitApp.setTextColor(203, 55, 23, 255);
	}
	else {
		exitApp.setOutlineThicknesAndColor(3, 0, 0, 0, 255);
		exitApp.setTextColor(0, 0, 0, 255);
	}
	exitApp.setButtonColor(60, 154, 188, 255);
	exitApp.draw(window);

	window.display();

}

void myProjectsWindow(sf::RenderWindow& window, char output2[10][100], int back, bool view, std::string& saveNameOfProject, int& slide, Camera camera)
{
	figuresInfo before;
	using namespace sf;
	Texture texture;
	texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
	Sprite sprite(texture);
	nrProiecte = 0;

	FILE* f2 = fopen("src\\userProjects/userNameOfProjects.txt", "r");

	bool clear = 0;
	// in clear alegem si culoarea backgroundului
	window.clear(Color(37, 150, 190));
	window.draw(sprite);

	// un patrat de culoare diferita ce va fi pozotionat in partea de sus a ferestrei
	// ce va fi practic, bara noastra de navigare
	button bar(0, 0, "", WINDOW_WIDTH, 40, 0);
	bar.setButtonColor(11, 126, 168, 255);
	bar.draw(window);

	// textul de dupa are vor fi afisate proiectele mele
	texts titlu(output2[0], 40, 55, 0, 0, 60, 4, 42, 56, 255);
	titlu.setFont("res/Fonts/Montserrat/static/Montserrat-Bold.ttf");
	titlu.draw(window);

	// linia ce separa bara de navigare de restul programului
	bar.changeLengthAndHeight(WINDOW_WIDTH, 0);
	bar.changePosition(0, 40);
	bar.setOutlineThicknesAndColor(1, 0, 0, 0, 255);
	bar.draw(window);

	// linia ce separa cele doua butoane din bara de navigare
	button divide(back, 6, "", 2, 30, 0);
	divide.setButtonColor(0, 0, 0, 255);
	divide.draw(window);

	texts goBack(output2[1], 20, 2, 0, 0, 25);
	if (pozMx < back && pozMy < 40)	goBack.changeColor(203, 55, 23, 255);
	else goBack.changeColor(0, 0, 0, 255);
	goBack.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	goBack.draw(window);

	texts newProject(output2[2], divide.getX() + 20, 2, 0, 0, 25);
	// textul celui de al doilea buton din bara de navigare, de creare a unui proiect nou
	if (pozMx > back && pozMy < 40) newProject.changeColor(203, 55, 23, 255);
	else newProject.changeColor(0, 0, 0, 255);
	newProject.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	newProject.draw(window);

	std::fclose(f2);

	FILE* f4 = fopen("src\\userProjects/userNameOfProjects.txt", "r");

	line = 0;
	// afisarea proiectelor pe care le avem salvate pana acum
	if (pozMx > WINDOW_WIDTH - 350 && pozMx < WINDOW_WIDTH - 195 && pozMy > 150)	nivel = (pozMy - 150) / 50;
	if (pozMx > WINDOW_WIDTH - 195 && pozMx < WINDOW_WIDTH && pozMy > 150)	nivel2 = (pozMy - 150) / 50;

	char proiecte[100];
	fgets(proiecte, 100, f4);
	int copieScrool = scrool;
	while (!feof(f4))
	{
		nrProiecte++;
		if (copieScrool > 0) copieScrool--;
		else
		{
			texts out(proiecte, 55, 150 + 50 * line, 0, 0, 30, 0, 0, 0, 255);
			out.draw(window);
			/*text.setString(proiecte);
			text.setPosition(10, 120 + 50 * line);
			window1.draw(text);*/

			if (!nivel) out.changeColor(203, 55, 23, 255);
			else out.changeColor(0, 0, 0, 255);

			out.PositionSizeString(output2[3], WINDOW_WIDTH - 300, 150 + 50 * line, 25);
			out.draw(window);

			if (!nivel2) out.changeColor(203, 55, 23, 255);
			else out.changeColor(0, 0, 0, 255);
			int lungimeSirRemove = strlen(output2[1]);

			out.PositionSizeString(output2[4], WINDOW_WIDTH - 150, 150 + 50 * line, 25);
			out.draw(window);

			if (!nivel2 && view == 1)
			{
				clear = 1;
				//std::cout << saveNameOfProject << "eheheh ";
				curentWindow = 3;
				char temp[100]{};
				strncpy(temp, proiecte, strlen(proiecte) - 1);
				saveNameOfProject = temp;
				slide = 1;
				window.clear();
				before.simpleChange(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, saveNameOfProject);
				//	before.change(window, camera, saveNameOfProject, );
				break;

			}
			if (!nivel)	divide.setButtonColor(203, 55, 23, 255);

			divide.changePosition(WINDOW_WIDTH - 350, 160 + 50 * line);
			divide.draw(window);

			if (!nivel2) divide.setButtonColor(203, 55, 23, 255);
			divide.changePosition(WINDOW_WIDTH - 195, 160 + 50 * line);
			divide.draw(window);

			divide.setButtonColor(0, 0, 0, 255);

			bar.changePosition(40, 175 + 50 * line + 20);
			bar.draw(window);

			nivel--;
			nivel2--;
			line++;
			copieScrool--;	
		}
		fgets(proiecte, 100, f4);
	}
	std::fclose(f4);
	//if (clear == 1) window.clear();
	window.display();
}

void detailsAboutProject(sf::RenderWindow& window, char output3[10][100], int nrFigure, int coordonates, int nextInput, char indexAndCoordonates[200][100], int down, std::string playerText, int index)
{
	//std::cout << playerText << std::endl;
	//std::cout << index << " ";
	using namespace sf;
	Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));

	texts detail(output3[3], 45, 70, 0, 0, 30, 0, 0, 0, 255);
	detail.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	Texture texture;
	//INCARCAREA BACKGROUNDULUI
	texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
	Sprite sprite(texture);
	window.clear(sf::Color(37, 150, 190));

	// un patrat de culoare diferita ce va fi pozotionat in partea de sus a ferestrei
	// ce va fi practic, bara noastra de navigare
	button bar(0, 0, "", WINDOW_WIDTH, 40, 0);
	bar.setButtonColor(11, 126, 168, 255);
	bar.draw(window);

	// linia ce separa bara de navigare de restul programului
	bar.changeLengthAndHeight(WINDOW_WIDTH, 0);
	bar.changePosition(0, 40);
	bar.setOutlineThicknesAndColor(1, 0, 0, 0, 255);
	bar.draw(window);

	window.draw(sprite);
	//numele figurii
	detail.draw(window);

	//minus pt engleza
	int minus;
	if (language == 2) minus = 10;
	else minus = 0;

	componentsDates figura;
	if (index == 1) figura.Line(window, playerText, indexAndCoordonates, coordonates, index, language);
	else if (index == 2 || index == 4) figura.cubAndSfera(window, output3, playerText, indexAndCoordonates, coordonates, minus, index, language);
	else if (index == 3) figura.prismaPatratica(window, playerText, indexAndCoordonates, coordonates, minus, language, index);
	else if (index == 5 || index == 7) figura.conAndCilinder(window, playerText, indexAndCoordonates, coordonates, minus, index, language);
	else if (index == 6) figura.prismaPatratica(window, playerText, indexAndCoordonates, coordonates, minus, language, index);

	//figura.cub(window, output3, playerText, indexAndCoordonates, coordonates, minus);
		
	texts goBack(output3[0], 20, 5, 0, 0, 25);
	goBack.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	button line(40 + 10 * strlen(output3[0]), 4, "", 2, 30, 0);
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
	//line.changePosition(10, 40);
	/*line.changeLengthAndHeight(30 + 10 * strlen(output3[0]), 2);
	line.draw(window);*/

	window.display();
}

void giveNameForProject(sf::RenderWindow& window, int language, std::string name, int PozMx, int PozMy)
{
	window.clear(sf::Color(37, 150, 190));

	// un patrat de culoare diferita ce va fi pozotionat in partea de sus a ferestrei
	// ce va fi practic, bara noastra de navigare
	//window.clear();
	button bar(0, 0, "", WINDOW_WIDTH, 40, 0);
	bar.setButtonColor(11, 126, 168, 255);
	bar.draw(window);

	// linia ce separa bara de navigare de restul programului
	bar.changeLengthAndHeight(WINDOW_WIDTH, 0);
	bar.changePosition(0, 40);
	bar.setOutlineThicknesAndColor(1, 0, 0, 0, 255);
	bar.draw(window);

	char sir[100];
	FILE* theNameTexts = fopen("src\\programtexts/giveNameForProject.txt", "r");

	for (int i = 1; i <= 3; i++)
	{
		char buff[100];
		fgets(buff, 100, theNameTexts);
		if (i == language)
			strcpy(sir, buff);
	}

	texts text(sir, 45, 70, 0, 0, 30, 0, 0, 0, 255);
	text.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	text.draw(window);
	texts theNmae(name, 600, 70, 0, 0, 30, 234, 235, 229, 255);
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

	texts goBack(sir, 20, 2, 0, 0, 25);
	if (pozMx < back && pozMy < 40)	goBack.changeColor(203, 55, 23, 255);
	else goBack.changeColor(0, 0, 0, 255);
	goBack.setFont("res/Fonts/Montserrat/static/Montserrat-Medium.ttf");
	goBack.draw(window);

	// linia ce separa cele doua butoane din bara de navigare
	button divide(back, 6, "", 2, 30, 0);
	divide.setButtonColor(0, 0, 0, 255);
	divide.draw(window);

	window.display();
}

void viewAndEdit(sf::RenderWindow& window, Camera camera, int xMoved, int yMoved, int language, int scrool, int sideScrool, int sidePress, int PozMx, int PozMy, std::string Name, bool& figureChosed, bool changeUp, bool changeDown, int& cpozx, int& cpozy, bool movingScreen, int& compScroll)
{
	sf::Font font;
	if (!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));

	sf::Event event{};
	using namespace sf;
	figuresInfo a;

	if (!movingScreen)
	{
		//window.clear(/*Color(51, 51, 51, 255)*/);

		int line = 0;
		char screen[10][100];
		char figure[100];
		Vector2u size = window.getSize();

		a.figures(window, size.x, size.y, xMoved, yMoved, language);
		a.componentsNames(window, WINDOW_WIDTH, WINDOW_HEIGHT, Name, PozMx, PozMy, changeUp, changeDown, cPozX, cPozY, language, camera, compScroll);


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

	}
	
	window.display();
}

void interfata(sf::RenderWindow& window)
{

	int compScroll = 0;
	//littleDraw(window, 10, 20, 30, 30, 1);
	//using namespace sf;
	figuresInfo firstEntry;
	Mouse::setPosition(sf::Vector2i(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), window);

	componentsDates addAndCreate;
	char indexAndCoordonates[200][100]{};
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
	if(!font.loadFromFile("res/Fonts/Montserrat/static/Montserrat-Medium.ttf"));

	//pentru detaliile unui proiect nou
	std::string playerInput{};
	std::string proiect{};
	std::string project{};

	//textul ce va aparea in fereastra cu detaliile proiectului
	sf::Text details("", font, 40);
	details.setFillColor(sf::Color::Black);

	texts detail(output3[0], 40, 0, 0, 0, 0);

	// textul pe care l scrie utilizatorul cand da nume proiectului
	sf::Text playerText("", font, 40);
	playerText.setFillColor(sf::Color::Black);
	playerText.setPosition(detail.getX() + 16 * strlen(output3[0]), 20);

	sf::Text playerText2("", font, 40);
	playerText2.setFillColor(sf::Color::Black);
	playerText2.setPosition(detail.getX() + 16 * strlen(output3[0]), 100);
	//astea au fost pentru detaliile unui proiect nou

	getOutText(output, output2, output3);

	int back = 40 + 10 * strlen(output2[1]);
	std::string saveNameOfProject;
	bool rightClickPressed = 0, figureChosed = 0;
	Camera camera(Vector(0, -100, -230), -30, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	
	while (window.isOpen())
	{
		sf::Event event;
		view = 0;
		bool changeUp = 0, changeDown = 0;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				window.close();
			}
			if (event.type == sf::Event::MouseMoved)
			{
				pozMx = event.mouseMove.x;
				pozMy = event.mouseMove.y;
			}
			if (curentWindow == 0)
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						//cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
						if (event.mouseButton.x > WINDOW_WIDTH - 80 && event.mouseButton.x < WINDOW_WIDTH - 30)
						{
							//daca apasam pe limba vor aparea limbile disponibile
							if (event.mouseButton.y > 30 && event.mouseButton.y < 60)
								selectL = 1;

							//aici vom calcula ce limba a ales utilizatorul
							if (event.mouseButton.y > 60 && event.mouseButton.y < 90) {
								if (language == 1) language = 2;
								else if (language == 2) language = 3;
								else if (language == 3) language = 1;
								window.clear();
								interfata(window);
							}
							else if (event.mouseButton.y > 90 && event.mouseButton.y < 120) {
								if (language == 1) language = 3;
								else if (language == 2) language = 1;
								else if (language == 3) language = 2;
								window.clear();
								interfata(window);
							}
						}
						if (event.mouseButton.x > WINDOW_WIDTH - 650 && event.mouseButton.x < WINDOW_WIDTH - 150 && event.mouseButton.y > 350 && event.mouseButton.y < 420)	curentWindow = 1;
						if (event.mouseButton.x > WINDOW_WIDTH - 650 && event.mouseButton.x < WINDOW_WIDTH - 150 && event.mouseButton.y > 440 && event.mouseButton.y < 510) { curentWindow = 3; slide = 0; window.clear(); }
						if (event.mouseButton.x > WINDOW_WIDTH - 650 && event.mouseButton.x < WINDOW_WIDTH - 150 && event.mouseButton.y > 530 && event.mouseButton.y < 600) window.close();
					}
				}
				
			}
			else if (curentWindow == 1)
			{
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
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
							slide = 0;
							window.clear();
						}
						if (event.mouseButton.x > 500 + 2 * 10 * strlen(output2[3]) && event.mouseButton.x < 500 + 2 * 10 * strlen(output2[1]) + 5 * strlen(output2[4]) + 15 * strlen(output2[4]) && event.mouseButton.y > 116) {
							view = 1;figuresInfo a;
							a.simpleChange(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, saveNameOfProject);
						}
					}
					// aici se realizeaza stergerea proiectului dorit
					if (event.mouseButton.x > WINDOW_WIDTH - 300 && event.mouseButton.x < WINDOW_WIDTH - 195 && event.mouseButton.y > 150)
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
							if (nivel != 0)
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
					if (pozMx > WINDOW_WIDTH - 195 && pozMx < WINDOW_WIDTH && pozMy > 150) view = 1;

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
					if (index == 1)
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
								rotateCamera = true;
								window.clear();
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
								rotateCamera = true;
								window.clear();
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
								rotateCamera = true;
								window.clear();
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
					else if (index == 5 || index == 7)
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
								rotateCamera = true;
								window.clear();
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
					else if (index == 6)
					{
						if (event.text.unicode == 13)
						{
							if (coordonates == 0)
								addAndCreate.createTxtForComponent(saveNameOfProject, project, playerInput);
							else
								addAndCreate.addCoordonates(saveNameOfProject, project, playerInput, coordonates);

							strcpy(indexAndCoordonates[coordonates], playerInput.c_str());

							coordonates++;
							/*if (coordonates == 6)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
							}*/
							if (coordonates == 7)
							{
								addAndCreate.addIndex(saveNameOfProject, project, index);
								memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
								curentWindow = 3;
								rotateCamera = true;

								window.clear();
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
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (event.mouseButton.button == sf::Mouse::Left)
					{
						if (event.mouseButton.x < 111 && event.mouseButton.y < 40)
						{
							figuresInfo a;
							curentWindow = 3;
							playerInput.clear();
							playerText.setString("");
							nextInput = 0;
							playerText2.setString("");
							window.clear();
							memset(indexAndCoordonates, 0, sizeof(indexAndCoordonates));
							coordonates = 0;

							int number = 0;
							char projectFolder[100];
							strcpy(projectFolder, "src\\userProjects\\");
							strcat(projectFolder, saveNameOfProject.c_str());
							strcat(projectFolder, "\\name.txt");
							FILE* numeProiect2 = fopen(projectFolder, "r");
							char buff[100];
							fgets(buff, 100, numeProiect2);
							while (!feof(numeProiect2))
							{
								number++;
								fgets(buff, 100, numeProiect2);

							}

							fclose(numeProiect2);
							char lastLine[100]{};
							strncpy(lastLine, buff, strlen(buff) - 1);
							FILE* t = fopen("src\\userProjects\\temp.txt", "w");

							FILE* numeProiect3 = fopen(projectFolder, "r");
							fgets(buff, 100, numeProiect3);
							while (!feof(numeProiect3))
							{
								number--;
								if (number >= 1) fprintf(t, "%s", buff);
								fgets(buff, 100, numeProiect3);

							}
							fclose(numeProiect3);
							fclose(t);

							FILE* f = fopen("src\\userProjects\\temp.txt", "r+");
							FILE* numeProiect4 = fopen(projectFolder, "w");
							fgets(buff, 100, f);
							while (!feof(f))
							{
								fprintf(numeProiect4, "%s", buff);
								fgets(buff, 100, f);

							}
							fclose(f);
							fclose(numeProiect4);
							a.simpleChange(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, saveNameOfProject);
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

							/*	while (proiect[proiect.size() - 1] == ' ')
								{
									proiect.pop_back();
								}*/
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

							while (saveNameOfProject[saveNameOfProject.size() - 1] == ' ')
							{
								saveNameOfProject.pop_back();
							}
							projectFolder = "src\\userProjects\\";
							projectFolder += saveNameOfProject;
							projectFolder += "\\name.txt";
							FILE* numeProiect2 = fopen(projectFolder.c_str(), "a");
							fclose(numeProiect2);
							playerInput.clear();
							window.clear();
						}
						else if (playerInput.length() < 25)
						{
							if (event.text.unicode != 8) {
								//aici modificam textul la fiecare litara apasata
								playerInput += event.text.unicode;
								playerText.setString(playerInput);
							}
						}
						if (event.text.unicode == 8)
						{
							if (playerInput.length() > 0) {
								playerInput.pop_back();
								playerText.setString(playerInput);
							}
						}
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							if (event.mouseButton.y < 40 && event.mouseButton.x < back) curentWindow = 0;

						}
					}
				}
				else
				{
					if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
						window.close();

					if (event.type == sf::Event::Resized) {
						window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
						WINDOW_WIDTH = event.size.width;
						WINDOW_HEIGHT = event.size.height;
						camera.reload_figures(WINDOW_WIDTH, WINDOW_HEIGHT);
					}
					if (event.type == sf::Event::MouseButtonPressed)
					{
						if (event.mouseButton.button == sf::Mouse::Left)
						{
							sf::Vector2u size = window.getSize();

							//intoarcere in meniul principal din modul de editare
							if (event.mouseButton.y > window.getSize().y - 30 && event.mouseButton.x < 180 && event.mouseButton.y > window.getSize().y - 30 && event.mouseButton.x > 20)
							{
								curentWindow = 0;
								window.clear();
							}

							if (event.mouseButton.x > 0 && event.mouseButton.x < 195)
							{
								//70 120 150
								for (int i = 0; i < 8; i++)
								{
									if (event.mouseButton.y > 15 + i * 60 && event.mouseButton.y < 15 + i * 60 + 50)
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
							if (event.mouseButton.y < 500 && event.mouseButton.x < window.getSize().x - 50)
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
						//if (event.text.unicode == 58 && !moving) moving = 1;
						//else if (event.text.unicode == 58 && moving) moving = 0;

					}
					if (event.type == sf::Event::MouseWheelScrolled)
					{
						if (event.mouseWheelScroll.delta > 0) { compScroll--; }
						else {
							compScroll++;
						}
						if (compScroll < 0) compScroll = 0;
					}
				}
			}
		}

		camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);

		// move camera
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

		//modul de editare
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
		{
			rotateCamera = true;
			camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);
			//btnAddPrism.setBackColor(sf::Color::White);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
		{
			rotateCamera = false;
			camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);
			//a.figures(window, 0, 0, 0, 0, 1);
		}
		//afisare
		//std::cout << figureChosed << " ";
		if (curentWindow == 0) principalScreen(window, output, selectL);
		else if (curentWindow == 1) myProjectsWindow(window, output2, back, view, saveNameOfProject, slide, camera);
		else if (curentWindow == 2)	detailsAboutProject(window, output3, nrFigure, coordonates, nextInput, indexAndCoordonates, down, playerInput, index);
		else if (curentWindow == 3)
		{
			////window.clear();
			if (slide == 0) giveNameForProject(window, language, playerInput, pozMx, pozMy);
			else
			{
				while (saveNameOfProject[saveNameOfProject.size() - 1] == ' ')
				{
					saveNameOfProject.pop_back();
				}
				int nothing = 0;
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
				nothing--;
				//firstEntry.change(window, camera, saveNameOfProject);
				if (rotateCamera == false || nothing == 0) {
					figuresInfo a;
					//a.simpleChange(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera, saveNameOfProject);
					viewAndEdit(window, camera, pozMx, pozMy, language, down, right, sidePress, pozX, pozY, saveNameOfProject, figureChosed, changeUp, changeDown, cPozX, cPozY, moving, compScroll);
				}
				else
				{
					int nr = 0;
					char everything[100][100];
					

					window.clear();

					if (nothing > 0)
					{

						FILE* compNames = fopen(path.c_str(), "r+");
						//std::cout << path << std::endl;
						//if(!feof)
						if (!feof(compNames))
						{
							char buff[100];
							fgets(buff, 100, compNames);
							while (!feof(compNames))
							{
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
								char position[100], sizes[101], Index[10];

								if (!feof(compDates))
								{
									std::fgets(position, 100, compDates);
									std::fgets(sizes, 101, compDates);
									std::fgets(Index, 10, compDates);
								}
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
								fgets(buff, 100, compNames);

							}
						}
							//std::cout << "aiurea";
							fclose(compNames);

						for (int i = 0; i < nr; i++)
						{
							int x = 0, y = 0, z = 0, index = 0, h = 0, l = 0, L = 0;
							int c = 0;
							for (int j = 0; j < strlen(everything[i]); j++)
							{
								if (everything[i][j] == ' ') c++;
								if (everything[i][j] >= '0' && everything[i][j] <= '9')
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
								{
									if (c == 0)
										if (everything[i][j] == '-') x = x * -1;
									if (c == 1)
										if (everything[i][j] == '-') y = y * -1;
									if (c == 2)
										if (everything[i][j] == '-') z = z * -1;
								}
							}
							std::cout<<"aaaaaaaaaaaaaaaaa" << std::endl;
							std::cout << "x =" << x << std::endl;
							std::cout << "y =" << y << std::endl;
							std::cout << "z =" << z << std::endl;
							std::cout << "h =" << h << std::endl;
							std::cout << "l =" << l << std::endl;
							std::cout << "L =" << L << std::endl;



							//std::cout << nr << " " << x << " " << y << " " << z;
							//std::cout << " " << index << " ";
							//std::cout << h << " " << l << " " << L << std::endl;
							if (index == 1)
							{
								Line line(Vector(x, y, z), Vector(h, l, L));
								line.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
							}
							else if (index == 2)
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
						window.display();
						memset(everything, 0, sizeof(everything));
					}

				}
			}
		}
	}
}
