#include <SFML\Graphics.hpp>
#include <iostream>
//#include "interfata.hpp"


int language = 1, line = 0, nivel = 0, nivel2, nrProiecte = 0, scrool = 0;
int curentWindow = 0;
char sir[100], proiect[100];
bool q = 0;
char stergere[200];
bool maximLength;
int pozMx, pozMy;

void interfata()
{
	using namespace sf;
	char indexAndCoordonates[200][10]{};
	// selectL --> selectarea limbei 
	int selectL = 0;
	// nextInput --> pentru pagina creare, apasand enter trecem la textul urmator si incremantam nextInput pentru a ajuta la salvarea textului
	int nextInput = 0;
	char output[10][100]{};
	char output2[10][100]{};
	char output3[10][100]{};
	int nrFigure = -1, coordonates = 1;
	bool view = 0;

	FILE* f1 = fopen("programtexts/textsForPrincipalScreen.txt", "r");
	FILE* creari = fopen("programtexts/textsForViewerScreen.txt", "r");
	FILE* detalii = fopen("programtexts/textsForCreateScreen.txt", "r");

	sf::RenderWindow window1(sf::VideoMode(1200, 800), "Editor/Vizualizator 3D");

	// fontul
	sf::Font font;
	if (!font.loadFromFile("Fonts/calibri.ttf"));

	// imaginea folosita ca background
	Texture texture;

	// un patrat/dreptunghi cel vom folosi pentru aproximativ toate patratele pe care le vom desena
	RectangleShape rectangle(sf::Vector2f(40, 25));
	rectangle.setFillColor(sf::Color(71, 154, 198, 255));
	rectangle.setOutlineThickness(3);
	rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));
	rectangle.setPosition(1150, 20);

	// o linie ce va deliminita atat bara de navigare de sus a programului
	// cat si va separa proiectele unul de altul
	RectangleShape rectangleLine(sf::Vector2f(1200, 3));
	rectangleLine.setFillColor(Color::Black);

	// o alta 
	//  ce va separa atat cele doua butoane din bara de navigare
	// cat si butoanele din dreptul proiectului
	RectangleShape rectangleBack(sf::Vector2f(2, 30));
	rectangleBack.setFillColor(Color::Black);

	//pentru detaliile unui proiect nou
	std::string playerInput;
	std::string proiect;

	//textul din ferestra de creeari a unui proiect mou
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[0], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[1], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[2], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[3], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[4], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[5], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[6], a);
	} //6
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[7], a);
	} //6 // 7
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[8], a);
	} //8
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, detalii);
		if (i == language)
			strcpy(output3[9], a);
	}

	//textul ce va aparea in fereastra cu detaliile proiectului
	Text details("", font, 40);
	details.setFillColor(Color::Black);

	// textul pe care l scrie utilizatorul cand da nume proiectului
	Text playerText("", font, 40);
	playerText.setFillColor(Color::Black);
	playerText.setPosition(details.getPosition().x + 16 * strlen(output3[0]), 20);

	Text playerText2("", font, 40);
	playerText2.setFillColor(Color::Black);
	playerText2.setPosition(details.getPosition().x + 16 * strlen(output3[0]), 100);
	fclose(detalii);
	//asteau au fost pentru detaliile unui proiect nou

	// un text ce va fi folosit pentru afisarea mari majoritati a textelor
	Text text;
	text.setFont(font);

	//in functie de limba verificam ce text vom afisa
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(output[0], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(output[1], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(output[2], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, f1);
		if (i == language)
			strcpy(output[3], a);
	}

	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(output2[0], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(output2[1], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(output2[2], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(output2[3], a);
	}
	for (int i = 1; i <= 3; i++)
	{
		char a[100];
		fgets(a, 99, creari);
		if (i == language)
			strcpy(output2[4], a);
	}


	int back = 40 + 10 * strlen(output2[1]);
	std::string saveNameOfProject;

	fclose(f1);
	fclose(creari);
	while (window1.isOpen())
	{
		sf::Event event;
		view = 0;
		while (window1.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window1.close();
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
								window1.close();
							}
							else if (event.mouseButton.y > 70 && event.mouseButton.y < 95) {
								if (language == 1) language = 3;
								else if (language == 2) language = 1;
								else if (language == 3) language = 2;
								window1.close();
							}
						}
						if (event.mouseButton.x > 60 && event.mouseButton.x < 360 && event.mouseButton.y > 200 && event.mouseButton.y < 260)	curentWindow = 1;
						if (event.mouseButton.x > 60 && event.mouseButton.x < 360 && event.mouseButton.y > 300 && event.mouseButton.y < 360)	curentWindow = 2;
					}


				}

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
							curentWindow = 2;
						}
						if (event.mouseButton.x > 500 + 2 * 10 * strlen(output2[3]) && event.mouseButton.x < 500 + 2 * 10 * strlen(output2[1]) + 5 * strlen(output2[4]) + 15 * strlen(output2[4]) && event.mouseButton.y > 116) view = 1;
					}
					// aici se realizeaza stergerea proiectului dorit
					if (event.mouseButton.x > 500 - 10 * strlen(output2[3]) && event.mouseButton.x < 500 + 2 * 10 * strlen(output2[3]) && event.mouseButton.y > 116)
					{
						nrProiecte--;
						char proiect[100];
						FILE* f2 = fopen("userProjects/userNameOfProjects.txt", "r");

						nivel = (event.mouseButton.y - 116) / 50;
						fseek(f2, 0, SEEK_SET);

						FILE* f3 = fopen("userProjects\\temporary.txt", "w+");

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
								strcpy(stergere, "userProjects\\");
								strncat(stergere, proiect, strlen(proiect) - 1);
								strcat(stergere, ".txt");
							}
							fgets(proiect, 100, f2);
							nivel--;
						}

						if (remove(stergere));
						fclose(f2);
						FILE* g = fopen("userProjects/userNameOfProjects.txt", "w");
						fseek(f3, 0, SEEK_SET);

						fgets(proiect, 100, f3);
						while (!feof(f3))
						{
							fprintf(g, "%s", proiect);
							fgets(proiect, 100, f3);

						}
						fclose(g);
						//s a terminat stergerea
					}
					//if (pozMx > 500 + 2 * 10 * strlen(output2[3]) && pozMx < 500 + 2 * 10 * strlen(output2[1]) + 5 * strlen(output2[4]) + 15 * strlen(output2[4]) && pozMy > 116) view = 1;

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
					if (nextInput == 0)
					{
						if (event.text.unicode == 13)
						{
							char creareFiserTextChar[256];

							FILE* numeProiect = fopen("userProjects/userNameOfProjects.txt", "a");

							proiect = playerInput;
							fprintf(numeProiect, "%s", proiect.c_str());
							fprintf(numeProiect, "%s", "\n");
							fclose(numeProiect);

							std::string creareFisierText;
							creareFisierText = "userProjects\\" + proiect + ".txt";
							int n = creareFisierText.length();
							strcpy(creareFiserTextChar, creareFisierText.c_str());
							FILE* creare = fopen(creareFiserTextChar, "w");
							fclose(creare);

							saveNameOfProject = playerInput;

							playerInput.clear();
							nextInput++;
							nrFigure = 0;
							maximLength = 0;
							nrProiecte++;

						}
						else if (playerInput.length() < 25)
						{
							if (event.text.unicode == 8)
							{
								//aici daca apasam stergere din tastatura se sterge ultima litera
								if (playerInput.length() > 0)
								{
									playerInput.pop_back();
									playerText.setString(playerInput);
								}
								maximLength = 0;
							}
							else
							{
								//aici modificam textul la fiecare litara apasata
								playerInput += event.text.unicode;
								playerText.setString(playerInput);
							}
							maximLength = 0;
						}
						else
						{
							maximLength = 1;
							if (event.text.unicode == 8)
							{
								//aici daca apasam stergere din tastatura se sterge ultima litera
								playerInput.pop_back();
								playerText.setString(playerInput);
								maximLength = 0;
							}
						}
					}
					else if (nextInput == 1)
					{
						if (event.text.unicode == 13)
						{
							std::string crearefisierTextSring = "userProjects\\" + saveNameOfProject + ".txt";
							strcat(creareFiserTextChar, crearefisierTextSring.c_str());

							FILE* date = fopen(creareFiserTextChar, "a");

							strcpy(creareFiserTextChar, playerInput.c_str());
							strcat(indexAndCoordonates[nrFigure * 5], creareFiserTextChar);
							fprintf(date, "%s", creareFiserTextChar);
							fprintf(date, "%s", " ");

							fclose(date);

							playerInput.clear();
							playerText2.setString("");
							nextInput = 2;
							maximLength = 0;
						}

						if ((event.text.unicode >= 48 && event.text.unicode <= 57) || event.text.unicode == 8)
						{
							if (playerInput.compare("20") < 0 && playerInput.length() < 2)
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
								maximLength = 0;
							}
							else
							{
								maximLength = 1;
								if (event.text.unicode == 8)
								{
									//aici daca apasam stergere din tastatura se sterge ultima litera
									playerInput.pop_back();
									playerText2.setString(playerInput);
									maximLength = 0;
								}
							}
						}
					}
					else if (nextInput == 2)
					{
						if (event.text.unicode == 13)
						{
							std::string crearefisierTextSring = "userProjects\\" + saveNameOfProject + ".txt";
							strcpy(creareFiserTextChar, crearefisierTextSring.c_str());

							FILE* date = fopen(creareFiserTextChar, "a");

							strcpy(creareFiserTextChar, playerInput.c_str());
							strcat(indexAndCoordonates[nrFigure * 5 + coordonates], creareFiserTextChar);
							fprintf(date, "%s", creareFiserTextChar);
							fprintf(date, "%s", " ");

							playerInput.clear();
							playerText2.setString("");
							maximLength = 0;
							coordonates++;
							if (coordonates == 5)
							{
								nrFigure++; coordonates = 1; nextInput = 1;
								fprintf(date, "%s", "\n");
							}
							fclose(date);

						}
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
								maximLength = 0;
							}
							else
							{
								maximLength = 1;
								if (event.text.unicode == 8)
								{
									//aici daca apasam stergere din tastatura se sterge ultima litera
									playerInput.pop_back();
									playerText2.setString(playerInput);
									maximLength = 0;
								}
							}
						}
					}
				}
				if (event.type == Event::MouseButtonPressed)
				{
					std::cout << event.mouseButton.x << " " << event.mouseButton.y << std::endl;
					if (event.mouseButton.button == sf::Mouse::Right)
					{
						if (event.mouseButton.x < 111 && event.mouseButton.y < 40)
						{
							curentWindow = 1;
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
		}

		//afisare
		if (curentWindow == 0)
		{
			texture.loadFromFile("images/PrincipalBackground2.jpg");
			Sprite sprite(texture);
			window1.clear();
			window1.draw(sprite);

			//titlu
			text.setCharacterSize(60);
			text.setFillColor(Color(14, 24, 65, 255));
			text.setString(output[0]);
			Vector2u size = window1.getSize();
			//textTitlu.setPosition(size.x / 2 -  textTitlu.getCharacterSize() / 2 * (strlen(sir) / 2), 50);*/

			//calculele necesare pentru a pozitiona titlul pe mijlocul ecranului
			FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.width / 2, textRect.height / 2);
			text.setPosition(sf::Vector2f(1200 / 2.0f, 100));

			window1.draw(text);
			text.setOrigin(0, 0);

			if (pozMx > 1150 && pozMx < 1200 && pozMy > 20 && pozMy < 45)	rectangle.setOutlineColor(Color::Red);
			else   rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));

			// butonul pentru a schimba limba
			rectangle.setSize(sf::Vector2f(40, 25));
			rectangle.setFillColor(sf::Color(43, 113, 149, 255));
			rectangle.setOutlineThickness(1.5);
			rectangle.setPosition(1150, 20);
			window1.draw(rectangle);

			// textul ce afiseaza in ce limba este scris textul
			text.setCharacterSize(20);
			text.setString(output[1]);
			text.setPosition(size.x - 42, 20);
			window1.draw(text);

			// in cazul in care schimbam limba
			if (selectL == 1)
			{
				if (pozMx > 1150 && pozMx < 1200 && pozMy > 45 && pozMy < 71)	rectangle.setOutlineColor(Color::Red);
				else   rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));

				rectangle.setOutlineThickness(1.5);
				rectangle.setPosition(1150, 48);

				window1.draw(rectangle);

				text.setCharacterSize(20);
				text.setFillColor(Color(14, 24, 65, 255));
				if (language == 1)
					text.setString("EG");
				else if (language == 2)
					text.setString("RU");
				else if (language == 3)
					text.setString("RO");
				text.setPosition(size.x - 42, 46);

				window1.draw(text);

				if (pozMx > 1150 && pozMx < 1200 && pozMy > 71 && pozMy < 90)  rectangle.setOutlineColor(Color::Red);
				else  rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));

				rectangle.setOutlineThickness(1.5);
				rectangle.setPosition(1150, 76);

				window1.draw(rectangle);

				text.setCharacterSize(20);
				text.setFillColor(Color(14, 24, 65, 255));
				if (language == 1)
					text.setString("RU");
				else if (language == 2)
					text.setString("RO");
				else if (language == 3)
					text.setString("EG");
				text.setPosition(size.x - 42, 74);

				window1.draw(text);

			}

			// patratul ce va contine butonul spre pagina cu proiectele mele
			if (pozMx > 60 && pozMx < 360 && pozMy > 200 && pozMy < 260)
			{
				rectangle.setOutlineColor(Color::Red);
				rectangle.setOutlineThickness(5);
				//text.setFillColor(Color::Red);
			}
			else
			{
				rectangle.setOutlineThickness(3);
				rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));
				text.setFillColor(Color(14, 24, 65, 255));
			}

			rectangle.setSize(sf::Vector2f(300, 60));
			rectangle.setFillColor(sf::Color(60, 154, 188, 255));
			rectangle.setPosition(60, 200);
			window1.draw(rectangle);

			// textul pus in butonul ce duce spre proiectele mele
			text.setCharacterSize(45);
			text.setString(output[2]);
			text.setPosition(60, 200);
			window1.draw(text);

			if (pozMx > 60 && pozMx < 360 && pozMy > 300 && pozMy < 360)
			{
				rectangle.setOutlineColor(Color::Red);
				rectangle.setOutlineThickness(5);
				//text.setFillColor(Color::Red);
			}
			else
			{
				rectangle.setOutlineThickness(3);
				rectangle.setOutlineColor(sf::Color(13, 47, 72, 255));
				text.setFillColor(Color(14, 24, 65, 255));
			}
			//butonul pentru a crea un proiect nou din pagina principala
			rectangle.setSize(sf::Vector2f(300, 60));
			rectangle.setFillColor(sf::Color(60, 154, 188, 255));
			rectangle.setPosition(60, 300);
			window1.draw(rectangle);

			text.setString(output[3]);
			text.setPosition(60, 300);
			window1.draw(text);

			rectangle.setOutlineColor(Color::Black);

			window1.display();

		}
		else if (curentWindow == 1)
		{
			texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
			Sprite sprite(texture);
			nrProiecte = 0;

			FILE* f2 = fopen("userProjects/userNameOfProjects.txt", "r");

			// in clear alegem si culoarea backgroundului
			window1.clear(Color(37, 150, 190));
			window1.draw(sprite);

			// un patrat de culoare diferita ce va fi pozotionat in partea de sus a ferestrei
			// ce va fi practic, bara noastra de navigare
			rectangle.setSize(sf::Vector2f(1200, 40));
			rectangle.setPosition(0, 0);
			rectangle.setFillColor(Color(11, 116, 168, 255));
			window1.draw(rectangle);

			// textul de dupa are vor fi afisate proiectele mele
			text.setCharacterSize(60);
			text.setFillColor(Color::Black);
			text.setString(output2[0]);
			text.setPosition(20, 36);
			window1.draw(text);

			// linia ce separa bara de navigare de restul programului
			rectangleLine.setPosition(0, 40);
			window1.draw(rectangleLine);

			// linia ce separa cele doua butoane din bara de navigare
			rectangleBack.setPosition(back, 6);
			window1.draw(rectangleBack);

			// textul butonului de intors la pagina anterioara din bara de navigare		
			if (pozMx < back && pozMy < 40)	text.setFillColor(Color::Red);
			else	text.setFillColor(Color::Black);

			text.setCharacterSize(30);
			text.setString(output2[1]);
			text.setPosition(20, 2);
			window1.draw(text);

			// textul celui de al doilea buton din bara de navigare, de creare a unui proiect nou
			if (pozMx > back && pozMy < 40) text.setFillColor(Color::Red);
			else text.setFillColor(Color::Black);

			text.setPosition(rectangleBack.getPosition().x + 20, 2);
			text.setCharacterSize(30);
			text.setString(output2[2]);
			window1.draw(text);
			text.setFillColor(Color::Black);
			fclose(f2);

			FILE* f4 = fopen("userProjects/userNameOfProjects.txt", "r");

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
					text.setString(proiecte);
					text.setPosition(10, 120 + 50 * line);
					window1.draw(text);

					if (!nivel) text.setFillColor(Color::Red);

					text.setCharacterSize(25);
					text.setString(output2[3]);
					text.setPosition(500, 130 + 50 * line);
					window1.draw(text);
					text.setFillColor(Color::Black);

					if (!nivel2) text.setFillColor(Color::Red);
					int lungimeSirRemove = strlen(output2[1]);
					text.setString(output2[4]);
					text.setPosition(500 + 2 * 10 * lungimeSirRemove + 5 * strlen(output2[4]), 130 + 50 * line);
					window1.draw(text);
					text.setFillColor(Color::Black);

					if (!nivel2 && view == 1)
					{
						char path[200]{};
						strcpy(path, "userProjects\\");
						strncat(path, proiecte, strlen(proiecte) - 1);
						strcat(path, ".txt");
						//draw(path);
					}
					if (!nivel)	rectangleBack.setFillColor(Color::Red);

					rectangleBack.setPosition(500 - 10 * lungimeSirRemove, 130 + 50 * line);
					window1.draw(rectangleBack);

					if (!nivel2) rectangleBack.setFillColor(Color::Red);
					rectangleBack.setPosition(500 + 2 * 10 * lungimeSirRemove, 130 + 50 * line);
					window1.draw(rectangleBack);

					if (!nivel)	rectangleBack.setFillColor(Color::Black);
					rectangleBack.setPosition(500 + 2 * 10 * lungimeSirRemove + 5 * strlen(output2[4]) + 15 * strlen(output2[4]), 130 + 50 * line);
					window1.draw(rectangleBack);

					rectangleBack.setFillColor(Color::Black);

					rectangleLine.setPosition(1, 145 + 50 * line + 20);
					window1.draw(rectangleLine);
					nivel--;
					nivel2--;
					line++;
					copieScrool--;
				}
				fgets(proiecte, 100, f4);
			}
			fclose(f4);
			window1.display();
		}
		else if (curentWindow == 2)
		{
			//INCARCAREA BACKGROUNDULUI
			texture.loadFromFile("images/PrincipalBackground2Blur.jpg");
			Sprite sprite(texture);
			window1.clear();
			window1.draw(sprite);

			details.setOutlineThickness(0);
			details.setCharacterSize(40);
			details.setPosition(10, 60);
			details.setString(output3[0]);
			window1.draw(details);

			int minus;
			if (language == 2) minus = 30;
			else minus = 0;

			if (nextInput == 0) playerText.setPosition(details.getPosition().x + 16 * strlen(output3[0]), 60);

			/*//for (int i = 0; i <= nrFigure; i++)
			//{
			//	details.setPosition(10, 110 + 100 * i);
			//	window1.draw(details);
			//}

			if (nextInput == 1)
			{
				if(language == 1)
					playerText2.setPosition(details.getPosition().x + 10 * strlen(output3[4]) + 10, 110 + 50 * nrFigure);
				else
					playerText2.setPosition(details.getPosition().x + 10 * strlen(output3[4]) + 36, 110 + 50 * nrFigure);
			}
			else if (nextInput == 2)
			{
				if (language == 1)
					playerText2.setPosition(details.getPosition().x + 10 * strlen(output3[4]) + 10 + 50 * (coordonates - 1), 130 + 50 * nrFigure);
				else
					playerText2.setPosition(details.getPosition().x + 10 * strlen(output3[4]) + 36 + 50 * (coordonates - 1), 130 + 50 * nrFigure);
				details.setString(output3[7]);
				details.setCharacterSize(30);
				details.setPosition(10, 110 + 100 * nrFigure + 50);
				window1.draw(details);
			}
			/*for (int i = 0; i <= nrFigure - 1; i++)
			{
				details.setString(output3[7]);
				details.setPosition(10, 110 + 100 * i + 50);
				window1.draw(details);
			}*/

			if (nextInput == 1)
			{
				details.setString(output3[4]);
				details.setPosition(10, 130);
				playerText2.setPosition(10 + 14 * strlen(output3[4]) + 10 + minus, 130);

				window1.draw(details);
			}
			else if (nextInput == 2)
			{
				details.setString(output3[4]);
				details.setPosition(10, 130);
				window1.draw(details);
				details.setString(indexAndCoordonates[nrFigure * 5]);
				details.setPosition(10 + 14 * strlen(output3[4]) + 10 + minus, 130);
				window1.draw(details);

				playerText2.setPosition(10 + 16 * strlen(output3[4]) + 82 + 100 * (coordonates - 1) + 25 - minus, 200);

				details.setString(output3[7]);
				details.setPosition(10, 200);
				window1.draw(details);

				for (int i = 1; i <= coordonates;i++)
				{
					if (i == 1) { details.setString("x:"); details.setPosition(10 + 16 * strlen(output3[4]) + 80 + 100 * (i - 1) - minus, 200); } window1.draw(details);
					if (i == 2) { details.setString("y:"); details.setPosition(10 + 16 * strlen(output3[4]) + 80 + 100 * (i - 1) - minus, 200); } window1.draw(details);
					if (i == 3) { details.setString("z:"); details.setPosition(10 + 16 * strlen(output3[4]) + 80 + 100 * (i - 1) - minus, 200); } window1.draw(details);

					for (int i = 1; i < coordonates;i++)
					{
						details.setString(indexAndCoordonates[nrFigure * 5 + i]);
						details.setPosition(10 + 16 * strlen(output3[4]) + 82 + 100 * (i - 1) + 25 - minus, 200);
						window1.draw(details);
					}
				}

				if (coordonates == 4)
				{
					details.setString(output3[8]);
					details.setPosition(10, 250);
					window1.draw(details);
					playerText2.setPosition(10 + 16 * strlen(output3[8]) + minus - 18, 250);
					window1.draw(playerText2);
				}
			}

			if (nextInput == 1)	text.setString(output3[1]);
			else if (nextInput == 0) text.setString(output3[6]);
			Vector2u size = window1.getSize();
			FloatRect textRect = text.getLocalBounds();
			text.setOrigin(textRect.width / 2, textRect.height / 2);
			text.setPosition(sf::Vector2f(1200 / 2.0f, 750));
			text.setCharacterSize(25);

			window1.draw(text);

			if (maximLength == 1)
			{
				if (nextInput == 0)
				{
					text.setString(output3[3]);
					text.setPosition(sf::Vector2f(1200 / 2.0f, 200));
				}
				else
				{
					text.setString(output3[5]);
					text.setPosition(sf::Vector2f(1200 / 2.0f, 300));
				}
				FloatRect textRect = text.getLocalBounds();
				text.setOrigin(textRect.width / 2, textRect.height / 2);
				window1.draw(text);
			}

			text.setOrigin(0, 0);
			window1.draw(playerText);
			window1.draw(playerText2);

			if (pozMx < 111 && pozMy < 40)
			{
				details.setFillColor(Color::Red);
				rectangleBack.setFillColor(Color::Red);
			}

			details.setOutlineThickness(0.2);
			details.setCharacterSize(30);
			details.setString(output3[2]);
			details.setPosition(20, 1);
			window1.draw(details);

			rectangleBack.setPosition(Vector2f(40 + 10 * strlen(output3[2]), 8));
			window1.draw(rectangleBack);

			rectangleBack.setSize(Vector2f(30 + 10 * strlen(output3[2]), 2));
			rectangleBack.setPosition(10, 40);
			window1.draw(rectangleBack);

			rectangleBack.setSize(Vector2f(2, 30));
			details.setFillColor(Color::Black);
			rectangleBack.setFillColor(Color::Black);

			if (pozMx > 1018 && pozMy < 40)
			{
				details.setFillColor(Color::Red);
				rectangleBack.setFillColor(Color::Red);
			}

			details.setString(output3[9]);
			details.setPosition(1200 - 13 * strlen(output3[9]), 1);
			window1.draw(details);

			rectangleBack.setPosition(Vector2f(1200 - 13 * strlen(output3[9]) - strlen(output3[9]), 8));
			window1.draw(rectangleBack);

			rectangleBack.setSize(Vector2f(30 + 10 * strlen(output3[9]), 2));
			rectangleBack.setPosition(1200 - 13 * strlen(output3[9]) - strlen(output3[9]) + 5, 40);
			window1.draw(rectangleBack);

			rectangleBack.setSize(Vector2f(2, 30));
			details.setFillColor(Color::Black);
			rectangleBack.setFillColor(Color::Black);
			window1.display();
		}
	}
}
