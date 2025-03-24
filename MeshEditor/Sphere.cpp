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



	return 0;
}

Vec Sphere::get_origin(const std::string str_origin)
{
	return Vec();
}
