#include "Application.h"

void Application::registerCommand(std::unique_ptr<Command> command)
{
	//m_commandmap.emplace((*command).getName(),command);


	m_commandmap.emplace(std::make_pair("Cube", nullptr)); // exapmle data

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

		if (isCommand(input_command))
		{
			std::cout << "success" << std::endl;
		}
		else std::cerr << "There is no such command!" << std::endl;



	}

	return 0;
}

bool Application::isCommand(const std::string& command)
{
	if (m_commandmap.find(command.substr(0, command.find_first_of(' '))) != m_commandmap.end())return true;
	else return false;
}
