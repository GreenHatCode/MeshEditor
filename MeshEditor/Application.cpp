#include "Application.h"

void Application::registerCommand(std::unique_ptr<Command> command)
{
	m_commandmap.emplace(command->getName(), std::move(command));
}

int Application::execute(int argc, char* argv[])
{
	std::string input_command;

	// main loop
	std::cout << "\tMESH EDITOR" << std::endl;
	while (true)
	{
		std::cout << "command> ";
		std::getline(std::cin, input_command);
		std::cout << input_command << std::endl;

		if (auto search = m_commandmap.find(input_command.substr(0, input_command.find_first_of(' '))); search != m_commandmap.end())
		{
			// todo: validate()


			search->second->execute(GetCommandArgs(input_command));
		}
		else std::cerr << "There is no such command!" << std::endl;



	}

	return 0;
}

std::map<std::string, std::string> Application::GetCommandArgs(std::string command)
{
	// remove command name
	command.erase(0, command.find(' ')+1);
	
	// remove all spaces and quotes
	auto no_space_end = std::remove(command.begin(), command.end(), ' ');
	command.erase(no_space_end, command.end());
	no_space_end = std::remove(command.begin(), command.end(), '\"');
	command.erase(no_space_end, command.end());

	// parsing
	std::map<std::string, std::string> result_map;
	std::string key, val;

	// after preparing for parsing
	// L=10.0,origin=(4.5,3.4,2.1),filepath="D:\cube.stl"

	command.push_back('\0');
	size_t prev = 0;
	for (size_t curr = 1; curr < command.size(); curr++)
	{
		if (command[curr] == '\0' || (command[curr] == ',' && std::isalpha(std::tolower(command[curr + 1]))))
		{
			std::string param = command.substr(prev, curr - prev);
			prev = curr + 1;

			// fill the map with params
			int delim_idx = param.find('=');
			result_map.emplace(param.substr(0, delim_idx), param.substr(delim_idx + 1, param.size()));
		}
	}

	return result_map;
}
