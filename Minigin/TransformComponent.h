#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)
#include "BaseComponent.h"

namespace Valdese
{
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent(glm::vec2 position = { 0,0 });
		glm::vec2& GetPosition() { return m_Position; }
		void SetPosition(float x, float y);

		void Initialize();
		void Update();
		void Draw();

	private:
		glm::vec2 m_Position;
	};
}
