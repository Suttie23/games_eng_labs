#pragma once
#include "entity.h"

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render(sf::RenderWindow &window);
};