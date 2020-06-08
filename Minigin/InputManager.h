#pragma once
#include <XInput.h>
#include "Singleton.h"

namespace Valdese
{
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY
	};

	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
		bool IsPressed(ControllerButton button) const;
		bool IsPressed(char key) const;
	private:
		XINPUT_STATE m_CurrentState{};
	};

}
