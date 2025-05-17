#include "Component.h"

fage::Component::Component(GameObject* parent)
{
	m_Parent = std::shared_ptr<GameObject>(parent);
}
