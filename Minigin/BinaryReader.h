#pragma once
#include "Singleton.h"
#include <string>
#include <fstream>

namespace Valdese
{
	class GameObject;
	class BinaryReader final : public Singleton<BinaryReader>
	{
	public:
		std::vector<GameObject*> ReadLevelData();
		bool OpenFile(std::string filename);

	private:
		std::fstream m_CurrentFile;
	};
}
