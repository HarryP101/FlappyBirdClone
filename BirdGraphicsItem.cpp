#include "BirdGraphicsItem.h"

#include "WorldToScreenPixelConverter.h"

BirdGraphicsItem::BirdGraphicsItem(const std::vector<Point2D<int>>& graphics,
	const double xVel, const double yVel,
	const WorldToScreenPixelConverter& worldConverter) 
	: GraphicsItem(graphics)
	, birdPhysics_(BirdPhysics(xVel, yVel, worldConverter))
{
}

void BirdGraphicsItem::Update(const float deltaTime)
{
	birdPhysics_.UpdateWorldPosition(deltaTime);

	UpdateScreenPosition(birdPhysics_.X(), birdPhysics_.Y());
}