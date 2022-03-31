#include "pacman.h"
#include "ghost.h"
#include "player.h"
#include "system_renderer.h"
#include <iostream>
#include <memory>


using namespace std;
using namespace sf;
//using namespace System;
//using namespace System::IO;

std::shared_ptr<Scene> gameScene = std::make_shared<Scene>();
std::shared_ptr<Scene> menuScene = std::make_shared<Scene>();
std::shared_ptr<Scene> activeScene = std::make_shared<Scene>();
Font font;
//MenuScene

void MenuScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}
	Scene::update(dt);
	
	
	
}

void MenuScene::render() {
	_ents.render(Renderer::getWindow());
	Renderer::queue(&text);
}

void MenuScene::load() {
	if (!font.loadFromFile("res/Roboto-Light.ttf")) {
		cout << "Font could not be found!" << endl;
	}
	text.setFont(font); 
	text.setCharacterSize(32);
	text.setString("For Legal Reasons this is not Pacman");
	text.setPosition(Vector2f((400.f) - text.getLocalBounds().width * 0.5f, 100));
}

MenuScene::MenuScene() {

}
//Game Scene

void GameScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
}

void GameScene::render() {
	_ents.render(Renderer::getWindow());
	//render clock and text adding to the queue RENDERER::
}

void GameScene::load() {
	shared_ptr<Player> player = make_shared<Player>();
	_ents.list.push_back(player);
	for (int i = 0; i < 4; i++)
	{
		shared_ptr<Ghost> ghost = make_shared<Ghost>(new Vector2f(100, 100));
		_ents.list.push_back(ghost);
	}
}