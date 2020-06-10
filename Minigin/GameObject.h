#pragma once
#include "BaseComponent.h"
#include "TransformComponent.h"
#include "SceneObject.h"
#include "Scene.h"

namespace Valdese
{
	class Texture2D;
	class GameObject final : public SceneObject
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
		void SetActive(bool active) { m_IsActive = active; }
		bool IsActive() const { return m_IsActive; }
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
			for (auto component : m_pComponents)
			{
				if (component && typeid(*component) == ti)
					return static_cast<T*>(component);
			}
			return nullptr;
		}

		template <class T>
		std::vector<T*> GetComponents()
		{
			const type_info& ti = typeid(T);
			std::vector<T*> components;

			for (auto* component : m_pComponents)
			{
				if (component && typeid(*component) == ti)
					components.push_back(static_cast<T*>(component));
			}
			return components;
		}

	private:
		std::vector<BaseComponent*> m_pComponents;

		TransformComponent* m_pTransformComponent;
		bool m_IsActive;
	};
}
