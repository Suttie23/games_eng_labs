#pragma once
#include "maths.h"
#include <algorithm>
#include <memory>
#include <typeindex>
#include <vector>

class Component; //forward declare

class Entity {
protected:
	std::vector<std::shared_ptr<Component>> _components;
	sf::Vector2f _position;
	float _rotation;
	bool _alive; //should be updated
	bool _visible; //should be rendered
	bool _fordeletion; //should be deleted

public:
	Entity();
	virtual ~Entity();
	const sf::Vector2f& getPosition() const;
	void setPosition(const sf::Vector2f& _pos);
	virtual void update(const double dt);
	virtual void render();
	bool is_fordeletion() const;
	float getRotation() const;
	void setRotation(float _rotation);
	bool isAlive() const;
	void setAlive(bool _alive);
	void setForDelete();
	bool isVisible() const;
	void setVisible(bool _visible);
	/*void move(const sf::Vector2f &pos);
	bool validMove(const sf::Vector2f &pos);*/

	template <typename T, typename... Targs>
	//implementing in .h, might better to do in .cpp
	std::shared_ptr<T> addComponent(Targs... params) {
		static_assert(std::is_base_of<Component, T>::value, "must be a component");
		std::shared_ptr<T> sp(std::make_shared<T>(this, params...));
		_components.push_back(sp);
		return sp;
	}
};

class Component {
protected:
	Entity* const _parent;
	bool _fordeletion; //should be removed
	explicit Component(Entity* const p);

public:
	Component() = delete;
	bool is_fordeletion() const;
	virtual void update(double dt) = 0;
	virtual void render() = 0;
	virtual ~Component();
};