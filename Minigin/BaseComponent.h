#pragma once

namespace Valdese
{
	class GameObject;
	class TransformComponent;

	class BaseComponent
	{
		friend class GameObject;

	public:
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) noexcept = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) noexcept = delete;
		BaseComponent();
		virtual ~BaseComponent() = default;

		GameObject* GetGameObject() const { return m_pGameObject; }
		TransformComponent* GetTransform() const;


	protected:

		virtual void Initialize() = 0;
		virtual void Update(float elapsedSec) = 0;
		virtual void Draw() = 0;

		GameObject* m_pGameObject;
	};
}

