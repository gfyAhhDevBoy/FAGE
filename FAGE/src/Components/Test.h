#pragma once

#include "../Component.h"
#include "../Render/Display.h"

namespace fage
{
	namespace component
	{
		class Test : Component
		{
		public:
			Test(GameObject* parent);

			void Update(float dt) override;
			void Draw(render::Display& display);
		};
	}
}