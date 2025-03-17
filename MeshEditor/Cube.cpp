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
    return 0;
}
