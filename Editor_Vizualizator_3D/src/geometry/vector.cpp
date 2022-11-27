#include "Vector.hpp"

//pentru a vedea comentarii despre fiecare metoda accesati Vector.hpp

// ##############################################
// ### operatori ################################
// ##############################################

Vector& Vector::operator=(const Vector& v) {
	if (this != &v) {
		x = v.x;
		y = v.y;
		z = v.z;
		color = v.color;
	}

	return *this;
}

Vector Vector::operator+(const Vector& v) const {
	return Vector(x + v.x, y + v.y, z + v.z, color);
}

Vector Vector::operator+=(const Vector& v) {
	x += v.x;
	y += v.y;
	z += v.z;

	return *this;
}

Vector Vector::operator-(const Vector& v) const {
	return Vector(x - v.x, y - v.y, z - v.z, color);
}

Vector Vector::operator-=(const Vector& v) {
	x -= v.x;
	y -= v.y;
	z -= v.z;

	return *this;
}

Vector Vector::operator-() {
	x = -x;
	y = -y;
	z = -z;

	return *this;
}

Vector Vector::operator*(const double factor) const {
	return Vector(x * factor, y * factor, z * factor, color);
}

Vector Vector::operator*=(const double factor) {
	x *= factor;
	y *= factor;
	z *= factor;

	return *this;
}

double Vector::operator*(const Vector& v) const {
	return x * v.x + y * v.y + z * v.z;
}

// ##############################################
// ### altele ###################################
// ##############################################

Vector Vector::get_normalized() const {
	return (*this) * (1 / this->norm());
}

double Vector::distance_to(const Vector& v) const {
	return ((*this) - v).norm();
}

//rotire, matrici ...
void Vector::rotate(const Vector& center, const Vector& axis, const double theta) {
	Vector temp(*this);

	*this -= center;

	Vector ax = axis.get_normalized();
	double ux = ax.x, uy = ax.y, uz = ax.z;
	double c = cos(as_radians(theta)), s = sin(as_radians(theta));

	temp.x = x * (c + square(ux) * (1 - c)) + y * (ux * uy * (1 - c) - uz * s) + z * (ux * uz * (1 - c) + uy * s);
	temp.y = x * (uy * ux * (1 - c) + uz * s) + y * (c + square(uy) * (1 - c)) + z * (uy * uz * (1 - c) - ux * s);
	temp.z = x * (uz * ux * (1 - c) - uy * s) + y * (uz * uy * (1 - c) + ux * s) + z * (c + square(uz) * (1 - c));

	*this = temp + center;
}
