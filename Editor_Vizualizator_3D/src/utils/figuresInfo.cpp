#include "figuresInfo.hpp"
#include "../menu/texts.hpp"
#include <SFML/Graphics.hpp>
#include "../menu/button.hpp"
#include "../geometry/geometrie.hpp"
#include "../geometry/solid3d.hpp"
#include <iostream>
#include "parameters.hpp"
//#include "mouse.hpp"
#include "..\\utils\mouse.hpp"


void figuresInfo::figures(sf::RenderWindow& window, int height, int width, int PozMx, int PozMy, int language)
{
	using namespace sf;
	char figure[100];
	Vector2u size = window.getSize();
	int line = 0;	
	Camera camera(Vector(0, -100, -230), -30, 0, 0, 1900, 900);

	button figures(0, 50, "",size.x / 7 - 5, 50, 30, 2, 81, 81, 81, 255);
	figures.setButtonColor(81, 81, 81, 255);

	RectangleShape dividerForFigures(Vector2f(size.x / 7, size.y));
	dividerForFigures.setFillColor(Color(81, 81, 81, 255));
	window.draw(dividerForFigures);

	sf::Font font;
	if (!font.loadFromFile("Fonts/Oswald-Medium.ttf"));
	//figures.changeFont(font);

	FILE* PosibleFiguresFromFile;
	if(PosibleFiguresFromFile = fopen("src\\programtexts\\posibleFigures.txt", "r"));
	{
		while (!feof(PosibleFiguresFromFile))
		{
			char sir[100]{};

			for (int i = 1; i <= 3; i++)
			{
				fgets(figure, 100, PosibleFiguresFromFile);
				if(i == language)
					strncpy(sir, figure, strlen(figure) - 1);
			}
			line++;
			figures.changeText(sir);
			figures.changePosition(0, 50 + 60 * line);

			if ((PozMx > 0 && PozMx < size.x / 7) && (PozMy > 60 * line + 50 && PozMy < 60 * line + 100))
				figures.setButtonColor(41, 45, 48, 255);
			else
				figures.setButtonColor(81, 81, 81, 255);

			if (line == 6 || line == 7) {
				figures.setTextSize(20);
				figures.textUpDown(window, sir);
			}
			else figures.setTextSize(25);

			if (line == 1) 	figures.putIcon(window, "", sir);
			figures.centerTextInMidddle();
			if(line != 6 && line != 7)
			figures.draw(window);
			figures.putIcon(window, "", sir);

		}
		std::fclose(PosibleFiguresFromFile);
	}
}

void figuresInfo::componentsNames(sf::RenderWindow& window, std::string Name, int pozMx, int pozMy, bool changeUp, bool changeDown, int x, int y)
{
	using namespace sf;
	using namespace std;
	int line = 0;
	char buff[100]{}, saveSir[100]{};
	int maximComponents = 0;
	int select = 0;
	Vector2u size = window.getSize();
	RectangleShape spaceForComponents(Vector2f(220, size.y));
	//Vector2f sizeSpace = spaceForComponents.getSize();
	spaceForComponents.setPosition(1380, 0);
	//cout << size.x - (size.x / 7) << endl;
	spaceForComponents.setFillColor(Color(81, 81, 81, 255));
	window.draw(spaceForComponents);

	RectangleShape Line(Vector2f(220, 2));
	Line.setFillColor(Color(204, 224, 228, 255));

	std::string pathForProject = "src\\userProjects\\";//; + Name; //+ "nameOfFigures";;
	pathForProject += Name + "\\name.txt";
	FILE* componentsFromFile;
	texts text(20, 51, 51, 51, 255, "");
	button components(0, 0, "", 220, 30, 25);
	components.setButtonColor(81, 81, 81, 255);
	components.setTextColor(234, 235, 229, 255);

	if (!(componentsFromFile = fopen(pathForProject.c_str(), "a+")));
	else
	{
		if (std::fgets(buff, 100, componentsFromFile) == 0);

		while (!feof(componentsFromFile))
		{
			if (maximComponents < 14)
			{
				char sir[100]{};
				std::strncpy(sir, buff, strlen(buff) - 1);
				componentsDrawStatic(window, Name, sir);

				//std::cout << sir << std::endl;
				components.changeText(sir);
				components.changePosition(1380, 50 + 30 * line + 5 + 2);
					if (pozMx > 1390 && pozMy > 50 + 30 * line + 5 + 2 && pozMy < 50 + 30 * line + 5 + 2 + 30)
					{
						strcpy(saveSir, sir);
						components.setButtonColor(49, 51, 49, 255);
						figureInfoPosition(window, "pozitie:", Name, sir, changeUp, changeDown, x, y);
						figureInfoType(window, "tip:", Name, sir);
						figureInfoSize(window, "size", Name, sir, 1, changeUp, changeDown, x, y);
					}
					else 
						components.setButtonColor(81, 81, 81, 255);

				components.draw(window);
				Line.setPosition(1380, 50 + 30 * (line + 1) + 5);
				window.draw(Line);
				line++;
				maximComponents++;
			}
			std::fgets(buff, 100, componentsFromFile);
		}
	}
	std::fclose(componentsFromFile);
}

