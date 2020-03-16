#pragma once
#include "Scene.h"

namespace Valdese
{
	class DemoScene : public Scene
	{
	public:
		void Add(SceneObject& object);

		void Initialize();
		void Update();
		void Render() const;

		~DemoScene();
		DemoScene(const DemoScene& other) = delete;
		DemoScene(DemoScene&& other) = delete;
		DemoScene& operator=(const DemoScene& other) = delete;
		DemoScene& operator=(DemoScene&& other) = delete;
		explicit DemoScene(const std::string& name);

	private:

		std::string m_Name;
		std::vector<SceneObject*> m_Objects{};

		static unsigned int m_IdCounter;
	};
}

