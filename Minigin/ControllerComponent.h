#pragma once
#include "BaseComponent.h"
#pragma warning(push)
#pragma warning (disable:4201)
#include "glm/vec2.hpp"
#pragma warning(pop)

namespace Valdese
{
	class TransformComponent;
	class ColliderComponent;
	class ControllerComponent :
		public BaseComponent
	{
		public:
			ControllerComponent(char left = 0, char right = 0, char up = 0, char down = 0, char fire = 0);
			virtual ~ControllerComponent() = default;
			ControllerComponent(const ControllerComponent& other) = delete;
			ControllerComponent(ControllerComponent&& other) = delete;
			ControllerComponent& operator=(const ControllerComponent& other) = delete;
			ControllerComponent& operator=(ControllerComponent&& other) = delete;


			void Initialize();
			void Update(float elapsedSec) override;
			void Draw() const override;
			void DebugDraw() const override;

			void HandleInput();

			void Move(int x, int y);

			glm::vec2 GetForce() { return m_Force; }
			void AddForce(glm::vec2 force);
			void SetForce(glm::vec2 force);

			void SetGravity(bool enable) { m_GravityEnabled = enable; }

			void CheckCollision();

			void Jump();
			void SetJumping(bool b) { m_IsJumping = b; }
		private:
			TransformComponent* m_pTransform;
			ColliderComponent* m_pCollider;
			glm::vec2 m_Force;
			char m_Left, m_Right, m_Up, m_Down, m_Fire;
			bool m_GravityEnabled = true;
			bool m_IsJumping = false;
	};
}

