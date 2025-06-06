#pragma once

#include <vector>
#include <memory>

#include "Component.h"
#include "Math/Math.h"

namespace fage
{


	class GameObject
	{
	public:

		GameObject();
		GameObject(Vec2f pos);

		void Update();
		void Draw(render::Display& display);

		void SetPosition(Vec2f pos);
		void Move(Vec2f pos);
		inline Vec2f GetPosition() const;

		template<typename T, typename... Args>
		std::shared_ptr<T> AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of<Component, T>::value, "T has to be a Component");
			std::shared_ptr<T> component = std::make_shared<T>(this, std::forward<Args>(args)...);
			m_Components.push_back(std::move(component));
			return component;
		}

	private:
		std::vector<std::shared_ptr<Component>> m_Components;

		Vec2f m_Position;
	};
}