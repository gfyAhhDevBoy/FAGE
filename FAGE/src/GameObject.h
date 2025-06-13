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
		T* AddComponent(Args&&... args)
		{
			static_assert(std::is_base_of<Component, T>::value, "T has to be a Component");
			std::unique_ptr<T> component = std::make_unique<T>(this, std::forward<Args>(args)...);
			T* compPtr = component.get();
			m_Components.push_back(std::move(component));
			return compPtr;
		}

		std::shared_ptr<Transform2DComponent> GetTransform();

	private:
		std::vector<std::unique_ptr<Component>> m_Components;
		Transform2DComponent* transform;
	};
}