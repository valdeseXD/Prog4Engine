#pragma once
#include "TransformComponent.h"
#include "SceneObject.h"

namespace Valdese
{
	class Texture2D;
	class GameObject : public SceneObject
	{
	public:
		void Update() override;
		void Render() const override;

		void SetTexture(const std::string& filename);
		void SetPosition(float x, float y);

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		TransformComponent* GetTransform() const { return m_pTransformComponent; }

	private:
		TransformComponent* m_pTransformComponent;
		std::shared_ptr<Texture2D> m_Texture{};
	};
}
