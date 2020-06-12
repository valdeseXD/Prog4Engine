#include "MiniginPCH.h"
#include "PlayerComponent.h"
#include "InputManager.h"
#include "Command.h"
#include "InputManager.h"

Valdese::PlayerComponent::PlayerComponent(char left, char right, char up, char down, char fire)
	:m_pController(nullptr)
	, m_Left(left)
	, m_Right(right)
	, m_Up(up)
	, m_Down(down)
	, m_Fire(fire)
{
}

void Valdese::PlayerComponent::Initialize()
{
	m_pController = GetGameObject()->GetComponent<ControllerComponent>();
	if (m_pController == nullptr)
	{
		std::cout << "ERROR: No controller attached to player object" << std::endl;
	}

	InputManager::GetInstance().AddInputAction(m_Left, new LeftCommand());
	InputManager::GetInstance().AddInputAction(m_Right, new RightCommand());
	InputManager::GetInstance().AddInputAction(m_Up, new JumpCommand());
	InputManager::GetInstance().AddInputAction(m_Down, new DownCommand());
	InputManager::GetInstance().AddInputAction(m_Fire, new FireCommand());
}

void Valdese::PlayerComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	HandleInput();
}

void Valdese::PlayerComponent::Draw() const
{
}

void Valdese::PlayerComponent::DebugDraw() const
{
}

void Valdese::PlayerComponent::HandleInput()
{
	InputManager::GetInstance().IsPressed(m_Left, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Right, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Up, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Down, *GetGameObject());
	InputManager::GetInstance().IsPressed(m_Fire, *GetGameObject());
}
