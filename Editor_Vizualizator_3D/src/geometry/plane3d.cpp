#include "plane3d.hpp"

// ##############################################
// ### operatori ################################
// ##############################################

Plane3d& Plane3d::operator=(const Plane3d& p) {
    if (this != &p) {
        base = p.base;
        normal = p.normal;
    }

    return *this;
}


// ##############################################
// ### altele ###################################
// ##############################################

// p(x, y, z) in plan [n(a, b, c), b] <=> n . (p - b)        = 0
//                                     <=> n.p - n.b          = 0
//                                     <=> ax + by + cz - n.b = 0 ⟹ d = - n.b
//double Plane3d::get_equation_coefficient_d() const {
//    return -(normal * base);
//}

// v(x, y, z) punct iar p este planul [n, b] cu vectorul unitate n, v2 intersectia normala a lui p cu v, distanta:
// D = | n . (v - v2) |
//   = | n.v - n.v2 |
//   = | n.v - d | deoarece d = - n.v2
// daca p[N, b], D = | n.v - d | * 1 / | n |
// daca eliminam | | de la numitor obtinem distanta cu semn(+ sau -)
//    D este distanta
//    semnul este pozitiv daca punctul este 'peste partea normala', si negativ daca este 'sub partea normala'

//double Plane3d::get_signed_distance_from_point_to_plane(const Vector& v) const {
//    return v * normal + get_equation_coefficient_d() / normal.norm();
//}

//bool Plane3d::handle_intersection_of_segment_with_plane(Segment& s) const {
//    const double da = get_signed_distance_from_point_to_plane(s.a);
//    const double db = get_signed_distance_from_point_to_plane(s.b);
//
//    if (da < 0 && db < 0)
//        return true;
//    else if (da > 0 & db < 0) {
//        double f = da / (da - db); // intersection factor (between 0 and 1)
//        sf::Color new_color = sf::Color(s.a.color.r + f * (s.b.color.r - s.a.color.r),
//            s.a.color.g + f * (s.b.color.g - s.a.color.g),
//            s.a.color.b + f * (s.b.color.b - s.a.color.b));
//        s.b = s.a + (s.b - s.a) * f;
//
//        s.b.color = new_color;
//    }
//    else if (da < 0 & db > 0) {
//        std::swap(s.a, s.b);
//        handle_intersection_of_segment_with_plane(s);
//    }
//
//    return false;
//}

//calculeaza pozitiile in plan pentru dimensiunile ecranului camera fiind in mijloc 
sf::Vertex Plane3d::get_projection_on_plane(const Vector& v, const unsigned window_width, const unsigned window_height) const {

    return sf::Vertex(sf::Vector2f(PROJECTION_FACTOR * v.x / v.z + window_width / 2,
        PROJECTION_FACTOR * v.y / v.z + window_height / 2),
        sf::Color::Yellow);
}
