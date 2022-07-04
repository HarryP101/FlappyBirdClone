#pragma once

#include "GraphicsItem.h"
#include <vector>
#include "Point2D.h"
#include "WorldPhysics.h"

class PolePairGraphicsItem : public GraphicsItem
{
public:
	PolePairGraphicsItem(const std::vector<Point2D<int>>& graphics, 
		const double xVel, const double yVel,
		const WorldToScreenPixelConverter& worldConverter);

	void Update(const float deltaTime) override;

private:
	WorldPhysics polePairPhysics_;
};