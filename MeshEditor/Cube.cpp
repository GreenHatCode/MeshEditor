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
<<<<<<< Updated upstream
=======

	if (args.count("L") != 1 || args.count("origin") != 1 || args.count("filepath") != 1) return 3;
	if (std::stod(args.at("L")) <= 0)return 1;
	std::ofstream test(args.at("filepath"));
	if (!test)return 2;

	//todo: calculate cube
	double L = std::stod(args.at("L"));






	STLParser stlParser;
	stlParser.write(TriangleSoup(), args.at("filepath"));

>>>>>>> Stashed changes
    return 0;
}
