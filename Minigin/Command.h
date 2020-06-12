#pragma once
#include "GameObject.h"

namespace Valdese
{
	class Command
	{
	public:
		virtual ~Command() {}
		virtual void execute(GameObject& gameObject) = 0;
	};

	class LeftCommand : public Command
	{
	public:
		virtual void execute(GameObject& gameObject) override;
	};

	class RightCommand : public Command
	{
	public:
		virtual void execute(GameObject& gameObject) override;
	};

	class JumpCommand : public Command
	{
	public:
		virtual void execute(GameObject& gameObject) override;
	};

	class DownCommand : public Command
	{
	public:
		virtual void execute(GameObject& gameObject) override;
	};

	class FireCommand : public Command
	{
	public:
		virtual void execute(GameObject& gameObject) override;
	};
}