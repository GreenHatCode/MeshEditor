#include "Cube.h"

const std::string& Cube::getName() const
{
    return m_command_name;
}

int Cube::execute(const std::map<std::string, std::string>& args)
{
	for (auto val: args)
	{
		std::cout << "Cube args: arg_name = " << val.first << "  arg_value = " << val.second << std::endl;
	}

	// todo: add validation and outputing codes
	if (args.count("L") != 1 || args.count("origin") != 1 || args.count("filepath") != 1) return 3;
	if (std::stod(args.at("L")) <= 0)return 1;
	std::ofstream test(args.at("filepath"));
	if (!test)return 2;

	// convert string args into nums
	double L = std::stod(args.at("L"));
	Vec origin = get_origin(args.at("origin"));

	// calculating the coordinates of all 8 vertices of the cube
	Vec A = origin + Vec(L / 2, -L / 2, 0);
	Vec B = origin + Vec(-L / 2, -L / 2, 0);
	Vec C = origin + Vec(-L / 2, L / 2, 0);
	Vec D = origin + Vec(L / 2, L / 2, 0);
	Vec A_top = A + Vec(0, 0, L);
	Vec B_top = B + Vec(0, 0, L);
	Vec C_top = C + Vec(0, 0, L);
	Vec D_top = D + Vec(0, 0, L);

	// creating the cude from triangles
	TriangleSoup cube;
	// bottom face
	cube.push_back(Triangle(A, B, C));
	cube.push_back(Triangle(A, D, C));
	// front face
	cube.push_back(Triangle(A, A_top, D_top));
	cube.push_back(Triangle(A, D, D_top));
	// right face
	cube.push_back(Triangle(D, D_top, C_top));
	cube.push_back(Triangle(D, C, C_top));
	// back face
	cube.push_back(Triangle(C, B, B_top));
	cube.push_back(Triangle(C, C_top, B_top));
	// left face
	cube.push_back(Triangle(B, A, A_top));
	cube.push_back(Triangle(B, B_top, A_top));
	// top face
	cube.push_back(Triangle(A_top, B_top, C_top));
	cube.push_back(Triangle(A_top, D_top, C_top));




	STLParser stlParser;
	stlParser.write(cube, args.at("filepath"));

    return 0;
}

Vec Cube::get_origin(const std::string str_origin)
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