void figuresInfo::componentsDrawStatic(sf::RenderWindow& window, std::string Name, std::string componentName)
{
	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";
	int index = 0;

	FILE* sizeDates = fopen(pathForProject.c_str(), "r");
	char position[100], sizes[101], Index[10];

	if (!feof(sizeDates))
	{
		std::fgets(position, 100, sizeDates);
		std::fgets(sizes, 101, sizeDates);
		std::fgets(Index, 10, sizeDates);

	}
	//scoatem indexul din fisier
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

	//scoatem pozitiile din fisier
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
			//std::cout << getText[i] << " " << c << std::endl;
			if (c == 0)
				if (getText[i] == '-') x = x * -1;
			if (c == 1)
				if (getText[i] == '-') y = y * -1;
			if (c == 2)
				if (getText[i] == '-') z = z * -1;
		}
	}

	/*std::cout << index << std::endl;
	std::cout << x << " " << y << " " << z << std::endl;
	std::cout << h << " " << l << " " << L << std::endl;*/

	Camera camera(Vector(0, -100, -230), -30, 0, 0, 1600, 900);

	if (index == 2)
	{
		Cub cub(Vector(x, y, h), h);
		cub.render_solid(window, 1600, 900, camera);
	}
	else if (index == 3)
	{
		Prism prisma(Vector(x, y, z), h, l, L);
		prisma.render_solid(window, 1600, 900, camera);
	}
	else if (index == 4)
	{
		Sphere3d sphere(Vector(x, y, z), h, 100, 20);
		sphere.render_solid(window, 1600, 900, camera);
	}
	else if (index == 5)
	{
		Cylinder3d cylinder(Vector(x, y, z), h, l, 20);
		cylinder.render_solid(window, 1600, 900, camera);
	}
	else if (index == 6)
	{
		Pyramid3d pyramid(Vector(x, y, z), h, l, L);
		pyramid.render_solid(window, 1600, 900, camera);
	}
	else if (index == 7)
	{
		Pyramid3d pyramid(Vector(x, y, z), h, l, L);
		pyramid.render_solid(window, 1600, 900, camera);
	}
	else if (index == 8)
	{
		Con3d con(Vector(x, y, z), h, l, 20);
		con.render_solid(window, 1600, 900, camera);
	}

	fclose(sizeDates);
}

