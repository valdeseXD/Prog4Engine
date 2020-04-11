#include "MiniginPCH.h"
#include "FPSComponent.h"

void Valdese::FPSComponent::Initialize()
{
}

void Valdese::FPSComponent::Update(float elapsedSec)
{
	m_FPS = (int)((1/ elapsedSec));
}

void Valdese::FPSComponent::Draw()
{
}