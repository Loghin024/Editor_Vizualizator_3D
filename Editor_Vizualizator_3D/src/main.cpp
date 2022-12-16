#include <SFML\Graphics.hpp>
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"
#include "geometry/camera.hpp"
#include "utils/mouse.hpp"

int main()
{

	//fereastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
	window.setVerticalSyncEnabled(true);
	Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	//creaza un cub 
	Cub cub(Vector(0, 0, 0), 40);
	Cub cub1(Vector(0, -30, 0), 20);
	Cub cub2(Vector(0, -45, 0), 10);
	//Cub cub1(Vector(100, 100, 100), 30);

	//creare platou

	Solid3d platou;

	platou.add_segment(Segment(Vector(-150, 0, -150, sf::Color::Cyan),
		Vector(150, 0, -150, sf::Color::Blue)));
	platou.add_segment(Segment(Vector(150, 0, -150, sf::Color::Blue),
		Vector(150, 0, 150, sf::Color::Red)));
	platou.add_segment(Segment(Vector(150, 0, 150, sf::Color::Red),
		Vector(-150, 0, 150, sf::Color::Green)));
	platou.add_segment(Segment(Vector(-150, 0, 150, sf::Color::Green),
		Vector(-150, 0, -150, sf::Color::Cyan)));

	Sphere3d sphere(Vector(-90, 0, 0), 40, 30, 50);


	// creaza camera
	Camera camera(Vector(0, -100, -230),-30, 0, 0, 1200, 800);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
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
		cub1.render_solid(window, 1200, 800, camera);
		cub2.render_solid(window, 1200, 800, camera);
		//platou.render_solid(window, 1200, 800, camera);
		//cub1.render_solid(window, 1200, 800, camera);
		cub.rotate(Vector(50,0,0), Vector(0,1,0), 1, true);
		cub1.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);
		cub2.rotate(Vector(50, 0, 0), Vector(0, 1, 0), 1, true);

		sphere.rotate(Vector(), Vector(0, 1, 1), 3, true);
		sphere.render_solid(window, 1200, 800, camera);

		window.display();
	}

}
