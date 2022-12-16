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