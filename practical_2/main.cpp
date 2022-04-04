#include "ship.h"
#include "game.h"
#include "bullet.h"
#include <iostream>
using namespace sf;
using namespace std;

vector<Ship*>ships;
Invader invader;
Sprite sprite;
Texture spritesheet;
Player* player;

const Keyboard::Key controls[2]{
	Keyboard::Left,
	Keyboard::Right
};

void Update(RenderWindow& window) {
	static Clock clock;
	float dt = clock.restart().asSeconds();
	for (auto& s : ships) {
		s->Update(dt);
	}
	Bullet::Update(dt);

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
	for (const auto s : ships) {
		window.draw(*s);
	}
	Bullet::Render(window);

}

void Load() {
	//creating list of invaders
	for (int i = 0; i < invaders_rows; i++) {
		for (int j = 0; j < invaders_columns; j++) {
			Invader* inv = new Invader(IntRect(Vector2(32 * i, 0), Vector2(32, 32)), { 100.0f + j * 50.0f,10.0f + i * 50.0f });
			ships.push_back(inv);
		}
	}
	if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << endl;
	}
	player = new Player();
	ships.push_back(player);

}

int main() {
	RenderWindow window(VideoMode(gameWidth, gameHeight), "FOR LEGAL REASONS THIS IS NOT SPACE INVADERS");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}