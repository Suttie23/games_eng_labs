// Ship.cpp
#include "game.h"
#include "ship.h"

using namespace sf;
using namespace std;

bool Invader::direction;
float Invader::speed;

Ship::Ship() {};

Ship::Ship(IntRect ir) : Sprite()
{

	_sprite = ir;
	setTexture(spritesheet);
	setTextureRect(_sprite);

};

void Ship::Update(const float& dt) {}

// Define ship deconstructor
Ship::~Ship() = default;

Invader::Invader() : Ship() {}

Invader::Invader(sf::IntRect ir, sf::Vector2f pos) : Ship(ir)
{
	setOrigin(Vector2f(16.f, 16.f));;
	setPosition(pos);
}

void Invader::Update(const float& dt)
{
	Ship::Update(dt);

	move(Vector2f(dt * (direction ? 1.0f : -1.0f) * speed, 0.0f));

	if ((direction && getPosition().x > gameWidth - 16) || (!direction && getPosition().x < 16))
	{

		direction = !direction;
		for (int i = 0; i < ships.size() - 1; ++i)
		{

			ships[i]->move(Vector2f(0.0f, 24.0f));

		}

	}
}

//ship.cpp
float speed = 100.0f;
Player::Player() : Ship(IntRect(Vector2(160, 32), Vector2(32, 32))) {
	setPosition({ gameWidth * .5f, gameHeight - 32.f });
}

void Player::Update(const float& dt) {
	Ship::Update(dt);
	Ship::Update(dt);
	if (Keyboard::isKeyPressed(Keyboard::Left) && getPosition().x > 0) {
		move(sf::Vector2f(dt * (-speed), 0));
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) && getPosition().x + 32 < gameWidth) {
		move(sf::Vector2f(dt * speed, 0));
	}
		
}