#include "Transform2DComponent.h"

fage::Transform2DComponent::Transform2DComponent(GameObject* parent, Vec2f pos) : Component(parent), position(pos)
{
}

void fage::Transform2DComponent::Update()
{
}

void fage::Transform2DComponent::Draw(render::Display& display)
{
}

void fage::Transform2DComponent::SetPosition(Vec2f pos)
{
}

void fage::Transform2DComponent::Move(Vec2f pos)
{
}
