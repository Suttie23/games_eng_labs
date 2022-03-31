#include "ghost.h"
#include "system_renderer.h"
#include <iostream>

using namespace std;
using namespace sf;

void Ghost::update(const double dt) {
	Entity::update(dt);

}

void Ghost::render(sf::RenderWindow &window) const {
	Renderer::queue(&*_shape); 
}

Ghost::Ghost(Vector2f* pos) :_speed(200.f), Entity(make_unique<CircleShape>(20.f)) {
	_shape->setFillColor(Color::Yellow);
	_shape->setOrigin(Vector2f(25.f, 25.f));
	_position = *pos;
}