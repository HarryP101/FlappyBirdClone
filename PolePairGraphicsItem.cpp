#include "PolePairGraphicsItem.h"

PolePairGraphicsItem::PolePairGraphicsItem(const std::vector<Point2D<int>>& graphics, 
		const double xVel, const double yVel,
		const WorldToScreenPixelConverter& worldConverter) :
		GraphicsItem(graphics),
		polePairPhysics_(WorldPhysics(xVel, yVel, worldConverter))
		
{
	
}

void PolePairGraphicsItem::Update(const float deltaTime)
{
	(void)deltaTime;
}