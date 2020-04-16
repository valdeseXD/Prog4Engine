#pragma once
#include "Scene.h"

namespace Valdese
{
	class GameObject;
	class DemoScene : public Scene
	{
	public:

		void Initialize();
		void Update(float elapsedSec) override;
		void Render() const;

		DemoScene();
		virtual ~DemoScene();
		DemoScene(const DemoScene& other) = delete;
		DemoScene(DemoScene&& other) = delete;
		DemoScene& operator=(const DemoScene& other) = delete;
		DemoScene& operator=(DemoScene&& other) = delete;

	private:
		GameObject* m_FPS;
	};
}

