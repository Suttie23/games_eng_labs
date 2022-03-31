#include "entity.h"
#include "player.h"
#include <iostream>

using namespace std;
using namespace sf;

Player* player;
void Load() {
	player = new Player();
	player->setPosition(Vector2f(150.f, 150.f));
}
void Update(RenderWindow& window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	player->Update(dt);
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
	player->Render(window);
}


int main() {
	RenderWindow window(VideoMode(800, 600), "TILE ENGINE");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}