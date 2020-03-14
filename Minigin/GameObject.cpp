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
