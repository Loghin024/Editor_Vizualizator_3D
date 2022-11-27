#pragma once

#include <SFML/Graphics.hpp>
#include "Vector.hpp"
#include "Segment.hpp"
#include "plane3d.hpp"
#include "Camera.hpp"

class Solid3d {
public:
    enum class SOLID_TYPE { CUBE};

public:
    std::vector<Segment> edges;
    sf::VertexArray figure;
    Vector center;

public:
    // constructori
    Solid3d() { figure.setPrimitiveType(sf::Lines); }

    // operators
    Solid3d operator+=(const Solid3d& solid);
    Solid3d operator+(const Vector& v) const;
    Solid3d operator+=(const Vector& v);

    // altele
    void set_center(const Vector& _center);
    void add_segment(const Segment& s) { edges.push_back(s); }
    void render_solid(sf::RenderWindow& window, const unsigned window_width, const unsigned window_height, const Camera& camera);
    void clear() { edges.clear(); }
};
