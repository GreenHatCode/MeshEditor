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
			std::cout << "success" << std::endl;
		}
		else std::cerr << "There is no such command!" << std::endl;



	}

	return 0;
}
