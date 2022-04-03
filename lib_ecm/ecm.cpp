#include "ecm.h"

Entity::Entity()
{
}

Entity::~Entity() {

}

const sf::Vector2f& Entity::getPosition() const
{
	return _position;
}

void Entity::setPosition(const sf::Vector2f& _pos) { _position = _pos; }

void Entity::update(const double dt) {

	for (auto component : _components) {
		component->update(dt);
	}
}

void Entity::render()
{

	for (auto component : _components) {
		component->render();
	}
}

bool Entity::is_fordeletion() const
{
	return _fordeletion;
}

float Entity::getRotation() const
{
	return _rotation;
}

void Entity::setRotation(float _rotation)
{
	_rotation = _rotation;
}

bool Entity::isAlive() const
{
	return _alive;
}

void Entity::setAlive(bool _alive)
{
	_alive = _alive;
}

void Entity::setForDelete()
{
	_fordeletion = true;
}

bool Entity::isVisible() const
{
	return _visible;
}

void Entity::setVisible(bool _visible)
{
	_visible = _visible;
}


//Component
Component::Component(Entity* const p) : _parent(p) {
	//todo

}

Component::~Component() {

}