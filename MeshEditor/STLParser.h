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
	TriangleSoup read(const std::string& filename); // reads model data from file
	void write(const TriangleSoup& triangleSoup, const std::string& filename); // writes model data to file
private:
	//todo: implement stl parser

};

