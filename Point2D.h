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

	Point2D<T>& operator+=(const Point2D<T>& rhs);
private:
	T x_;
	T y_;
};

template<typename T>
Point2D<T> operator+(const Point2D<T>& lhs, const Point2D<T>& rhs)
{
    Point2D<T> result(lhs);
    return result += rhs;
}