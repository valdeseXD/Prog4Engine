#include "MiniginPCH.h"
#include "ColliderComponent.h"
#include "SceneManager.h"
#include "SceneObject.h"
#include "Scene.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "ControllerComponent.h"
#include "Renderer.h"

void Valdese::ColliderComponent::Initialize()
{
    m_Box = GetGameObject()->GetComponent<RenderComponent>()->GetDestRect();
}

void Valdese::ColliderComponent::Update(float elapsedSec)
{
	UNREFERENCED_PARAMETER(elapsedSec);
    glm::vec2 currentPos = GetTransform()->GetPosition();
    glm::vec2 lastPos = GetTransform()->GetPrevPosition();

    m_Box.x += (int)(currentPos.x - lastPos.x);
    m_Box.y += (int)(currentPos.y - lastPos.y);
}

void Valdese::ColliderComponent::Draw() const
{
}

void Valdese::ColliderComponent::DebugDraw() const
{
    //SDL_RenderFillRect(Renderer::GetInstance().GetSDLRenderer(), &m_Box);
}

void Valdese::ColliderComponent::CheckCollision()
{

    

}

bool Valdese::ColliderComponent::IsColliding(SDL_Rect otherCollider)
{
    if (m_Box.x < otherCollider.x + otherCollider.w &&
        m_Box.x + m_Box.w > otherCollider.x&&
        m_Box.y < otherCollider.y + otherCollider.h &&
        m_Box.y + m_Box.h > otherCollider.y)
    {
        return true;
    }
    return false;
}

bool Valdese::ColliderComponent::IsTopCollision(SDL_Rect otherCollider)
{
    int verticalCheck = otherCollider.y - m_Box.y + m_Box.h / 2;

    if (verticalCheck > 0) //Box is on top
    {
        return true;
    }
    return false;
}

bool Valdese::ColliderComponent::IsLeftCollision(SDL_Rect otherCollider)
{
    
    if (m_Box.x > otherCollider.x) //Box is on the left
    {
        return true;
    }
    return false;
}

bool Valdese::ColliderComponent::IsRightCollision(SDL_Rect otherCollider)
{
    if (otherCollider.x > m_Box.x) //Box is on the Right
    {
        return true;
    }
    return false;
}

void Valdese::ColliderComponent::CheckCollisionSide(SDL_Rect otherbox)
{
    UNREFERENCED_PARAMETER(otherbox);
}

void Valdese::ColliderComponent::SetBox(SDL_Rect box)
{
    m_Box = box;
}

void Valdese::ColliderComponent::UpdateBox(int x, int y, int width, int height)
{
    m_Box.x += x;
    m_Box.y += y;
    m_Box.w += width;
    m_Box.h += height;
}
