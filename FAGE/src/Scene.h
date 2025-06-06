#pragma once

#include <memory>
#include <vector>

#include "Render/Display.h"
#include "GameObject.h"

namespace fage
{
	class Scene
	{
	public:
		void Update();

		void Draw(std::shared_ptr<render::Display> display);
		void SetClearColor(Color color);

		GameObject* CreateGameObject();

	private:
		Color m_ClearColor;

		std::vector<std::unique_ptr<GameObject>> m_GameObjects;
	};
}

