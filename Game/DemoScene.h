#pragma once
#include "Scene.h"

namespace Valdese
{
	class GameObject;
	class DemoScene : public Scene
	{
	public:
		//void Add(SceneObject& object);

		void Initialize();
		void Update(float elapsedSec) override;
		void Render() const;

		DemoScene();
		~DemoScene();
		DemoScene(const DemoScene& other) = delete;
		DemoScene(DemoScene&& other) = delete;
		DemoScene& operator=(const DemoScene& other) = delete;
		DemoScene& operator=(DemoScene&& other) = delete;

	private:

		std::string m_Name;
		std::vector<SceneObject*> m_Objects{};

		static unsigned int m_IdCounter;

		GameObject* m_FPS;
	};
}

