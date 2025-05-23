#include "Split.h"

const std::string& Split::getName() const
{
	return m_command_name;
}

int Split::execute(const std::map<std::string, std::string>& args)
{
	if (args.count("input") != 1 || args.count("origin") != 1 || args.count("direction") != 1 || args.count("output1") != 1 || args.count("output2") != 1) return 3;
	if (get_origin(args.at("direction")).length() <= 0)return 1;
	if (!fileExists(args.at("output1"), false) || !fileExists(args.at("output2"), false) || !fileExists(args.at("input"), true))return 2;
	
	STLParser stlParser;
	TriangleSoup input_mesh = stlParser.read(args.at("input"));
	if (!intersects_mesh(input_mesh, get_origin(args.at("origin")), get_origin(args.at("direction"))))return 4;

	
	// splitting meshes
    Vec normal = get_origin(args.at("direction"));
    Vec origin = get_origin(args.at("origin"));
    TriangleSoup above, below; // above mesh - all Vecs that are placed above the panel. below - below the panel
    std::vector<Vec> boundary_vecs;

    for (const auto& triangle : input_mesh) 
    {
        double d0 = normal.dot(triangle.A - origin);
        double d1 = normal.dot(triangle.B - origin);
        double d2 = normal.dot(triangle.C - origin);

        if (d0 >= 0 && d1 >= 0 && d2 >= 0)above.push_back(triangle);
        else if (d0 < 0 && d1 < 0 && d2 < 0)below.push_back(triangle);
        else {
            // triangle is split - compute intersection points
            std::vector<Vec> positive, negative;
            if (d0 >= 0) positive.push_back(triangle.A); 
            else negative.push_back(triangle.A);
            
            if (d1 >= 0) positive.push_back(triangle.B); 
            else negative.push_back(triangle.B);
            
            if (d2 >= 0) positive.push_back(triangle.C); 
            else negative.push_back(triangle.C);

            std::vector<Vec> intersectionPoints;
            for (size_t i = 0; i < positive.size(); ++i) {
                for (size_t j = 0; j < negative.size(); ++j) {
                    Vec p1 = positive[i];
                    Vec p2 = negative[j];
                    double t = normal.dot(origin - p2) / normal.dot(p1 - p2);
                    intersectionPoints.push_back(p2.interpolate(p1, t));
                    boundary_vecs.push_back(p2.interpolate(p1, t));
                }
            }

            // triangulate the new shapes
            above.push_back({ positive[0], intersectionPoints[0], intersectionPoints[1] });
            below.push_back({ negative[0], intersectionPoints[1], intersectionPoints[0] }); // problem

            if (positive.size() == 2) {
                above.push_back({ positive[1], positive[0], intersectionPoints[1] });
            }
            if (negative.size() == 2) {
                below.push_back({ negative[0], negative[1], intersectionPoints[1] });
            }
        }
    }

    // triangulating the hole
    TriangleSoup filled_hole = triangulate_hole(boundary_vecs);
    above.insert(above.end(), filled_hole.begin(), filled_hole.end());
    below.insert(below.end(), filled_hole.begin(), filled_hole.end());


    stlParser.write(above, args.at("output1"));
    stlParser.write(below, args.at("output2"));





	return 0;
}

bool Split::fileExists(const std::string& file_path, bool input_file)
{
	if (input_file)
	{
		std::ifstream test(file_path);
		if (!test)return false;
		else return true;
	}
	else
	{
		std::ofstream test(file_path);
		if (!test)return false;
		else return true;
	}
}

Vec Split::get_origin(const std::string str_origin)
{
	double e[3];
	size_t prev = 1;
	for (size_t i = 0; i < 3; i++)
	{
		size_t curr = str_origin.find_first_of(",)", prev);
		e[i] = std::stod(str_origin.substr(prev, curr - prev));
		prev = curr + 1;
	}
	return Vec(e[0], e[1], e[2]);
}

TriangleSoup Split::triangulate_hole(const std::vector<Vec>& vecs)
{
    TriangleSoup filled_hole;

    if (vecs.size() < 3) return filled_hole; // Not enough points to form a triangle

    std::vector<Vec> vertices = vecs;
    while (vertices.size() >= 3)
    {
        size_t n = vertices.size();
        for (size_t i = 0; i < n; i++) 
        {
            size_t prev = (i + n - 1) % n;
            size_t next = (i + 1) % n;

            Vec A = vertices[prev], B = vertices[i], C = vertices[next];

            Vec edge1 = B - A;
            Vec edge2 = C - B;
            Vec normal = unit_vector(cross(edge1, edge2));

            if (normal.dot(normal) < 1e-6) continue; // Skip degenerate cases

            filled_hole.push_back(Triangle(A, B, C));
            vertices.erase(vertices.begin() + i); // Remove "ear"
            break;
        }
    }

    return filled_hole;
}
