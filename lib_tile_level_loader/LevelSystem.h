#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>
#include <vector>
#include <maths.h>
#include <map>

#define ls LevelSystem

class LevelSystem {
public:
	enum TILE { EMPTY, START, END, WALL, ENEMY, WAYPOINT };
	static void loadLevelFile(const std::string&, float tileSize = 100.f);
	static void render(sf::RenderWindow& window);
	static sf::Color getColor(TILE t);
	static void setColor(TILE t, sf::Color c);
	//Get tile at grid coordinate
	static TILE getTile(sf::Vector2ul);
	//Get Screenspace coordinate of title
	static sf::Vector2f getTilePosition(sf::Vector2ul);
	//get the tile at screenspacepos
	static TILE getTileAt(sf::Vector2f);
	static size_t getHeight();
	static size_t getWidth();
	static std::vector<sf::Vector2ul> findTiles(TILE);

protected:
	static std::unique_ptr<TILE[]> _tiles;
	static size_t _width;
	static size_t _height;
	static float _tileSize;
	static std::map<TILE, sf::Color> _colours;
	static std::vector<std::unique_ptr<sf::RectangleShape>> _sprites;
	static sf::Vector2f _offset;

	static void buildSprites();

private:
	LevelSystem() = delete;
	~LevelSystem() = delete;
};