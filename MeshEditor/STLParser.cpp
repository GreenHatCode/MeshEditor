#include "STLParser.h"

void STLParser::write(const TriangleSoup& triangleSoup, const std::string& filename)
{
	std::string content;
	content += "solid MeshEditor\n";






	content += "endsolid MeshEditor";

	// writing to file
	std::ofstream otf(filename, std::ios::out);
	otf.write(content.c_str(), content.size());
	otf.flush();
	otf.close();
}
