#define OLC_PGE_APPLICATION

#include <memory>

#include "FlappyBirdWorldEngine.h"
#include "BirdGraphicsItem.h"
#include "BirdPhysics.h"

FlappyBirdWorldEngine::FlappyBirdWorldEngine()
{
}

bool FlappyBirdWorldEngine::OnUserCreate()
{
    const auto graphics = [&]
    {
        std::vector<Point2D<int>> graphics_;
        for (auto i = 20; i <  20 + ScreenHeight() / 10; ++i)
        {
            for (auto j = 20; j < 20 + ScreenHeight() / 10; ++j)
            {
                graphics_.push_back(Point2D<int>(i, j));
            }
        }

        return graphics_;
    }();

    BirdGraphicsItem birdGraphics(graphics, 1.0, 0.0);

    worldItems_.push_back(std::make_unique<BirdGraphicsItem>(birdGraphics));

    return true;
}

bool FlappyBirdWorldEngine::OnUserUpdate(float fElapsedTime)
{
    Clear(olc::BLACK);

    for (auto&& item : worldItems_)
    {
        item->Update(fElapsedTime);

        for (const auto& point : item->GetPointsToRaster())
        {
            Draw(point.X(), point.Y(), olc::Pixel(255, 255, 255));
        }
    }

    return true;
}