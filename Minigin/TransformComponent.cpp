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

void Valdese::TransformComponent::SetPosition(glm::vec2& pos)
{
	m_Position = pos;
}

void Valdese::TransformComponent::Initialize()
{
	m_PrevPosition = m_Position;
}

void Valdese::TransformComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	m_PrevPosition = m_Position;
}

void Valdese::TransformComponent::Draw() const
{
}

void Valdese::TransformComponent::DebugDraw() const
{
}
