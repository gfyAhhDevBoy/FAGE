#pragma once

#include "Render/Display.h"

#include <memory>

namespace fage {
class GameObject;

class Component {
public:
	Component(GameObject* parent);
	virtual ~Component() = default;

	virtual void Update() = 0;
	virtual void Draw(render::Display& display) = 0;

	

private:
	std::shared_ptr<GameObject> m_Parent;
};
}
