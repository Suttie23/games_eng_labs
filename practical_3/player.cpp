#include "player.h"
using namespace sf;
using namespace std;

void Player::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		Vector2f pos = Vector2f(0, -_speed * dt) + _position + Vector2f(0, -25);
		if (validMove(pos))
			move(Vector2f(0, -_speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::A)) {
		Vector2f pos = Vector2f(-_speed * dt, 0) + _position + Vector2f(-25, 0);
		if (validMove(pos))
			move(Vector2f(-_speed * dt, 0));
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		Vector2f pos = Vector2f(0, _speed * dt) + _position + Vector2f(0, 25);
		if (validMove(pos))
			move(Vector2f(0, _speed * dt));
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		Vector2f pos = Vector2f(_speed * dt, 0) + _position + Vector2f(25, 0);
		if (validMove(pos))
			move(Vector2f(_speed * dt, 0));
	}
	Entity::update(dt);
}

Player::Player()
	: _speed(200.0f), Entity(make_unique<CircleShape>(25.f)) {
	_shape->setFillColor(Color::Magenta);
	_shape->setOrigin(Vector2f(25.f, 25.f));

}

void Player::render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}

bool Player::validMove(sf::Vector2f pos) {
	return (ls::getTileAt(pos) != ls::WALL);
}