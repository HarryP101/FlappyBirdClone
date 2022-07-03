#include "WorldToScreenPixelConverter.h"

#include <iostream>

WorldToScreenPixelConverter::WorldToScreenPixelConverter(const double worldWidth,
	const double worldHeight, const int screenWidth, const int screenHeight) :
	worldWidth_(worldWidth), worldHeight_(worldHeight), screenWidth_(screenWidth),
	screenHeight_(screenHeight)
{

}

int WorldToScreenPixelConverter::ConvertWorldXPosToPixel(const double worldXPos) const
{
	return static_cast<int>((worldXPos / worldWidth_) * static_cast<double>(screenWidth_));
}

int WorldToScreenPixelConverter::ConvertWorldYPosToPixel(const double worldYPos) const
{
	return static_cast<int>((worldYPos / worldHeight_) * static_cast<double>(screenHeight_));
}