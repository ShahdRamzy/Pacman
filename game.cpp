#include<SFML/Graphics.hpp>
#include"gameWorld.h"
#include <iostream>
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include"graph.h"
#include<thread>
using namespace std;
int main() {

	float windowWidth = 840;
	float windowHeight = 1000;
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Pacman");
	int cnt = 0;
	gameWorld GameWorld ;
	while (window.isOpen()) {
		unsigned int random_direction = rand() % 4;

		GameWorld.randGhost(random_direction);
		sf::sleep(sf::milliseconds(80));
		sf::Event event;

		while (window.pollEvent(event)) {
			cnt++;
			if (GameWorld.lose())
			{
				sf::RenderWindow window4(sf::VideoMode(420, 500), "!!YOU LOSE!!");
				sf::Image image;
				string filelose = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\gameoverrs.jpg";
				if (!(image.loadFromFile(filelose)))
					std::cout << "Cannot load image";

				sf::Texture texture;
				texture.loadFromImage(image);
				sf::Sprite sprite;
				sprite.setTexture(texture);
				while (window4.isOpen())
				{
					window.close();
					window4.clear();
					window4.draw(sprite);
					window4.display();
				}

				window4.close();

			}
			else if (GameWorld.GAMEOVER())
			{


				sf::RenderWindow window2(sf::VideoMode(420, 500), "!!YOU WIN!!");
				sf::Image image;
				string filewin = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\YOUWINRS.jpg";
				if (!(image.loadFromFile(filewin)))
					std::cout << "Cannot load image";

				sf::Texture texture;

				texture.loadFromImage(image);

				sf::Sprite sprite;
				sprite.setTexture(texture);
				while (window2.isOpen())
				{
					window.close();


					window2.clear();
					window2.draw(sprite);
					window2.display();
				}

				window2.close();


			}
			if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
				GameWorld.movingPac();

			else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
				GameWorld.movingPacdown();

			else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				GameWorld.movingPacleft();

			else if (event.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				GameWorld.movingPacright();

			else if (event.type == sf::Event::Closed)
				window.close();

			else
				continue;

			//cout << "counter " << cnt;
			if (GameWorld.moveGhost(cnt)) {
				sf::RenderWindow window9(sf::VideoMode(420, 500), "!!YOU LOSE!!");
				sf::Image image;
				string filelose = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\gameoverrs.jpg";
				if (!(image.loadFromFile(filelose)))
					std::cout << "Cannot load image";

				sf::Texture texture;
				texture.loadFromImage(image);
				sf::Sprite sprite;
				sprite.setTexture(texture);
				while (window9.isOpen())
				{
					window.close();
					window9.clear();
					window9.draw(sprite);
					window9.display();
				}

				window9.close();

			}
		}


		window.clear();

		for (int i = 0; i < GameWorld.gridLength; i++) {
			for (int j = 0; j < 21; j++) {
				window.draw(GameWorld.tiles[j][i]->sprite);
			}
		}
		window.display();
	}
}


	
	 
