#pragma once

#include "Render/Display.h"

namespace fage {
	class Component {
	public:
		Component() = delete;

		Component(const Component&) = delete;
		Component& operator=(const Component&) = delete;

		Component(const Component&&) = delete;
		Component&& operator=(const Component&&) = delete;

		virtual void Update(float dt);
		virtual void Draw(render::Display& display);

	private:
		GameObject* parent;
	};
}

