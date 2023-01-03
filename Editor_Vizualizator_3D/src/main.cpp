#include <SFML\Graphics.hpp>
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"
#include "utils/mouse.hpp"
#include "utils/parameters.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include "utils/foldersAndTexts.hpp"
#include "Menu.hpp"

int main()
{
	
	//f/reastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	Mouse::setPosition(sf::Vector2i(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), window);

	//create Folders
	createFolderAndTexts();

	//create Interface
	/*while (1)
		interfata();*/

	///////////////////////////////////////////////
	//Verificari//////////////////////////////////
	/////////////////////////////////////////////

	////creaza un cub 
	//Cub cub(Vector(0, 0, 0), 40);
	//Cub cub1(Vector(0, -30, 0), 20);
	//Cub cub2(Vector(0, -45, 0), 10);
	////Cub cub1(Vector(100, 100, 100), 30);
	//Prism prisma1(Vector(0,0,0), 50, 20, 30);

	Prism leg1(Vector(0, 0, 0), 30, 5, 5);
	Prism leg2(Vector(0, 0, 20), 30, 5, 5);
	Prism leg3(Vector(40, 0, 0), 30, 5, 5);
	Prism leg4(Vector(40, 0, 20), 30, 5, 5);
	Prism fata(Vector(-25, -35, -25), 5, 50, 70);

	Sphere3d sfera(Vector(0, 0, 0), 100, 40, 40);

	Cylinder3d cilindru(Vector(0, 0, 0), 100, 5, 100);
	Cylinder3d cilindru1(Vector(50, 0, 0), 20, 40, 500);

	Con3d con1(Vector(0, 0, 0), 70, 30, 100);
	Pyramid3d piramida(Vector(0, 0, 0), 20, 30, 100);

	//////////////////////////////////////////////////
	/////////////////////////////////////////////////
	////////////////////////////////////////////////


	// create camera
	Camera camera(Vector(0, -100, -230),-30, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();

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

		//afisare
		window.clear();
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
		piramida.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);

		window.display();
	}

}
