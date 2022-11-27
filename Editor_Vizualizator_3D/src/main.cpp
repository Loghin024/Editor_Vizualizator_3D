#include <SFML\Graphics.hpp>
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"

int main()
{

	//fereastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
	window.setVerticalSyncEnabled(true);

	//creaza un cub 
	Cub cub(Vector(0, 0, 0), 50);

	// creaza camera
	Camera camera(Vector(0, -120, -230), -30, 0, 0, 1200, 800);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		//afisare
		window.clear();
		cub.render_solid(window, 1200, 800, camera);
		window.display();
	}

}
