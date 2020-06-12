#pragma once
#include "BaseComponent.h"
namespace Valdese
{
	class ControllerComponent;
	class PlayerComponent : public BaseComponent
	{
	public:
		PlayerComponent(char left = 0, char right = 0, char up = 0, char down = 0, char fire = 0);
		virtual ~PlayerComponent() = default;
		PlayerComponent(const PlayerComponent& other) = delete;
		PlayerComponent(PlayerComponent&& other) = delete;
		PlayerComponent& operator=(const PlayerComponent& other) = delete;
		PlayerComponent& operator=(PlayerComponent&& other) = delete;


		void Initialize();
		void Update(float elapsedSec) override;
		void Draw() const override;
		void DebugDraw() const override;

		void HandleInput();
	private:
		ControllerComponent* m_pController;
		char m_Left, m_Right, m_Up, m_Down, m_Fire;
	};
}
