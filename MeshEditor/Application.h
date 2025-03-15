#pragma once
#include "Command.h"
#include <iostream>

class Application
{
public:
	// stores all commands inside the application to enable a future extension with new commands
	void registerCommand(std::unique_ptr<Command> command);
	// call appropriate commands depending on the C arguments received from the main function
	// also converts argc and argv to a dictionary understandable to each command
	int execute(int argc, char* argv[]);

private:
	//todo: To store the commands for calling them later, choose a container that suits your implementation best
};

