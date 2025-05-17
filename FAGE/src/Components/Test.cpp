#include "Test.h"

namespace fage
{
	namespace component
	{
		Test::Test(GameObject* parent) : Component(parent)
		{
		}

		void Test::Update(float dt)
		{
			std::cout << "test\n";
		}

		void Test::Draw(render::Display& display)
		{
		}

	}
}

