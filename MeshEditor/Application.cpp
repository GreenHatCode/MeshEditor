#include "Application.h"

void Application::registerCommand(std::unique_ptr<Command> command)
{
	//m_commandmap.emplace((*command).getName(),command);
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
	}

	return 0;
}
