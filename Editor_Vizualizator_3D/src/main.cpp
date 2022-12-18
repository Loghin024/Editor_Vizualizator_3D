#include <SFML\Graphics.hpp>
#include "geometry/geometrie.hpp"
#include "geometry/solid3d.hpp"
#include "utils/mouse.hpp"
#include <cstring>
#include <string>

//using namespace sf;
//using namespace std;

int language = 1, linie;
int curentWindow = 0;
char sir[100], proiect[100];
bool q;						
char stergere[200];


//void Home()
//{
//	int selectL = 0;
//	FILE* f1 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\text.txt", "r");
//
//	sf::RenderWindow window1(sf::VideoMode(1200, 800), "Editor/Vizualizator 3D");
//
//	for (int i = 1; i <= 3; i++)
//	{
//		char a[100];
//		fgets(a, 99, f1);
//		if (i == language)
//			strcpy(sir, a);
//	}
//
//	sf::Font font;
//	if (!font.loadFromFile("Fonts/calibri.ttf"));
//
//	Texture texture;
//	texture.loadFromFile("images/PrincipalBackground.jpg");
//	Sprite sprite(texture);

	/*RectangleShape rectangle(sf::Vector2f(40, 25));
	rectangle.setFillColor(sf::Color(71, 154, 198, 255));
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));
	rectangle.setPosition(1150, 20);

	RectangleShape rectangle2(sf::Vector2f(40, 25));
	rectangle2.setFillColor(sf::Color(71, 154, 198, 255));
	rectangle2.setOutlineThickness(3);
	rectangle2.setOutlineColor(sf::Color(13, 47, 72, 255));
	rectangle2.setPosition(1150, 45);

	RectangleShape rectangle3(sf::Vector2f(40, 25));
	rectangle3.setFillColor(sf::Color(71, 154, 198, 255));
	rectangle3.setOutlineThickness(3);
	rectangle3.setOutlineColor(sf::Color(13, 47, 72, 255));
	rectangle3.setPosition(1150, 70);*/

	/*RectangleShape rectangleCreate(sf::Vector2f(200, 75));
	rectangleCreate.setFillColor(sf::Color(98, 192, 226, 255));
	rectangleCreate.setOutlineThickness(3);
	rectangleCreate.setOutlineColor(sf::Color(13, 47, 72, 255));
	rectangleCreate.setPosition(60, 200);*/
	
	//RectangleShape rectangleMyProjects(sf::Vector2f(300, 60));
	//rectangleMyProjects.setFillColor(sf::Color(98, 192, 226, 255));
	//rectangleMyProjects.setOutlineThickness(3);
	//rectangleMyProjects.setOutlineColor(sf::Color(13, 47, 72, 255));
	//rectangleMyProjects.setPosition(60, 200);

	//Text textTitlu;
	//textTitlu.setFont(font);
	//textTitlu.setCharacterSize(60);
	//textTitlu.setFillColor(Color(14, 24, 65, 255));
	//textTitlu.setString(sir);
	//Vector2u size = window1.getSize();
	////textTitlu.setPosition(size.x / 2 -  textTitlu.getCharacterSize() / 2 * (strlen(sir) / 2), 50);*/

	//FloatRect textRect = textTitlu.getLocalBounds();
	//textTitlu.setOrigin(textRect.width / 2, textRect.height / 2);
	//textTitlu.setPosition(sf::Vector2f(1200 / 2.0f, 100));

	/*for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(sir, a);
	}

	Text text2;
	text2.setFont(font);
	text2.setCharacterSize(20);
	text2.setFillColor(Color(14, 24, 65, 255));
	text2.setString(sir);
	text2.setPosition(size.x - 42, 20);

	Text text3;
	text3.setFont(font);
	text3.setCharacterSize(20);
	text3.setFillColor(Color(14, 24, 65, 255));
	if (language == 1)
		text3.setString("EG");
	else if (language == 2)
		text3.setString("RU");
	else if (language == 3)
		text3.setString("RO");
	text3.setPosition(size.x - 42, 45);*/

	/*Text text4;
	text4.setFont(font);
	text4.setCharacterSize(20);
	text4.setFillColor(Color(14, 24, 65, 255));
	if (language == 1)
		text4.setString("RU");
	else if (language == 2)
		text4.setString("RO");
	else if (language == 3)
		text4.setString("EG");
	text4.setPosition(size.x - 42, 70);*/

	/*for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(sir, a);
	}

	Text textCreate;
	textCreate.setFont(font);
	textCreate.setCharacterSize(45);
	textCreate.setFillColor(Color(14, 24, 65, 255));
	textCreate.setString(sir);
	textCreate.setPosition(70, 205);*/

	/*for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(sir, a);
	}

	Text textMyProjects;
	textMyProjects.setFont(font);
	textMyProjects.setCharacterSize(45);
	textMyProjects.setFillColor(Color(14, 24, 65, 255));
	textMyProjects.setString(sir);
	textMyProjects.setPosition(70, 200);*/

	/*while (window1.isOpen())
	{
		sf::Event event;

		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window1.close();
				q = 1;
			}
			if (event.type == Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Right)
				{
					cout << event.mouseButton.x << " " << event.mouseButton.y << endl;
					if (event.mouseButton.x > 1150 && event.mouseButton.x < 1200)
					{
						if (event.mouseButton.y > 20 && event.mouseButton.y < 45)
							selectL = 1;

						if (event.mouseButton.y > 45 && event.mouseButton.y < 70) {
							if (language == 1) language = 2;
							else if (language == 2) language = 3;
							else if (language == 3) language = 1;
							window1.close();
						}*/
				/*		else if (event.mouseButton.y > 70 && event.mouseButton.y < 95) {
								if (language == 1) language = 3;
								else if (language == 2) language = 1;
								else if (language == 3) language = 2;
								window1.close();

						}

					}
					if (event.mouseButton.x > 60 && event.mouseButton.x < 260 && event.mouseButton.y > 200 && event.mouseButton.y < 275) 
					{
						curentWindow = 1;
						window1.close();
					}

						
				}
				

			}

			
		}*/

		//afisare
	//	window1.clear();

	//	window1.draw(sprite);
	//	window1.draw(textTitlu);
	//	window1.draw(rectangle);
	//	window1.draw(text2);

	//	if (selectL == 1) 
	//	{
	//		window1.draw(rectangle2);
	//		window1.draw(text3);
	//		window1.draw(rectangle3);
	//		window1.draw(text4);

	//	}

	//	//window1.draw(rectangleCreate);
	//	//window1.draw(textCreate);
	//	window1.draw(rectangleMyProjects);
	//	window1.draw(textMyProjects);

	//	window1.display();
	//}

