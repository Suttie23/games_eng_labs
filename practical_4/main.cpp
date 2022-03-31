#include <SFML\Graphics.hpp>
#include "entity.h"
#include "player.h"
#include "ghost.h"
#include "entityManager.h"
#include "system_renderer.h"
#include "pacman.h"
#include <iostream>

using namespace sf;
using namespace std;

void Load() {
	//Load Scene-Local Assets
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->load();
	menuScene->load();
	//Start at main menu
	activeScene = menuScene;

}

void Update(RenderWindow &window) {
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

	activeScene->update(dt);
	
}

void Render(RenderWindow &window) { 
	activeScene->render();
	//flush to screen
	Renderer::render();
}

int main() {
	RenderWindow window(VideoMode(800, 600), "For Legal Reasons this is not Pacman");
	Renderer::initialise(window);
	
	Load();
	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	return 0;
}