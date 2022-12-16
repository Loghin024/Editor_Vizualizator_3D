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

	//const double horizontal_angle = atan2(window_width / 2.0, PROJECTION_FACTOR) - 0.0001;
	//const double vertical_angle = atan2(window_height / 2.0, PROJECTION_FACTOR) - 0.0001;
	//const double ch = cos(horizontal_angle);
	//const double sh = sin(horizontal_angle);
	//const double cv = cos(vertical_angle);
	//const double sv = sin(vertical_angle);

	//frustrum[0] = Plane3d(Vector(0, 0, 0), Vector(0, 0, 1)); // close
	//frustrum[1] = Plane3d(Vector(0, 0, PROJECTION_MAX_DEPTH), Vector(0, 0, -1)); // far
	//frustrum[2] = Plane3d(Vector(0, 0, 0), Vector(ch, 0, sh)); // left
	//frustrum[3] = Plane3d(Vector(0, 0, 0), Vector(-ch, 0, sh)); // right
	//frustrum[4] = Plane3d(Vector(0, 0, 0), Vector(0, cv, sv)); // top
	//frustrum[5] = Plane3d(Vector(0, 0, 0), Vector(0, -cv, sv)); // bottom
}

// ##############################################
// ### operatori ###################################
// ##############################################

Camera Camera::operator+=(const Vector& v) {
	position += v * CAMERA_TRANSLATION_SENSIBILITY;

	return *this;
}

// ##############################################
// ### altele ###################################
// ##############################################

void Camera::move(const DIRECTION direction) {
	Vector normal(cos(theta_x) * sin(theta_y), -sin(theta_x), cos(theta_x) * cos(theta_y));
	normal.normalize();

	Vector orthog(normal.z, 0, -normal.x);
	orthog.normalize();

	Vector up(0, 1, 0);

	if (direction == DIRECTION::FRONT)
		*this += normal;
	else if (direction == DIRECTION::BACK)
		*this += -normal;
	else if (direction == DIRECTION::RIGHT)
		*this += orthog;
	else if (direction == DIRECTION::LEFT)
		*this += -orthog;
	else if (direction == DIRECTION::UP)
		*this += up;
	else if (direction == DIRECTION::DOWN)
		*this += -up;
}


void Camera::rotate(const double mouse_move_x, const double mouse_move_y) {
	theta_x -= as_radians(mouse_move_y) * CAMERA_ROTATION_SENSIBILITY;
	theta_y += as_radians(mouse_move_x) * CAMERA_ROTATION_SENSIBILITY;
}

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