//}

//void fereastraDetaliiProiect()
//{
//	FILE* f2 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\nameofproject.txt", "r");
//	FILE* f1 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\proiecte.txt", "a");
//
//	sf::RenderWindow detaliiProiect(sf::VideoMode(1200, 100), "fereastraDetaliiProiect");
//
//	Font font;
//	if (!font.loadFromFile("Fonts/calibri.ttf"));
//
//	String playerInput;
//
//	for (int i = 1; i <= 3; i++)
//	{
//		char a[100];
//		fgets(a, 99, f2);
//		if (i == language)
//			strcpy(sir, a);
//	}
//
//	Text datiNume(sir, font, 40);
//	datiNume.setFillColor(Color::Black);
//	datiNume.setPosition(10, 20);
//	
//	Text playerText("", font, 40);
//	playerText.setFillColor(Color::Black);
//	playerText.setPosition(datiNume.getPosition().x + 16 * strlen(sir), 20);

	/*string proiect;
	while (detaliiProiect.isOpen())
	{
		sf::Event event;

		while (detaliiProiect.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				detaliiProiect.close();
				q = 1;
			}

			if (event.type == sf::Event::TextEntered)
			{
				if(event.text.unicode < 128)
					std::cout << "ASCII character typed: " << event.text.unicode << std::endl;
				if (event.text.unicode == 13)
				{
					proiect = playerInput;
					fprintf(f1, "%s", proiect.c_str());
					fprintf(f1, "%s", "\n");
					fclose(f1);*/
					/*string creareFisierText;
					creareFisierText = "C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\proiectele utilizatorului\\" + proiect + ".txt";
					int n = creareFisierText.length();
					char creareFiserTextChar[256];
					strcpy(creareFiserTextChar, creareFisierText.c_str());
					FILE* creare = fopen(creareFiserTextChar, "w");
					fclose(creare);
					detaliiProiect.close();
				}
				else
				{
					playerInput += event.text.unicode;
					playerText.setString(playerInput);
				}
			}
		}

		detaliiProiect.clear(Color(37, 150, 190));
		detaliiProiect.draw(playerText);
		detaliiProiect.draw(datiNume);
		detaliiProiect.display();*/
	//}

//}


