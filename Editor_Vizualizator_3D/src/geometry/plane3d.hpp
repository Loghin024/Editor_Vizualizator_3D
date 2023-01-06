#pragma once

#include "vector.hpp"
#include "segment.hpp"

#define PROJECTION_FACTOR    1024.0
#define PROJECTION_MAX_DEPTH 800

class Plane3d {
private:
    Vector base;
    Vector normal;

public:
    // constructors
    Plane3d() : base(Vector()), normal(Vector()) {}
    Plane3d(const Vector& _base, const Vector& _normal) : base(_base), normal(_normal) {}
    Plane3d(const Plane3d& p) : base(p.base), normal(p.normal) {}

    // operators
    Plane3d& operator=(const Plane3d& p);

    // others
    double get_equation_coefficient_d() const;
    double get_signed_distance_from_point_to_plane(const Vector& v) const;
    bool handle_intersection_of_segment_with_plane(Segment& s) const;
    //sf::Vertex get_projection_on_plane(const Vector3d& v, const unsigned window_width, const unsigned window_height) const;
    sf::Vertex get_projection_on_plane(const Vector& v, const unsigned window_width, const unsigned window_height, sf::Color color) const;
};