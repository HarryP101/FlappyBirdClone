#pragma once

class BirdPhysics
{
public:
	BirdPhysics(const double xVel, const double yVel);

	void UpdateWorldPosition(const float fElapsedTime);

	int X() const;
	int Y() const;

private:
	double xWorldPosition_;
	double yWorldPosition_;
	double xWorldVelocity_;
	double yWorldVelocity_;
};