#pragma once

#include "../utils/tools.hpp"
#include "Vector.hpp"
#include "Segment.hpp"
#include "plane3d.hpp"

#define CAMERA_ROTATION_SENSIBILITY    0.25
#define CAMERA_TRANSLATION_SENSIBILITY 4

class Camera {
public:
	enum class DIRECTION { FRONT, BACK, RIGHT, LEFT, UP, DOWN };

private:
	Vector position;
	double theta_x, theta_y, theta_z;

	Plane3d frustrum[6];

public:
	// constructori
	Camera(const Vector& _position,
		const double _theta_x,
		const double _theta_y,
		const double _theta_z,
		const unsigned window_width,
		const unsigned window_height);

	// operatori
	Camera operator+=(const Vector& v);

	//altele
	void rotate(const double mouse_move_x, const double mouse_move_y, bool state);
	void move(const DIRECTION direction);
	Vector transform_vector(const Vector& v) const;
	Segment transform_segment(const Segment& s) const;


	friend class Solid3d;
};
