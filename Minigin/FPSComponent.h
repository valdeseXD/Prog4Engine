#pragma once
#include "BaseComponent.h"

namespace Valdese
{
	class FPSComponent : public BaseComponent
	{
	public:
		FPSComponent() = default;
		virtual ~FPSComponent() = default;
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;


		void Initialize();
		void Update(float elapsedSec);
		void Draw();

		int GetFPS() { return m_FPS; }
	private:
		int m_FPS = 0;
	};
}