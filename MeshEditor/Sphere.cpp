#include "Sphere.h"

const std::string& Sphere::getName() const
{
	return m_command_name;
}

int Sphere::execute(const std::map<std::string, std::string>& args)
{
	if (args.count("R") != 1 || args.count("origin") != 1 || args.count("slices") != 1 || args.count("rings") != 1 || args.count("filename") != 1) return 3;
	if (std::stod(args.at("R")) <= 0)return 1;
	if (std::stod(args.at("slices")) <= 2 || std::stod(args.at("rings")) <= 1)return 2;
	std::ofstream test(args.at("filename"));
	if (!test)return 2;

	double R = std::stod(args.at("R"));
	Vec origin = get_origin(args.at("origin")); // I consider it the center of the sphere
	unsigned long slices = std::stoul(args.at("slices"));
	unsigned long rings = std::stoul(args.at("rings"));

	TriangleSoup sphere_mesh;

	for (unsigned long m = 0; m < rings; m++)
	{
		for (unsigned long n = 0; n < slices; n++)
		{

		}
	}





	STLParser stlParser;
	stlParser.write(sphere_mesh, args.at("filename"));

	return 0;
}

Vec Sphere::get_origin(const std::string str_origin)
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
