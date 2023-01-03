#include "../utils/tools.hpp"
#include "Vector.hpp"
#include "Segment.hpp"
#include "solid3d.hpp"

// ##############################################
// ### Cub3d ###################################
// ##############################################

class Cub : public Solid3d {

public:
    Cub(const Vector& _center, const double size);
};

class Prism : public Solid3d {

public:
    Prism(const Vector& _center, const double height, const double lenght, const double width);
};

// ##############################################
// ### Sphere3d #################################
// ##############################################

class Sphere3d : public Solid3d {

public:
    Sphere3d(const Vector& _center,
        const double size,
        const unsigned number_of_circles,
        const unsigned number_of_points_per_circle);
};

// ##############################################
// ### Cylinder3d #################################
// ##############################################

class Cylinder3d : public Solid3d {

public:
    Cylinder3d(const Vector& _center,
        const double height,
        const double radius,
        const unsigned number_of_points_per_circle);
};

// ##############################################
// ### Con3d #################################
// ##############################################

class Con3d : public Solid3d {

public:
    Con3d(const Vector& _center,
        const double height,
        const double radius,
        const unsigned number_of_points_per_circle);
};