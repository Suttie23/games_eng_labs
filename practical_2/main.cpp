#include <SFML/Graphics.hpp>
#include "game.h"
#include "ship.h"
#include <iostream>
#include "bullet.h"

using namespace sf;
using namespace std;

sf::Texture spritesheet;
sf::Sprite invader;

std::vector<Ship*> ships;


const Keyboard::Key controls[2]{
	Keyboard::Left,
	Keyboard::Right
};

void Update(RenderWindow& window) {
	// Reset clock, recalculate deltatime
	static Clock clock;
	float dt = clock.restart().asSeconds();
	// check and consume events
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			return;
		}
	}

	for (auto& s : ships)
	{
		s->Update(dt);
	}
	Bullet::Update(dt);

	// Quit Via ESC Key
	if (Keyboard::isKeyPressed(Keyboard::Escape))
	{
		window.close();
	}

}

void Render(RenderWindow& window)
{

	window.draw(invader);

	for (const auto s : ships)
	{
		window.draw(*s);
	}
	Bullet::Render(window);

}

void Load()
{
	Invader::speed = 45.0f;

	for (int i = 0; i < invaders_rows; i++) {
		for (int j = 0; j < invaders_columns; j++) {
			Invader* inv = new Invader(IntRect(Vector2(32 * i, 0), Vector2(32, 32)), { 100.0f + j * 50.0f,10.0f + i * 50.0f });
			ships.push_back(inv);
		}
	}

	if (!spritesheet.loadFromFile("res/invaders_sheet.png"))
	{
		cerr << "Failed to load spritesheet!" << std::endl;
	}
	Player* player = new Player;
	ships.push_back(player);
}

int main()
{
	RenderWindow window(VideoMode(gameWidth, gameHeight), "FOR LEGAL PURPOSES THIS IS NOT SPACE INVADERS");
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}