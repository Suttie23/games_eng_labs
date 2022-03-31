#include <SFML\Graphics.hpp>
#include "entity.h"
#include "player.h"
#include "ghost.h"
#include <iostream>

using namespace sf;
using namespace std;

vector<Entity*> entities;

void Load() {

	Player* player = new Player();
	entities.push_back(player);
	for (int i = 0; i < 4; i++)
	{
		Ghost* ghost = new Ghost(new Vector2f(100, 100));
		entities.push_back(ghost);
	}

}

void Update(RenderWindow& window) {
	static Clock clock;
	double dt = clock.restart().asSeconds();
	//check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::Escape))
		window.close();


	for (auto e : entities) {
		e->update(dt);
	}
}

void Render(RenderWindow& window) {
	for (Entity* e : entities) {
		e->render(window);
	}
}

int main() {
	RenderWindow window(VideoMode(800, 600), "For legal reasons this isn't Pacman");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}