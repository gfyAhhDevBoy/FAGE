#include "GameObject.h"

namespace fage
{
	GameObject::GameObject() : GameObject({ 0,0 })
	{
	}

	GameObject::GameObject(Vec2f pos)
	{
		AddComponent<Transform2DComponent>(pos);
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
}


