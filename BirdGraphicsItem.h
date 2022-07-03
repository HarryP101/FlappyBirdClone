#pragma once

#include "GraphicsItem.h"

#include <vector>

#include "BirdPhysics.h"
#include "Point2D.h"

class BirdGraphicsItem : public GraphicsItem 
{
public:
	BirdGraphicsItem(const std::vector<Point2D<int>>& graphics, const double xVel, const double yVel);

	void Update(const float deltaTime) override;
private:
	BirdPhysics birdPhysics_;
};