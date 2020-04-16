#include "MiniginPCH.h"
#include <SDL.h>
#include <SDL_ttf.h>

#include "Font.h"
#include "Texture2D.h"
#include "TextComponent.h"
#include "ResourceManager.h"
#include "Renderer.h"
#include "TransformComponent.h"

Valdese::TextComponent::TextComponent(const std::string& text, Font* font)
	:m_pTexture(nullptr)
	, m_Text(text)
	, m_pFont(font)
	, m_NeedsUpdate(true)
{
}

Valdese::TextComponent::~TextComponent()
{
	SafeDelete(m_pTexture);
	SafeDelete(m_pFont);
}

void Valdese::TextComponent::Initialize()
{
}

void Valdese::TextComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);

	if (m_NeedsUpdate)
	{
		const SDL_Color color = { 255,255,255 }; // only white text is supported now
		const auto surf = TTF_RenderText_Blended(m_pFont->GetFont(), m_Text.c_str(), color);
		if (surf == nullptr)
		{
			throw std::runtime_error(std::string("Render text failed: ") + SDL_GetError());
		}
		auto texture = SDL_CreateTextureFromSurface(Renderer::GetInstance().GetSDLRenderer(), surf);
		if (texture == nullptr)
		{
			throw std::runtime_error(std::string("Create text texture from surface failed: ") + SDL_GetError());
		}
		SDL_FreeSurface(surf);
		SafeDelete(m_pTexture);

		m_pTexture = new Texture2D(texture);
		m_NeedsUpdate = false;
	}
}

void Valdese::TextComponent::Draw()
{
	if (m_pTexture != nullptr)
	{
		auto pos = GetTransform()->GetPosition();
		Renderer::GetInstance().RenderTexture(*m_pTexture, pos.x, pos.y);
	}
}

void Valdese::TextComponent::SetText(const std::string& text)
{
	m_Text = text;
	m_NeedsUpdate = true;
}