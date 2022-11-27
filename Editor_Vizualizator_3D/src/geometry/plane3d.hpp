#ifndef PLANE_3D_HPP
#define PLANE_3D_HPP

#include "Vector.hpp"
#include "Segment.hpp"

#define PROJECTION_FACTOR    1024.0
#define PROJECTION_MAX_DEPTH 800

class Plane3d {

public:

    sf::Vertex get_projection_on_plane(const Vector& v, const unsigned window_width, const unsigned window_height) const;
};

#endif
