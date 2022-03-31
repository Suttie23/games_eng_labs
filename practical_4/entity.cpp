#include "entity.h"


const sf::Vector2f Entity::getPosition() { return _position;
}

void Entity::setPosition(const sf::Vector2f &pos) { _position = pos;
}

void Entity::update(const double dt) { _shape->setPosition(_position);
}
void Entity::move(const sf::Vector2f &pos) {
	_position += pos;
}

bool Entity::validMove(const sf::Vector2f &pos) {
	if ((pos.x < 800 && pos.x > 0) && (pos.y < 600 && pos.y > 0 )) //hard coded values, need to add global height/width (externals)
		return true;
	return false;
}
Entity::Entity(std::unique_ptr<sf::Shape> s) : _shape(std::move(s)) {}