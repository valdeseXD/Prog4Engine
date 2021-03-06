#pragma once
#include "SceneManager.h"

namespace Valdese
{
	class GameObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(GameObject& object);
		void Remove(GameObject* pObject);

		virtual void Update(float elapsedSec);
		void Render() const;
		std::vector<GameObject*> GetObjects() { return m_Objects; }

		virtual ~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;
	protected: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector<GameObject*> m_Objects{};

		static unsigned int m_IdCounter; 
	};

}
