#include "geometrie.hpp"

// ##############################################
// ### Cub3d ###################################
// ##############################################

Cub::Cub(const Vector& _center, const double size) : Solid3d() {
    Vector points[8];

    // fata
    points[0] = Vector(-size / 2, -size / 2, -size / 2);
    points[1] = points[0] + Vector(size, 0, 0);
    points[2] = points[0] + Vector(size, size, 0);
    points[3] = points[0] + Vector(0, size, 0);

    // spate
    for (int i = 4; i < 8; ++i)
        points[i] = points[i - 4] + Vector(0, 0, size);

    for (int i = 0; i < 8; ++i)
        points[i].set_color(sf::Color::White);

    for (int i = 0; i < 4; ++i) {
        add_segment(Segment(points[i], points[(i + 1) % 4]));         // fata
        add_segment(Segment(points[i + 4], points[(i + 1) % 4 + 4])); // spate
        add_segment(Segment(points[i], points[i + 4]));               // legaturi fata spate
    }

    *this += _center;
}