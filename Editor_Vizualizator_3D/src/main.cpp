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

bool rotateCamera = true;
bool ok = false;

int main()
{
	createFolderAndTexts();
	
	//f/reastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(1600, 900), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	while(1)
		interfata(window);

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
