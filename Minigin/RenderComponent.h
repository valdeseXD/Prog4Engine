#pragma once
#include "BaseComponent.h"



namespace Valdese
{
	class RenderComponent : public BaseComponent
	{
		void Initialize() = 0;
		void Update() = 0;
		void Draw() = 0;

	private:

	};
}


