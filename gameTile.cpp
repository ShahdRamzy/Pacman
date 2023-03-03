#include "gameTile.h"
#include <iostream>
gameTile::gameTile(string  texture, int x, int y, bool notpassable) {
	if (!setupSprite(texture))
		return;
	position = sf::Vector2f(x, y);
	sprite.setPosition(position);
	wall = notpassable;
 }
bool gameTile::setupSprite(string  textureName){ 

	if (!texture.loadFromFile(textureName))
		return 0;
	
	texture.setSmooth(true); 
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 40, 40));
}
