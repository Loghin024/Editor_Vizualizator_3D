#pragma once

#include <SFML/Graphics.hpp>
#include "Vector.hpp"

class Segment {

private:
    
    Vector a, b;

public:

    ////////////////
    // constructori
    //////////////

    //constructor default apelat fara parametrii, a(0,0,0), b(0,0,0)
    Segment() : a(Vector()), b(Vector()) {}

    //contructor apelat cu 2 parametrii
    Segment(const Vector& _a, const Vector& _b) : a(_a), b(_b) {}

    //constructor apelat cu 2 parametrii si o culoare
    Segment(const Vector& _a, const Vector& _b, const sf::Color _color) : a(_a, _color), b(_b, _color) {}

    //constructor apelat cu un alt segment 
    Segment(const Segment& s) : a(s.a), b(s.b) {}


    /////////////
    // operatori
    ////////////

    //atribuire
    Segment& operator=(const Segment& s);

    //modifica segmentul care a apelat metoda
    Segment operator+=(const Vector& v);

    friend class Plane3d;
    friend class Solid3d;
    friend class Camera;
};
