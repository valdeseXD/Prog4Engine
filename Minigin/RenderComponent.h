#pragma once
#include "BaseComponent.h"



namespace Valdese
{
	class Texture2D;
	class Font;

	class RenderComponent : public BaseComponent
	{
	public:
		void Initialize();
		void Update();
		void Draw();

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);
	private:
		Texture2D* m_pTexture;
	};
}


