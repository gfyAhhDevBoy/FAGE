#pragma once

#include <vector>
#include <memory>

#include "Component.h"
#include "Math/Math.h"
#include "Components/Transform2DComponent.h"

namespace fage
{


	class GameObject
	{
	public:

		GameObject();
		GameObject(Vec2f pos);

		void Update();
		void Draw(render::Display& display);

		template<typename T, typename... Args>
		std::shared_ptr<T> AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of<Component, T>::value, "T has to be a Component");
			std::shared_ptr<T> component = std::make_shared<T>(this, std::forward<Args>(args)...);
			m_Components.push_back(std::move(component));
			return component;
		}

		std::shared_ptr<Transform2DComponent> GetTransform();

	private:
		std::vector<std::shared_ptr<Component>> m_Components;
		std::shared_ptr<Transform2DComponent> transform;
	};
}