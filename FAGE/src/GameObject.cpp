#include "GameObject.h"

namespace fage
{
	GameObject::GameObject() : m_Position({0,0}) 
	{
	}

	GameObject::GameObject(Vec2f pos) : m_Position(pos)
	{
	}

	void GameObject::Update(float dt)
	{
		for (auto& c : m_Components)
		{
			c->Update(dt);
		}
	}
	void GameObject::Draw(render::Display& display)
	{
	}
	void GameObject::SetPosition(Vec2f pos)
	{
		m_Position = pos;
	}

	void GameObject::Move(Vec2f pos)
	{
		m_Position += pos;
	}

	inline Vec2f GameObject::GetPosition() const
	{
		return m_Position;
	}
}


