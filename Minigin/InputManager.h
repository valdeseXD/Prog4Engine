#pragma once
#include <XInput.h>
#include "Singleton.h"
#include <map>
#include "GameObject.h"

namespace Valdese
{
	enum class ControllerButton
	{
		ButtonA,
		ButtonB,
		ButtonX,
		ButtonY
	};
	class Command;

	class InputManager final : public Singleton<InputManager>
	{
	public:
		~InputManager();
		bool ProcessInput();
		bool IsPressed(ControllerButton button) const;
		bool IsPressed(char key, GameObject& actor);
		void AddInputAction(char key, Command* command);
	private:
		std::map <char, Command*> m_pCommands;
		XINPUT_STATE m_CurrentState{};
	};

}
