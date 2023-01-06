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

    for (double j = 0; j <= size; j += 0.9)
    {
        add_segment(Segment(points[0] + Vector(0, j, 0), points[1] + Vector(0, j, 0)));//fata
        add_segment(Segment(points[4] + Vector(0, j, 0), points[5] + Vector(0, j, 0)));//spate
        add_segment(Segment(points[0] + Vector(0, j, 0), points[4] + Vector(0, j, 0)));//lateral stanga
        add_segment(Segment(points[1] + Vector(0, j, 0), points[5] + Vector(0, j, 0)));//lateral dreapta

    }

    for (double j = 0; j <= size; j += 0.9)
    {
        add_segment(Segment(points[0] + Vector(j, 0, 0), points[3] + Vector(j, 0, 0)));//fata
        add_segment(Segment(points[4] + Vector(j, 0, 0), points[7] + Vector(j, 0, 0)));//spate
        add_segment(Segment(points[0] + Vector(j, 0, 0), points[4] + Vector(j, 0, 0)));//sus
        add_segment(Segment(points[3] + Vector(j, 0, 0), points[7] + Vector(j, 0, 0)));//jos

    }

    for (double j = 0; j <= size; j += 0.9)
    {
        add_segment(Segment(points[0] + Vector(0, 0, j), points[3] + Vector(0, 0, j)));//lateral stanga
        add_segment(Segment(points[1] + Vector(0, 0, j), points[2] + Vector(0, 0, j)));//lateral dreapta
        add_segment(Segment(points[0] + Vector(0, 0, j), points[1] + Vector(0, 0, j)));//sus
        add_segment(Segment(points[3] + Vector(0, 0, j), points[2] + Vector(0, 0, j)));//jos
    }

    *this += _center;
}

//Line::Line(const Vector& point1, const Vector& point2,  int lenght) : Solid3d() {
//    Vector points[2];
//
//    points[0] = Vector(point1);
//    points[1] = Vector(point2);
//
//    add_segment(Segment(points[0], points[1]));
//
//   // *this += _center;
//}

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
    for (double j = 0; j <= height; j += 0.9)
    {
        add_segment(Segment(points[0] + Vector(0,j,0), points[1] + Vector(0,j,0)));//fata
        add_segment(Segment(points[4] + Vector(0, j, 0), points[5] + Vector(0, j, 0)));//spate
        add_segment(Segment(points[0] + Vector(0, j, 0), points[4] + Vector(0, j, 0)));//lateral stanga
        add_segment(Segment(points[1] + Vector(0, j, 0), points[5] + Vector(0, j, 0)));//lateral dreapta

    }

    for (double j = 0; j <= width; j += 0.9)
    {
        add_segment(Segment(points[0] + Vector(j, 0, 0), points[3] + Vector(j, 0, 0)));//fata
        add_segment(Segment(points[4] + Vector(j, 0, 0), points[7] + Vector(j, 0, 0)));//spate
        add_segment(Segment(points[0] + Vector(j, 0, 0), points[4] + Vector(j, 0, 0)));//sus
        add_segment(Segment(points[3] + Vector(j, 0, 0), points[7] + Vector(j, 0, 0)));//jos

    }

    for (double j = 0; j <= lenght; j += 0.9)
    {
        add_segment(Segment(points[0] + Vector(0, 0, j), points[3] + Vector(0, 0, j)));//lateral stanga
        add_segment(Segment(points[1] + Vector(0, 0, j), points[2] + Vector(0, 0, j)));//lateral dreapta
        add_segment(Segment(points[0] + Vector(0, 0, j), points[1] + Vector(0, 0, j)));//sus
        add_segment(Segment(points[3] + Vector(0, 0, j), points[2] + Vector(0, 0, j)));//jos
    }





    *this += _center;
}

// ##############################################
// ### Sphere3d #################################
// ##############################################

Sphere3d::Sphere3d(const Vector& _center,
    const double size,
    const unsigned number_of_circles,
    const unsigned number_of_points_per_circle) : Solid3d() {

    std::vector<Vector> points;

    for (unsigned i = 0; i < number_of_circles; ++i) {
        double theta = map(i, 0, number_of_circles - 1, -90, 90);

        for (unsigned j = 0; j < number_of_points_per_circle; ++j) {
            double phi = map(j, 0, number_of_points_per_circle, -180, 180);

            points.push_back(Vector(size * cos(as_radians(theta)) * cos(as_radians(phi)),
                size * cos(as_radians(theta)) * sin(as_radians(phi)),
                size * sin(as_radians(theta))));

            // no need to repeat this point
            if (theta <= -90 || theta >= 90)
                break;
        }
    }

    for (size_t i = 0; i < points.size(); ++i)
        add_segment(Segment(points[i], points[i] + Vector(0.5, 0, 0)));

    *this += _center;
}

