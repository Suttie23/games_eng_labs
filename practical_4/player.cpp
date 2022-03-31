#include "player.h"
#include "system_renderer.h"
#include <iostream>

using namespace sf;
using namespace std;

void Player::update(const double dt) {
	
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		move(Vector2f( -dt * _speed, 0 ));
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		move(Vector2f( 0, - dt * _speed ));
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		move(Vector2f( dt * _speed, 0 ));
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		move(Vector2f( 0, dt * _speed ));
	}

	Entity::update(dt);

}

Player::Player() 
	: _speed(200.f), Entity(make_unique<CircleShape>(20.f)) {
	_shape->setFillColor(Color::Yellow);
	_shape->setOrigin(Vector2f(25.f, 25.f));
}


void Player::render(RenderWindow &window) const{
	Renderer::queue(&*_shape); 
}
