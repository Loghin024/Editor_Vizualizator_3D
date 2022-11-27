#include "tools.hpp"

// returneaza x^2
double square(const double x) {
	return x * x;
}

//transformare liniara(pastreaza adunarea si inmultirea scalara) a lui x 
// [a, b]  [c, d], if x < a ⟹ c, if x > b ⟹ d
double map(double x, const double a, const double b, const double c, const double d) {
	if (x < a)
		x = a;
	else if (x > b)
		x = b;

	return (x - a) / (b - a) * (d - c) + c;
}

// converteste unghiul theta din grade in radiani
double as_radians(const double theta) {
	return theta / 180.0 * M_PI;
}

// converteste unghiul theta din radiani in grade
double as_degrees(const double theta) {
	return theta / M_PI * 180.0;
}

// returneaza o valoare int random [a,b]
int rand(const int a, const int b) {
	return rand() % (b - a) + a;
}

// returneaza o valoare double random [a,b]
double rand(const double a, const double b) {
	return rand() / static_cast<double>(RAND_MAX) * (b - a) + a;
}

// returneaza un sf::Color (un obiect cu o culoare rgb random)
sf::Color get_random_colour() {
	return sf::Color(rand(0, 256), rand(0, 256), rand(0, 256));
}
