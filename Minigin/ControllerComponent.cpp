#include "MiniginPCH.h"
#include "ControllerComponent.h"
#include "TransformComponent.h"
#include "InputManager.h"
#include "Command.h"
#include "ColliderComponent.h"

#include "Renderer.h"
#include "RenderComponent.h"

Valdese::ControllerComponent::ControllerComponent(char left, char right, char up, char down, char fire)
	:m_pTransform(nullptr)
	,m_pCollider(nullptr)
	,m_Left(left)
	,m_Right(right)
	,m_Up(up)
	,m_Down(down)
	,m_Fire(fire)
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
	InputManager::GetInstance().AddInputAction(m_Left, new LeftCommand());
	InputManager::GetInstance().AddInputAction(m_Right, new RightCommand());
	InputManager::GetInstance().AddInputAction(m_Up, new JumpCommand());
	InputManager::GetInstance().AddInputAction(m_Down, new DownCommand());
	InputManager::GetInstance().AddInputAction(m_Fire, new FireCommand());
}

void Valdese::ControllerComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	SDL_Rect EndRect;
	EndRect = GetGameObject()->GetComponent<RenderComponent>()->GetDestRect();
	EndRect.x += (int)GetTransform()->GetPosition().x;
	EndRect.y += (int)GetTransform()->GetPosition().y;

	m_pCollider->SetBox(EndRect);

	HandleInput();
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
}

void Valdese::ControllerComponent::Draw() const
{

}

void Valdese::ControllerComponent::DebugDraw() const
{
}

void Valdese::ControllerComponent::HandleInput()
{
	InputManager::GetInstance().IsPressed(m_Left, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Right, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Up, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Down, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Fire, *GetGameObject());
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
