#pragma once
#include <vector>
#include <string>

struct Vec
{
	double x, y, z;
};

struct Triangle
{
	Vec A, B, C;
	Vec normal;
};

using TriangleSoup = std::vector<Triangle>;

class STLParser
{
public:
	TriangleSoup read(const std::string& filename);
	void write(const TriangleSoup& triangleSoup, const std::string& filename);
private:
	//todo: implement stl parser

};

