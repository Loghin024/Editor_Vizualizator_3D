#include <SFML\Graphics.hpp>
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"
#include "utils/mouse.hpp"
#include "utils/Button.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include "utils/foldersAndTexts.hpp"
#include "Menu.hpp"

//void draw(char path[200])
//{
//	sf::ContextSettings window_settings;
//	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
//	sf::RenderWindow window(sf::VideoMode(1200, 800), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
//	window.setVerticalSyncEnabled(true);
//	Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);
//
//	char line[200];
//	int place = 0;
//	
//	Camera camera(Vector(0, -100, -230), -30, 0, 0, 1200, 800);
//
//	while (window.isOpen())
//	{
//		sf::Event event;
//
//		while (window.pollEvent(event))
//		{
//			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
//				window.close();
//		}
//
//		//rotire camera
//		camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window));
//
//		// misca camera
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
//			camera.move(Camera::DIRECTION::FRONT);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
//			camera.move(Camera::DIRECTION::BACK);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//			camera.move(Camera::DIRECTION::RIGHT);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//			camera.move(Camera::DIRECTION::LEFT);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
//			camera.move(Camera::DIRECTION::UP);
//		if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
//			camera.move(Camera::DIRECTION::DOWN);
//
//		//afisare
//		window.clear();
//		int x = 0, y = 0, z = 0, index = 0, h = 0;
//		FILE* open = fopen(path, "r+");
//		int nr = 0;
//		while (!feof(open))
//		{
//			x = 0, y = 0, z = 0, index = 0, h = 0;
//			nr = 0;
//			fgets(line, 100, open);
//			for (int i = 0; i < strlen(line); i++)
//			{
//				int minus;
//				if (line[i] == ' ')	nr++;
//				if (line[i - 1] == '-') minus = -1;
//				else minus = 1;
//				if (nr == 0 && line[i] != ' ' && line[i] != '-') index = (index * 10 + int(line[i]) - 48);
//				else if (nr == 1 && line[i] != ' ' && line[i] != '-') x = (x * 10 + int(line[i]) - 48) * minus;
//				else if (nr == 2 && line[i] != ' ' && line[i] != '-') y = (y * 10 + int(line[i]) - 48) * minus;
//				else if (nr == 3 && line[i] != ' ' && line[i] != '-') z = (z * 10 + int(line[i]) - 48) * minus;
//				else if (nr == 4 && line[i] != ' ' && line[i] != '-') h = (h * 10 + int(line[i]) - 48);
//			}
//
//			if (index == 1)
//			{
//				Cub cub(Vector(x, y, z), h);
//				cub.render_solid(window, 1200, 800, camera);
//			}
//		}
//
//		fclose(open);
//
//		window.display();
//	}
//
//}

	//// in "lungimeSirRemove" vom retine lungimea sirului ce va fi afisat pe butonul de stergere a unui proiect salvat
	//int lungimeSirRemove = strlen(sir);

	//// in "removeProj" vom retine textul afisat pe butonul de stergere a unui proiect salvat
	//Text removeProj;
	//removeProj.setFont(font);
	//removeProj.setCharacterSize(25);
	//removeProj.setString(sir);
	//removeProj.setFillColor(Color::Black);

	//// "rectangleLine" este o linie ce va deliminita proiectele unul de altul
	//RectangleShape rectangleLine(sf::Vector2f(1200, 3));
	//rectangleLine.setFillColor(Color::Black);

	//// "rectangleUp" este un patrat colorat mai inchis ce deliminiteaza bara de navigare de restul ferestrei
	//RectangleShape rectangleUp(sf::Vector2f(1200, 40));
	//rectangleUp.setPosition(0, 0);
	//rectangleUp.setFillColor(Color(11, 116, 168, 255));

	//while (windowCreari.isOpen())
	//{
	//	sf::Event event;

		/*while (windowCreari.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				windowCreari.close();
				q = 1;
			}

			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					cout << event.mouseButton.x << " " << event.mouseButton.y << " " << endl;
					if (event.mouseButton.y < 40 && event.mouseButton.x < back)
					{
						curentWindow = 0;
						windowCreari.close();
					}
					
					if (event.mouseButton.y < 40 && event.mouseButton.x > back + 1)
					{
						fereastraDetaliiProiect();
					}*/

					//if (event.mouseButton.x > 500 - 10 * strlen(sir) && event.mouseButton.x < 500 + 2 * 10 * strlen(sir) && event.mouseButton.y > 116)
					//{
					//	// aici se realizeaza stergerea proiectului dorit
					//	FILE* f2 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\proiecte.txt", "r");

					//	int nivel = (event.mouseButton.y - 116) / 50;
					//	fseek(f2, 0, SEEK_SET);

					//	FILE* f3 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\temporar.txt", "w+");

					//	fgets(proiect, 100, f2);
					//	nivel--;

					//	while (!feof(f2))
					//	{
					//		if (nivel != -1)
					//		{
					//			fprintf(f3, "%s", proiect);
					//		}
					//		else
					//		{
					//			strcpy(stergere, "C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\proiectele utilizatorului\\");
					//			cout << proiect;
					//			strncat(stergere, proiect, strlen(proiect) - 1);
					//			strcat(stergere, ".txt");
					//		}
					//		fgets(proiect, 100, f2);
					//		nivel--;
					/*	}

						if (remove(stergere));
						fclose(f2);
						FILE* g = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\proiecte.txt", "w");
						fseek(f3, 0, SEEK_SET);

						fgets(proiect, 100, f3);
						while (!feof(f3))
						{
							fprintf(g, "%s", proiect);
							fgets(proiect, 100, f3);

						}
						fclose(g);
						
					}
				}
			}
		}
		FILE* f2 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\proiecte.txt", "r");

		windowCreari.clear(Color(37, 150, 190));

		rectangleBack.setPosition(back, 6);
		textUp.setPosition(rectangleBack.getPosition().x + 20, 2);*/

		/*windowCreari.draw(textTitlu);
		windowCreari.draw(rectangleUp);
		windowCreari.draw(rectangleBack);
		
		rectangleLine.setPosition(0, 40);
		windowCreari.draw(rectangleLine);

		windowCreari.draw(textUp);
		windowCreari.draw(textBack);

		fseek(f2, 0, SEEK_SET);
		linie = 0;

		fgets(proiect, 100, f2);
		while (!feof(f2))
		{
			proiecte.setString(proiect);
			proiecte.setPosition(4, 120 + 50 * linie);

			rectangleLine.setPosition(1, 145 + 50 * linie + 20);

			removeProj.setPosition(500, 130 + 50 * linie);
			rectangleBack.setPosition(500 - 10 * lungimeSirRemove, 130 + 50 * linie);
			windowCreari.draw(rectangleBack);*/

			/*rectangleBack.setPosition(500 + 2 * 10 * lungimeSirRemove, 130 + 50 * linie);
			windowCreari.draw(rectangleBack);

			windowCreari.draw(proiecte);
			windowCreari.draw(rectangleLine);
			windowCreari.draw(removeProj);
			linie++;
			fgets(proiect, 100, f2);

		}
		fclose(f2);
		windowCreari.display();
	}
}*/
bool rotateCamera = true;
bool ok = false;

