#include "Segment.hpp"

// ##############################################
// ### operatori ################################
// ##############################################

Segment& Segment::operator=(const Segment& s) {

    if (this != &s) {
        a = s.a;
        b = s.b;
    }

    return *this;
}

Segment Segment::operator+=(const Vector& v) {
    a += v;
    b += v;

    return *this;
}
