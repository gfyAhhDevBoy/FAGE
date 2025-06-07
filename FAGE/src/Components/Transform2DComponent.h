#pragma once

#include "../Component.h"
#include "../Math/Math.h"

namespace fage
{
	class Transform2DComponent : public Component
	{
	public:
		Vec2f position;
		// Rotation
		Vec2f scale;

		Transform2DComponent(GameObject* parent, Vec2f pos);

		void Update() override;
		void Draw(render::Display& display) override;

		void SetPosition(Vec2f pos);
		void Move(Vec2f pos);

	};
}

