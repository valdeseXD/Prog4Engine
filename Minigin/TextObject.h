#pragma once
#include "SceneObject.h"
#include "TransformComponent.h"

namespace Valdese
{
	class Font;
	class Texture2D;
	class TextObject final : public SceneObject
	{
	public:
		void Update() override;
		void Draw() const override;

		void SetText(const std::string& text);
		void SetPosition(float x, float y);

		explicit TextObject(const std::string& text, const std::shared_ptr<Font>& font);
		virtual ~TextObject() = default;
		TextObject(const TextObject& other) = delete;
		TextObject(TextObject&& other) = delete;
		TextObject& operator=(const TextObject& other) = delete;
		TextObject& operator=(TextObject&& other) = delete;
	private:
		bool m_NeedsUpdate;
		std::string m_Text;
		TransformComponent m_pTransformComponent;
		std::shared_ptr<Font> m_Font;
		std::shared_ptr<Texture2D> m_Texture;
	};
}
