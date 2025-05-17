#pragma once

#include <cstdint>
#include <iostream>

namespace fage
{
	struct Color
	{
		Color() = default;
		Color(float r, float g, float b, float alpha = 1.f);

		float r;
		float g;
		float b;
		float alpha;
	};
}

