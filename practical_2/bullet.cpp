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
	else
	{
		const FloatRect boundingBox = getGlobalBounds();
		move(Vector2f(0, dt * 200.0f * (_mode ? 1.0f : -1.0f)));

		for (auto s : ships) {
			if (!_mode && s == player) {
				//player bullets dont collide with player
				continue;
			}
			if (_mode && s != player) {
				//invaders' bullets dont collide with other invaders
				continue;
			}
			if (!s->is_exploded() && s->getGlobalBounds().findIntersection(boundingBox)) {
				//explode the ship
				s->Explode();
				//warp bullet off-screen
				setPosition(Vector2f(-100, -100));
				return;
			}
		}

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