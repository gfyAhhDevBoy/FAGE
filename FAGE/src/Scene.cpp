#include "Scene.h"

namespace fage
{
	void Scene::Update(float dt)
	{
		for (auto& obj : m_GameObjects)
		{
			obj->Update(dt);
		}
	}

	void Scene::Draw(std::shared_ptr<render::Display> display)
	{
		display->Clear(m_ClearColor);
	}

	void Scene::SetClearColor(Color color)
	{
		m_ClearColor = color;
	}

	GameObject* Scene::CreateGameObject()
	{
		m_GameObjects.push_back(std::make_unique<GameObject>());
		return m_GameObjects.back().get();
	}

}

