#include "STLParser.h"

TriangleSoup STLParser::read(const std::string& filename)
{
	std::ifstream file;
	file.open(filename);

	TriangleSoup mesh;
	std::string line, buf;
	double px, py, pz;
	Vec v[3];
	int i = 0;
	while (std::getline(file, line)) {
		if (line.find("vertex") != std::string::npos) {
			std::istringstream s(line);
			s >> buf >> px >> py >> pz;
			v[i] = { px, py, pz };
			if (++i >= 3) {
				i = 0;
				Triangle t(v[0], v[1], v[2]);
				mesh.push_back(t);
			}
			continue;
		}
	}
	return mesh;
}

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


