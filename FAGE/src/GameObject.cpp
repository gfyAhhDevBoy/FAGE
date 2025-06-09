#include "GameObject.h"

namespace fage
{
	GameObject::GameObject() : GameObject({ 0,0 })
	{
	}

	GameObject::GameObject(Vec2f pos)
	{
		transform = AddComponent<Transform2DComponent>(pos);
	}

	void GameObject::Update()
	{
		for (auto& c : m_Components)
		{
			c->Update();
		}
	}
	void GameObject::Draw(render::Display& display)
	{
	}
	std::shared_ptr<Transform2DComponent> GameObject::GetTransform()
	{
		return std::shared_ptr<Transform2DComponent>();
	}
}


