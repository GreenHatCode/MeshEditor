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

	// calculating of all 8 cube vertices


	STLParser stlParser;
	stlParser.write(TriangleSoup(), args.at("filepath"));

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
