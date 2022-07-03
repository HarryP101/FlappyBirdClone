#include "Point2D.h"

template<typename T>
Point2D<T>::Point2D(const T x, const T y) : x_(x), y_(y)
{

}

template<typename T>
const T& Point2D<T>::X() const { return x_; }

template<typename T>
const T& Point2D<T>::Y() const { return y_; }

template<typename T>
T& Point2D<T>::X() { return x_; }

template<typename T>
T& Point2D<T>::Y() { return y_; }

template<typename T>
Point2D<T>& Point2D<T>::operator+=(const Point2D<T>& rhs)
{
	x_ += rhs.X();
	y_ += rhs.Y();

	return *this;
}

template class Point2D<int>;
template class Point2D<double>;