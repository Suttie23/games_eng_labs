#pragma once
#include "SFML\Graphics.hpp"
#include "entity.h"


class Player : public Entity {
private:
	float _speed;
public:
	virtual void update(const double dt);
	Player();
	virtual void render(sf::RenderWindow &window) const;
};