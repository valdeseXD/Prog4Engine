#include "MiniginPCH.h"
#include "Minigin.h"
#include <chrono>
#include <thread>
#include "InputManager.h"
#include "SceneManager.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <SDL.h>
#include "TextObject.h"
#include "GameObject.h"
#include "Scene.h"
#include "RenderComponent.h"
#include "TextComponent.h"

using namespace std;
using namespace std::chrono;

void Valdese::Minigin::Initialize()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) 
	{
		throw std::runtime_error(std::string("SDL_Init Error: ") + SDL_GetError());
	}

	m_Window = SDL_CreateWindow(
		"Programming 4 assignment",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		640,
		480,
		SDL_WINDOW_OPENGL
	);
	if (m_Window == nullptr) 
	{
		throw std::runtime_error(std::string("SDL_CreateWindow Error: ") + SDL_GetError());
	}

	Renderer::GetInstance().Init(m_Window);
}

/**
 * Code constructing the scene world starts here
 */
void Valdese::Minigin::LoadGame() const
{
	auto& scene = SceneManager::GetInstance().CreateScene("Demo");

	GameObject* go = new GameObject();
	go->AddComponent(new RenderComponent());
	go->GetComponent<RenderComponent>()->SetTexture("background.jpg");
	scene.Add(*go);

	go = new GameObject();
	go->AddComponent(new RenderComponent());
	go->GetComponent<RenderComponent>()->SetTexture("logo.png");
	go->GetTransform()->SetPosition(216, 180);
	scene.Add(*go);

	go = new GameObject();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComp = new TextComponent("Programming 4 Assignment", font);
	go->AddComponent(textComp);
	go->GetTransform()->SetPosition(80, 20);
	scene.Add(*go);

	go = new GameObject();
	textComp = new TextComponent("FPS: ", font);
	go->AddComponent(textComp);
	go->GetTransform()->SetPosition(0, 80);
	scene.Add(*go);
}

void Valdese::Minigin::Cleanup()
{
	Renderer::GetInstance().Destroy();
	SDL_DestroyWindow(m_Window);
	m_Window = nullptr;
	SDL_Quit();
}

void Valdese::Minigin::Run()
{
	Initialize();

	// tell the resource manager where he can find the game data
	ResourceManager::GetInstance().Init("../Data/");

	LoadGame();

	{
		auto& renderer = Renderer::GetInstance();
		auto& sceneManager = SceneManager::GetInstance();
		auto& input = InputManager::GetInstance();

		bool doContinue = true;
		while (doContinue)
		{
			const auto currentTime = high_resolution_clock::now();
			
			doContinue = input.ProcessInput();
			sceneManager.Update();
			renderer.Render();
			
			auto sleepTime = duration_cast<duration<float>>(currentTime + milliseconds(MsPerFrame) - high_resolution_clock::now());
			this_thread::sleep_for(sleepTime);
		}
	}

	Cleanup();
}
