#pragma once

#include "GraphicsItem.h"
#include <vector>

class BirdGraphicsItem : public GraphicsItem 
{
public:
	BirdGraphicsItem(const BirdPhysics& birdPhysics);

	void Update(const float deltaTime) override;
private:
	BirdPhysics& birdPhysics_;
};