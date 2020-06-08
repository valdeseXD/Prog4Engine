#include "MiniginPCH.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"
#include "Texture2D.h"
#include "SDL_image.h"

Valdese::RenderComponent::RenderComponent(const std::string& filename)
	:BaseComponent()
	,m_pTexture(nullptr)
{
	m_pTexture = ResourceManager::GetInstance().LoadTexture(filename);

	int width;
	int height;
	SDL_QueryTexture(m_pTexture->GetSDLTexture(), nullptr, nullptr, &width, &height);
	m_SourceRect = { 0, 0, width, height };
	m_DestRect = { 0,0, width, height };
}

Valdese::RenderComponent::~RenderComponent()
{
	SafeDelete(m_pTexture);
}

void Valdese::RenderComponent::Initialize()
{
}

void Valdese::RenderComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
}

void Valdese::RenderComponent::Draw()
{	
	if (m_pTexture != nullptr)
	{
		Renderer::GetInstance().RenderTexture(*m_pTexture, m_SourceRect, m_DestRect);
	}
}

void Valdese::RenderComponent::SetPosition(const float x, const float y)
{
	m_DestRect.x = (int)x;
	m_DestRect.y = (int)y;
}
