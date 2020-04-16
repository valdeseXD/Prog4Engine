#pragma once
#include "SceneManager.h"

namespace Valdese
{
	class SceneObject;
	class Scene
	{
		friend Scene& SceneManager::CreateScene(const std::string& name);
	public:
		void Add(SceneObject& object);


		virtual void Update(float elapsedSec);
		void Render() const;

		virtual ~Scene();
		Scene(const Scene& other) = delete;
		Scene(Scene&& other) = delete;
		Scene& operator=(const Scene& other) = delete;
		Scene& operator=(Scene&& other) = delete;

	protected: 
		explicit Scene(const std::string& name);

		std::string m_Name;
		std::vector<SceneObject*> m_Objects{};

		static unsigned int m_IdCounter; 
	};

}
