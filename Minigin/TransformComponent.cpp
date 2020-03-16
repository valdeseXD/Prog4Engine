#include "MiniginPCH.h"
#include "TransformComponent.h"

Valdese::TransformComponent::TransformComponent(glm::vec2 position)
	:m_Position(position)
{
}

void Valdese::TransformComponent::SetPosition(const float x, const float y)
{
	m_Position.x = x;
	m_Position.y = y;
}

void Valdese::TransformComponent::Initialize()
{
}

void Valdese::TransformComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);

}

void Valdese::TransformComponent::Draw()
{
}
