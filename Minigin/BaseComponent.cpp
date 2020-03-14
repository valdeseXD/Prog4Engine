#include "MiniginPCH.h"
#include "BaseComponent.h"
#include "GameObject.h"

Valdese::BaseComponent::BaseComponent()
	: m_pGameObject(nullptr)
{

}

Valdese::TransformComponent* Valdese::BaseComponent::GetTransform() const
{
	if (m_pGameObject == nullptr)
	{
		std::cout << "BaseComponent::GetTransform() > Failed to retrieve the TransformComponent. GameObject is NULL." << std::endl;
		return nullptr;
	}
	return m_pGameObject->GetTransform();
}