int main()
{
	createFolderAndTexts();
	
	while(1)
	interfata();
	
	//f/reastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	//butoane
	Button btnAddPrism("Prism", {100,50}, 20, sf::Color::Blue, sf::Color::White);
	btnAddPrism.setPosition({50,50});

	sf::Font arial;
	arial.loadFromFile("res/Fonts/ARIAL.TTF");
	btnAddPrism.setFont(arial);


	//creaza un cub 
	//Cub cub(Vector(0, 0, 0), 40);
	//Cub cub1(Vector(0, -30, 0), 20);
	//Cub cub2(Vector(0, -45, 0), 10);
	////Cub cub1(Vector(100, 100, 100), 30);
	////Prism prisma1(Vector(0,0,0), 50, 20, 30);

	///*Prism leg1(Vector(0, 0, 0), 30, 5, 5);*/
	//Prism leg2(Vector(0, 0, 20), 30, 5, 5);
	//Prism leg3(Vector(40, 0, 0), 30, 5, 5);
	//Prism leg4(Vector(40, 0, 20), 30, 5, 5);
	//Prism fata(Vector(-25, -35, -25), 5, 50, 70);
	Line line(Vector(0, 0 ,0), Vector(15, 0, 40), 240);


	// creaza camera
	Camera camera(Vector(0, -100, -230),-30, 0, 0, 1200, 800);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

			//if(event.type == sf::Event::MouseButtonPressed)
			//{ 
			//	if (btnAddPrism.isMouseOver(window))
			//	{
			//		std::cout << "*";
			//		/*btnAddPrism.setBackColor(sf::Color::Green);*/
			//		Prism prisma(Vector(0,0,0), 30,5, 5);
			//		window.clear();
			//		prisma.render_solid(window, 1200, 800, camera);
			//	}
			//	else
			//	{
			//		btnAddPrism.setBackColor(sf::Color::Blue);
			//	}
			//}
		}

		//rotire camera
		camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);

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

		/*if(event.type == sf::Event::KeyPressed)
		{
			std::cout << "*";
			if (event.key.code == sf::Keyboard::T)
			{
				rotateCamera = !rotateCamera;
				std::cout << rotateCamera;
				camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);
				btnAddPrism.setBackColor(sf::Color::White);
			}
		}*/

		//afisare
		window.clear();
		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (btnAddPrism.isMouseOver(window))
			{
				std::cout << "*";
				/*btnAddPrism.setBackColor(sf::Color::Green);*/
				ok = true;
			}
			else
			{
				btnAddPrism.setBackColor(sf::Color::Blue);
			}
		}

		if (ok)
		{
			Prism prisma(Vector(0, 0, 0), 30, 5, 5);
			prisma.render_solid(window, 1200, 800, camera);


		}
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
	/*	leg1.render_solid(window, 1200, 800, camera);
		leg2.render_solid(window, 1200, 800, camera);
		leg3.render_solid(window, 1200, 800, camera);
		leg4.render_solid(window, 1200, 800, camera);
		fata.render_solid(window, 1200, 800, camera);*/
		line.render_solid(window, 1200, 800, camera);
		//btnAddPrism.drawTo(window);

		window.display();
	}

}
