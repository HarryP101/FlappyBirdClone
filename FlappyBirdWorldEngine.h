#pragma once

#include "olcPixelGameEngine.h"

class FlappyBirdWorldEngine : public olc::PixelGameEngine
{
public:
	FlappyBirdWorldEngine();

	bool OnUserCreate() override;

	bool OnUserUpdate(float fElapsedTime) override;

private:
};