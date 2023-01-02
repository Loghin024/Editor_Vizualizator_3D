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

// ##############################################
// ### Prisma3d ###################################
// ##############################################

Prism::Prism(const Vector& _center, const double height, const double lenght, const double width) : Solid3d() {
    Vector points[8];

    //fata
    points[0] = Vector(-height / 2, -height / 2, -height / 2);
    points[1] = points[0] + Vector(width, 0, 0);
    points[2] = points[0] + Vector(width, height, 0);
    points[3] = points[0] + Vector(0, height, 0);

    // spate
    for (int i = 4; i < 8; ++i)
        points[i] = points[i - 4] + Vector(0, 0, lenght);

    for (int i = 0; i < 8; ++i)
        points[i].set_color(sf::Color::White);

    for (int i = 0; i < 4; ++i) {
        add_segment(Segment(points[i], points[(i + 1) % 4]));         // fata
        add_segment(Segment(points[i + 4], points[(i + 1) % 4 + 4])); // spate
        add_segment(Segment(points[i], points[i + 4]));               // legaturi fata spate
    }


    //fata
    for (double j = 0; j <= height; j += 0.5)
    {
        add_segment(Segment(points[0] + Vector(0,j,0), points[1] + Vector(0,j,0)));//fata
        add_segment(Segment(points[4] + Vector(0, j, 0), points[5] + Vector(0, j, 0)));//spate
        add_segment(Segment(points[0] + Vector(0, j, 0), points[4] + Vector(0, j, 0)));//lateral stanga
        add_segment(Segment(points[1] + Vector(0, j, 0), points[5] + Vector(0, j, 0)));//lateral dreapta

    }

    for (double j = 0; j <= width; j += 0.5)
    {
        add_segment(Segment(points[0] + Vector(j, 0, 0), points[3] + Vector(j, 0, 0)));//fata
        add_segment(Segment(points[4] + Vector(j, 0, 0), points[7] + Vector(j, 0, 0)));//spate
        add_segment(Segment(points[0] + Vector(j, 0, 0), points[4] + Vector(j, 0, 0)));//sus
        add_segment(Segment(points[3] + Vector(j, 0, 0), points[7] + Vector(j, 0, 0)));//jos

    }

    for (double j = 0; j <= lenght; j += 0.5)
    {
        add_segment(Segment(points[0] + Vector(0, 0, j), points[3] + Vector(0, 0, j)));//lateral stanga
        add_segment(Segment(points[1] + Vector(0, 0, j), points[2] + Vector(0, 0, j)));//lateral dreapta
        add_segment(Segment(points[0] + Vector(0, 0, j), points[1] + Vector(0, 0, j)));//sus
        add_segment(Segment(points[3] + Vector(0, 0, j), points[2] + Vector(0, 0, j)));//jos
    }





    *this += _center;
}