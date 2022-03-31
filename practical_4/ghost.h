#pragma once
#include "entity.h"

class Ghost : public Entity {
private:
	float _speed;
public:
	virtual void update(const double dt);
	Ghost(sf::Vector2f* pos);
	virtual void render(sf::RenderWindow& window) const;
};