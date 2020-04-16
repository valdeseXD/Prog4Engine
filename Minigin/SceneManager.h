#pragma once
#include "Singleton.h"

namespace Valdese
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);
		void AddScene(Scene* pScene);
		void Update(float elapsedSec);
		void Render();
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		~SceneManager();
		std::vector<Scene*> m_pScenes;
	};
}