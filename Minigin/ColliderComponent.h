#pragma once
#include "BaseComponent.h"
#include "SDL_image.h"
#pragma warning(push)
#pragma warning (disable:4201)
#include "glm/vec2.hpp"
#pragma warning(pop)

namespace Valdese
{
	enum class CollisionSide
	{
		Top,
		Bottom,
		Left,
		Right,
		None
	};
	class ColliderComponent :
		public BaseComponent
	{
	public:
		ColliderComponent() = default;
		virtual ~ColliderComponent() = default;
		ColliderComponent(const ColliderComponent& other) = delete;
		ColliderComponent(ColliderComponent&& other) = delete;
		ColliderComponent& operator=(const ColliderComponent& other) = delete;
		ColliderComponent& operator=(ColliderComponent&& other) = delete;

		SDL_Rect GetBox() { return m_Box; }
		void Initialize();
		void Update(float elapsedSec);
		void Draw() const override;
		void DebugDraw() const override;

		void CheckCollision();
		bool IsColliding(SDL_Rect otherCollider);
		bool IsTopCollision(SDL_Rect otherCollider);
		bool IsLeftCollision(SDL_Rect otherCollider);
		bool IsRightCollision(SDL_Rect otherCollider);

		void CheckCollisionSide(SDL_Rect otherBox);
		void SetBox(SDL_Rect box);
		void UpdateBox(int x, int y, int width = 0, int height = 0);
	private:
		SDL_Rect m_Box = {0, 0, 0, 0};
		CollisionSide m_VerticalCollisionSide;
		CollisionSide m_HorizontalCollisionSide;

		SDL_Rect m_BoxCollision;
		int m_HorizontalCollisionDifference = 0;
	};

}