//void createProjectsWindow()
//{
//	//Deschidem fisierul text din care ne luam informatiile, in cele 3 limbi
//	FILE* f1 = fopen("C:\\Users\\HP\\source\\repos\\Editor_Vizualizator_3D\\Editor_Vizualizator_3D\\Texts\\creari.txt", "r");
//
//	sf::RenderWindow windowCreari(sf::VideoMode(1200, 800), "Creare proiecte");
//
//	Font font;
//	if (!font.loadFromFile("Fonts/calibri.ttf"));
//
//	// texul "proiecte" va fi pentru afisare numelor proiectelor
//	Text proiecte;
//	proiecte.setFont(font);
//	proiecte.setCharacterSize(40);
//	proiecte.setFillColor(Color::Black);
//
//
//	for (int i = 1; i <= 3; i++)
//	{
//		char a[100];
//		fgets(a, 99, f1);
//		if (i == language)
//			strcpy(sir, a);
//	}
	
	//// textul "textTitlu" va fi pentru afisare titlului
	//Text textTitlu;
	//textTitlu.setFont(font);
	//textTitlu.setCharacterSize(60);
	//textTitlu.setFillColor(Color::Black);
	//textTitlu.setString(sir);
	//Vector2u size = windowCreari.getSize();
	//textTitlu.setPosition(20, 36);

	//for (int i = 1; i <= 3; i++)
	//{
	//	char a[100];
	//	fgets(a, 99, f1);
	//	if (i == language)
	//		strcpy(sir, a);
	//}

	//// in "back" memoram lungimea textului "inapoi/back" care ne duce la fereastra anterioara
	//int back = 40 + 10 * strlen(sir);

	//// rectangleBack este o linie ce separa butonul de intoarcere in fereastra anterioara si butonul de creare a unui nou proiect
	//// de asemenea il vom folosi pentru a desparti butonul de steregere cu cel de vizionare
	//RectangleShape rectangleBack(sf::Vector2f(2, 30));
	//rectangleBack.setFillColor(Color::Black);

	////in "textBack" vom avea textut pus pe butonul de dat inapoi, in una din cele 3 limbi
	//Text textBack;
	//textBack.setFont(font);
	//textBack.setCharacterSize(30);
	//textBack.setFillColor(Color::Black);
	//textBack.setString(sir);
	//textBack.setPosition(20, 2);

	//for (int i = 1; i <= 3; i++)
	//{
	//	char a[100];
	//	fgets(a, 99, f1);
	//	if (i == language)
	//		strcpy(sir, a);
	//}

	//// in "textUp" vom retine textul afisat pe butonul de creeare a unui nou proiect
	//Text textUp;
	//textUp.setFont(font);
	//textUp.setCharacterSize(30);
	//textUp.setFillColor(Color::Black);
	//textUp.setString(sir);

	//for (int i = 1; i <= 3; i++)
	//{
	//	char a[100];
	//	fgets(a, 99, f1);
	//	if (i == language)
	//		strcpy(sir, a);
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


int main()
{
	/*
	while (!q)
	{
		if (curentWindow == 0)
			Home();
		else if (curentWindow == 1)
			createProjectsWindow();
	}*/

	//fereastra aplicatiei
	sf::ContextSettings window_settings;
	window_settings.antialiasingLevel = 8; // nivelul de distorsionare
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Editor\Vizualizator 3D", sf::Style::Close | sf::Style::Resize, window_settings);
	window.setVerticalSyncEnabled(true);
	Mouse::setPosition(sf::Vector2i(1200 / 2, 800 / 2), window);

	//creaza un cub 
	//Cub cub(Vector(0, 0, 0), 40);
	//Cub cub1(Vector(0, -30, 0), 20);
	//Cub cub2(Vector(0, -45, 0), 10);
	//Cub cub1(Vector(100, 100, 100), 30);
	Prism prisma1(Vector(0,0,0), 50, 20, 30);

	Prism leg1(Vector(0, 0, 0), 30, 5, 5);
	Prism leg2(Vector(0, 0, 20), 30, 5, 5);
	Prism leg3(Vector(40, 0, 0), 30, 5, 5);
	Prism leg4(Vector(40, 0, 20), 30, 5, 5);
	Prism fata(Vector(-25, -15, -25), 5, 50, 70);


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
		leg1.render_solid(window, 1200, 800, camera);
		leg2.render_solid(window, 1200, 800, camera);
		leg3.render_solid(window, 1200, 800, camera);
		leg4.render_solid(window, 1200, 800, camera);
		fata.render_solid(window, 1200, 800, camera);

		window.display();
	}

}
