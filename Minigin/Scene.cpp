#include "MiniginPCH.h"
#include "Scene.h"
#include "GameObject.h"
#include "SceneObject.h"

using namespace Valdese;

unsigned int Scene::m_IdCounter = 0;

Scene::Scene(const std::string& name) : m_Name(name)
{}

Scene::~Scene()
{
	for (GameObject* pObj : m_Objects)
	{
		SafeDelete(pObj);
	}
}

void Valdese::Scene::Add(GameObject& object)
{
	m_Objects.push_back(&object);
}

void Scene::Update(float elapsedSec)
{
	for(auto& object : m_Objects)
	{
		object->Update(elapsedSec);
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Draw();
	}
}

