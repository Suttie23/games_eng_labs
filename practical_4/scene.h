#pragma once
#include "entityManager.h"


class Scene {
public:
	Scene() = default;

	virtual ~Scene() = default;
	virtual void update(double dt);
	virtual void render();
	virtual void load() ;
	std::vector<std::shared_ptr<Entity>> &getEnts();

protected:
	EntityManager _ents; 
};