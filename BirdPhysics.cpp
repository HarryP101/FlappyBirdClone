#include "BirdPhysics.h"

#include "WorldToScreenPixelConverter.h"

BirdPhysics::BirdPhysics(const double xVel, const double yVel,
	const WorldToScreenPixelConverter& worldConverter) 
	: xWorldVelocity_(xVel), yWorldVelocity_(yVel), worldConverter_(worldConverter)
{}

void BirdPhysics::UpdateWorldPosition(const float fElapsedTime)
{
	xWorldPosition_ += static_cast<double>(fElapsedTime) * xWorldVelocity_;
	yWorldPosition_ += static_cast<double>(fElapsedTime) * yWorldVelocity_;
}

// TODO: Perform mapping from world position in float points to screen position in integers
int BirdPhysics::X() const
{
	return worldConverter_.ConvertWorldXPosToPixel(xWorldPosition_);
}

int BirdPhysics::Y() const
{
	return worldConverter_.ConvertWorldYPosToPixel(yWorldPosition_);
}