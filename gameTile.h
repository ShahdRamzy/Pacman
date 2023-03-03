#pragma once
#include<SFML/Graphics.hpp>
#ifndef GAMETILE_H
#define GAMETILE_H
#include <iostream>

using namespace std;
class gameTile
{
public:
	sf::Vector2f position; 
	sf::Texture texture;
	sf::Sprite sprite;
	bool wall; 
	gameTile(string, int, int, bool);
	bool setupSprite(string);
};
#endif // !GAMETILE_H

