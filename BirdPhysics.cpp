#include "BirdPhysics.h"

BirdPhysics::BirdPhysics(const double xVel, const double yVel) 
	: xWorldVelocity_(xVel), yWorldVelocity_(yVel)
{}

void BirdPhysics::UpdateWorldPosition(const float fElapsedTime)
{
	xWorldPosition_ += static_cast<double>(fElapsedTime) * xWorldVelocity_;
	yWorldPosition_ += static_cast<double>(fElapsedTime) * yWorldVelocity_;
}

int BirdPhysics::X() const
{
	return static_cast<int>(xWorldPosition_);
}

int BirdPhysics::Y() const
{
	return static_cast<int>(yWorldPosition_);
}