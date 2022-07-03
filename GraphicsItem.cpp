#include "GraphicsItem.h"

GraphicsItem::GraphicsItem(const std::vector<Point2D<int>>& points) : pointsToRaster_(points)
{

}

const std::vector<Point2D<int>>& GraphicsItem::GetPointsToRaster() const 
{
	return pointsToRaster_;
}

std::vector<Point2D<int>>& GraphicsItem::GetPointsToRaster()
{
	return pointsToRaster_;
}
