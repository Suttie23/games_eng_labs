#include "bullet.h"
#include "game.h"
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

unsigned char Bullet::bulletPointer = '0';
Bullet Bullet::bullets[256];

Bullet::Bullet() {};
Bullet::Bullet(const sf::Vector2f& pos, const bool mode) {
	setPosition(pos);
	_mode = mode;
	setTexture(spritesheet);
	if (_mode)
		setTextureRect(IntRect(Vector2(32, 32), Vector2(32, 32)));
	else
		setTextureRect(IntRect(Vector2(72, 32), Vector2(32, 32)));

}

void Bullet::Update(const float& dt) {
	for (auto& b : bullets) {
		b.move({ 0, 200.0f * dt * (b._mode ? 1.0f : -1.0f) });
		b._Update(dt);
	}
}
void Bullet::_Update(const float& dt) {
	if (getPosition().y < -32 || getPosition().y > gameHeight + 32) {
		//do nothing, bullet out of screen
		return;
	}

}
void Bullet::Fire(const sf::Vector2f& pos, const bool mode) {
	bullets[++bulletPointer] = Bullet(pos, mode);
}

void Bullet::Render(sf::RenderWindow& window) {

	for (auto b : bullets) {
		window.draw(b);
	}
}