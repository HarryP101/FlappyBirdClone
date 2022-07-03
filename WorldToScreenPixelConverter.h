#pragma once

class WorldToScreenPixelConverter
{
public:
	WorldToScreenPixelConverter(const double worldWidth, const double worldHeight,
		const int screenWidth, const int screenHeight);

	int ConvertWorldXPosToPixel(const double worldXPos) const;

	int ConvertWorldYPosToPixel(const double worldYPos) const;
private:
	double worldWidth_;
	double worldHeight_;

	int screenWidth_;
	int screenHeight_;
};