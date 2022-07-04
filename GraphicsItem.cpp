#include "GraphicsItem.h"

GraphicsItem::GraphicsItem(const std::vector<Point2D<int>>& points) :
 	staticGraphicsPoints_(points), screenPositionGraphicsPoints_(points)
{

}

const std::vector<Point2D<int>>& GraphicsItem::GetPointsToRaster() const 
{
	return screenPositionGraphicsPoints_;
}

void GraphicsItem::UpdateScreenPosition(const int screenX, const int screenY)
{
	const Point2D<int> screenPoint(screenX, screenY);
	for (size_t i = 0; i < staticGraphicsPoints_.size(); ++i)
	{
		screenPositionGraphicsPoints_[i] = staticGraphicsPoints_[i] + screenPoint;
	}
}
