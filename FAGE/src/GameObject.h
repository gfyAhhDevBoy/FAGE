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
		void AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of<Component, T>::value, "T has to be a Component");
			std::unique_ptr<T> component = std::make_unique<T>(this, std::forward<Args>(args)...);
			m_Components.push_back(std::move(component));
		}

		template<typename T>
		bool TryGetComponent(Component& component)
		{
			static_assert(std::is_base_of<Component, T>::value, "T has to be a Component");
			for (auto& c : m_Components)
			{
				if (std::is_base_of<Component, c>::value)
				{
					component = c;
					return true;
				}
			}

			return false;
		}

	private:
		std::vector<std::unique_ptr<Component>> m_Components;

		Vec2f m_Position;
	};
}