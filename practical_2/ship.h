// ship.h
#pragma once
#include <SFML/Graphics.hpp>

class Ship : public sf::Sprite
{
protected:
	sf::IntRect _sprite;
	Ship();
	bool _exploded = false;
public:
	// Constructor that takes a sprite
	explicit Ship(sf::IntRect ir);

	// Pure virtual deconstructor -- this makes an abstract class and avoids undefined behaviour!
	virtual ~Ship() = 0;

	// Update, virtual so can be overidden, but not pure virtual
	virtual void Update(const float& dt);

	bool is_exploded() const;
	virtual void Explode();

};

class Invader : public Ship
{
public:
	static bool direction;
	static float speed;
	Invader(sf::IntRect ir, sf::Vector2f pos);
	Invader();
	void Update(const float& dt) override;
	void Explode() override;

};

class Player : public Ship {
public:
  Player();
  static float speed;
  void Update(const float &dt) override;
  void Explode() override;
};