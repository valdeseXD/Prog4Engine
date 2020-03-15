#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"

void Valdese::RenderComponent::Initialize()
{
}

void Valdese::RenderComponent::Update()
{
}

void Valdese::RenderComponent::Draw()
{	
	if (m_pTexture != nullptr)
	{
		auto pos = GetTransform()->GetPosition();	
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void Valdese::RenderComponent::SetTexture(const std::string& filename)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);
}
void Valdese::RenderComponent::SetPosition(const float x, const float y)
{
	GetTransform()->SetPosition(x, y);
}
