#pragma once
#pragma warning(push)
#pragma warning (disable:4201)
#include "vector2.h"
#pragma warning(pop)
#include "BaseComponent.h"

namespace Valdese
{
	class TransformComponent : public BaseComponent
	{
	public:
		TransformComponent(math::vector2 position = { 0,0 });
		 math::vector2& GetPosition() { return m_Position; }
		void SetPosition(float x, float y);

		void Initialize();
		void Update(float elapsedSec);
		void Draw();

	private:
		math::vector2 m_Position;
	};
}
