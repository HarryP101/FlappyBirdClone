#pragma once

#include <vector>
#include "Point2D.h"

class GraphicsItem
{
public:
	GraphicsItem(const std::vector<Point2D<int>>& points);
	virtual ~GraphicsItem() = default;

	virtual void Update(const float deltaTime) = 0;

	const std::vector<Point2D<int>>& GetPointsToRaster() const; 
protected:
	void UpdateScreenPosition(const int screenX, const int screenY);

private:
	const std::vector<Point2D<int>> staticGraphicsPoints_;
	std::vector<Point2D<int>> screenPositionGraphicsPoints_;
};