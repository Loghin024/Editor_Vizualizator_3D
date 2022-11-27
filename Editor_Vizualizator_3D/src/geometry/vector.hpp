#pragma once

#include "../utils/tools.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip> // pentru setprecision si setw

//vector tridimensional de forma v = (v1,v2,v3); cu valori reale
class Vector {

private:

	double x, y, z;
	sf::Color color; //culoare

public:

	///////////////
	// constructori
	//////////////

	//constructor default apelat fara parametrii
	Vector() : x(0.0), y(0.0), z(0.0), color(sf::Color::White) {}

	//constructor apelat cu coordonate dar fara culoare(primeste culoarea alb)
	Vector(const double _x, const double _y, const double _z) : x(_x), y(_y), z(_z), color(sf::Color::White) {}

	//constructor apelat cu coordonate si cu o culoare specificata
	Vector(const double _x, const double _y, const double _z, const sf::Color _color) : x(_x), y(_y), z(_z), color(_color) {}
	
	//constructor care primeste ca parametru un alt vector si ia valorile acestuia
	Vector(const Vector& v) : x(v.x), y(v.y), z(v.z), color(v.color) {}
	
	//constructor care primeste ca parametru un alt vector si o culoare si ia valorile acestuia mai putin culoarea(deaorece este specificata)
	Vector(const Vector& v, const sf::Color _color) : x(v.x), y(v.y), z(v.z), color(_color) {}

	/////////////
	// operatori
	///////////

	//atribuire
	Vector& operator=(const Vector& v);

	//returneaza un vector nou cu suma vectorului care a apelat metoda si vectorul parametru
	Vector operator+(const Vector& v) const;

	//modifica vectorul care a apelat metoda
	Vector operator+=(const Vector& v);

	//returneaza un vector nou cu diferenta dintre vectorul care a apelat metoda si vectorul parametru
	Vector operator-(const Vector& v) const;

	//modifica vectorul care a apelat metoda
	Vector operator-=(const Vector& v);

	//modifica vectorul care a apelat metoda x = -x; y = -y; z = -z;
	Vector operator-();

	//returneaza un nou vector cu produsul dintre vectorul ce a apelat metoda si un scalar primit ca parametru
	Vector operator*(const double factor) const;

	//modifica vectorul care apeleaza procedura
	Vector operator*=(const double factor);

	//produs scalar
	double operator*(const Vector& v) const;


	// altele

	//seteaza culoarea
	void set_color(const sf::Color& _color) { color = _color; }

	//calculeaza norma unui vector || vector ||
	double norm() const { return sqrt(x * x + y * y + z * z); }

	//normalizeaza vectorul
	void normalize() { *this = (*this) * (1 / this->norm()); }

	//returneaza vectorul normalizat
	Vector get_normalized() const;

	//calculeaza distanta
	double distance_to(const Vector& v) const;

	//rotirea unui obiect, se foloseste de axa si unghi
	void rotate(const Vector& center, const Vector& axis, const double theta);


	//clasele prietene pot accesa intre ele variabile protejate si private
	friend class Segment;
	friend class Plane3d;
	friend class Solid3d;
	friend class Camera;

};
