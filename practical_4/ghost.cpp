#include "ghost.h"
#include <iostream>

using namespace std;
using namespace sf;

void Ghost::update(const double dt) {


	Entity::update(dt);

}

// Render ghost
void Ghost::render(sf::RenderWindow& window) const {
	window.draw(*_shape);
}

// Ghost Character
Ghost::Ghost(Vector2f* pos) :_speed(200.f), Entity(make_unique<CircleShape>(20.f)) {
	_shape->setFillColor(Color::Red);
	_shape->setOrigin(Vector2f(25.f, 25.f));
	_position = *pos;
}