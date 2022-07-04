#pragma once

#include "WorldToScreenPixelConverter.h"

class WorldPhysics
{
public:
	WorldPhysics(const double xVel, const double yVel,
		const WorldToScreenPixelConverter& worldConverter);

	void UpdateWorldPosition(const float fElapsedTime);

	int X() const;
	int Y() const;

private:
	double xWorldPosition_;
	double yWorldPosition_;
	double xWorldVelocity_;
	double yWorldVelocity_;

	WorldToScreenPixelConverter worldConverter_;
};