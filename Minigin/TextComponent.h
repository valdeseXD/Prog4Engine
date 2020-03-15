#pragma once
#include "BaseComponent.h"



namespace Valdese
{
	class Texture2D;
	class Font;

	class TextComponent : public BaseComponent
	{
	public:
		TextComponent(const std::string& text, Font* font);
		virtual ~TextComponent() = default;
		TextComponent(const TextComponent& other) = delete;
		TextComponent(TextComponent&& other) = delete;
		TextComponent& operator=(const TextComponent& other) = delete;
		TextComponent& operator=(TextComponent&& other) = delete;


		void Initialize();
		void Update();
		void Draw();

		void SetTexture(const std::string& filename);

		void SetText(const std::string& text);
	private:
		Texture2D* m_pTexture;

		bool m_NeedsUpdate;
		std::string m_Text;
		Font* m_pFont;
	};
}

