#define OLC_PGE_APPLICATION

#include "FlappyBirdWorldEngine.h"

FlappyBirdWorldEngine::FlappyBirdWorldEngine()
{
}

bool FlappyBirdWorldEngine::OnUserCreate()
{
    return true;
}

bool FlappyBirdWorldEngine::OnUserUpdate(float fElapsedTime)
{
    for (auto&& item : worldItems_)
    {
        item->Update(fElapsedTime);
    }

    return true;
}