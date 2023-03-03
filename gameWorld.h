//#pragma once
//#include<SFML/Graphics.hpp>
//#include"gameTile.h"
//#include"graph.h"
//#include"pacman.h"
//#include<vector>
//#include <iostream>
#pragma once 
#include<SFML/Graphics.hpp>
#include"gameTile.h"
#include<vector>
#include"graph.h"
#include"pacman.h"
#include"ghost.h"
#ifndef GAMEWORLD_H
#define GAMEWORLD_H
using namespace std;
class gameWorld
{
	 

	sf::Vector2i foodpos;
	void setUpInitialState();///reset the whole map
	void setUpGhostPos();
	void setUpTiles();

	
public:
	vector<sf::Vector2i> ghostpos;
	vector<vector<gameTile*>> tiles;
	int gridLength;
	gameWorld();
	graph gr;
	sf::Vector2i pacmanpos;
	Pacman pac;
	ghost Ghost;
	void movingPac();
	void movingPacright();
	void movingPacdown();
	void movingPacleft();
	bool moveGhost(int cnt);
	int nodenumber(sf::Vector2i& positions, graph& gr);
	void randGhost(int random_direction);
	bool GAMEOVER();
	bool lose();
	void draw(sf::RenderWindow & window);
	string filnamehl = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\tryhdown.jpg";
	string filnamevll = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\tryvl.png";
	string filnamefood = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\food.jpg";
	string filnameg = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\greenline.jpg";
	string filnamewhite = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\white.png";
	string filnameblack = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\black.jpg";
	string filnamehldown = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\tryhup.jpg";
	string filnamevlmiddle = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\vlmid.jpg";
	string filnamepacman = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\pacman.jpg";
	string filnameredghost= "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\redghost.jpg";
	string filnameghost = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\BLUEGHOSTrs.jpg";
	string filelose = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\gameoverrs.jpg";
	string filewin = "C:\\Users\\HP\\source\\repos\\Pacman\\Pacman\\pacmanscreens\\YOUWINrs.jpg";
};
#endif // !GAMEWORLD_H

