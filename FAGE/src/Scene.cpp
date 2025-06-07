#include "Scene.h"

namespace fage
{
	void Scene::Update()
	{
		for (auto& obj : m_GameObjects)
		{
			obj->Update();
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
		m_GameObjects.back()->AddComponent<Transform2DComponent>();
		return m_GameObjects.back().get();
	}

}

