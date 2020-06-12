#pragma once
#include "BaseComponent.h"
#include <SDL_image.h>

namespace Valdese
{
	class Texture2D;

	class RenderComponent : public BaseComponent
	{
	public:
		RenderComponent(const std::string& filename);
		virtual ~RenderComponent();
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Initialize();
		void Update(float elapsedSec) override;
		void Draw() const override;
		void DebugDraw() const override;

		void SetPosition(float x, float y);
		void SetDestRect(SDL_Rect destRect) { m_DestRect = destRect; }
		void SetWidth(int width) { m_DestRect.w = width; }
		void SetHeight(int height) { m_DestRect.h = height; }

		SDL_Rect GetDestRect() { return m_DestRect; }
	private:
		Texture2D* m_pTexture;
		SDL_Rect m_SourceRect;
		SDL_Rect m_DestRect;
	};
}


