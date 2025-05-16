#pragma once

#include <memory>

#include "Display.h"

namespace fage
{
	class Scene
	{
	public:
		void Update();

		void Draw(std::weak_ptr<Display> display);
	};
}