void figuresInfo::componentsDrawMoving(sf::RenderWindow& window, std::string Name, std::string componentName)
{
	Camera camera(Vector(0, -100, -230),-30, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	while (window.isOpen())
	{
		char everything[100][100];
		int nr = 0;
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			if (event.type == sf::Event::Resized) {
				window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
				WINDOW_WIDTH = event.size.width;
				WINDOW_HEIGHT = event.size.height;
				camera.reload_figures(WINDOW_WIDTH, WINDOW_HEIGHT);
			}

		}

		//rotate camera
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
		}

		std::string path = "src\\userProjects\\";
		path += Name;
		path += "\\";
		path += "name.txt";
		FILE* compNames = fopen(path.c_str(), "r+");
		//std::cout << path << std::endl;
		while (!feof(compNames))
		{
			int index = 0;
			char buff[100];
			fgets(buff, 100, compNames);
			char comp[100]{};
			strncpy(comp, buff, strlen(buff) - 1);
			std::string pathForDates = "src\\userProjects\\";
			pathForDates += Name;
			pathForDates += "\\";
			pathForDates += comp;
			pathForDates += ".txt";
			std::cout << pathForDates << std::endl;
			FILE* compDates = fopen(pathForDates.c_str(), "r+");

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

			//scoatem pozitiile din fisier
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
		fclose(compNames);

		window.clear();
		for (int i = 0; i < nr; i++)
		{
			int x = 0, y = 0, z = 0, index = 0, h = 0, l = 0, L = 0;
			int c = 0;
			for (int j = 0; j < strlen(everything[i]); j++)
			{
				if (everything[i][j] == ' ') c++;
				else
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
			std::cout <<nr<<" "<< x << " " << y << " " << z;
			std::cout << " " <<index;
			std::cout << h << " " << l << " " << L << std::endl;

			if (index == 2)
			{
				Cub cub(Vector(x, y, h), h);
				cub.render_solid(window, 1600, 900, camera);
			}
			else if (index == 3)
			{
				Prism prisma(Vector(x, y, z), h, l, L);
				prisma.render_solid(window, 1600, 900, camera);
			}
			else if (index == 4)
			{
				Sphere3d sphere(Vector(x, y, z), h, 100, 20);
				sphere.render_solid(window, 1600, 900, camera);
			}
			else if (index == 5)
			{
				Cylinder3d cylinder(Vector(x, y, z), h, l, 20);
				cylinder.render_solid(window, 1600, 900, camera);
			}
			else if (index == 6)
			{
				Pyramid3d pyramid(Vector(x, y, z), h, l, L);
				pyramid.render_solid(window, 1600, 900, camera);
			}
			else if (index == 7)
			{
				Pyramid3d pyramid(Vector(x, y, z), h, l, L);
				pyramid.render_solid(window, 1600, 900, camera);
			}
			else if (index == 8)
			{
				Con3d con(Vector(x, y, z), h, l, 20);
				con.render_solid(window, 1600, 900, camera);
			}
		}
			//std::cout << everything[i] << std::endl;
			
			memset(everything, 0, sizeof(everything));
			//afisare
			//window.clear();
			//Cub cub(Vector(0, 0, 0), 40);
			//cub.render_solid(window, 1200, 800, camera);
			//cub1.render_solid(window, 1200, 800, camera);
			//cub2.render_solid(window, 1200, 800, camera);
			////platou.render_solid(window, 1200, 800, camera);
			////cub1.render_solid(window, 1200, 800, camera);
			//cub.rotate(Vector(50,0,0), Vector(0,1,0), 1, true);
			//cub1.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);
			//cub2.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);

			//prisma1.render_solid(window, 1200, 800, camera);
			//prisma1.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);
			/*leg1.render_solid(window, 1200, 800, camera);
			leg2.render_solid(window, 1200, 800, camera);
			leg3.render_solid(window, 1200, 800, camera);
			leg4.render_solid(window, 1200, 800, camera);
			fata.render_solid(window, 1200, 800, camera);*/
			//btnAddPrism.drawTo(window);

			//sfera.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			//cilindru.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			//cilindru1.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			//con1.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			//con1.rotate(Vector(50, 0, 0), Vector(1, 0, 0), 1, false);
			//piramida.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
			//figura.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);

			window.display();
		

	}

}

	
void figuresInfo::figureInfoType(sf::RenderWindow& window, std::string Type, std::string Name, std::string componentName)
{
	int index = 0;
	using namespace sf;
	Vector2u size = window.getSize();
	texts type(15, 51, 51, 51, 255, Type);
	type.changePosition(1380 + 10, 500);
	type.draw(window);
	FloatRect textWidht = type.getLocalBoundsAuto();

	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";

	FILE* figuresFromFile = fopen(pathForProject.c_str(), "r");
	char buff[100];

	if (!feof(figuresFromFile))
	{
		std::fgets(buff, 100, figuresFromFile);
		std::fgets(buff, 100, figuresFromFile);
		fgets(buff, 100, figuresFromFile);
		char getText[100]{};
		strncpy(getText, buff, strlen(buff) - 1);
		for (int i = 0; i < strlen(getText); i++)
		{
			if(getText[i] >= '0' && getText[i] <= '9')
				index = index * 10 + int(getText[i] - 48);

		}
	}
	fclose(figuresFromFile);


	button figureType(1390 + textWidht.width + 10, 510, "", 150, 24, 24);

	FILE* typeText;
	if (typeText = fopen("src\\programtexts\\posibleFigures.txt", "r"));

	if (index == 6 || index == 7)
		figureType.setTextSize(15);
	else
		figureType.setTextSize(24);

	while (!feof(typeText) && index)
	{
		fgets(buff, 100, typeText);
		index--;
	}
	std::fclose(typeText);

	char typeName[100]{};
	strncpy(typeName, buff, strlen(buff) - 1);
	figureType.changeText(typeName);
	figureType.setTextColor(51, 51, 51, 255);
	figureType.setButtonColor(132, 125, 120, 255);

	figureType.draw(window);
}

void figuresInfo::figureInfoPosition(sf::RenderWindow& window, std::string position, std::string Name, std::string componentName, bool changeUp, bool changeDown, int pozMx, int pozMy)
{
	using namespace sf;
	std::string xCoordonate ="x: ", yCoordonate = "y: ", zCoordonate = "z: ";
	char X[20]{}, Y[20]{}, Z[20]{};
	int x = 0, y = 0, z = 0;
	//Vector2u size = window.getSize();
	//std::cout << changeUp << " " << changeDown << std::endl;
	texts type(15, 51, 51, 51, 255, position);
	type.changePosition(1380 + 10, 540);
	type.draw(window);

	FloatRect l = type.getLocalBoundsAuto();
	char size[200], index[30]{};
	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";
	
	button forX(1400 + l.width, 548, "", 100, 24, 24);
	button forY(1400 + l.width, 578, "", 100, 24, 24);
	button forZ(1400 + l.width, 608, "", 100, 24, 24);

	FILE* compALL;
	if(compALL = fopen(pathForProject.c_str(), "r"));
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
	
	if (pozMx > 1400 + l.width && pozMx < 1500 + l.width && pozMy > 548 && pozMy < 548 + 24)
	{
		forX.setButtonColor(244, 207, 137, 255);
		if (changeDown) x--;
		if (changeUp) x++;
	}
	else
		forX.setButtonColor(132, 125, 120, 255);

	if (pozMx > 1400 + l.width && pozMx < 1500 + l.width && pozMy > 578 && pozMy < 578 + 24)
	{
		forY.setButtonColor(244, 207, 137, 255);
		if (changeDown) y--;
		if (changeUp) y++;
	}
	else
		forY.setButtonColor(132, 125, 120, 255);

	if (pozMx > 1400 + l.width && pozMx < 1500 + l.width && pozMy > 608 && pozMy < 608 + 24)
	{
		forZ.setButtonColor(244, 207, 137, 255);
		if (changeDown) z--;
		if (changeUp) z++;
	}
	else
		forZ.setButtonColor(132, 125, 120, 255);

	_itoa(x, X, 10); xCoordonate += X;
	_itoa(y, Y, 10); yCoordonate += Y;
	_itoa(z, Z, 10); zCoordonate += Z;
	//std::cout << xCoordonate << " " << yCoordonate << " " << zCoordonate << std::endl;
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
}

void figuresInfo::figureInfoSize(sf::RenderWindow& window, std::string _size, std::string Name, std::string componentName, int language, bool changeUp, bool changeDown, int pozMx, int pozMy)
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
				strcpy(output[j], temporary);
		}
	std::fclose(Texts);

	texts size(15, 51, 51, 51, 255, output[0]);
	size.changePosition(1380 + 10, 630);
	size.draw(window);

	FloatRect textWidht = size.getLocalBoundsAuto();

	std::string pathForProject = "src\\userProjects\\";
	pathForProject += Name;
	pathForProject += "\\";
	pathForProject += componentName;
	pathForProject += ".txt";

	FILE* sizeDates = fopen(pathForProject.c_str(), "r");
	char position[100], sizes[101], Index[10];

	button forH(1400 + textWidht.width, 640, "", 100, 24, 24);
	button forlen(1400 + textWidht.width, 670, "", 100, 24, 24);
	button forW(1400 + textWidht.width, 700, "", 100, 24, 24);

	if (!feof(sizeDates))
	{
		std::fgets(position, 100, sizeDates);
		std::fgets(sizes, 101, sizeDates);
		std::fgets(Index, 10, sizeDates);

	}
	char getIndex[100];
	std::strncpy(getIndex, Index, strlen(Index) - 1);
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

	if (pozMx > 1400 + textWidht.width && pozMx < 1500 + textWidht.width && pozMy > 640 && pozMy < 640 + 24)
	{
		forH.setButtonColor(244, 207, 137, 255);
		if (changeDown) h--;
		if (changeUp) h++;
	}
	else
		forH.setButtonColor(132, 125, 120, 255);

	if (pozMx > 1400 + textWidht.width && pozMx < 1500 + textWidht.width && pozMy > 670 && pozMy < 670 + 24)
	{
		forlen.setButtonColor(244, 207, 137, 255);
		if (changeDown) l--;
		if (changeUp) l++;
	}
	else
		forlen.setButtonColor(132, 125, 120, 255);

	if (pozMx > 1400 + textWidht.width && pozMx < 1500 + textWidht.width && pozMy > 700 && pozMy < 700 + 24)
	{
		forW.setButtonColor(244, 207, 137, 255);
		if (changeDown) L--;
		if (changeUp) L++;
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
	//std::cout << index << " ";

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

