#include "Application.h"


void Application::registerCommand(std::unique_ptr<Command> command)
{
	m_commandmap.emplace(command->getName(), std::move(command));
}

int Application::execute(int argc, char* argv[])
{

	if (argc <= 1)
	{
		std::cout << "No command entered." << std::endl;
		return 0;
	}
	std::vector<std::string> input_command(argv + 1, argv + argc);

	if (auto search = m_commandmap.find(input_command[0]); search != m_commandmap.end())
	{
		std::cout << "Command finished with code " << search->second->execute(GetCommandArgs(input_command)) << std::endl;;
	}
	else std::cerr << "There is no such command!" << std::endl;

	return 0;
}

std::map<std::string, std::string> Application::GetCommandArgs(const std::vector<std::string>& command)
{
	// parsing
	std::map<std::string, std::string> result_map;
	std::string val;

	// command example
	// 0    1 2  3    4      5 6              7        8 9
	// Cube L = 10.0, origin = (4.5,3.4,2.1), filepath = "D:\cube.stl"
	for (size_t i = 1; i < command.size() - 2; i+=3)
	{
		val = command[i + 2];
		if (val.back() == ',')val.pop_back();
		result_map.emplace(command[i], val);
	}


	return result_map;
}
