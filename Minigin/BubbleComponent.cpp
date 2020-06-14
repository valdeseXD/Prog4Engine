#include "MiniginPCH.h"
#include "BubbleComponent.h"
#include "GameObject.h"
#include "ControllerComponent.h"

Valdese::BubbleComponent::BubbleComponent(glm::vec2 bubbleForce)
	:m_BubbleForce(bubbleForce)
{
}

void Valdese::BubbleComponent::Initialize()
{
	m_pController = GetGameObject()->GetComponent<ControllerComponent>();
	if (m_pController == nullptr)
	{
		std::cout << "No controller attached to Bubble" << std::endl;
	}
	m_pController->SetGravity(false);
}

void Valdese::BubbleComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	if (m_ShootTime > 0.0f)
	{
		m_pController->AddForce({ m_BubbleForce.x, 0 });
	}
	if (GetTransform()->GetPosition().y > 100)
	{
		m_pController->AddForce({ 0, m_BubbleForce.y });
	}
	else
	{
		m_pController->SetForce({ 0,0 });
	}
	if (m_LifeTime < 0.0f)
	{
		SceneManager::GetInstance().GetActiveScene()->Remove(GetGameObject());
	}
	m_LifeTime -= elapsedSec;
	m_ShootTime -= elapsedSec;
}

void Valdese::BubbleComponent::Draw() const
{
}

void Valdese::BubbleComponent::DebugDraw() const
{
}
