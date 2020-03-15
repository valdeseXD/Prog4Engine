#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "RenderComponent.h"


Valdese::GameObject::GameObject()
{
	m_pTransformComponent = new TransformComponent();
}

Valdese::GameObject::~GameObject()
{
	delete m_pTransformComponent;
	m_pTransformComponent = nullptr;

	for (BaseComponent* pComp : m_pComponents)
	{
		delete pComp;
	}

}

void Valdese::GameObject::AddComponent(BaseComponent* pComp)
{
	m_pComponents.push_back(pComp);
	pComp->m_pGameObject = this;
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
	pComp->m_pGameObject = nullptr;
}

void Valdese::GameObject::Update()
{
	for (BaseComponent* pComp : m_pComponents)
	{
		pComp->Update();
	}
}

void Valdese::GameObject::Draw() const
{
	for (BaseComponent* pComp : m_pComponents)
	{
		pComp->Draw();
	}
}

void Valdese::GameObject::SetPosition(float x, float y)
{
	m_pTransformComponent->SetPosition(x, y);
}
