#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "RenderComponent.h"

Valdese::GameObject::GameObject()
{
	m_pTransformComponent = new TransformComponent();
	m_IsActive = true;
	m_pComponents.push_back(m_pTransformComponent);
}

Valdese::GameObject::~GameObject()
{

	for (BaseComponent* pComp : m_pComponents)
	{
		SafeDelete(pComp);
	}
}

void Valdese::GameObject::AddComponent(BaseComponent* pComp)
{
	m_pComponents.push_back(pComp);
	pComp->SetGameObject(this);
	pComp->Initialize();
}

void Valdese::GameObject::RemoveComponent(BaseComponent* pComp)
{
	auto componentToDelete = find(m_pComponents.begin(), m_pComponents.end(), pComp);

	if (componentToDelete == m_pComponents.end())
	{
		std::cout << "this gameObject doesn't have the right component" << std::endl;
		return;
	}

	if (typeid(*pComp) == typeid(TransformComponent))
	{
		std::cout << "TransformComponent can't be removed!" << std::endl;
		return;
	}

	m_pComponents.erase(componentToDelete);
	pComp->SetGameObject(nullptr);
}

void Valdese::GameObject::Update(float elapsedSec)
{
	if (m_IsActive)
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->Update(elapsedSec);
		}
	}
}

void Valdese::GameObject::Draw() const
{
	if (m_IsActive)
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->Draw();
		}
	}
}

void Valdese::GameObject::DebugDraw() const
{
	if (m_IsActive)
	{
		for (BaseComponent* pComp : m_pComponents)
		{
			pComp->DebugDraw();
		}
	}
}

void Valdese::GameObject::SetPosition(float x, float y)
{
	m_pTransformComponent->SetPosition(x, y);
}
