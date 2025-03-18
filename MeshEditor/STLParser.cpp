#include "STLParser.h"

void STLParser::write(const TriangleSoup& triangleSoup, const std::string& filename)
{
	std::string content;
	content += "solid MeshEditor\n";

	for (size_t i = 0; i < triangleSoup.size(); i++)
	{
		content += print_triangle(triangleSoup[i]);
	}

	content += "endsolid MeshEditor";

	// writing to file
	std::ofstream otf(filename, std::ios::out);
	otf.write(content.c_str(), content.size());
	otf.flush();
	otf.close();
}

std::string STLParser::print_triangle(Triangle triangle)
{
	std::ostringstream printed_triangle;

	printed_triangle << "facet normal " << triangle.normal.x << " " << triangle.normal.y << " " << triangle.normal.z << std::endl;
	printed_triangle << "outer loop" << std::endl;
	printed_triangle << "vertex " << triangle.A.x << " " << triangle.A.y << " " << triangle.A.z << std::endl;
	printed_triangle << "vertex " << triangle.B.x << " " << triangle.B.y << " " << triangle.B.z << std::endl;
	printed_triangle << "vertex " << triangle.C.x << " " << triangle.C.y << " " << triangle.C.z << std::endl;
	printed_triangle << "endloop" << std::endl;
	printed_triangle << "endfacet" << std::endl;

	return printed_triangle.str();
}
