//bullet.h
#pragma once
#include <SFML/Graphics.hpp>

class Bullet : public sf::Sprite {
public:
	//Update all bullets
	static void Update(const float& dt);
	//render all bullets
	static void Render(sf::RenderWindow& window);
	//choose an inactive bullet and use it
	static void Fire(const sf::Vector2f& pos, const bool mode);
	Bullet(const sf::Vector2f& pos, const bool mode);
	~Bullet() = default;
protected:
	//Never called by code
	Bullet();
	static unsigned char bulletPointer;
	static Bullet bullets[256];
	//called by static Update()
	void _Update(const float& dt);
	//false=player bullet, true=enemy bullet
	bool _mode;
};