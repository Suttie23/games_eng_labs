#include "entity.h"
using namespace std;
using namespace sf;

const Vector2f Entity::getPosition() { return _position; }
void Entity::move(const Vector2f& pos) { _position += pos; }
void Entity::update(const double dt) {
	_shape->setPosition(_position);
}
void Entity::setPosition(const sf::Vector2f& _pos) { _position = _pos; }
Entity::Entity(unique_ptr<Shape> s) : _shape(std::move(s)) {}