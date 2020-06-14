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

void Valdese::Scene::Remove(GameObject* pObject)
{
	auto objectToDelete = find(m_Objects.begin(), m_Objects.end(), pObject);

	if (objectToDelete == m_Objects.end())
	{
		std::cout << "this gameObject is not in the scene" << std::endl;
		return;
	}
	
	m_Objects.erase(objectToDelete);
	SafeDelete(pObject);
}

void Scene::Update(float elapsedSec)
{
	//for(auto& object : m_Objects)
	//{
	//	object->Update(elapsedSec);
	//}

	for (UINT i = 0; i < m_Objects.size(); i++)
	{
		m_Objects[i]->Update(elapsedSec);
	}
}

void Scene::Render() const
{
	for (const auto& object : m_Objects)
	{
		object->Draw();
#ifdef _DEBUG
		object->DebugDraw();
#endif // DEBUG

	}
}

