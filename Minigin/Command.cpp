#include "MiniginPCH.h"
#include "Command.h"
#include "ControllerComponent.h"

void Valdese::LeftCommand::execute(GameObject& gameObject)
{
	ControllerComponent* controller = gameObject.GetComponent<ControllerComponent>();
	if (controller != nullptr)
	{
		controller->AddForce({ -100.0f, 0.0f });
	}
}

void Valdese::RightCommand::execute(GameObject& gameObject)
{
	ControllerComponent* controller = gameObject.GetComponent<ControllerComponent>();
	if (controller != nullptr)
	{
		controller->AddForce({ 100.0f, 0.0f });
	}
}

void Valdese::JumpCommand::execute(GameObject& gameObject)
{
	ControllerComponent* controller = gameObject.GetComponent<ControllerComponent>();
	if (controller != nullptr)
	{
		controller->Jump();
	}
}

void Valdese::DownCommand::execute(GameObject& gameObject)
{
	UNREFERENCED_PARAMETER(gameObject);
	//ControllerComponent* controller = gameObject.GetComponent<ControllerComponent>();
	//if (controller != nullptr)
	//{
	//	controller->AddForce({ 0.0f, 1000.0f });
	//}
}

void Valdese::FireCommand::execute(GameObject& gameObject)
{
	ControllerComponent* controller = gameObject.GetComponent<ControllerComponent>();
	if (controller != nullptr)
	{
		controller->Fire();
	}
}
