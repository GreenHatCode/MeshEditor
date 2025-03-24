#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>


struct Vec
{
	Vec() { x = 0; y = 0; z = 0; }
	Vec(double X, double Y, double Z) { x = X; y = Y; z = Z; }
	double length() const {
		return std::sqrt(length_squared());
	}
	double length_squared() const {
		return x * x + y * y + z * z;
	}
	double x, y, z;
};

inline Vec operator+(const Vec& u, const Vec& v) {
	return Vec(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline Vec operator-(const Vec& u, const Vec& v) {
	return Vec(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline Vec operator*(const Vec& u, const Vec& v) {
	return Vec(u.x * v.x, u.y * v.y, u.z * v.z);
}

inline Vec operator*(double t, const Vec& v) {
	return Vec(t * v.x, t * v.y, t * v.z);
}

inline Vec operator*(const Vec& v, double t) {
	return t * v;
}

inline Vec operator/(Vec v, double t) {
	return (1 / t) * v;
}

inline Vec unit_vector(Vec v) {
	return v / v.length();
}

inline Vec cross(const Vec& u, const Vec& v) {
	return Vec(u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x);
}

inline Vec get_normal(const Vec& v1, const Vec& v2, const Vec& v3) {
	return unit_vector(cross(v2 - v1, v3 - v2));
}


struct Triangle
{
	Triangle(Vec a, Vec b, Vec c)
	{
		A = a;
		B = b;
		C = c;
		//normal = get_normal(a, b, c);
		normal = { 0,0,0 };
	}

	Vec A, B, C;
	Vec normal;
};

using TriangleSoup = std::vector<Triangle>;

class STLParser
{
public:
	TriangleSoup read(const std::string& filename); // reads model data from file
	void write(const TriangleSoup& triangleSoup, const std::string& filename); // writes model data to file
private:
	std::string print_triangle(Triangle triangle);

};

