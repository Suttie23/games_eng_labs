#pragma once
#include <SFML\Graphics.hpp>
#include <memory>

class Entity {
protected:
	std::unique_ptr<sf::Shape> _shape;
	sf::Vector2f _position;
	Entity(std::unique_ptr<sf::Shape> shp);
public:
	Entity() = delete;
	virtual ~Entity() = default;
	const sf::Vector2f getPosition();
	void setPosition(const sf::Vector2f & pos);
	virtual void update(const double dt);
	virtual void render(sf::RenderWindow & window) const = 0;
	void move(const sf::Vector2f & pos);
	bool validMove(const sf::Vector2f & pos);
};