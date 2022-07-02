#include "BirdGraphicsItem.h"

BirdGraphicsItem::BirdGraphicsItem(const BirdPhysics& birdPhysics) : birdPhysics_(birdPhysics)
{

}

void BirdGraphicsItem::Update(const float deltaTime);
{
	for (auto&& point2d : GetPointsToRaster())
	{
		const auto xIncrement = static_cast<int>(deltaTime * birdPhysics_.XVelocity());
		const auto yIncrement = static_cast<int>(deltaTime * birdPhysics_.YVelocity());

		point2d.X() = point2d.X() + xIncrement;
		point2d.Y() = point2d.Y() + yIncrement;
	}
}