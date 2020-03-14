#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include <glm/vec2.hpp>
#pragma warning(pop)
#include "BaseComponent.h"

namespace Valdese
{
	class TransformComponent final : public BaseComponent
	{
	public:
		const glm::vec2& GetPosition() const { return m_Position; }
		void SetPosition(float x, float y);

		void Initialize();
		void Update() = 0;
		void Draw() = 0;

	private:
		glm::vec2 m_Position;
	};
}
