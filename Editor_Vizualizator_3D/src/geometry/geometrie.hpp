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