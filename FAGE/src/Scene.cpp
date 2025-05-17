#include "Scene.h"

namespace fage
{
	void Scene::Update()
	{
		
	}

	void Scene::Draw(std::shared_ptr<render::Display> display)
	{
		display->Clear(clearColor);
	}

	void Scene::SetClearColor(Color color)
	{
		clearColor = color;
	}

}

