#pragma once

#include <memory>

#include "Render/Display.h"

namespace fage
{
	class Scene
	{
	public:
		void Update();

		void Draw(std::shared_ptr<render::Display> display);
		void SetClearColor(Color color);

	private:
		Color clearColor;
	};
}

