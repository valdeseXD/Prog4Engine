#include "MiniginPCH.h"
#include "DemoScene.h"
#include "GameObject.h"
#include "ResourceManager.h"	
#include "RenderComponent.h"
#include "TextComponent.h"
#include "FPSComponent.h"
#include <string>
#include "BinaryReader.h"
#include "ControllerComponent.h"
#include "ColliderComponent.h"
#include "PlayerComponent.h"

void Valdese::DemoScene::Initialize()
{
	GameObject* go = new GameObject();
	go->AddComponent(new RenderComponent("background.jpg"));
	Add(*go);

	go = new GameObject();
	go->AddComponent(new RenderComponent("logo.png"));
	go->GetTransform()->SetPosition(216, 180);
	Add(*go);

	go = new GameObject();
	auto font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	auto textComp = new TextComponent("Programming 4 Assignment", font);
	go->AddComponent(textComp);
	go->GetTransform()->SetPosition(80, 20);
	Add(*go);

	go = new GameObject();
	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	textComp = new TextComponent("FPS: ", font);
	go->AddComponent(textComp);
	go->GetTransform()->SetPosition(0, 80);
	Add(*go);

	m_FPS = new GameObject();
	font = ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	textComp = new TextComponent("0", font);
	m_FPS->AddComponent(textComp);
	m_FPS->AddComponent(new FPSComponent());
	m_FPS->GetTransform()->SetPosition(80, 80);
	Add(*m_FPS);

	m_pPlayer = new GameObject();
	auto playerModel = new RenderComponent("Character.png");
	m_pPlayer->GetTransform()->SetPosition(100, 100);
	playerModel->SetWidth(40);
	playerModel->SetHeight(40);
	m_pPlayer->AddComponent(playerModel);
	m_pPlayer->AddComponent(new ColliderComponent(ColliderState::Character));
	m_pPlayer->AddComponent(new ControllerComponent(Side::Player));
	m_pPlayer->AddComponent(new PlayerComponent('A', 'D', 'W', 'S', ' '));
	Add(*m_pPlayer);


	auto enemy = new GameObject();
	auto enemyModel = new RenderComponent("Zen-chan.png");
	enemy->GetTransform()->SetPosition(200, 100);
	enemyModel->SetWidth(40);
	enemyModel->SetHeight(40);
	enemy->AddComponent(enemyModel);
	enemy->AddComponent(new ColliderComponent(ColliderState::Character));
	enemy->AddComponent(new ControllerComponent(Side::Enemy));
	Add(*enemy);

	m_pLevels = BinaryReader::GetInstance().ReadLevelData();
	for (int i = 0; i < m_pLevels.size(); i++)
	{
		m_pLevels[i]->SetActive(false);
		Add(*m_pLevels[i]);
	}
	m_pLevels[0]->SetActive(true);
}

void Valdese::DemoScene::Update(float elapsedSec)
{
	if (m_FPS != nullptr)
	{
		m_FPS->GetComponent<TextComponent>()->SetText(std::to_string(m_FPS->GetComponent<FPSComponent>()->GetFPS()));
	}

	Scene::Update(elapsedSec);
}

void Valdese::DemoScene::Render() const
{
}

Valdese::DemoScene::~DemoScene()
{
	Scene::~Scene();
}

Valdese::DemoScene::DemoScene()
	:Scene("DemoScene")
{
	Initialize();
}
