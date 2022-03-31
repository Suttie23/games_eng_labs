#pragma once
#include "entity.h"

class Ghost : public Entity{ 
private:
	float _speed;
	int randNumx = 0;
	int randNumy = 0;
public:
	virtual void update(const double dt);
	Ghost(sf::Vector2f* pos);
	virtual void render(sf::RenderWindow &window) const;
};
