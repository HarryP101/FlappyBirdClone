#include "BirdGraphicsItem.h"

#include "WorldToScreenPixelConverter.h"

BirdGraphicsItem::BirdGraphicsItem(const std::vector<Point2D<int>>& graphics,
	const double xVel, const double yVel,
	const WorldToScreenPixelConverter& worldConverter) 
	: GraphicsItem(graphics)
	, worldPhysics_(WorldPhysics(xVel, yVel, worldConverter))
{
}

void BirdGraphicsItem::Update(const float deltaTime)
{
	worldPhysics_.UpdateWorldPosition(deltaTime);

	UpdateScreenPosition(worldPhysics_.X(), worldPhysics_.Y());
}