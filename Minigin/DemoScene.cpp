#include "MiniginPCH.h"
#include "DemoScene.h"
#include "GameObject.h"
#include "ResourceManager.h"	
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"

void Valdese::DemoScene::Add(SceneObject& object)
{
}

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

	go = new GameObject();
	textComp = new TextComponent("", font);
	go->AddComponent(textComp);
	go->AddComponent(new FPSComponent());
	go->GetTransform()->SetPosition(50, 80);
	Add(*go);

}

void Valdese::DemoScene::Update()
{
}

void Valdese::DemoScene::Render() const
{
}

Valdese::DemoScene::~DemoScene()
{
}

Valdese::DemoScene::DemoScene(const std::string& name)
{
}
