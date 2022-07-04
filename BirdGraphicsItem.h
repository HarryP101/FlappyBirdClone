#pragma once

#include "GraphicsItem.h"

#include <vector>

#include "WorldPhysics.h"
#include "Point2D.h"
#include "WorldToScreenPixelConverter.h"

class BirdGraphicsItem : public GraphicsItem 
{
public:
	BirdGraphicsItem(const std::vector<Point2D<int>>& graphics,
	 const double xVel, const double yVel, const WorldToScreenPixelConverter& worldConverter);

	void Update(const float deltaTime) override;
private:
	WorldPhysics worldPhysics_;
};