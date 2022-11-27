#define M_PI 3.14159265358979323846

#include <SFML/Graphics.hpp>
#include <cmath>

double square(const double x);
double map(const double x, const double a, const double b, const double c, const double d);
double as_radians(const double theta);
double as_degrees(const double theta);
int rand(const int a, const int b);
double rand(const double a, const double b);
sf::Color get_random_colour();
