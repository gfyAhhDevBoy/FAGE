#pragma once

#include "../Component.h"

namespace fage
{
	namespace component
	{
		class Test : public Component
		{
		public:
			Test(GameObject* parent, const char* txt) : Component(parent), txt(txt)
			{

			}

			void Update() override
			{
				std::cout << txt << std::endl;
			}

			void Draw(render::Display& display) override
			{
				
			}

			const char* txt;
		};
	}
}