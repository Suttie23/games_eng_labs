#include "scene.h"
#include "system_renderer.h"
void Scene::update(double dt)
{
	_ents.update(dt); 
}

void Scene::render()
{
	
}

void Scene::load() {

}
std::vector<std::shared_ptr<Entity>>& Scene::getEnts()
{
	return _ents.list;
}