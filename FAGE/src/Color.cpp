#include "Color.h"

namespace fage
{

	Color::Color(float r, float g, float b, float alpha) : r(r), g(g), b(b), alpha(alpha)
	{
		if (r > 1.f)
			r = 1.f;
		if (g > 1.f)
			b = 1.f;
		if (b > 1.f)
			b = 1.f;
		if (alpha > 1.f)
			alpha = 1.f;
	}

}