// ##############################################
// ### Cylinder3d #################################
// ##############################################

Cylinder3d::Cylinder3d(const Vector& _center,
    const double height,
    const double radius,
    const unsigned number_of_points_per_circle) : Solid3d() {

    std::vector<Vector> points1, points2;



    for (unsigned i = 2; i < 3; ++i) {
        double theta = map(i, 0, 5 - 1, -90, 90);
        for (unsigned j = 0; j < number_of_points_per_circle; ++j) {
            double phi = map(j, 0, number_of_points_per_circle, -180, 180);
            std::cout << "*";

            points1.push_back(Vector(radius * cos(as_radians(theta)) * cos(as_radians(phi)),
                radius * cos(as_radians(theta)) * sin(as_radians(phi)), -height/2));
                //height * sin(as_radians(theta))));

            points2.push_back(Vector(radius * cos(as_radians(theta)) * cos(as_radians(phi)),
                radius * cos(as_radians(theta)) * sin(as_radians(phi)), height / 2));

            // no need to repeat this point
            if (theta <= -90 || theta >= 90)
                break;
        }
    }

    /*for (size_t i = 0; i < points.size(); ++i)
        add_segment(Segment(points[i], points[i] + Vector(0.5, 0, 0)));*/

    //linii laterale(dupa inaltime)
    for (size_t i = 0; i < points1.size(); ++i)
        add_segment(Segment(points1[i], points2[i]));

    //linii capete(dupa raza)
    for (size_t i = 0; i < points1.size()/2; ++i)
        add_segment(Segment(points1[i], points1[i + points1.size() / 2]));

    for (size_t i = 0; i < points1.size() / 2; ++i)
        add_segment(Segment(points2[i], points2[i + points1.size() / 2]));

    *this += _center;
}

// ##############################################
// ### Con3d #################################
// ##############################################

Con3d::Con3d(const Vector& _center,
    const double height,
    const double radius,
    const unsigned number_of_points_per_circle) : Solid3d() {

    std::vector<Vector> points1, points2;



    for (unsigned i = 2; i < 3; ++i) {
        double theta = map(i, 0, 5 - 1, -90, 90);
        for (unsigned j = 0; j < number_of_points_per_circle; ++j) {
            double phi = map(j, 0, number_of_points_per_circle, -180, 180);
            std::cout << "*";

            points1.push_back(Vector(radius * cos(as_radians(theta)) * cos(as_radians(phi)),
                radius * cos(as_radians(theta)) * sin(as_radians(phi)), -height / 2));
            //height * sin(as_radians(theta))));

            /*points2.push_back(Vector(radius * cos(as_radians(theta)) * cos(as_radians(phi)),
                radius * cos(as_radians(theta)) * sin(as_radians(phi)), height / 2));*/

            // no need to repeat this point
            if (theta <= -90 || theta >= 90)
                break;
        }
    }

    /*for (size_t i = 0; i < points.size(); ++i)
        add_segment(Segment(points[i], points[i] + Vector(0.5, 0, 0)));*/

        //linii laterale(dupa inaltime)
    for (size_t i = 0; i < points1.size(); ++i)
        add_segment(Segment(points1[i], Vector(0,0, height/2)));

    //linii capete(dupa raza)
    for (size_t i = 0; i < points1.size() / 2; ++i)
        add_segment(Segment(points1[i], points1[i + points1.size() / 2]));

    //for (size_t i = 0; i < points1.size() / 2; ++i)
    //    add_segment(Segment(points2[i], points2[i + points1.size() / 2]));

    *this += _center;
}

// ##############################################
// ### Pyramid3d ###################################
// ##############################################

Pyramid3d::Pyramid3d(const Vector& _center, const double height, const double base_lenght, const double base_width) : Solid3d() {
    Vector points[8];

    // baza
    points[0] = Vector(-base_lenght / 2, 0, -base_width/2);
    points[1] = points[0] + Vector(base_lenght, 0, 0);
    points[2] = points[0] + Vector(base_lenght, 0, base_width);
    points[3] = points[0] + Vector(0, 0, base_width);

    for (double j = 0; j <= base_width; j += 0.5)
    {
        add_segment(Segment(points[0] + Vector(0, 0, j), points[1] + Vector(0, 0, j)));
        add_segment(Segment(points[0] + Vector(0, 0, j), Vector(0, -height,0)));
        add_segment(Segment(points[1] + Vector(0, 0, j), Vector(0, -height,0)));
    }

    for (double j = 0; j <= base_lenght; j += 0.5)
    {
        add_segment(Segment(points[3] + Vector(j, 0, 0), points[0] + Vector(j, 0, 0)));
        add_segment(Segment(points[3] + Vector(j, 0, 0), Vector(0, -height, 0)));
        add_segment(Segment(points[0] + Vector(j, 0, 0), Vector(0, -height, 0)));
    }

    //varf


}