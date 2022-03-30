#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

//Main.cpp
sf::Texture spritesheet;
sf::Sprite invader;

const int gameWidth = 800;
const int gameHeight = 600;

void Load() {
    if (!spritesheet.loadFromFile("res/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << std::endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(IntRect(Vector2(0, 0), Vector2(32, 32)));
}

void Render(RenderWindow& window) {
    window.draw(invader);
}

int main() {

	RenderWindow window(VideoMode(gameWidth, gameHeight), "FOR LEGAL REASONS THIS IS NOT SPACE INVADERS");
	Load();


	while (window.isOpen()) {
		window.clear();
		Render(window);
		window.display();
	}

	return 0;

}