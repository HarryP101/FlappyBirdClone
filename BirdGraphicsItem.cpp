#include "BirdGraphicsItem.h"

BirdGraphicsItem::BirdGraphicsItem(const std::vector<Point2D<int>>& graphics, const double xVel, const double yVel) 
	: GraphicsItem(graphics)
	, birdPhysics_(BirdPhysics(xVel, yVel))
{
}

void BirdGraphicsItem::Update(const float deltaTime)
{
	birdPhysics_.UpdateWorldPosition(deltaTime);

	for (auto&& point2d : GetPointsToRaster())
	{
		point2d.X() = point2d.X() + birdPhysics_.X();
		point2d.Y() = point2d.Y() + birdPhysics_.Y();
	}
}