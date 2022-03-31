// player.cpp
#include "player.h"
using namespace sf;
using namespace std;

void Player::Update(double dt) {
	// Move in 4 directions
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		Vector2f pos = Vector2f(0, -_speed * dt) + _position + Vector2f(0, -25);
			move(Vector2f(0, -_speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		Vector2f pos = Vector2f(-_speed * dt, 0) + _position + Vector2f(-25, 0);
			move(Vector2f(-_speed * dt, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		Vector2f pos = Vector2f(0, _speed * dt) + _position + Vector2f(0, 25);
			move(Vector2f(0, _speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		Vector2f pos = Vector2f(_speed * dt, 0) + _position + Vector2f(25, 0);
			move(Vector2f(_speed * dt, 0));
	}

	Entity::Update(dt);
}

Player::Player()
	: _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.f, 25.f));
}

void Player::Render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}


