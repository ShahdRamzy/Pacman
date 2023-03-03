#pragma once
#include<SFML/Graphics.hpp>
#include"graph.h"
class ghost
{
public:
	vector<int> moving(sf::Vector2i& gostpos, const sf::Vector2i pacman,graph & gr);

};
