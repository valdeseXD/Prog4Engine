#include "MiniginPCH.h"
#include "GameObject.h"
#include "ResourceManager.h"
#include "Renderer.h"

Valdese::GameObject::GameObject()
{
	m_pTransformComponent = new TransformComponent();
}

Valdese::GameObject::~GameObject()
{
	delete m_pTransformComponent;
	m_pTransformComponent = nullptr;
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

void Valdese::GameObject::Update(){}

void Valdese::GameObject::Render() const
{
	const auto pos = m_pTransformComponent->GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

void Valdese::GameObject::SetTexture(const std::string& filename)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
}

void Valdese::GameObject::SetPosition(float x, float y)
{
	m_pTransformComponent->SetPosition(x, y);
}
