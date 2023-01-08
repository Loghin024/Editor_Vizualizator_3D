#include <SFML\Graphics.hpp>
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"
//#include "utils/mouse.hpp"
//#include "utils/parameters.hpp"
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include "utils/foldersAndTexts.hpp"
#include "Menu.hpp"
//#include "utils/figuresInfo.hpp"

int main()
{

	//f/reastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Editor\Vizualizator 3D", sf::Style::Fullscreen, window_settings);
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	//Mouse::setPosition(sf::Vector2i(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), window);

	//create Folders
	createFolderAndTexts();
	//figuresInfo a;
	//create Interface
	while (1)
		interfata(window);

	///////////////////////////////////////////////
	//Verificari//////////////////////////////////
	/////////////////////////////////////////////

	//////creaza un cub 
	//Cub cub(Vector(0, 0, 0), 10);
	//Cub cub1(Vector(0, -10, 0), 10);
	////Cub cub2(Vector(0, -45, 0), 10);
	//////Cub cub1(Vector(100, 100, 100), 30
	////Prism prisma1(Vector(0,0,0), 50, 20, 30);

	/////*Prism leg1(Vector(0, 0, 0), 30, 5, 5);*/
	////Prism leg2(Vector(0, 0, 20), 30, 5, 5);
	////Prism leg3(Vector(40, 0, 0), 30, 5, 5);
	////Prism leg4(Vector(40, 0, 20), 30, 5, 5);
	////Prism fata(Vector(-25, -35, -25), 5, 50, 70);
	////Line line(Vector(0, 0 ,0), Vector(15, 0, 40), 240);

	////char figura[100];
	////Con3d figura(Vector(0, 0, 0), 70, 30, 100);
	////Sphere3d sfera(Vector(0, 0, 0), 100, 40, 40);

	////Cylinder3d cilindru(Vector(0, 0, 0), 100, 5, 100);
	////Cylinder3d cilindru1(Vector(50, 0, 0), 20, 40, 500);

	////Con3d con1(Vector(0, 0, 0), 70, 30, 100);
	////Pyramid3d piramida(Vector(0, 0, 0), 20, 30, 100);

	//////////////////////////////////////////////////////
	/////////////////////////////////////////////////////
	////////////////////////////////////////////////////

	//std::vector<Cub>cubes;
	//cubes.push_back(cub);

	// //create camera
	//Camera camera(Vector(0, -100, -230),-30, 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	//while (window.isOpen())
	//{
	//	sf::Event event;

	//	while (window.pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	//			window.close();

	//		if (event.type == sf::Event::Resized) {
	//			window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
	//			WINDOW_WIDTH = event.size.width;
	//			WINDOW_HEIGHT = event.size.height;
	//			camera.reload_figures(WINDOW_WIDTH, WINDOW_HEIGHT);
	//		}

	//	}

	////	//rotate camera
	//	camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);

	////	// move camera
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	//		camera.move(Camera::DIRECTION::FRONT);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	//		camera.move(Camera::DIRECTION::BACK);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	//		camera.move(Camera::DIRECTION::RIGHT);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	//		camera.move(Camera::DIRECTION::LEFT);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	//		camera.move(Camera::DIRECTION::UP);
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	//		camera.move(Camera::DIRECTION::DOWN);

	////	//modul de editare
	//	if (sf::Keyboard::isKeyPressed(sf::Keyboard::O))
	//	{
	//		rotateCamera = true;
	//		camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);
	//		//btnAddPrism.setBackColor(sf::Color::White);
	//	}
	//	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
	//	{
	//		rotateCamera = false;
	//		camera.rotate(Mouse::get_move_x(window), Mouse::get_move_y(window), rotateCamera);
	//		//a.figures(window, 0, 0, 0, 0, 1);
	//	}
	//	

	//	//afisare
	//	window.clear();
	//	//Cub cub(Vector(0, 0, 0), 10);
	//	//cub.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	//	cubes[0].render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	//	cubes[0].rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, false);
	//	//cub1.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	//	//if (rotateCamera == false) {
	//	//	a.figures(window, 0, 0, 0, 0, 1);
	//		//a.componentsNames(window, Name, PozMx, PozMy, changeUp, changeDown, cPozX, cPozY, language);

	//	//} 
	//	//Cub cub(Vector(0, 0, 0), 40);
	//	//cub.render_solid(window, 1200, 800, camera);
	////	//cub1.render_solid(window, 1200, 800, camera);
	////	//cub2.render_solid(window, 1200, 800, camera);
	////	////platou.render_solid(window, 1200, 800, camera);
	////	////cub1.render_solid(window, 1200, 800, camera);
	////	//cub.rotate(Vector(50,0,0), Vector(0,1,0), 1, true);
	////	//cub1.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);
	////	//cub2.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);

	////	//prisma1.render_solid(window, 1200, 800, camera);
	////	//prisma1.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);
	////	/*leg1.render_solid(window, 1200, 800, camera);
	////	leg2.render_solid(window, 1200, 800, camera);
	////	leg3.render_solid(window, 1200, 800, camera);
	////	leg4.render_solid(window, 1200, 800, camera);
	////	fata.render_solid(window, 1200, 800, camera);*/
	////	//btnAddPrism.drawTo(window);

	////	//sfera.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	////	//cilindru.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	////	//cilindru1.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	////	//con1.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	////	//con1.rotate(Vector(50, 0, 0), Vector(1, 0, 0), 1, false);
	////	//piramida.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);
	////	//figura.render_solid(window, WINDOW_WIDTH, WINDOW_HEIGHT, camera);

	//	window.display();
	//}

}