#include "entityManager.h"

void EntityManager::update(double dt) {
	for (auto item : list) {
		item->update(dt);
	}
}


void EntityManager::render(sf::RenderWindow &window) {
	for (auto item : list) {
		item->render(window); 
	}
}