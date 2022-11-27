#include "Camera.hpp"

// ##############################################
// ### constructori #############################
// ##############################################

Camera::Camera(const Vector& _position,
	const double _theta_x,
	const double _theta_y,
	const double _theta_z,
	const unsigned window_width,
	const unsigned window_height) : position(_position),
	theta_x(as_radians(_theta_x)),
	theta_y(as_radians(_theta_y)),
	theta_z(as_radians(_theta_z)) {
}

// ##############################################
// ### altele ###################################
// ##############################################

Vector Camera::transform_vector(const Vector& v) const {
	double cx = cos(theta_x), cy = cos(theta_y), cz = cos(theta_z);
	double sx = sin(theta_x), sy = sin(theta_y), sz = sin(theta_z);
	Vector u = v - position; // camera se afla in centru (0, 0, 0)

	double x = u.x, y = u.y, z = u.z;

	// rotatii
	return (Vector(cy * (sz * y + cz * x) - sy * z,
		sx * (cy * z + sy * (sz * y + cz * x)) + cx * (cz * y - sz * x),
		cx * (cy * z + sy * (sz * y + cz * x)) - sx * (cz * y - sz * x), v.color));
}

Segment Camera::transform_segment(const Segment& s) const {
	return Segment(transform_vector(s.a), transform_vector(s.b));
}
