#include "GraphicsItem.h"

const std::vector<Point2D<int>>& GraphicsItem::GetPointsToRaster() const 
{
	return pointsToRaster_;
}

std::vector<Point2D<int>>& GraphicsItem::GetPointsToRaster()
{
	return pointsToRaster_;
}
