#include "STLParser.h"

void STLParser::write(const TriangleSoup& triangleSoup, const std::string& filename)
{
	std::ofstream otf(filename, std::ios::out);
	otf << std::fixed;
	otf << "solid MeshEditor\n";
	for (const auto& triangle: triangleSoup)
	{
		otf << "facet normal " << triangle.normal.x << " " << triangle.normal.y << " " << triangle.normal.z << std::endl;
		otf << "outer loop" << std::endl;
		otf << "vertex " << triangle.A.x << " " << triangle.A.y << " " << triangle.A.z << std::endl;
		otf << "vertex " << triangle.B.x << " " << triangle.B.y << " " << triangle.B.z << std::endl;
		otf << "vertex " << triangle.C.x << " " << triangle.C.y << " " << triangle.C.z << std::endl;
		otf << "endloop" << std::endl;
		otf << "endfacet" << std::endl;
	}

	otf << "endsolid MeshEditor";
	otf.flush();
	otf.close();
}
