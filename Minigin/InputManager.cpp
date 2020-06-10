#include "MiniginPCH.h"
#include "InputManager.h"
#include <SDL.h>
#include "Command.h"

Valdese::InputManager::~InputManager()
{
	//https://stackoverflow.com/questions/19970531/properly-destroying-pointers-in-an-stdmap
	for (std::map<char, Command*>::iterator itr = m_pCommands.begin(); itr != m_pCommands.end(); itr++)
	{
		delete (itr->second);
	}
}

bool Valdese::InputManager::ProcessInput()
{
	ZeroMemory(&m_CurrentState, sizeof(XINPUT_STATE));
	XInputGetState(0, &m_CurrentState);

	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			return false;
		}
		if (e.type == SDL_KEYDOWN) {
			
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			
		}
	}

	return true;
}

bool Valdese::InputManager::IsPressed(ControllerButton button) const
{
	switch (button)
	{
	case ControllerButton::ButtonA:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_A;
	case ControllerButton::ButtonB:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_B;
	case ControllerButton::ButtonX:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_X;
	case ControllerButton::ButtonY:
		return m_CurrentState.Gamepad.wButtons & XINPUT_GAMEPAD_Y;
	default: return false;
	}
}

bool Valdese::InputManager::IsPressed(char key, GameObject& actor)
{
	//http://www.cplusplus.com/forum/beginner/140654/
	if (GetAsyncKeyState(key) & 0x8000)
	{
		m_pCommands[key]->execute(actor);
		return true;
	}
	return false;
}

void Valdese::InputManager::AddInputAction(char key, Command* command)
{
	m_pCommands[key] = command;


}
