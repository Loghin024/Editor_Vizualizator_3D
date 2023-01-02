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

class Line : public Solid3d {

public:
    Line(const Vector& point1, const Vector& point2, int lenght);
};