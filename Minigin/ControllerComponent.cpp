#include "MiniginPCH.h"
#include "ControllerComponent.h"
#include "TransformComponent.h"
#include "InputManager.h"
#include "ColliderComponent.h"
#include "BubbleComponent.h"

#include "Renderer.h"
#include "RenderComponent.h"

Valdese::ControllerComponent::ControllerComponent(Side side)
	:m_pTransform(nullptr)
	,m_pCollider(nullptr)
	,m_Side(side)
{

}

void Valdese::ControllerComponent::Initialize()
{
	m_pTransform = GetTransform();
	m_pCollider = GetGameObject()->GetComponent<ColliderComponent>();
	if (m_pCollider == nullptr)
	{
		std::cout << "No collider found in controllercomponent" << std::endl;
	}
}

void Valdese::ControllerComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	SDL_Rect EndRect;
	EndRect = GetGameObject()->GetComponent<RenderComponent>()->GetDestRect();
	EndRect.x += (int)GetTransform()->GetPosition().x;
	EndRect.y += (int)GetTransform()->GetPosition().y;

	m_pCollider->SetBox(EndRect);

	if (m_GravityEnabled && m_Force.y < 100)
	{
		m_Force.y += 50.0f;
	}
	if (m_pTransform != nullptr)
	{
		m_pTransform->SetPosition(m_pTransform->GetPosition().x + m_Force.x * elapsedSec, m_pTransform->GetPosition().y + m_Force.y * elapsedSec);
		CheckCollision();
		m_Force.x = 0;
	}

	if (m_ElapsedFireCooldown > 0)
	{
		m_ElapsedFireCooldown -= elapsedSec;
	}
}

void Valdese::ControllerComponent::Draw() const
{

}

void Valdese::ControllerComponent::DebugDraw() const
{
}

void Valdese::ControllerComponent::Move(int x, int y)
{
	m_pTransform->SetPosition(m_pTransform->GetPosition().x + x,m_pTransform->GetPosition().y + y);
	m_pCollider->UpdateBox(x, y);
}

void Valdese::ControllerComponent::AddForce(glm::vec2 force)
{
	m_Force += force;
}

void Valdese::ControllerComponent::SetForce(glm::vec2 force)
{
	m_Force = force;
}

void Valdese::ControllerComponent::CheckCollision()
{
	std::vector<ColliderComponent*> otherColliders;
	std::vector<GameObject*> gameObjects = SceneManager::GetInstance().GetActiveScene()->GetObjects();
	for (int object = 0; object < gameObjects.size(); object++)
	{
		if (gameObjects[object]->IsActive())
		{
			std::vector<ColliderComponent*> collidersInObject = gameObjects[object]->GetComponents<ColliderComponent>();
			for (int i = 0; i < collidersInObject.size(); i++)
			{
				if (collidersInObject[i] != m_pCollider)
				{
					otherColliders.push_back(collidersInObject[i]);
				}
			}
		}
	}

	int offset = 2;
	for (int i = 0; i < otherColliders.size(); i++)
	{
		if (m_pCollider->IsColliding(otherColliders[i]->GetBox()))
		{
			//Check if collision is between controller - block or bubble - bubble
			if (otherColliders[i]->GetColliderState() == ColliderState::Static || (m_pCollider->GetColliderState() == ColliderState::Bubble && otherColliders[i]->GetColliderState() == ColliderState::Bubble))
			{
				if (m_pCollider->IsTopCollision(otherColliders[i]->GetBox()))
				{
					Move(0, -offset);
					m_IsJumping = false;

					//Recheck if there is still collision after moving the character up
					if (m_pCollider->IsColliding(otherColliders[i]->GetBox()))
					{
						auto prevPos = m_pTransform->GetPrevPosition();
						if (m_pCollider->IsLeftCollision(otherColliders[i]->GetBox()))
						{
							Move(offset, 0);
						}
						if (m_pCollider->IsRightCollision(otherColliders[i]->GetBox()))
						{
							Move(-offset, 0);
						}
					}
				}
				if (m_pTransform->GetPosition().y < 0)
				{
					m_pTransform->SetPosition(m_pTransform->GetPosition().x, 50);
				}
			}
			else
			{
				Side otherColliderSide = otherColliders[i]->GetGameObject()->GetComponent<ControllerComponent>()->GetSide();
				if (otherColliderSide != m_Side)
				{
					std::cout << "enemy hit" << std::endl;
				}
			}
		}
	}
	m_pCollider->CheckCollision();
}

void Valdese::ControllerComponent::Jump()
{
	if (!m_IsJumping)
	{
		m_GravityEnabled = true;
		m_Force.y = -600;
		m_IsJumping = true;
	}
}

void Valdese::ControllerComponent::Fire()
{
 	if (m_ElapsedFireCooldown <= 0)
	{
		GameObject* bubble = new GameObject();
		bubble->GetTransform()->SetPosition(m_pTransform->GetPosition().x + 5, m_pTransform->GetPosition().y);
		bubble->AddComponent(new RenderComponent("Bubble.png"));
		bubble->AddComponent(new ColliderComponent(ColliderState::Bubble));
		bubble->AddComponent(new ControllerComponent(Side::Player));
		bubble->AddComponent(new BubbleComponent());
		SceneManager::GetInstance().GetActiveScene()->Add(*bubble);
		m_ElapsedFireCooldown = m_FireCooldown;
	}              
}
