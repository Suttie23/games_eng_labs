#pragma once
#include "ecm.h"
#include <SFML/Graphics.hpp>

struct EntityManager {
	std::vector<std::shared_ptr<Entity>> list;
	void update(double dt);
	void render(sf::RenderWindow &window);
};