#include "MiniginPCH.h"
#include "SceneManager.h"
#include "Scene.h"

void Valdese::SceneManager::Update(float elapsedSec)
{
	for(auto& scene : m_pScenes)
	{
		scene->Update(elapsedSec);
	}
}

void Valdese::SceneManager::Render()
{
	for (const auto& scene : m_pScenes)
	{
		scene->Render();
	}
}

Valdese::Scene& Valdese::SceneManager::CreateScene(const std::string& name)
{
	const auto scene = new Scene(name);
	m_pScenes.push_back(scene);
	return *scene;
}

void Valdese::SceneManager::AddScene(Scene* pScene)
{
	if (pScene)
	{
		m_pScenes.push_back(pScene);
	}
	else
	{
		throw("scene was a nullpoiter");
	}
}


