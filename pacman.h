
#include <iostream>
#pragma once 
#include<SFML/Graphics.hpp>
#include"graph.h"

class Pacman
{
public:
    int moveUP(sf::Vector2i& pacmanpos, graph& gr, int n);
    int moveRIGHT(sf::Vector2i& pacmanpos, graph& gr, int n);
    int moveLEFT(sf::Vector2i& pacmanpos, graph& gr, int n);
    int moveDOWN(sf::Vector2i& position, graph& gr, int n);



};

