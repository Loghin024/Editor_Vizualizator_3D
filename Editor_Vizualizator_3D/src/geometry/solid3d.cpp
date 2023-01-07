#include "solid3d.hpp"

// ##############################################
// ### operatori ################################
// ##############################################

Solid3d Solid3d::operator+=(const Solid3d& solid) {
    for (auto s : solid.edges)
        this->add_segment(s);

    return *this;
}

Solid3d Solid3d::operator+(const Vector& v) const {
    Solid3d new_solid(*this);

    for (auto& s : new_solid.edges)
        s += v;

    new_solid.center += v;

    return new_solid;
}

Solid3d Solid3d::operator+=(const Vector& v) {
    for (auto& s : edges)
        s += v;

    center += v;

    return *this;
}


// ##############################################
// ### altele ###################################
// ##############################################

void Solid3d::set_center(const Vector& _center) {
    *this += _center;
    center = _center;
}


void Solid3d::render_solid(sf::RenderWindow& window, const unsigned window_width, const unsigned window_height, const Camera& camera) {
    figure.clear();

    for (auto s : edges) {

        bool outside_frustrum = false;
        //recalculeaza pozitiile segmentului in plan
        s = camera.transform_segment(s);

        for (auto side : camera.frustrum) {
            outside_frustrum = side.handle_intersection_of_segment_with_plane(s);
            if (outside_frustrum)
                break;
        }

        if (!outside_frustrum) {
            //adaug in figura pe care vreau sa o afisez noile pozitii ale segmentului din noul unghi
            figure.append(camera.frustrum[0].get_projection_on_plane(s.a, window_width, window_height));
            figure.append(camera.frustrum[0].get_projection_on_plane(s.b, window_width, window_height));
        }

        ////adaug in figura pe care vreau sa o afisez noile pozitii ale segmentului din noul unghi
        //figure.append(camera.frustrum[0].get_projection_on_plane(s.a, window_width, window_height, color));
        //figure.append(camera.frustrum[0].get_projection_on_plane(s.b, window_width, window_height, color));
    }

    window.draw(figure);
}


//rotire corp
void Solid3d::rotate(const Vector& rotation_center, const Vector& axis, const double theta, const bool object_axis) {

    Vector center_of_rotation(rotation_center);

    if (object_axis)
        center_of_rotation = center;

    for (auto& s : edges) {
        s.a.rotate(center_of_rotation, axis, theta);
        s.b.rotate(center_of_rotation, axis, theta);
    }

    center.rotate(center_of_rotation, axis, theta);
}