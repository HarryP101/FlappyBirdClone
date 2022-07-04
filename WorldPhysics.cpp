#include "WorldPhysics.h"

#include "WorldToScreenPixelConverter.h"

WorldPhysics::WorldPhysics(const double xVel, const double yVel,
	const WorldToScreenPixelConverter& worldConverter) 
	: xWorldVelocity_(xVel), yWorldVelocity_(yVel), worldConverter_(worldConverter)
{}

void WorldPhysics::UpdateWorldPosition(const float fElapsedTime)
{
	xWorldPosition_ += static_cast<double>(fElapsedTime) * xWorldVelocity_;
	yWorldPosition_ += static_cast<double>(fElapsedTime) * yWorldVelocity_;
}

// TODO: Perform mapping from world position in float points to screen position in integers
int WorldPhysics::X() const
{
	return worldConverter_.ConvertWorldXPosToPixel(xWorldPosition_);
}

int WorldPhysics::Y() const
{
	return worldConverter_.ConvertWorldYPosToPixel(yWorldPosition_);
}