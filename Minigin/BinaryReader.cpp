#include "MiniginPCH.h"
#include "BinaryReader.h"
#include "GameObject.h"
#include "RenderComponent.h"
#include "ColliderComponent.h"

int isNthBitSet(char* c, int n) {
    static unsigned char mask[] = { 128, 64, 32, 16, 8, 4, 2, 1 };
    return ((*c & mask[n]) != 0);
}

std::vector<Valdese::GameObject*> Valdese::BinaryReader::ReadLevelData()
{
    std::vector<GameObject*> levels;
    if (OpenFile("../Data/SeperatedLevelData.dat"))
    {
        std::cout << "File opened" << std::endl;
        int amountOfBytesPerRow = 4;
        int amountOfRows = 25;
        char byte;

        int posX = 0;
        int posY = 0;
        int width = 0;
        int height = 19;
        int blockSize = 20;
        for (int i = 0; i < 3; i++)
        {
            levels.push_back(new GameObject());

            for (int row = 0; row < amountOfRows; row++)
            {
                for (int byteInRow = 0; byteInRow < amountOfBytesPerRow; byteInRow++)
                {
                    m_CurrentFile.read(&byte, 1);
                    for (int bit = 0; bit < 8; bit++)
                    {
                        if (isNthBitSet(&byte, bit))
                        {
                            RenderComponent* renderComp = new RenderComponent("../Data/block.png");
                            renderComp->SetDestRect({ (bit + byteInRow * 8) * blockSize, row * 19, blockSize, blockSize });
                            levels[i]->AddComponent(renderComp);
                            width += blockSize;
                        }
                        else if(width != 0)
                        {
                            //Add collision box if this bit is empty
                            ColliderComponent* colliderComp = new ColliderComponent();
                            levels[i]->AddComponent(colliderComp);
                            colliderComp->SetBox({ posX, posY, width, height });
                            posX += width + blockSize;
                            width = 0;
                        }
                        else
                        {
                            posX += blockSize;
                        }
                    }
                }
                //Add collision box if row is finished
                if (width != 0)
                {
                    ColliderComponent* colliderComp = new ColliderComponent();
                    levels[i]->AddComponent(colliderComp);
                    colliderComp->SetBox({ posX, posY, width, height });
                    width = 0;
                }
                posX = 0;
                posY += height;
            }
        }
        m_CurrentFile.close();
    }
       
    return levels;
}

bool Valdese::BinaryReader::OpenFile(std::string filename)
{
    m_CurrentFile = std::fstream(filename, std::ios::in | std::ios::binary);

    if (m_CurrentFile.is_open())
    {
        return true;
    }
    return false;
}
