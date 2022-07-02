#pragma once

#include <memory>

#include "olcPixelGameEngine.h"
#include "GraphicsItem.h"

class FlappyBirdWorldEngine : public olc::PixelGameEngine
{
public:
	FlappyBirdWorldEngine();

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

private:
	std::vector<std::unique_ptr<GraphicsItem>> worldItems_;
};