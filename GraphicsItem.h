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
	std::vector<Point2D<int>>& GetPointsToRaster();
private:
	std::vector<Point2D<int>> pointsToRaster_;
};