#include "entity.h"
#include "player.h"
#include "levelsystem.h"
#include <iostream>

using namespace std;
using namespace sf;

Player* player;
void Load() {
	player = new Player();
	player->setPosition(Vector2f(150.f, 150.f));
	ls::loadLevelFile("res/maze_2.txt");
	//print level to console
	for (size_t y = 0; y < ls::getHeight(); ++y) {
		for (size_t x = 0; x < ls::getWidth(); ++x) {
			cout << ls::getTile({ x,y });
		}
	}
}
void Update(RenderWindow& window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	player->update(dt);
	//check and consume events
	Event event;
	while (window.pollEvent(event)) {
		if (event.type == Event::Closed) {
			window.close();
			return;
		}
	}

	//Quit via esc key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}
}
void Render(RenderWindow& window) {
	ls::render(window);
	player->render(window);
}


int main() {
	RenderWindow window(VideoMode(800, 600), "Tile Engine");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}