#pragma once

namespace Valdese
{
	class GameObject;
	class TransformComponent;

	class BaseComponent abstract
	{

	public:
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;
		BaseComponent();
		virtual ~BaseComponent() = default;

		GameObject* GetGameObject() const { return m_pGameObject; }
		void SetGameObject(GameObject* gameObject) { m_pGameObject = gameObject; }
		TransformComponent* GetTransform() const;


		virtual void Initialize() = 0;
		virtual void Update(float elapsedSec) = 0;
		virtual void Draw() const = 0;
	protected:

		GameObject* m_pGameObject;
	};
}

