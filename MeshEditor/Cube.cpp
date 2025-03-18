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



	STLParser stlParser;
	stlParser.write(TriangleSoup(), args.at("filepath"));

    return 0;
}
