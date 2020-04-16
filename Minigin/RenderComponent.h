#pragma once
#include "BaseComponent.h"



namespace Valdese
{
	class Texture2D;
	class Font;

	class RenderComponent : public BaseComponent
	{
	public:
		RenderComponent();
		virtual ~RenderComponent();
		RenderComponent(const RenderComponent& other) = delete;
		RenderComponent(RenderComponent&& other) = delete;
		RenderComponent& operator=(const RenderComponent& other) = delete;
		RenderComponent& operator=(RenderComponent&& other) = delete;

		void Initialize();
		void Update(float elapsedSec);
		void Draw();

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
	private:
		Texture2D* m_pTexture;
	};
}


