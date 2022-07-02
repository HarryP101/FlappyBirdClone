#pragma once

template<typename T>
class Point2D
{
public:

	Point2D<T>(const T x, const T y);
	const T& X() const;
	const T& Y() const;

	T& X();
	T& Y();
private:
	T x_;
	T y_;
};