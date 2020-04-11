#include "MiniginPCH.h"
#include "DemoScene.h"
#include "GameObject.h"
#include "ResourceManager.h"	
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include <string>

//void Valdese::DemoScene::Add(SceneObject& object)
//{
//	UNREFERENCED_PARAMETER(object);
//}

void Valdese::DemoScene::Initialize()
{
	GameObject* go = new GameObject();
	go->AddComponent(new RenderComponent());
	go->GetComponent<RenderComponent>()->SetTexture("background.jpg");
	Add(*go);

	go = new GameObject();
	go->AddComponent(new RenderComponent());
	go->GetComponent<RenderComponent>()->SetTexture("logo.png");
	go->GetTransform()->SetPosition(216, 180);
	Add(*go);

	go = new GameObject();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComp = new TextComponent("Programming 4 Assignment", font);
	go->AddComponent(textComp);
	go->GetTransform()->SetPosition(80, 20);
	Add(*go);

	go = new GameObject();
	textComp = new TextComponent("FPS: ", font);
	go->AddComponent(textComp);
	go->GetTransform()->SetPosition(0, 80);
	Add(*go);

	m_FPS = new GameObject();
	textComp = new TextComponent("0", font);
	m_FPS->AddComponent(textComp);
	m_FPS->AddComponent(new FPSComponent());
	m_FPS->GetTransform()->SetPosition(80, 80);
	Add(*m_FPS);

}

void Valdese::DemoScene::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
	m_FPS->GetComponent<TextComponent>()->SetText(std::to_string(m_FPS->GetComponent<FPSComponent>()->GetFPS()));

	Scene::Update(elapsedSec);
}

void Valdese::DemoScene::Render() const
{
}

Valdese::DemoScene::~DemoScene()
{
}

Valdese::DemoScene::DemoScene()
	:Scene("DemoScene")
{
	Initialize();
}
