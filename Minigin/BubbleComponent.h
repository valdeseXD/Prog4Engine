#pragma once
#include "BaseComponent.h"
#pragma warning(push)
#pragma warning (disable:4201)
#include "glm/vec2.hpp"
#pragma warning(pop)

namespace Valdese
{
	class ControllerComponent;
	class BubbleComponent : public BaseComponent
	{
	public:
		BubbleComponent() = default;
		virtual ~BubbleComponent() = default;
		BubbleComponent(const BubbleComponent& other) = delete;
		BubbleComponent(BubbleComponent&& other) = delete;
		BubbleComponent& operator=(const BubbleComponent& other) = delete;
		BubbleComponent& operator=(BubbleComponent&& other) = delete;


		void Initialize();
		void Update(float elapsedSec) override;
		void Draw() const override;
		void DebugDraw() const override;

	private:
		ControllerComponent* m_pController = nullptr;

		glm::vec2 m_BubbleForce;
		float m_ShootTime = 5.0f;
		float m_LifeTime = 15.0f;
	};
}

