#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>


struct Vec
{
	Vec() { x = 0; y = 0; z = 0; }
	Vec(double x, double y, double z) { x = x; y = y; z = z; }
	Vec operator-() const { return Vec(-x, -y, -z); }
	Vec& operator+=(const Vec& right)
	{
		x += right.x;
		y += right.y;
		z += right.z;
		return *this;
	}
	Vec& operator*=(const double t)
	{
		x *= t;
		y *= t;
		z *= t;
		return *this;
	}
	Vec& operator/=(const double t) {
		return *this *= 1 / t;
	}
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
	Triangle(Vec a, Vec b, Vec c, Vec normal)
	{
		A = a;
		B = b;
		C = c;
		normal = normal;
	}
	Triangle(Vec a, Vec b, Vec c)
	{
		A = a;
		B = b;
		C = c;
		normal = get_normal(a, b, c);
	}
	void flip_normal() {
		std::swap(B, C);
		normal = get_normal(A, B, C);
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
	//todo: implement stl parser
	std::string print_triangle(Triangle triangle);

};

