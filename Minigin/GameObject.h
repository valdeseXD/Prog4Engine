#pragma once
#include "TransformComponent.h"
#include "SceneObject.h"

namespace Valdese
{
	class Texture2D;
	class GameObject : public SceneObject
	{
	public:
		void Update(float elapsedSec) override;
		void Draw() const override;

		void SetPosition(float x, float y);

		GameObject();
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		TransformComponent* GetTransform() const { return m_pTransformComponent; }


		//COMPONENTS

		void AddComponent(BaseComponent* pComp);
		void RemoveComponent(BaseComponent* pComp);

		template <class T>
		bool HasComponent()
		{
			return GetComponent<T>();
		}

		template <class T>
		T* GetComponent()
		{
			const type_info& ti = typeid(T);
			for (auto* component : m_pComponents)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}
			return nullptr;
		}

	private:
		std::vector<BaseComponent*> m_pComponents;

		TransformComponent* m_pTransformComponent;
	};
}
