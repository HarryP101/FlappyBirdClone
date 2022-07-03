#define OLC_PGE_APPLICATION

#include <memory>

#include "FlappyBirdWorldEngine.h"
#include "BirdGraphicsItem.h"
#include "BirdPhysics.h"
#include "WorldToScreenPixelConverter.h"

constexpr double WORLD_WIDTH = 100.0;
constexpr double WORLD_HEIGHT = 100.0;

//constexpr double SCROLL_SPEED = 10;

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

    WorldToScreenPixelConverter worldConverter(WORLD_WIDTH, WORLD_HEIGHT, ScreenWidth(), ScreenHeight());

    BirdGraphicsItem birdGraphics(graphics, 10.0, 0.0, worldConverter);

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