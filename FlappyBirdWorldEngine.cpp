#define OLC_PGE_APPLICATION

#include <memory>

#include "FlappyBirdWorldEngine.h"
#include "BirdGraphicsItem.h"
#include "PolePairGraphicsItem.h"
#include "WorldPhysics.h"
#include "WorldToScreenPixelConverter.h"

constexpr double WORLD_WIDTH = 100.0;
constexpr double WORLD_HEIGHT = 100.0;

//constexpr double SCROLL_SPEED_X = 10.0;
//constexpr double SCROLL_SPEED_Y = 0.0;

namespace
{
std::vector<Point2D<int>> getBirdGraphics(const int winWidth, const int winHeight)
{
    const auto screenYMidPoint = winHeight / 2;
    constexpr auto birdRadius = 10;
    std::vector<Point2D<int>> graphics_;
    for (auto i = 0; i < winWidth / 10; ++i)
    {
        for (auto j = screenYMidPoint - birdRadius; j < screenYMidPoint + birdRadius; ++j)
        {
            graphics_.push_back(Point2D<int>(i, j));
        }
    }
    return graphics_;
}

std::vector<Point2D<int>> getPoleGraphics(const int winWidth, const int winHeight)
{
    const auto screenYMidPoint = winHeight / 2;
    const auto screenXMidPoint = winWidth / 2;
    constexpr auto poleRadius = 5;
    std::vector<Point2D<int>> graphics_;
    for (auto i = screenXMidPoint - poleRadius; i < screenXMidPoint + poleRadius; ++i)
    {
        for (auto j = 0; j < screenYMidPoint; ++j)
        {
            graphics_.push_back(Point2D<int>(i, j));
        }
    }

    return graphics_;
}
}

FlappyBirdWorldEngine::FlappyBirdWorldEngine()
{
}

bool FlappyBirdWorldEngine::OnUserCreate()
{
    WorldToScreenPixelConverter worldConverter(WORLD_WIDTH, WORLD_HEIGHT, ScreenWidth(), ScreenHeight());

    BirdGraphicsItem birdGraphics(getBirdGraphics(ScreenWidth(), ScreenHeight()),
                                                  10.0, 0.0, worldConverter);
    PolePairGraphicsItem polePairGraphics(getPoleGraphics(ScreenWidth(), ScreenHeight()),
                                          -10.0, 0.0, worldConverter);

    worldItems_.push_back(std::make_unique<BirdGraphicsItem>(birdGraphics));
    worldItems_.push_back(std::make_unique<PolePairGraphicsItem>(polePairGraphics));

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