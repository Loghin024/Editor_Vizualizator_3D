#include "plane3d.hpp"


// ##############################################
// ### altele ###################################
// ##############################################


//calculeaza noile pozitii in plan
sf::Vertex Plane3d::get_projection_on_plane(const Vector& v, const unsigned window_width, const unsigned window_height) const {

    return sf::Vertex(sf::Vector2f(PROJECTION_FACTOR * v.x / v.z + window_width / 2,
        PROJECTION_FACTOR * v.y / v.z + window_height / 2),
        sf::Color::White);
}
