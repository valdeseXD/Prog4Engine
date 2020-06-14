#pragma once
#include "BaseComponent.h"
#pragma warning(push)
#pragma warning (disable:4201)
#include "glm/vec2.hpp"
#pragma warning(pop)

namespace Valdese
{

	enum class Side
	{
		Player,
		Enemy,
		EnemyVulnerable
	};
	class TransformComponent;
	class ColliderComponent;
	class ControllerComponent :
		public BaseComponent
	{
		public:
			ControllerComponent(Side side);
			virtual ~ControllerComponent() = default;
			ControllerComponent(const ControllerComponent& other) = delete;
			ControllerComponent(ControllerComponent&& other) = delete;
			ControllerComponent& operator=(const ControllerComponent& other) = delete;
			ControllerComponent& operator=(ControllerComponent&& other) = delete;


			void Initialize();
			void Update(float elapsedSec) override;
			void Draw() const override;
			void DebugDraw() const override;


			void Move(int x, int y);

			glm::vec2 GetForce() { return m_Force; }
			void AddForce(glm::vec2 force);
			void SetForce(glm::vec2 force);

			void SetGravity(bool enable) { m_GravityEnabled = enable; }

			void CheckCollision();

			void Jump();
			void SetJumping(bool b) { m_IsJumping = b; }

			void Fire();

			Side GetSide() { return m_Side; }
		private:
			TransformComponent* m_pTransform;
			ColliderComponent* m_pCollider;
			glm::vec2 m_Force;
			bool m_GravityEnabled = true;
			bool m_IsJumping = false;
			Side m_Side;

			float m_FireCooldown = 2.0f;
			float m_ElapsedFireCooldown = 0.0f;
	};
}

